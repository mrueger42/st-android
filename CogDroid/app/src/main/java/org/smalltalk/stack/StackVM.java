package org.smalltalk.stack;

import android.app.NotificationManager;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Environment;
import android.speech.tts.TextToSpeech;
import android.text.ClipboardManager;
import android.util.Log;

import java.io.File;
import java.text.DecimalFormatSymbols;
import java.text.SimpleDateFormat;
import java.util.Locale;


public class StackVM {
    StackActivity context;
    StackView view;
    boolean updateProcessSentinelle;

    public StackVM(StackActivity ctx){
        this.context = ctx;
    }

    public void setView(StackView aView){
        this.view = aView;
    }


    private static final String TAG = "JAVA Smalltalk VM";

    public void finish() {
        Log.v(TAG, "Stack VM finishing");
        context.finish();
        String ns = Context.NOTIFICATION_SERVICE;
        NotificationManager notmgr = (NotificationManager) context.getSystemService(ns);
        if(notmgr != null) notmgr.cancelAll();
        //surelyExit();
    }

    public int loadImage(String executablePath, String imageName, String cmd) {
        String imgpath = imageName;
        File imgfile = new File(imgpath);
        long fsize = imgfile.length();
        int why = 0;
        Log.v(TAG, "loadImage: ");
//        why = this.setVMPath(executablePath, imageName, cmd);
        why = launchImage(executablePath, "-vm vm-display-android", imageName, cmd);
        if (why == 3) this.updateDisplayProcess();
        return why;

    }

    /* VM callbacks */
    public void invalidate(int left, int top, int right, int bottom) {
        Log.v(TAG, "invalidate ");
        view.invalidate(left, top, right, bottom);
    }

    /* Show/hide soft keyboard: needed by a Smalltalk primitive */

    public void showHideKbd(int what) {
    }

    /* Display a brief message (toast) - to be called by the fer */

    public void briefMessage(String s) {
    }


    /* Obtain a string of text from Android clipboard, if available */

    public String getClipboardString() {
        ClipboardManager cmgr =
                (ClipboardManager) context.getSystemService(Context.CLIPBOARD_SERVICE);
        if (cmgr == null) return "";
        CharSequence paste = cmgr.getText();
        String ptxt = (paste != null)?paste.toString():"";
        return ptxt;
    }

    /* Obtain the time format per current locale */

    public String getTimeFormat(int longfmt) {
        Locale loc = Locale.getDefault();
        int jlfmt =
                (longfmt == 1)?java.text.SimpleDateFormat.LONG:java.text.SimpleDateFormat.SHORT;
        SimpleDateFormat sdf =
                (SimpleDateFormat)SimpleDateFormat.getTimeInstance(jlfmt, loc);
        return sdf.toLocalizedPattern();
    }

    /* Obtain the date format per current locale */

    public String getDateFormat(int longfmt) {
        Locale loc = Locale.getDefault();
        int jlfmt =
                (longfmt == 1)?java.text.SimpleDateFormat.LONG:java.text.SimpleDateFormat.SHORT;
        SimpleDateFormat sdf =
                (SimpleDateFormat)SimpleDateFormat.getDateInstance(jlfmt, loc);
        return sdf.toLocalizedPattern();
    }

    /* Obtain the current/default Locale string */

    public String getLocaleString() {
        Locale loc = Locale.getDefault();
        return loc.toString();
    }

    /* Obtain the thousand and decimal separators per current locale */

    public String getSeparators() {
        Locale loc = Locale.getDefault();
        DecimalFormatSymbols dfs = new DecimalFormatSymbols(loc);
        char dec = dfs.getDecimalSeparator();
        char thou = dfs.getGroupingSeparator();
        return new String(new char[] {dec, thou});
    }

    /* Obtain the currency symbol per current locale */

    public String getCurrencySymbol() {
        Locale loc = Locale.getDefault();
        DecimalFormatSymbols dfs = new DecimalFormatSymbols(loc);
        return dfs.getCurrencySymbol();
    }

    /* Set VM idle timer interval */

    public void setVMTimerInterval(int d) {
        //if (view != null) view.setTimerDelay(d);
    }

    /* Get VM idle timer interval */

    public int getVMTimerInterval() {
        //if (view != null) returwwwn view.getTimerDelay();
        //else return -1;
        return 1;
    }


    public int sendKeyboardEventToVM( int arg3, int arg4, int arg5, int arg6){
        int why = 0;
        Log.v(TAG, "sendKeyboardEventToVM: " + arg3 + "  "+ arg4 + "  " + arg5 + "  " + arg6);
        why = this.sendKeyboardEvent(arg3,arg4,arg5,arg6);
        if (why == 3) this.updateDisplayProcess();
        return why;
    }

    public int sendTouchEventToVM(int arg3, int arg4, int arg5){
        int why = 0;
        Log.v(TAG, "sendTouchEventToVM: " + arg3 + "  "+ arg4 + "  " + arg5);
        why = this.sendTouchEvent(arg3,arg4,arg5);
        if (why == 3) this.updateDisplayProcess();
        return why;
    }

    public void updateDisplayProcess(){
        view.invalidate();
        updateProcessSentinelle = true;
    }


    public boolean updatingViewProcessIsActive(){
        return updateProcessSentinelle;
    }

    public int reenterFromDisplays(){
        int why = 0;
        why = this.runVM();
        if (why == 3) this.updateDisplayProcess();
        return why;
    }

    /* Get SD card root directory */

    public String getSDCardRoot() {
        return Environment.getExternalStorageDirectory().getAbsolutePath();
    }

    /* Main entry points */
    public native int setScreenSize(int w, int h);
    public native int setVMPath(String exeName, String imageName, String cmd);
    private native int sendKeyboardEvent( int arg3, int arg4, int arg5, int arg6);
    private native int sendTouchEvent(int arg3, int arg4, int arg5);
    public native int updateDisplay(int bits[], int w, int h, int d, int l, int t, int r, int b);
    private native int runVM();

    public native int launchImage(String exeName, String options, String imageName, String cmd);

    /* Load the StackVM module */
    static {

//        System.loadLibrary("vm-display-android");
        // System.loadLibrary("vm-display-null");
//        System.loadLibrary("vm-sound-null");
//        System.loadLibrary("vm-display-null");
        System.loadLibrary("StackVM");
    }
}
