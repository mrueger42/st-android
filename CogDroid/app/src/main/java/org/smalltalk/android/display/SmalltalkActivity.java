package org.smalltalk.android.display;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import org.smalltalk.android.R;
import org.smalltalk.android.VMApplication;

public class SmalltalkActivity extends Activity {

	private DisplayView displayView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_smalltalk);

		displayView = (DisplayView)findViewById(R.id.display_view);
	}

	@Override
	public void onStart() {
		super.onStart();

		displayView.setVisibility(View.VISIBLE);
		displayView.setFocusable(true);
		displayView.setFocusableInTouchMode(true);
		displayView.requestFocus();

		ensureVM();
	}

	@Override
	public void onBackPressed() {
		// just drop it
//		super.onBackPressed();
		Log.d("activity", "back pressed");
	}

	private void ensureVM() {
		((VMApplication)getApplication()).ensureVM(this, displayView);
	}

}
