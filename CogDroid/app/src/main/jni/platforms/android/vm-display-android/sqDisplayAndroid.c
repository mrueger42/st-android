/* sqDisplayAndroid.c -- support for display and input events on Android based systems
 *
 *   Copyright (C) 2010-2017 by Andreas Raab, Jean Baptiste Arnaud, Santiago Bragagnolo, Dmitry Golubovsky, Michael Rueger
 *   All rights reserved.
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 *   copy of this software and associated documentation files (the "Software"),
 *   to deal in the Software without restriction, including without limitation
 *   the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *   and/or sell copies of the Software, and to permit persons to whom the
 *   Software is furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *   DEALINGS IN THE SOFTWARE.
 */

#include "sq.h"
#include "sqaio.h"
#include "sqVirtualMachine.h"

#include "SqDisplay.h"
#include "sqUnixGlobals.h"

#include <jni.h>
#include <fcntl.h>

#define JUMP_FOR_GRAPHIC 3
#define JUMP_FOR_IDLE 2

extern int inputEventSemaIndex;
extern struct VirtualMachine *interpreterProxy;

extern void jnilog(char *str);

extern JNIEnv *CogEnv;
extern jobject CogVM;

extern jclass vmClass = 0;
extern jmethodID invalidate;

extern void jumpOut(int);
extern sqInt primitiveFail(void);
extern int scrw, scrh;

#include "sqUnixEvent.c"



/****************************************************************************/
/* Display control                                                          */   
/****************************************************************************/

//maybe to change later
static int handleEvents(void)
{
  return 0;	/* 1 if events processed */
}

static sqInt display_clipboardSize(void)
{
  return 0;
}

static sqInt display_clipboardWriteFromAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
  return 0;
}

static sqInt display_clipboardReadIntoAt(sqInt count, sqInt byteArrayIndex, sqInt startIndex)
{
  return 0;
}


static sqInt display_ioFormPrint(sqInt bitsIndex, sqInt width, sqInt height, sqInt depth, double hScale, double vScale, sqInt landscapeFlag)
{
  return 1;
}

static sqInt display_ioBeep(void)
{
  return 0;
}
//Quit the VM interpretation but explain why for Idle
static sqInt display_ioRelinquishProcessorForMicroseconds(sqInt microSeconds)
{
//	jnilog("ioRelinquishProcessorForMicroseconds " + microSeconds);
//	sleep(10);
//  jumpOut(JUMP_FOR_IDLE);
  return 0;
}

/* Poll asynchronous IO requests. Return 1 if the GUI events buffer is not empty */

static sqInt display_ioProcessEvents(void)
{
//	jnilog("ioProcessEvents");
	aioPoll(0);
	return (0);
}

static sqInt display_ioScreenDepth(void)
{
  return 32;
}

static double display_ioScreenScaleFactor(void)
{
	return 1.0;
}

static sqInt display_ioScreenSize(void)
{
  return (scrw << 16) | (scrh);
}

static sqInt display_ioSetCursorWithMask(sqInt cursorBitsIndex, sqInt cursorMaskIndex, sqInt offsetX, sqInt offsetY)
{
  return 0;
}

static sqInt display_ioSetFullScreen(sqInt fullScreen)
{
  return 0;
}

//Quit the VM interpretation but explain why for graphical update

static sqInt display_ioForceDisplayUpdate(void)
{
	jnilog("ioForceDisplayUpdate");
//	if(sqInvalidate && displayEnv && displayView) {
//		jnilog("call jni invalidate");
//		(*displayEnv)->CallVoidMethod(displayEnv, displayView, sqInvalidate, 0, 0, scrw, scrh);
//	}
	jnilog("ioForceDisplayUpdate done");
//	jumpOut(JUMP_FOR_GRAPHIC);
	return 1;
}

//Quit the VM interpretation but explain why for graphical update

//static sqInt display_ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
//				   sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB)
//{
//	jumpOut(JUMP_FOR_GRAPHIC);
//	return 1;
//}

static sqInt display_ioShowDisplay(sqInt dispBitsIndex, sqInt width, sqInt height, sqInt depth,
								   sqInt affectedL, sqInt affectedR, sqInt affectedT, sqInt affectedB)
{
	jnilog("ioShowDisplay");
	if(CogEnv && CogVM) {
		if (invalidate) {
			jnilog("call jni invalidate");
			(*CogEnv)->CallVoidMethod(CogEnv, CogVM, invalidate, affectedL, affectedT, affectedR, affectedB);
		} else {
			jnilog("invalidate not ready");
		}
	} else {
		jnilog("globals not ready");
	}
	jnilog("ioShowDisplay done");
//	jumpOut(JUMP_FOR_GRAPHIC);
	return 1;
}
static sqInt display_ioHasDisplayDepth(sqInt i)
{
	switch (i)
	  {
	  case 1:
	  case 2:
	  case 4:
	  case 8:
	  case 16:
	  case 32:
		return true;
	  }
	return false;
}

static sqInt display_ioSetDisplayMode(sqInt width, sqInt height, sqInt depth, sqInt fullscreenFlag)
{
  return 1;
}

static void display_winSetName(char *imageName)
{}

static void *display_ioGetDisplay(void)	{ return 0; }
static void *display_ioGetWindow(void)	{ return 0; }

static sqInt display_ioGLinitialise(void) { return 0; }
static sqInt display_ioGLcreateRenderer(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h, sqInt flags) { return 0; }
static void  display_ioGLdestroyRenderer(glRenderer *r) {}
static void  display_ioGLswapBuffers(glRenderer *r) {}
static sqInt display_ioGLmakeCurrentRenderer(glRenderer *r) { return 0; }
static void  display_ioGLsetBufferRect(glRenderer *r, sqInt x, sqInt y, sqInt w, sqInt h) { }

static char *display_winSystemName(void)
{
  return "android";
}

static void display_winInit(void){}

static void display_winOpen(void){}


static void display_winExit(void) {}

static int  display_winImageFind(char *buf, int len)		{ return 0; }
static void display_winImageNotFound(void)			{ }

static sqInt display_primitivePluginBrowserReady(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURLStream(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginPostURL(void)		{ return primitiveFail(); }
static sqInt display_primitivePluginRequestFileHandle(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginDestroyRequest(void)	{ return primitiveFail(); }
static sqInt display_primitivePluginRequestState(void)		{ return primitiveFail(); }


static sqInt display_ioSetCursorARGB(sqInt cursorBitsIndex, 
		sqInt extentX, sqInt extentY, 
		sqInt offsetX, sqInt offsetY) { 
return 0; }

static char **display_clipboardGetTypeNames(void) { 
			return NULL; }

static sqInt display_clipboardSizeWithType(char *typeName, int nTypeName) { 
			return 0; }

static void display_clipboardWriteWithType(char *data, size_t ndata, 
		char *typeName, size_t nTypeName, 
		int isDnd, int isClaiming) { 
			return; }
			
static int display_hostWindowCreate(int w, int h, int x, 
		int y, char *list, int attributeListLength) { return 0; }

static int display_hostWindowClose(int index) { return 0; }

static int display_hostWindowCloseAll(void) { return 0; }

static int display_hostWindowShowDisplay(unsigned *dispBitsIndex, int width, 
		int height, int depth, int affectedL, int affectedR, 
		int affectedT, int affectedB, int windowIndex) { return 0; }

static int display_hostWindowGetSize(int windowIndex) { return display_ioScreenSize; }

static int display_hostWindowSetSize(int windowIndex, int w, int h) { return -1; }

static int display_hostWindowGetPosition(int windowIndex) { return -1; }

static int display_hostWindowSetPosition(int windowIndex, int x, int y) { return -1; }

static int display_ioSizeOfNativeWindow(void *windowHandle) { return -1; }

static int display_ioPositionOfNativeWindow(void *windowHandle) { return -1; }

static int display_hostWindowSetTitle(int windowIndex, 
		char *newTitle, int sizeOfTitle) { return -1; }

static int display_ioPositionOfScreenWorkArea(int windowIndex) { return 0; }

static int display_ioSizeOfScreenWorkArea(int windowIndex) { return 0; }

void *display_ioGetWindowHandle() { return NULL; }

static sqInt display_ioSetCursorPositionXY(sqInt x, sqInt y) {return 0; }

static int display_ioPositionOfNativeDisplay(void *windowHandle) { return -1; }

static int display_ioSizeOfNativeDisplay(void *windowHandle) { return -1; }

static sqInt display_dndOutStart(char *types, int ntypes)	{ return 0; }

static void  display_dndOutSend (char *bytes, int nbytes)	{ return  ; }

static sqInt display_dndOutAcceptedType(char *buf, int nbuf)	{ return 0; }

static sqInt display_dndReceived(char *fileName)	{ return 0; }

SqDisplayDefine(android);	/* name must match that in makeInterface() below */


/*** module ***/

static void display_printUsage(void)
{
 /* otherwise... */
}

static void display_printUsageNotes(void)
{
}

static void display_parseEnvironment(void)
{
}

static int display_parseArgument(int argc, char **argv)
{
  return 0;	/* arg not recognised */
}

static void *display_makeInterface(void)
{
  return &display_android_itf;		/* name must match that in SqDisplayDefine() above */
}

#include "SqModule.h"

SqModuleDefine(display, android);	/* name must match that in sqUnixMain.c's moduleDescriptions */