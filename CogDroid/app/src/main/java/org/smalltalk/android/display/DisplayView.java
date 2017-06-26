package org.smalltalk.android.display;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

import org.smalltalk.android.VMApplication;
import org.smalltalk.stack.StackView;

import java.util.Arrays;

public class DisplayView extends View {

	private static final int DISPLAY_DEPTH = 32;
	private static final Bitmap.Config DISPLAY_CONFIG = Bitmap.Config.ARGB_8888;

	private int width = 0;
	private int height = 0;
	private int bits[];
	private Bitmap display;
	private Paint paint = new Paint();

	public DisplayView(Context context) {
		super(context);
	}

	public DisplayView(Context context, @Nullable AttributeSet attrs) {
		super(context, attrs);
	}

	public DisplayView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
		super(context, attrs, defStyleAttr);
	}

	private boolean toggle;

	public Bitmap getDisplayBitmap() {
		Log.d("display view", "get display bitmap");
		return display;
	}

	public void invalidateDisplay(int left, int top, int right, int bottom) {
		Log.d("display view", "invalidate " + left + " " + top + " " + right + " " + bottom);
//		display = null;
		toggle = !toggle;
		if (toggle) {
			setBackgroundColor(Color.RED);
		} else {
			setBackgroundColor(Color.GREEN);
		}
		invalidate(left, top, right, bottom);
	}

	@Override
	protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
		Log.d("display view", "onLayout");
		super.onLayout(changed, left, top, right, bottom);
		if(!changed
			&& display != null) {
			return;
		}
		int newWidth = right - left;
		int newHeight = bottom - top;
		if (newWidth != width
			|| newHeight != height) {
			width = right - left;
			height = bottom - top;
			Log.d("display view", "create new bits w " + width + " h " + height);
			bits = new int[width * height];
			Arrays.fill(bits, 0);
			display = Bitmap.createBitmap(bits, width, height, DISPLAY_CONFIG);
//			setDisplayBitmap(display);
//			Log.d("display view", "call set screen size");
//			setScreenSize(width, height);
		}
	}

	@Override
	protected void onDraw(Canvas canvas) {
		Log.d("display view", "draw");
		super.onDraw(canvas);

		if (bits == null) return;
		canvas.drawColor(-1);

//		if (display == null) {
//			Rect dirtyRect = new Rect(0,0,0,0);
//			if(canvas.getClipBounds(dirtyRect)) {
////				updateDisplay(bits, width, height, DISPLAY_DEPTH, dirtyRect.left, dirtyRect.top, dirtyRect.right, dirtyRect.bottom);
//			}
//			display = Bitmap.createBitmap(bits, width, height, DISPLAY_CONFIG);
//		}
		canvas.drawBitmap(display, 0, 0 , paint);
	}

	public native int setScreenSize(int w, int h);
	private native int sendKeyboardEvent( int arg3, int arg4, int arg5, int arg6);
	private native int sendTouchEvent(int arg3, int arg4, int arg5);
//	public native int updateDisplay(int bits[], int w, int h, int d, int l, int t, int r, int b);

}
