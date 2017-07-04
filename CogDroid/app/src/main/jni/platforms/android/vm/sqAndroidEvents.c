/* sqAndroidEvents.c -- support for window system events.
 * 
 *   Copyright (C) 1996-2017 by Ian Piumarta and other authors/contributors
  *  Ian Piumarta, eliot, nuke, Dmitry Golubovsky, Michael Rueger
 *   All rights reserved.
 *   
 *   This file is part of Android Squeak.
 * 
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 * 
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <sq.h>

#if defined(DEBUG_EVENTS)
# undef DEBUG_EVENTS
# define DEBUG_EVENTS 1
# define DEBUG_KEYBOARD_EVENTS 1
# define DEBUG_MOUSE_EVENTS 1
#else
# if defined(DEBUG_KEYBOARD_EVENTS)
#	undef DEBUG_KEYBOARD_EVENTS
#	define DEBUG_KEYBOARD_EVENTS 1
# endif
# if defined(DEBUG_MOUSE_EVENTS)
#	undef DEBUG_MOUSE_EVENTS
#	define DEBUG_MOUSE_EVENTS 1
# endif
#endif

#define IEB_SIZE	 64	/* must be power of 2 */

#define ioProcessEvents()

typedef struct
{
  int x, y;
} SqPoint;

SqPoint mousePosition= { 0, 0 };	/* position at last motion event */
int	swapBtn= 0;			/* 1 to swap yellow and blue buttons */

sqInputEvent inputEventBuffer[IEB_SIZE];

int iebIn=  0;	/* next IEB location to write */
int iebOut= 0;	/* next IEB location to read  */

#define iebEmptyP()	(iebIn == iebOut)
#define iebAdvance(P)	(P= ((P + 1) & (IEB_SIZE - 1)))

int buttonState= 0;		/* mouse button state or 0 if not pressed */
int modifierState= 0;		/* modifier key state or 0 if none pressed */

extern int inputEventSemaIndex;

#if DEBUG_EVENTS || DEBUG_KEYBOARD_EVENTS || DEBUG_MOUSE_EVENTS

#include <ctype.h>

static void printKey(int key)
{
  dprintf(7, " `%c' (%d = 0x%x)", (isgraph(key) ? key : ' '), key, key);
}

static void printButtons(int buttons)
{
  if (buttons & RedButtonBit)    dprintf(7, " red");
  if (buttons & YellowButtonBit) dprintf(7, " yellow");
  if (buttons & BlueButtonBit)   dprintf(7, " blue");
}

static void printModifiers(int midofiers)
{
  if (midofiers & ShiftKeyBit)   dprintf(7, " Shift");
  if (midofiers & CtrlKeyBit)    dprintf(7, " Control");
  if (midofiers & CommandKeyBit) dprintf(7, " Command");
  if (midofiers & OptionKeyBit)  dprintf(7, " Option");
}

#endif /* DEBUG_KEYBOARD_EVENTS || DEBUG_MOUSE_EVENTS */

/*** event handling ***/

//sqInt inputEventSemaIndex= 0;

/* set asynchronous input event semaphore  */

//sqInt ioSetInputSemaphore(sqInt semaIndex)
//{
//  if (semaIndex == 0)
//    success(false);
//  else
//    inputEventSemaIndex= semaIndex;
//  return true;
//}


static sqInputEvent *allocateInputEvent(int eventType)
{
  sqInputEvent *evt= &inputEventBuffer[iebIn];
  iebAdvance(iebIn);
  if (iebEmptyP())
    {
      /* overrun: discard oldest event */
      iebAdvance(iebOut);
    }
  evt->type= eventType;
  evt->timeStamp= ioMSecs();
  return evt;
}

#define allocateMouseEvent() ( \
  (sqMouseEvent *)allocateInputEvent(EventTypeMouse) \
)

#define allocateKeyboardEvent() ( \
  (sqKeyboardEvent *)allocateInputEvent(EventTypeKeyboard) \
)

#define allocateDragEvent() ( \
  (sqDragDropFilesEvent *)allocateInputEvent(EventTypeDragDropFiles) \
)

#define allocateWindowEvent() ( \
  (sqWindowEvent *)allocateInputEvent(EventTypeWindow) \
)


sqInt getButtonState(void)
{
  /* red button honours the modifiers:
   *	red+ctrl    = yellow button
   *	red+command = blue button
   */
  int buttons= buttonState;
  int modifiers= modifierState;
  if ((buttons == RedButtonBit) && modifiers)
    {
      int yellow= swapBtn ? BlueButtonBit   : YellowButtonBit;
      int blue=   swapBtn ? YellowButtonBit : BlueButtonBit;
      switch (modifiers)
	{
	case CtrlKeyBit:    buttons= yellow; modifiers &= ~CtrlKeyBit;    break;
	case CommandKeyBit: buttons= blue;   modifiers &= ~CommandKeyBit; break;
	}
    }
#if DEBUG_MOUSE_EVENTS
  dprintf(7, "BUTTONS");
  printModifiers(modifiers);
  printButtons(buttons);
  dprintf(7, "\n");
#endif
  return buttons | (modifiers << 3);
}


static void signalInputEvent(void)
{
#if DEBUG_EVENTS
  dprintf(7, "signalInputEvent\n");
#endif
  if (inputEventSemaIndex > 0)
    signalSemaphoreWithIndex(inputEventSemaIndex);
}


static void recordMouseEvent(void)
{
  int state= getButtonState();
  sqMouseEvent *evt= allocateMouseEvent();
  evt->x= mousePosition.x;
  evt->y= mousePosition.y;
  evt->buttons= (state & 0x7);
  evt->modifiers= (state >> 3);
  evt->nrClicks=
    evt->windowIndex= 0;
  signalInputEvent();
#if DEBUG_MOUSE_EVENTS
  dprintf(7, "EVENT: mouse (%d,%d)", mousePosition.x, mousePosition.y);
  printModifiers(state >> 3);
  printButtons(state & 7);
  dprintf(7, "\n");
#endif
}


static void recordKeyboardEvent(int keyCode, int pressCode, int modifiers, int ucs4)
{
  sqKeyboardEvent *evt= allocateKeyboardEvent();
  if (keyCode < 0) keyCode= 0;
  evt->charCode= keyCode;
  evt->pressCode= pressCode;
  evt->modifiers= modifiers;
  evt->utf32Code= ucs4;
  evt->reserved1=
    evt->windowIndex= 0;
  signalInputEvent();
#if DEBUG_KEYBOARD_EVENTS
  dprintf(7, "EVENT: key");
  switch (pressCode)
    {
    case EventKeyDown: dprintf(7, " down "); break;
    case EventKeyChar: dprintf(7, " char "); break;
    case EventKeyUp:   dprintf(7, " up   "); break;
    default:           dprintf(7, " ***UNKNOWN***"); break;
    }
  printModifiers(modifiers);
  printKey(keyCode);
  dprintf(7, " ucs4 %d\n", ucs4);
#endif
}


static void recordDragEvent(int dragType, int numFiles)
{
  int state= getButtonState();
  sqDragDropFilesEvent *evt= allocateDragEvent();
  evt->dragType= dragType;
  evt->x= mousePosition.x;
  evt->y= mousePosition.y;
  evt->modifiers= (state >> 3);
  evt->numFiles= numFiles;
  evt->windowIndex= 0;
  signalInputEvent();
#if DEBUG_EVENTS
  dprintf(7, "EVENT: drag (%d,%d)", mousePosition.x, mousePosition.y);
  printModifiers(state >> 3);
  printButtons(state & 7);
  dprintf(7, "\n");
#endif
}


static void recordWindowEvent(int action, int v1, int v2, int v3, int v4, int windowIndex)
{
  sqWindowEvent *evt= allocateWindowEvent();
  evt->action= action;
  evt->value1= v1;
  evt->value2= v2;
  evt->value3= v3;
  evt->value4= v4;
  evt->windowIndex= windowIndex;
  signalInputEvent();
#if DEBUG_EVENTS
  dprintf(7, "EVENT: window (%d %d %d %d %d %d) ", action, v1, v2, v3, v4, 0);
  switch (action)
    {
    case WindowEventMetricChange: dprintf(7, "metric change");  break;
    case WindowEventClose:        dprintf(7, "close");	    break;
    case WindowEventIconise:      dprintf(7, "iconise");	    break;
    case WindowEventActivated:    dprintf(7, "activated");	    break;
    case WindowEventPaint:        dprintf(7, "paint");	    break;
    default:                      dprintf(7, "***UNKNOWN***");  break;
    }
  dprintf(7, "\n");
#endif
}

static sqInputEvent noEvent = {EventTypeNone, 0, 0, 0, 0, 0, 0, 0};

/* retrieve the next input event from the queue */

//static sqInt display_ioGetNextEvent(sqInputEvent *evt)
//{
//  if (iebEmptyP()) {
//    *evt = noEvent;
//    return false;
//  }
//  *evt= inputEventBuffer[iebOut];
//  iebAdvance(iebOut);
//  return true;
//}

