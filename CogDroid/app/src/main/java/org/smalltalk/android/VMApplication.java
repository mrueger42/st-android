package org.smalltalk.android;

/*  VMApplication.java
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
import android.app.Application;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.View;

import org.smalltalk.android.display.DisplayView;
import org.smalltalk.android.vm.VM;

import java.io.IOException;

import static java.lang.System.exit;
import static java.lang.Thread.sleep;

public class VMApplication extends Application {

	private VM vm;

	/*
	 * this is the first thing that gets called when an application launches
	 * the application object is also the only object guaranteed to live
	 * as long as the App lives, even if in the background
	 *
	 * Beware that the onDestroy method is actually never called,
	 * so don't try to use it for shutdown actions
	 */
	@Override
	public void onCreate() {
		super.onCreate();
	}


	public void ensureVM(Activity activity, DisplayView displayView) {
		if (vm != null) {
			// all good
			return;
		}
		// this "works"
		createVM(activity, displayView);
		// this crashes
//		createVMThread(activity, displayView);
	}

	private void createVM(Activity activity, DisplayView displayView) {
		Log.d("vm", "create VM");
		vm = new VM(this);
		try {
			Log.d("vm", "launch VM");
			vm.launchImage(activity, displayView);
		} catch (IOException e) {
			e.printStackTrace();
			exit(-1);
		}
		vm.runVM();
	}

	public void reRunVM() {
//		vm.reRunVM();
	}

	private void createVMThread(final Activity activity, final DisplayView displayView) {
		new Thread(new Runnable() {
			@Override
			public void run() {
				Log.d("vm", "wait for run VM");
				Log.d("vm", "run VM");
				createVM(activity, displayView);
			}
		}).start();
	}

}
