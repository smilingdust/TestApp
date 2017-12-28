//
// Created by sgx on 17-12-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "include/JavaCallC.h"
#include <string.h>


using namespace std;

/**
 * c回调java的方法
 * 1.首先需要找到对应的类文件.class，通过反射的方式找到class对象
 * 2.获取到class中对应的方法，
 * 3.获取到class对应的实例
 * 4.调用方法
 */
extern "C"{

//将const char类型转换成jstring类型
jstring CStr2Jstring( JNIEnv* env, const char* pat )
{
    // 定义java String类 strClass
    jclass strClass = (env)->FindClass("Ljava/lang/String;");
    // 获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    // 建立byte数组
    jbyteArray bytes = (env)->NewByteArray((jsize)strlen(pat));
    // 将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, (jsize)strlen(pat), (jbyte*)pat);
    //设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("GB2312");
    //将byte数组转换为java String,并输出
    return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);

}


JNIEXPORT void JNICALL
Java_com_example_ccalljava_JNI_stringCallBack(JNIEnv *env, jobject instance) {
    //找到class，通过参数全类名  jclass FindClass(const char* name)
    jclass jclazz=env->FindClass("com/example/ccalljava/JNI");
    //找到方法,参数分别为class（类名），方法名，方法签名（查看方法签名：终端进入build/intermediates/classes/debug目录下执行命令
    // javap -s com.example.ccalljava.JNI全类名 得到方法的签名）
    jmethodID jmethodID1=env->GetMethodID(jclazz,"getString","(II)Ljava/lang/String;");
    //获取对象实例,谁调用当前方法jobject就是调用者的实例
    jobject jobject1=env->AllocObject(jclazz);
    //调用方法(java中的方法的返回值是什么类型就调用返回什么类型的方法，但是string是例外，string则调用Object)
    //jobject     (*CallObjectMethod)(JNIEnv*, jobject, jmethodID, ...);
    jobject jobject2=env->CallObjectMethod(jobject1,jmethodID1,6,8);
    LOGE("c回调java的getString方法=========%s","6*8的值转为string");
}

/**
 * 两个地方都要调用static方法,静态方法只需要jclass就可以了，不需要实例
 * @param env
 * @param instance
 */
JNIEXPORT void JNICALL
Java_com_example_ccalljava_JNI_staticCallBack(JNIEnv *env, jobject instance) {
    //找到class，通过参数全类名  jclass FindClass(const char* name)
    jclass jclazz=env->FindClass("com/example/ccalljava/JNI");
    //找到方法,参数分别为class（类名），方法名，方法签名（查看方法签名：终端进入build/intermediates/classes/debug目录下执行命令
    // javap -s com.example.ccalljava.JNI全类名 得到方法的签名）
    //jmethodID GetStaticMethodID(jclass clazz, const char* name, const char* sig)
    jmethodID jmethodID1=env->GetStaticMethodID(jclazz,"hello","(II)I");
    //获取对象实例,谁调用当前方法jobject就是调用者的实例,相当于java层new操作
    //jobject jobject1=env->AllocObject(jclazz);
    //调用方法(java中的方法的返回值是什么类型就调用返回什么类型的方法，但是string是例外，string则调用Object)
    //jint        (*CallStaticIntMethod)(JNIEnv*, jclass, jmethodID, ...);
    jint jint1=env->CallStaticIntMethod(jclazz,jmethodID1,9,5);
    LOGE("c回调java的hello方法=========%d",jint1);

}

JNIEXPORT void JNICALL
Java_com_example_ccalljava_MainActivity_updateUI(JNIEnv *env, jobject instance) {

    //找到class，通过参数全类名  jclass FindClass(const char* name),这里传递的类名是MainActivity
    jclass jclazz=env->FindClass("com/example/ccalljava/MainActivity");
    //找到方法,参数分别为class（类名），方法名，方法签名（查看方法签名：终端进入build/intermediates/classes/debug目录下执行命令
    // javap -s com.example.ccalljava.JNI全类名 得到方法的签名）
    //jmethodID GetStaticMethodID(jclass clazz, const char* name, const char* sig)
    jmethodID jmethodID1=env->GetMethodID(jclazz,"showToast","()V");
    //获取对象实例,谁调用当前方法jobject就是调用者的实例,相当于java层new操作,但是更新UI操作需要的Activity的实例，
    // new出来只是作为一个普通类使用，这里需要使用传入的实例即activity实例
    //jobject jobject1=env->AllocObject(jclazz);
    //调用方法(java中的方法的返回值是什么类型就调用返回什么类型的方法，但是string是例外，string则调用Object)
    env->CallVoidMethod(instance,jmethodID1);
    LOGE("c回调java的showToast方法=========%s","c层调用java方法进行UI的更新");

}

}

