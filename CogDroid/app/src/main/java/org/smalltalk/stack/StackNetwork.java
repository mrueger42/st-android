package org.smalltalk.stack;

import android.os.Environment;
import android.util.Log;

import java.io.FileOutputStream;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;


public class StackNetwork implements Runnable {
    private static final String TAG = "JAVA Smalltalk Act";
    public StackNetwork(){}
    public void run(){
        this.loadFile();
    }


    private void loadFile() {
        try{
            URL website = new URL("http://files.Smalltalk.org/image/40/Smalltalk-Image-4.0-latest.zip");
            ReadableByteChannel rbc = Channels.newChannel(website.openStream());
            String extdir = Environment.getExternalStorageDirectory().getAbsolutePath();
            FileOutputStream fos = new FileOutputStream(extdir + "/Smalltalk-Image-4.0-latest.zip");
            fos.getChannel().transferFrom(rbc, 0, Long.MAX_VALUE);
            fos.close();
            Log.v(TAG, extdir);
        }
        catch (Exception e) {Log.v(TAG, e.getMessage());}

    }

}
