package org.squeak.android;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputMethodManager;

public class SqueakView extends View {
	private SqueakVM vm;
	private int bits[];
	private int width;
	private int height;
	private int depth;
	private Paint paint;
	private int timerDelay;


	public void timerEvent() {
		final class SqueakTimer implements Runnable {
			public void run() {
				timerEvent();
			}
		}
		if(vm != null) vm.interpret();
		postDelayed(new SqueakTimer(), timerDelay);
	}

	public SqueakView(Context context) {
		super(context);
		timerDelay = 100;
		width = 800;
		height = 600;
		depth = 32;
		bits = new int[800*600];
    	paint = new Paint();
    	timerEvent();
	}

	public void setVm(SqueakVM vm) {
		this.vm = vm;
	}

	public boolean onKeyEvent(KeyEvent event) {
		System.out.println("Key Event: " + event);
		return true;
	}

	public boolean onTouchEvent(MotionEvent event) {
		int buttons = 0;
		int modifiers = 0;

		System.out.println("MotionEvent: " + event);
		switch(event.getAction()) {
			case MotionEvent.ACTION_DOWN: 
				buttons = 4;
				// XXXX: This *should* work but it doesn't. Why???
				InputMethodManager imm = (InputMethodManager)
					getContext().getSystemService(Context.INPUT_METHOD_SERVICE);
				boolean result = imm.showSoftInput(this, 0);
				System.out.println("imm.showSoftInput: " + result);
				break;
			case MotionEvent.ACTION_MOVE: 
				buttons = 4;
				break;
			case MotionEvent.ACTION_UP: 
				buttons = 0;
				break;
			default:
				System.out.println("Unsupported motion action: " + event.getAction());
				return false;
		}
		vm.sendEvent(1 /* EventTypeMouse */, 0 /* timestamp */, 
					(int)event.getX(), (int)event.getY(), 
					buttons, modifiers, 0, 0);
		vm.interpret();
		return true;
	}

	/**
     * Render me
     * 
     * @see View#onDraw(Canvas)
     */
    @Override
    protected void onDraw(Canvas canvas) {
    	Rect dirtyRect = new Rect(0,0,0,0);
    	if(canvas.getClipBounds(dirtyRect)) {
    		/* System.out.println("dirtyRect: " + dirtyRect); */
    		// clip the rectangle to bitmap size
			Rect bitRect = new Rect(0, 0, width-1, height-1);
			if (bitRect.intersect(dirtyRect)) {
	    		vm.updateDisplay(bits, width, height, depth, bitRect.left, bitRect.top, bitRect.right, bitRect.bottom);
			}
    	}
        super.onDraw(canvas);
        canvas.drawColor(-1);
    	canvas.drawBitmap(bits, 0, width, 0, 0, width, height, false, paint);
    }
    
    /**
     * Text Input handling
     */
    @Override
    public boolean onCheckIsTextEditor() {
    	return true;
    }
    
    @Override
    public InputConnection onCreateInputConnection(EditorInfo outAttrs) {
    	if(!onCheckIsTextEditor()) return null;
    	return new SqueakInputConnection(this, false);
    }
    
    public void sendText(CharSequence text) {
		System.out.println("sendText: " + text);
    	for(int index=0; index<text.length(); index++) {
    		vm.sendEvent(2 /* EventTypeKeyboard */, 0 /* timestamp */, 
    			(int)text.charAt(index),
    			0 /* EventKeyChar */,
    			0 /* Modifiers */, 
    			0, 0, 0);
    	}
		vm.interpret();
    }
}
