package com.example.ccalljava;

import android.util.Log;

/**
 * Created by sgx on 17-12-27.
 */

public class JNI {

    static{
        System.loadLibrary("ccalljava");
    }

    public native void stringCallBack();

    public native void staticCallBack();

    /**
     * c回调java的方法
     * @param a
     * @param b
     * @return
     */
    public String getString(int a,int b){
        int c=a*b;
        String s = String.valueOf(c);
        Log.e(JNI.class.getSimpleName(),s);
        return s;
    }

    public static int hello(int m,int n){
        int c=m*n;
        Log.e(JNI.class.getSimpleName(), String.valueOf(c));
        return c;
    }
}
