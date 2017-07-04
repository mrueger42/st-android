package org.smalltalk.android.display;


import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;

import org.smalltalk.android.vm.VM;

public class EventHandler {
	private static final int LEFT_BUTTON_BIT = 4;
	private static final int MIDDLE_BUTTON_BIT = 2;
	private static final int RIGHT_BUTTON_BIT = 1;

	private DisplayView view;
//	private long timestamp = System.currentTimeMillis();
//	private int lastX = -1, lastY = -1, lastBut = -1;
	boolean makeNextClickRightButton = false;
	boolean softKbdOn;
	int ctrlOn, shiftOn;
	int timerDelay;

	private static final String TAG = "JAVA Smalltalk Events";


	public EventHandler(DisplayView view) {
		this.view = view;
		softKbdOn = false;
		ctrlOn = 0;
		shiftOn = 0;
	}

	public int getTimerDelay() {
		return timerDelay;
	}


	public void setTimerDelay(int d) {
		timerDelay = d;
	}

	public boolean onKeyUp(int keyCode, KeyEvent event) {
		switch(keyCode) {
			case 59:
			case 60:
				shiftOn = 0;
				break;
			case 126:
			case 127:
				ctrlOn = 0;
				break;
			default:
				break;
		}
		return true;
	}

	public boolean onKeyDown(int keyCode, KeyEvent event) {
		Log.d("display view", "key event " + keyCode);
		switch(keyCode) {
			case 59:
			case 60:
				shiftOn = 1;
				return true;
			case 126:
			case 127:
				ctrlOn = 1;
				return true;
			case KeyEvent.KEYCODE_BACK:
				makeNextClickRightButton = true;
				return true;
			case 92: //KeyEvent.KEYCODE_PAGE_UP:
				return true;
			case KeyEvent.KEYCODE_MENU:
				return true;
			case 78: // received for Home and End, but scancodes are different
				switch(event.getScanCode()) {
					case 102:	// Home
						emulate(1);
						break;
					case 107:	// End
						emulate(4);
						break;
					default:
						break;
				}
				break;
			case KeyEvent.KEYCODE_ENTER:      // special handling for Enter: send ^M
				view.sendKeyboardEvent(13 /* charCode */,
						0 /* EventKeyChar */,
						0 /* modifiers */,
						13 /* utf32Code */);
				break;
			case KeyEvent.KEYCODE_DPAD_RIGHT: // special handling for right arrow
				emulate(29);
				break;
			case KeyEvent.KEYCODE_DPAD_LEFT: // special handling for left arrow
				emulate(28);
				break;
			case KeyEvent.KEYCODE_DPAD_UP: // special handling for up arrow
				emulate(30, (event.getScanCode() == 0) ? 2 : 0); // 2 for wheel
				break;
			case KeyEvent.KEYCODE_DPAD_DOWN: // special handling for down arrow
				emulate(31, (event.getScanCode() == 0) ? 2 : 0); // 2 for wheel
				break;
			case KeyEvent.KEYCODE_DEL: // special handling for DEL
				emulate(8);
				break;
			default:		 // send key event
				int uchar = (keyCode != -1)?
						event.getUnicodeChar():
						event.getCharacters().codePointAt(0);
				if (uchar == 0) return false;
				int mod = (ctrlOn > 0) ? 2 : 0;
				if (ctrlOn > 0) uchar = uchar & 0x1F;
				view.sendKeyboardEvent(
						uchar /* charCode */,
						0 /* EventKeyChar */,
						mod /* modifiers */,
						uchar /* utf32Code */);
		}
		return true;
	}

	// Touch the screen and possibly move while pressing. Current button bits
	// will be used until the pressure removed, i. e. forward/back button modifiers
	// last exactly for one touch (or click).

	public boolean onTouchEvent(MotionEvent event) {
		int buttons = 0;
		int ex = (int)event.getX();
		int ey = (int)event.getY();
		int motionAction = event.getAction();
		int pointerCount = event.getPointerCount();
		switch(pointerCount){
			case 1:
				buttons = makeNextClickRightButton ? RIGHT_BUTTON_BIT : LEFT_BUTTON_BIT;
				break;
			case 2:
				buttons = RIGHT_BUTTON_BIT;
				break;
		}
		switch (motionAction & MotionEvent.ACTION_MASK) {
			case MotionEvent.ACTION_POINTER_DOWN:
				break;
			case MotionEvent.ACTION_DOWN: // 0
				break;
			case MotionEvent.ACTION_MOVE: // 2
				break;
			case MotionEvent.ACTION_UP: // 1
				buttons = 0;
				makeNextClickRightButton = false;
				break;
			default:
//				Log.v(TAG, "Unsupported mtn. action: " + event.getAction());
		}
		view.sendTouchEvent(ex, ey, buttons);
		return true;
	}

	private void emulate(int keycode) {
		emulate(keycode, 0);
	}

	private void emulate(int keycode, int mods) {
		view.sendKeyboardEvent(
				keycode /* charCode */,
				0 /* EventKeyChar */,
				mods | (shiftOn > 0 ? 1 : 0) /* modifiers */,
				keycode /* utf32Code */);
	}


}
