package org.smalltalk.android.vm;

/*  VM.java
 *  Set up the VM, providing the image and library path, which the Android VM will need to load plugins.
 *  Via vm options the VM can be set up to run with or without display
 *
 *   Copyright (C) 2010-2017 by
 *   Andreas Raab, Jean Baptiste Arnaud, Santiago Bragagnolo, Dmitry Golubovsky, Michael Rueger
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

import android.app.Activity;
import android.content.Context;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.View;

import org.smalltalk.android.R;
import org.smalltalk.android.display.DisplayView;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

import static android.content.Context.MODE_PRIVATE;
import static java.lang.Thread.sleep;

public class VM {

	private Context context;
	private String vmLibraryName;

//	static {
//		System.loadLibrary("StackVM");
//	}

	public VM(Context context) {
		Log.d("vm", "instantiate");
		this.context = context;
		vmLibraryName = context.getString(R.string.vm_library_name);
		System.loadLibrary(vmLibraryName);
	}

	/*
	 * Copy and load the image in the asset folder
	 * Fail if there is no or more than one image
	 */
	public void launchImage(Activity activity, DisplayView displayView) throws IOException {
		this.activity = activity;
		this.displayView = displayView;

		String assetFolderName = context.getString(R.string.vm_asset_folder);
		String imagePath = copyFilesFromAssetFolder(assetFolderName);
		String libraryPath = context.getApplicationInfo().nativeLibraryDir;
		libraryPath = libraryPath + "/" + vmLibraryName;

		launchImage(libraryPath, "-vm vm-display-android", imagePath, "");
	}

	private void launchImage(final String libraryPath, final String options, final String imagePath, final String cmd) {
		Log.d("vm", "launching image " + imagePath);
		Log.d("vm", "run VM");
		int result = launchImage(libraryPath, options, imagePath, cmd, displayView.getWidth(), displayView.getHeight());
		Log.d("vm", "finished launching VM " + result);
	}
/*
	public void loadImage(String executablePath, String imageName, String cmd) {
		String imgpath = imageName;
		File imgfile = new File(imgpath);
		long fsize = imgfile.length();
		int why = 0;
//		Log.v(TAG, "loadImage: ");
        why = this.setVMPath(executablePath, imageName, cmd);
//		 set this from BuildConfig.headless
		int returnCode = launchImage(executablePath, "-vm vm-display-android", imageName, cmd);
		if (returnCode == 3) this.updateDisplayProcess();
	}
*/
	private void copyFileFromAssetFolder(String sourceFile, AssetManager assetManager, String pathDestination) throws IOException {
		int buflen = 65536;
		byte[] buf = new byte[buflen];
		int ofs, len;
		InputStream is = assetManager.open(sourceFile , AssetManager.ACCESS_STREAMING);
		FileOutputStream fos = context.openFileOutput(pathDestination, MODE_PRIVATE);

		while((len = is.read(buf, 0, buflen)) > 0) {
			fos.write(buf, 0, len);
		}
		is.close();
		fos.close();
	}

	private String copyFilesFromAssetFolder(String subfolders) throws IOException {
		String imagePath = null;
		AssetManager assetManager = context.getAssets();
		String assetFiles[] = assetManager.list(subfolders);
		//Copy all file from assets Sources should be at the same place that the vm
		for(int i = 0; i < assetFiles.length; i++) {
			copyFileFromAssetFolder(subfolders + "/" +  assetFiles[i], assetManager, assetFiles[i] );
			if(assetFiles[i].contains(".image")) {
				imagePath = context.getFileStreamPath(assetFiles[i]).getPath();
			}
		}
		return imagePath;
	}

	private Activity activity;
	private DisplayView displayView;

	public Bitmap getDisplayBitmap() {
		Log.d("vm", "get display bitmap");
		return displayView.getDisplayBitmap();
	}

	public void invalidate(final int left, final int top, final int right, final int bottom) {
//		Log.d("vm", "invalidate view");
		activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				displayView.invalidateDisplay(left, top, right, bottom);
			}
		});
	}

	public void lockCanvas() {
		displayView.lockCanvas();
	}

	public void unlockCanvas() {
		displayView.unlockCanvas();
	}

	public native int runVM();

	public native int launchImage(String exeName, String options, String imageName, String cmd, int w, int h);

}
