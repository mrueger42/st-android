#include <string.h>
#include <jni.h>
#include "sq.h"
#include <stdarg.h>
#include <android/log.h>
#include <sqaio.h>

#include <dirent.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/param.h>
#include <sys/stat.h>

#ifndef SQUEAK_BUILTIN_PLUGIN
# error "SQUEAK_BUILTIN_PLUGIN must be defined"
#endif

extern struct VirtualMachine *interpreterProxy;

/* Static references to callback instances during interpret() */
static JNIEnv *SqueakEnv = NULL;
static jobject *SqueakVM = NULL;
static jmethodID sqInvalidate = NULL;

static unsigned char *sqMemory = NULL;
static int sqHeaderSize = 0;

/* Higher values introduce more logging:
   1 - CRITICAL failures (out of memory etc)
   3 - ERRORS (opening resources etc)
   4 - WARNINGS (only one-time warnings)
   5 - NOTIFICATIONS (one-time)
   7 - REPEAT NOTIFICATIONS
   9 - TRACING
 */
static int vmLogLevel = 5;
int dprintf(int logLvl, const char *fmt, ...) {
  int result;
  va_list args;
  va_start(args, fmt);
  if(logLvl <= vmLogLevel) {
	result = __android_log_vprint(ANDROID_LOG_INFO, "SqueakVM", fmt, args);
  }
  va_end(args);
  return result;
}

/****************************************************************************/
/* Events */
/****************************************************************************/
#define MAX_EVENT_BUFFER 1024
static sqInputEvent eventBuffer[MAX_EVENT_BUFFER];
static int eventBufferGet = 0;
static int eventBufferPut = 0;

static int inputSemaphoreIndex = 0;/* if non-zero the event semaphore index */

sqInputEvent *sqNextEventPut(void) {
  sqInputEvent *evt;
  evt = eventBuffer + eventBufferPut;
  eventBufferPut = (eventBufferPut + 1) % MAX_EVENT_BUFFER;
  if (eventBufferGet == eventBufferPut) {
    /* buffer overflow; drop the last event */
    printf("WARNING: event buffer overflow\n");
    eventBufferGet = (eventBufferGet + 1) % MAX_EVENT_BUFFER;
  }
  return evt;
}

int ioSetInputSemaphore(int semaIndex) {
  inputSemaphoreIndex = semaIndex;
  return 1;
}

int ioGetNextEvent(sqInputEvent *evt) {
  if (eventBufferGet == eventBufferPut) {
    ioProcessEvents();
  }
  if (eventBufferGet == eventBufferPut)
    return 1;

  *evt = eventBuffer[eventBufferGet];
  eventBufferGet = (eventBufferGet+1) % MAX_EVENT_BUFFER;
  return 1;
}


/****************************************************************************/
/* JNI entry points */
/****************************************************************************/
int 
Java_org_squeak_android_SqueakVM_loadImageHeap(JNIEnv *env, jobject self,
					       jstring imageName, 
					       int heapSize) {
  if(longAt(sqMemory) < 0xFFFF) {
    sqHeaderSize = longAt(sqMemory+4);
  } else {
    sqHeaderSize = byteSwapped(longAt(sqMemory+4));
  }
  initTimer();
  aioInit();
  dprintf(4, "loadImageHeap: headerSize = %d\n", sqHeaderSize);
  //imageFile = sqImageFileOpen(imageName, "rb");
  readImageFromFileHeapSizeStartingAt(0, heapSize-sqHeaderSize, 0);
  //sqImageFileClose(imageFile);
  prepareActiveProcess();
  return 0;
}

int
Java_org_squeak_android_SqueakVM_allocate(JNIEnv *env, jobject self, 
					  int heapSize) {
  sqMemory = malloc(heapSize);
  dprintf(4, "allocate: %d bytes %x result\n", heapSize, sqMemory);
  /* Find the callBack method ID */
  jclass cls = (*env)->GetObjectClass(env, self);
  sqInvalidate = (*env)->GetMethodID(env, cls, "invalidate", "(IIII)V");
  dprintf(2, "invalidate: FAILED TO LOOK UP SqueakVM.invalidate(int, int, int, int)");
  return (int)sqMemory;
}

int
Java_org_squeak_android_SqueakVM_setLogLevel(JNIEnv *env, jobject self, 
					  int logLevel) {
  dprintf(4, "logLevel: %d\n", logLevel);
  vmLogLevel = logLevel;
  return vmLogLevel;
}

int
Java_org_squeak_android_SqueakVM_loadMemRegion(JNIEnv *env, jobject self,
					       jbyteArray ba, int ofs, 
					       int len) {
  jbyte *jbuf = (*env)->GetByteArrayElements(env, ba, NULL);
  memcpy(sqMemory+ofs, jbuf, len);
  (*env)->ReleaseByteArrayElements(env, ba, jbuf, 0);
  return 0;
}

int 
Java_org_squeak_android_SqueakVM_sendEvent(JNIEnv *env, jobject self, int 
					   type, int stamp,
					   int arg3, int arg4, int arg5,
					   int arg6, int arg7, int arg8) {

  sqInputEvent *event = sqNextEventPut();
  event->type = type;
  event->timeStamp = stamp;
  event->unused1 = arg3;
  event->unused2 = arg4;
  event->unused3 = arg5;
  event->unused4 = arg6;
  event->unused5 = arg7;
  event->windowIndex = arg8;
  if(inputSemaphoreIndex) signalSemaphoreWithIndex(inputSemaphoreIndex);
}

int 
Java_org_squeak_android_SqueakVM_interpret(JNIEnv *env, jobject jsqueak) {
  JNIEnv *oldEnv = SqueakEnv;
  jobject *oldSqueak = SqueakVM;
  dprintf(7, "Interpret Enter");
  SqueakEnv = env;
  SqueakVM = jsqueak;
  interpret();
  SqueakEnv = oldEnv;
  SqueakVM = oldSqueak;
  dprintf(7, "Interpret Leave");
}

int 
Java_org_squeak_android_SqueakVM_updateDisplay(JNIEnv *env, jobject self,
					       jintArray bits, int w, int h,
					       int d, int left, int top, int right, int bottom) {
  int row;
  sqInt formObj = interpreterProxy->displayObject();
  sqInt formBits = interpreterProxy->fetchPointerofObject(0, formObj);
  sqInt width = interpreterProxy->fetchIntegerofObject(1, formObj);
  sqInt height = interpreterProxy->fetchIntegerofObject(2, formObj);
  sqInt depth = interpreterProxy->fetchIntegerofObject(3, formObj);
  int *dispBits = interpreterProxy->firstIndexableField(formBits);

  if(depth != 32) {
    dprintf(4, "updateDisplay: Display depth %d\n", depth);
    return 0;
  }
  if(width != w) {
    dprintf(4, "updateDisplay: Display width is %d (expected %d)\n", width, w);
  }
  if(height != h) {
    dprintf(4, "updateDisplay: Display width is %d (expected %d)\n", height, h);
  }
  for(row = top; row < bottom; row++) {
  	int ofs = width*row+left;
  	(*env)->SetIntArrayRegion(env, bits, ofs, right-left, dispBits+ofs);
  }
  return 1;
}

/****************************************************************************/
/* sqImageFile functions */
/****************************************************************************/
int imgFilePos = 0;

int sqImageFileClose(sqImageFile h) {
  imgFilePos = 0;
}
sqImageFile sqImageFileOpen(char *fileName, char *mode) {
  imgFilePos = 0;
}

squeakFileOffsetType sqImageFilePosition(sqImageFile h) {
  return imgFilePos;
}

size_t sqImageFileRead(void *ptr, size_t sz, size_t count, sqImageFile h) {
  int nbytes = count * sz;
  dprintf(7, "sqImageFileRead: %d bytes\n", nbytes);
  if(nbytes < 256) {
    memcpy(ptr, sqMemory+imgFilePos, nbytes);
  }
  imgFilePos += nbytes;
  return nbytes;
}
squeakFileOffsetType sqImageFileSeek(sqImageFile h, squeakFileOffsetType pos){
  imgFilePos = (int)pos;
}
size_t sqImageFileWrite(void *ptr, size_t sz, size_t count, sqImageFile h) {
  return 0;
}

/****************************************************************************/
/* Memory allocation functions */
/****************************************************************************/
void *sqAllocateMemory(int minHeapSize, int desiredHeapSize) {
  return sqMemory + sqHeaderSize;
}
int sqGrowMemoryBy(int oldLimit, int delta) {
  return oldLimit;
}
int sqShrinkMemoryBy(int oldLimit, int delta) {
  return oldLimit;
}
int sqMemoryExtraBytesLeft(int includingSwap) {
  return 0;
}
void sqReleaseMemory(void) {
}

int ioDoDialog(void) {
}

/****************************************************************************/
/* Directory primitives */
/****************************************************************************/

time_t convertToSqueakTime(time_t unixTime) {
  /* Squeak epoch is Jan 1, 1901.  Unix epoch is Jan 1, 1970: 17 leap years
     and 52 non-leap years later than Squeak. */
  return unixTime + ((52*365UL + 17*366UL) * 24*60*60UL);
}

# define NAMLEN(dirent) strlen((dirent)->d_name)
int sq2uxPath(char* sqString, int sqLength, char* uxString, int uxLength, int term) {
  int count = uxLength < sqLength ? uxLength : sqLength;
  memcpy(uxString, sqString, count-term);
  if(term) uxString[count] = '\0';
  return count;
}

int ux2sqPath(char* uxString, int uxLength, char* sqString, int sqLength, int term) {
  int count = uxLength < sqLength ? uxLength : sqLength;
  dprintf(7, "%s\n", __FUNCTION__);
  memcpy(sqString, uxString, count-term);
  if(term) sqString[count] = '\0';
  return count;
}

/*** Constants ***/
#define ENTRY_FOUND     0
#define NO_MORE_ENTRIES 1
#define BAD_PATH        2

#define DELIMITER '/'

/*** Variables ***/
char lastPath[MAXPATHLEN+1];
int  lastPathValid = false;
int  lastIndex= -1;
DIR *openDir= 0;

sqInt dir_Delimitor(void) {
	return '/';
}

sqInt dir_Create(char *pathString, sqInt pathStringLength) {
  /* Create a new directory with the given path. By default, this
     directory is created relative to the cwd. */
  char name[MAXPATHLEN+1];
  int i;
  dprintf(7, "%s\n", __FUNCTION__);
  if (pathStringLength >= MAXPATHLEN) return false;
  if (!sq2uxPath(pathString, pathStringLength, name, MAXPATHLEN, 1))
    return false;
  return mkdir(name, 0777) == 0;	/* rwxrwxrwx & ~umask */
}

sqInt dir_Delete(char *pathString, sqInt pathStringLength) {
  /* Delete the existing directory with the given path. */
  char name[MAXPATHLEN+1];
  int i;
  dprintf(7, "%s\n", __FUNCTION__);
  if (pathStringLength >= MAXPATHLEN) return false;
  if (!sq2uxPath(pathString, pathStringLength, name, MAXPATHLEN, 1))
    return false;
  if (lastPathValid && !strcmp(lastPath, name)) {
    closedir(openDir);
    lastPathValid= false;
    lastIndex= -1;
    lastPath[0]= '\0';
  }
  return rmdir(name) == 0;
}

static int maybeOpenDir(char *unixPath) {
  /* if the last opendir was to the same directory, re-use the directory
     pointer from last time.  Otherwise close the previous directory,
     open the new one, and save its name.  Return true if the operation
     was successful, false if not. */
  dprintf(7, "%s\n", __FUNCTION__);
  if (!lastPathValid || strcmp(lastPath, unixPath)) {
    /* invalidate the old, open the new */
    if (lastPathValid) closedir(openDir);
    lastPathValid= false;
    strcpy(lastPath, unixPath);
    if ((openDir= opendir(unixPath)) == 0) return false;
    lastPathValid= true;
    lastIndex= 0;	/* first entry is index 1 */
  }
  return true;
}

sqInt dir_Lookup(char *pathString, sqInt pathStringLength, sqInt index,
		 char *name, sqInt *nameLength, sqInt *creationDate, 
		 sqInt *modificationDate, sqInt *isDirectory, 
		 squeakFileOffsetType *sizeIfFile)
{
  /* Lookup the index-th entry of the directory with the given path, starting
     at the root of the file system. Set the name, name length, creation date,
     creation time, directory flag, and file size (if the entry is a file).
     Return:	0 	if a entry is found at the given index
     		1	if the directory has fewer than index entries
		2	if the given path has bad syntax or does not reach a dir
  */

  int i;
  int nameLen= 0;
  struct dirent *dirEntry= 0;
  char unixPath[MAXPATHLEN+1];
  struct stat statBuf;

  dprintf(7, "%s\n", __FUNCTION__);

  /* default return values */
  *name             = 0;
  *nameLength       = 0;
  *creationDate     = 0;
  *modificationDate = 0;
  *isDirectory      = false;
  *sizeIfFile       = 0;

  if ((pathStringLength == 0)) strcpy(unixPath, ".");
  else if (!sq2uxPath(pathString, pathStringLength, unixPath, MAXPATHLEN, 1))
    return BAD_PATH;

  /* get file or directory info */
  if (!maybeOpenDir(unixPath)) return BAD_PATH;

  if (++lastIndex == index) {
    dprintf(7, "dir cache hit\n");
    index= 1; /* fake that the dir is rewound and we want the first entry */
  } else {
    dprintf(7, "dir cache miss\n");
    rewinddir(openDir);	/* really rewind it, and read to the index */
    lastIndex= index;
  }

  for (i= 0; i < index; i++) {
  nextEntry:
    do { 
      errno= 0; 
      dirEntry= readdir(openDir);
    }  while ((dirEntry == 0) && (errno == EINTR));

    if (!dirEntry) return NO_MORE_ENTRIES;
    nameLen= NAMLEN(dirEntry);

    /* ignore '.' and '..' (these are not *guaranteed* to be first) */
    if (nameLen < 3 && dirEntry->d_name[0] == '.')
      if (nameLen == 1 || dirEntry->d_name[1] == '.')
	goto nextEntry;
  }

  *nameLength= ux2sqPath(dirEntry->d_name, nameLen, name, MAXPATHLEN, 0);

  {
    char terminatedName[MAXPATHLEN];
    strncpy(terminatedName, dirEntry->d_name, nameLen);
    terminatedName[nameLen]= '\0';
    strcat(unixPath, "/");
    strcat(unixPath, terminatedName);
    if (stat(unixPath, &statBuf) && lstat(unixPath, &statBuf)) {
      /* We can't stat the entry, but failing here would invalidate
	 the whole directory --bertf */
      return ENTRY_FOUND;
    }
  }

  /* last change time */
  *creationDate= convertToSqueakTime(statBuf.st_ctime);
  /* modification time */
  *modificationDate= convertToSqueakTime(statBuf.st_mtime);

  if (S_ISDIR(statBuf.st_mode)) {
    *isDirectory= true;
  } else {
    *sizeIfFile= statBuf.st_size;
  }
  return ENTRY_FOUND;
}


sqInt dir_PathToWorkingDir(char *pathName, sqInt pathNameMax) {
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt dir_SetMacFileTypeAndCreator(char *filename, sqInt filenameSize, 
				   char *fType, char *fCreator) {
  dprintf(7, "%s\n", __FUNCTION__);
  return 1;
}

sqInt dir_GetMacFileTypeAndCreator(char *filename, sqInt filenameSize, 
				   char *fType, char *fCreator) {
  dprintf(7, "%s\n", __FUNCTION__);
  return 1;
}


/* timer support */
static unsigned int   lowResMSecs= 0;
static struct timeval startUpTime;

int initTimer() {
  /* set up the micro/millisecond clock */
  gettimeofday(&startUpTime, 0);
}

sqInt ioMSecs(void) {
  struct timeval now;
  gettimeofday(&now, 0);
  if ((now.tv_usec-= startUpTime.tv_usec) < 0) {
    now.tv_usec+= 1000000;
    now.tv_sec-= 1;
  }
  now.tv_sec-= startUpTime.tv_sec;
  return lowResMSecs= (now.tv_usec / 1000 + now.tv_sec * 1000);
}

sqInt ioMicroMSecs(void) {
  return ioMSecs();
}

sqInt ioSeconds(void) {
  return convertToSqueakTime(time(0));
}


/* Profiling. */
sqInt clearProfile(void)   { return 0; }
sqInt dumpProfile(void)    { return 0; }
sqInt startProfiling(void) { return 0; }
sqInt stopProfiling(void)  { return 0; }

/* Clipboard (cut/copy/paste). */
sqInt clipboardSize(void) { return 0; }
sqInt clipboardReadIntoAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex) { return 0; }
sqInt clipboardWriteFromAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex) { return 0; }

/* Image file and VM path names. */
char imageName[256];
char *getImageName(void) { return imageName; }

sqInt imageNameGetLength(sqInt sqImageNameIndex, sqInt length){
  char *sqImageName= (char *)sqImageNameIndex;
  int count = strlen(imageName);
  count= (length < count) ? length : count;
  memcpy(sqImageName, imageName, count);
  return count;
}

sqInt imageNamePutLength(sqInt sqImageNameIndex, sqInt length){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt imageNameSize(void){
  return strlen(imageName);
}

sqInt vmPathSize(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt vmPathGetLength(sqInt sqVMPathIndex, sqInt length){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}



/* Display, mouse, keyboard, time. */
sqInt ioBeep(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioExit(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioFormPrint(sqInt bitsAddr, sqInt width, sqInt height, sqInt depth,
		  double hScale, double vScale, sqInt landscapeFlag){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioSetFullScreen(sqInt fullScreen){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioRelinquishProcessorForMicroseconds(sqInt microSeconds){
  // dprintf("%s\n", __FUNCTION__);
  return 0;
}

sqInt ioScreenSize(void){
  return (800 << 16) | (600);
}

sqInt ioScreenDepth(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 32;
}

sqInt ioSetCursor(sqInt cursorBitsIndex, sqInt offsetX, sqInt offsetY){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioSetCursorWithMask(sqInt cursorBitsIndex, sqInt cursorMaskIndex, sqInt offsetX, sqInt offsetY){
  //dprintf(7, "%s\n", __FUNCTION__);
  return 1;
}

sqInt ioSetCursorARGB(sqInt cursorBitsIndex, sqInt offsetX, sqInt offsetY){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioForceDisplayUpdate(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 1;
}

sqInt ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
		    sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB){
  if(sqInvalidate && SqueakEnv && SqueakVM) {
  	dprintf(7, "SqueakVM.invalidate(): %d, %d -- %d, %d", affectedL, affectedT, affectedR, affectedB);
  	(*SqueakEnv)->CallVoidMethod(SqueakEnv, SqueakVM, sqInvalidate, affectedL, affectedT, affectedR, affectedB);
  }
  return 1;
}

sqInt ioHasDisplayDepth(sqInt depth){
  dprintf(7, "%s: %d\n", __FUNCTION__, depth);
  return depth == 32;
}

sqInt ioSetDisplayMode(sqInt width, sqInt height, sqInt depth, sqInt fullscreenFlag){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

// sqInt ioSetInputSemaphore(sqInt semaIndex) { return 0; }
// sqInt ioGetNextEvent(sqInputEvent *evt) { return 0; }
sqInt ioGetButtonState(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioGetKeystroke(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioMousePoint(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioPeekKeystroke(void){
  dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}

sqInt ioProcessEvents(void){
  // dprintf(7, "%s\n", __FUNCTION__);
  return 0;
}


/* System attributes. */
char * getAttributeString(int id) {
  /* This is a hook for getting various status strings back from
     the OS. In particular, it allows Squeak to be passed arguments
     such as the name of a file to be processed. Command line options
     could be reported this way as well.
  */
  /* id == 0 : return the full name of the VM */
  if(id == 0) return "Squeak.exe";
  /* 0 < id <= 1000 : return options of the image (image args)*/
  if(id > 0 && id <= 1000) return NULL;
  /* id < 0 : return options of the VM (vm args) */
  if(id < 0) return NULL;

  /* special attributes */
  switch(id) {
    case 1001: /* Primary OS type */
      return "Android";
    case 1002: /* Secondary OS type */
      return "3";
    case 1003:/* Processor type */
      return "ARM";
    case 1004:
      return (char*) interpreterVersion;
    case 1005: /* window system name */
      return "Android";
      //    case 1006: /* VM build ID */
      // return vmBuildString;
  }
  return NULL;
}

sqInt attributeSize(sqInt id){
  char *attrValue;
  attrValue = getAttributeString(id);
  if(!attrValue) return primitiveFail();
  return strlen(attrValue);
}

sqInt getAttributeIntoLength(sqInt id, sqInt byteArrayIndex, sqInt length){
  int count;
  char *srcPtr = getAttributeString(id);
  if(!srcPtr) return 0;
  count = strlen(srcPtr);
  count = count > length ? length : count;
  memcpy((char*)byteArrayIndex, srcPtr, count);
  return count;
}

sqInt sqGetFilenameFromString(char * aCharBuffer, char * aFilenameString, sqInt filenameLength, sqInt aBoolean) { return 0; }
sqInt ioDisablePowerManager(sqInt disableIfNonZero) { return 0; }
