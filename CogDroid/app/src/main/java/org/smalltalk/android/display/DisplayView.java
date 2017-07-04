package org.smalltalk.android.display;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.util.Arrays;

public class DisplayView extends SurfaceView {

	private static final int DISPLAY_DEPTH = 32;
	private static final Bitmap.Config DISPLAY_CONFIG = Bitmap.Config.ARGB_8888;

	private EventHandler eventHandler;
	private int width = 0;
	private int height = 0;
	private Bitmap display;

	private SurfaceHolder surfaceHolder;

	public DisplayView(Context context) {
		super(context);
		init();
	}

	public DisplayView(Context context, @Nullable AttributeSet attrs) {
		super(context, attrs);
		init();
	}

	public DisplayView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
		super(context, attrs, defStyleAttr);
		init();
	}

	private void init() {
		eventHandler = new EventHandler(this);

		surfaceHolder = getHolder();
		surfaceHolder.addCallback(new SurfaceHolder.Callback() {
			@Override
			public void surfaceCreated(SurfaceHolder holder) {
				int bits[] = new int[width * height];
				Arrays.fill(bits, 0);
				display = Bitmap.createBitmap(bits, width, height, DISPLAY_CONFIG);
			}

			@Override
			public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
				int bits[] = new int[width * height];
				Arrays.fill(bits, 0);
				display = Bitmap.createBitmap(bits, width, height, DISPLAY_CONFIG);
			}

			@Override
			public void surfaceDestroyed(SurfaceHolder holder) {
				display.recycle();
				display = null;
			}
		});
	}

	private Canvas canvas;

	public void lockCanvas() {
		canvas = getHolder().lockCanvas();
	}

	public void unlockCanvas() {
		canvas.drawBitmap(display, getLeft(), getTop() , null);
		getHolder().unlockCanvasAndPost(canvas);
		canvas = null;
	}

	// called by the VM to fetch the display bitmap
	// bits are updated on the VM side
	public Bitmap getDisplayBitmap() {
		Log.d("display view", "get display bitmap");
		return display;
	}

	// called by the VM to signal the display bitmap was updated
	public void invalidateDisplay(int left, int top, int right, int bottom) {
//		Log.d("display view", "invalidate l " + left + " t " + top + " r " + right + " b " + bottom);
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
//			int bits[] = new int[width * height];
//			Arrays.fill(bits, 0);
//			display = Bitmap.createBitmap(bits, width, height, DISPLAY_CONFIG);
			// TODO we need to signal the size change to the VM
			// do we?
		}
	}

	@Override
	protected void onDraw(Canvas canvas) {
//		Log.d("display view", "draw");
		super.onDraw(canvas);

		if (display == null) {
			return;
		}

		canvas.drawColor(-1);

		Rect dirtyRect = new Rect(0,0,0,0);
		if(canvas.getClipBounds(dirtyRect)) {
//			Log.d("display view", "draw at " + getLeft() + " " + getTop());
//			Log.d("display view", "rect at " + dirtyRect.left + " " + dirtyRect.top);
			canvas.drawBitmap(display, getLeft(), getTop() , null);
			// TODO honor clip rectangle
			// drawBitmap(@NonNull Bitmap bitmap, @Nullable Rect src, @NonNull Rect dst, @Nullable Paint paint)
		}
	}

	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		return eventHandler.onKeyUp(keyCode,event);
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		return eventHandler.onKeyDown(keyCode,event);
	}

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		return eventHandler.onTouchEvent(event);
	}

	public native int setScreenSize(int w, int h);
	public native int sendKeyboardEvent( int arg3, int arg4, int arg5, int arg6);
	public native int sendTouchEvent(int arg3, int arg4, int arg5);


}
