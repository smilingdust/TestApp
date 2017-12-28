package com.example.javacallc;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

/**
 * @author sgx
 */
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNI jni=new JNI();
        String stringFromC = jni.getStringFromC();
        TextView textView = findViewById(R.id.getString);
        textView.setText(stringFromC);

        jni.math(4,6);
    }




}
