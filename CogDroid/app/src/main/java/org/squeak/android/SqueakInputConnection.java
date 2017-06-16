package org.squeak.android;

import android.os.Bundle;
import android.view.KeyEvent;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.CompletionInfo;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.ExtractedText;
import android.view.inputmethod.ExtractedTextRequest;

public class SqueakInputConnection extends BaseInputConnection {
	SqueakView myView;

	public SqueakInputConnection(SqueakView targetView, boolean fullEditor) {
		super(targetView, fullEditor);
		myView = targetView;
	}

	public boolean beginBatchEdit() {
		return true;
	}

	public boolean clearMetaKeyStates(int states) {
		return true;
	}

	public boolean commitCompletion(CompletionInfo text) {
		return true;
	}

	public boolean commitText(CharSequence text, int newCursorPosition) {
		myView.sendText(text);
		return true;
	}

	public boolean deleteSurroundingText(int leftLength, int rightLength) {
		return true;
	}

	public boolean endBatchEdit() {
		return true;
	}

	public boolean finishComposingText() {
		return true;
	}

	public int getCursorCapsMode(int reqModes) {
		return 0;
	}

	public ExtractedText getExtractedText(ExtractedTextRequest request, int flags) {
		return null;
	}

	public CharSequence getTextAfterCursor(int n, int flags) {
		return null;
	}

	public CharSequence getTextBeforeCursor(int n, int flags) {
		return null;
	}

	public boolean performEditorAction(int actionCode) {
		if(actionCode == EditorInfo.IME_ACTION_UNSPECIFIED) {
			// The "return" key has been pressed on the IME.
			myView.sendText("\n");
			return true;
		}
		return false;
	}

	public boolean performContextMenuAction(int id) {
		return true;
	}

	public boolean performPrivateCommand(String action, Bundle data) {
		return true;
	}

	public boolean sendKeyEvent(KeyEvent event) {
		return true;
	}

	public boolean setComposingText(CharSequence text, int newCursorPosition) {
		return true;
	}

	public boolean setSelection(int start, int end) {
		return true;
	}

};
