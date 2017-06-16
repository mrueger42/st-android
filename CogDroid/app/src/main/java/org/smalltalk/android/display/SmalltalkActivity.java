package org.smalltalk.android.display;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import org.smalltalk.android.R;
import org.smalltalk.android.VMApplication;
import org.smalltalk.android.vm.VM;

import java.io.IOException;

import static java.lang.System.exit;

public class SmalltalkActivity extends AppCompatActivity {

	private View displayFrame;
	private DisplayView displayView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_smalltalk);

		displayFrame = findViewById(R.id.display_frame);
		displayView = (DisplayView)findViewById(R.id.display_view);
	}

	@Override
	public void onStart() {
		super.onStart();
		displayView.setVisibility(View.VISIBLE);
		ensureVM();
	}

	private void ensureVM() {
		((VMApplication)getApplication()).ensureVM(this, displayView);
	}

}
