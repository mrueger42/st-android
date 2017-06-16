package org.smalltalk.stack;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnKeyListener;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

public class StackActivity extends Activity {
    StackVM vm;
    StackView view;
    String libraryPath = "";
    String filesPath = "";
    String applicationPath = "";

    int globalModeForFile = MODE_PRIVATE;
    File imagePath = null;
    File vmFile = null;

    private static final String TAG = "JAVA Smalltalk Act";

    @Override
    public void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        applicationPath = this.getApplicationContext().getApplicationInfo().dataDir + "/";
        libraryPath = applicationPath + "lib/";
        filesPath = applicationPath + "files/";
        vmFile = new File(libraryPath + "/libStackVM.so");

        if(loadFromAssets("smalltalk")) {
            startVM("");
        }
    }

    boolean copyFileFromAssetTo(String sourceFile, AssetManager assetManager, String pathDestination){
        int buflen = 65536;
        byte[] buf = new byte[buflen];
        int ofs, len;
        try {
            InputStream is = assetManager.open(sourceFile , AssetManager.ACCESS_STREAMING);
            FileOutputStream fos = openFileOutput(pathDestination, globalModeForFile);

            while((len = is.read(buf, 0, buflen)) > 0) {
                fos.write(buf, 0, len);}
            is.close();fos.close();
        } catch (Exception e) {
            Log.v(TAG, e.toString());
            return false;
        }
        return true;
    }

    boolean loadFromAssets(String subfolders) {
        try {
            AssetManager assetManager = getAssets();
            String assetFiles[] = assetManager.list(subfolders);
            //Copy all file from assets Sources should be at the same place that the vm
            for(int i = 0; i < assetFiles.length; i++) {
                copyFileFromAssetTo(subfolders + "/" +  assetFiles[i], assetManager, assetFiles[i] );
                if(assetFiles[i].contains(".image")) {
                    imagePath = getFileStreamPath(assetFiles[i]);
                    Log.v(TAG, imagePath.getAbsolutePath());}
            }
        } catch (Exception e) {
            Log.v(TAG, e.toString());
            return false;
        }
        return true;
    }

    /** If image is not loaded from assets, set title to its path */

    void setWindowTitle(String t) {
        super.setTitle(t);
    }


    /** Unzip pre-packed files along with the image.
     *  The assets facility is not very convenient when it comes to packong multiple
     *  files in a tree hierarchy. This method obtains the list of zipped files
     *  stored under the "zipped" directory of assets and unzips them along with the
     *  earlier unpacked image. Such unzipping occurs each time VM is started.
     */

    public void startVM(String cmd) {

    	/* stupid setup dance but I''m not sure who is going to need what here */

        vm = new StackVM(this);
        view = new StackView(this,vm);

        DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        setContentView(view);


        vm.setScreenSize(metrics.widthPixels, metrics.heightPixels);


        vm.loadImage(vmFile.getAbsolutePath(), imagePath.getAbsolutePath(), cmd);

	/* Unicode characters may be passed as extra characters array with action code
	 * ACTION_MULTIPLE. Examine this, an if not the case, return false to pass the
	 * event along, otherwise call the view''s onKeyDown directly and consume the event.
	  Variable or expression expected ->* Use the first character of the array.
	 */
        view.setOnKeyListener(new OnKeyListener() {
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                int action = event.getAction();
                if (action != KeyEvent.ACTION_MULTIPLE) return false;

                return false;
            }
        });
        view.setFocusable(true);
        view.setFocusableInTouchMode(true);
        view.requestFocus();
    }

}
