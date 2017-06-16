/* ANDROID sqPlatformSpecific.h -- Platform-specific prototypes and definitions */

/* How to use this file:
   This file is for general platform-specific macros and declarations.
   The goal is to keep most of the other header files generic across platforms.
   To override a definition or macro from sq.h, you must first #undef it, then
   provide the new definition.

*/



#ifdef ANDROID

#define squeakFileOffsetType unsigned long long

#undef sqImageFile
#undef sqImageFileClose
#undef sqImageFileOpen
#undef sqImageFilePosition
#undef sqImageFileRead
#undef sqImageFileSeek
#undef sqImageFileWrite

#define sqImageFile int

int sqImageFileClose(sqImageFile h);
sqImageFile sqImageFileOpen(char *fileName, char *mode);
squeakFileOffsetType sqImageFilePosition(sqImageFile h);
size_t sqImageFileRead(void *ptr, size_t sz, size_t count, sqImageFile h);
squeakFileOffsetType sqImageFileSeek(sqImageFile h, squeakFileOffsetType pos);
size_t sqImageFileWrite(void *ptr, size_t sz, size_t count, sqImageFile h);

#undef sqAllocateMemory
#undef sqGrowMemoryBy
#undef sqShrinkMemoryBy
#undef sqMemoryExtraBytesLeft

void *sqAllocateMemory(int minHeapSize, int desiredHeapSize);
int sqGrowMemoryBy(int oldLimit, int delta);
int sqShrinkMemoryBy(int oldLimit, int delta);
int sqMemoryExtraBytesLeft(int includingSwap);
void sqReleaseMemory(void);

#undef ioMSecs
sqInt ioMSecs(void);


#endif /* ANDROID */

