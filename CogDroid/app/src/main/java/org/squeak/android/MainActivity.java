package org.squeak.android;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//    }

    SqueakVM vm;
    SqueakView view;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        System.out.println("onCreate");

    	/* stupid setup dance but I'm not sure who is going to need what here */
        vm = new SqueakVM(this);
//        vm.setLogLevel(5);
        view = new SqueakView(this);
        view.setVm(vm);
        vm.setView(view);

        vm.loadImage("android.image", 16*1024*1024);
        super.onCreate(savedInstanceState);
        setContentView(view);
        /* Let's see if we can display the soft input */
        view.setFocusable(true);
        view.requestFocus();

    }

}
