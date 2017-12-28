package com.example.ccalljava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

/**
 * @author sgx
 */
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNI jni=new JNI();
//        jni.stringCallBack();
//
//        jni.staticCallBack();

        updateUI();

    }

    public native void updateUI();

    public void showToast(){
        Toast.makeText(MainActivity.this, "showToast----------",Toast.LENGTH_SHORT).show();
    }
}
