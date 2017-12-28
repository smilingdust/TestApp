package com.example.javacallc;

/**
 * Created by sgx on 17-12-27.
 */

public class JNI {

    //加载so动态库
    static{

        System.loadLibrary("javacallc");
    }

    public native String getStringFromC();

    public native int math(int a,int b);

}
