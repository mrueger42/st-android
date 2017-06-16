package org.squeak.android;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;

import java.io.InputStream;

public class SqueakVM {
	private Context context;

	private SqueakView view;

	public SqueakVM(Context context) {
		this.context = context;
	}

	public void setView(SqueakView view) {
		this.view = view;
	}

	public void loadImage(String imageName, int heap) {
    	Log.d("vm", "Loading image: " + imageName);
    	AssetManager assets = context.getAssets();
    	byte buf[] = new byte[4096];
    	int ofs, len;

		allocate(heap);

		/* Try loading from a single image file */
    	try {
			Log.d("vm", "Loading image file (full)");
    		InputStream image = assets.open(imageName, 2 /*ACCESS_STREAMING*/);
    		ofs = 0;
    		while((len = image.read(buf, 0, 4096)) > 0) {
    			loadMemRegion(buf, ofs, len);
    			ofs += len;
    		}
    	} catch(Exception e) {
			Log.d("vm", "Failed to read image file");
    		e.printStackTrace();
    	}

    	/* Try loading from segments squeak.image.1 ... squeak.image.N */
    	try {
    		int part = 1;
			Log.d("vm", "Loading image file (segments)");
    		ofs = 0;
        	while(true) {
        		String partName = imageName + "." + part;
            	System.out.println(partName);
        		InputStream image = assets.open(partName, 2);
        		while((len = image.read(buf, 0, 4096)) > 0) {
        			loadMemRegion(buf, ofs, len);
        			ofs += len;
        		}
        		image.close();
        		part++;
        	}
    	} catch(Exception e) {
    		System.out.println(e);
    	}
		Log.d("vm", "Loading image from heap");
    	loadImageHeap(imageName, heap);
		Log.d("vm", "Calling interpret()");
    	interpret();
		Log.d("vm", "Finished");
    }
    
    /* VM callbacks */
    public void invalidate(int left, int top, int right, int bottom) {
    	/* System.out.println("Invalidating: (" + left + "," + top + " -- " + right + "," + bottom + ")"); */
    	view.invalidate(left, top, right, bottom);
    }

    /* PRELOAD functions */
    public native int allocate(int heap);
    public native int loadMemRegion(byte[] buf, int ofs, int len);
//    public native int setLogLevel(int logLevel);

    /* Main entry points */
    public native int loadImageHeap(String imageName, int heap);
    public native int sendEvent(int type, int stamp, int arg3, int arg4,
				int arg5, int arg6, int arg7, int arg8);
    public native int updateDisplay(int bits[], int w, int h, int d, int l, int t, int r, int b);
    public native int interpret();

    /* Load the SqueakVM module */
    static {
    	System.out.println("Loading squeakvm shared library");
        System.loadLibrary("StackVM");
    }
}
