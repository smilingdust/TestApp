//
// Created by sgx on 17-12-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <android/log.h>

#define TAG "c-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

using namespace std;
extern  "C" {
JNIEXPORT jstring JNICALL
Java_com_example_javacallc_JNI_getStringFromC(JNIEnv *env, jobject instance) {
    const char *string="Hello I am From C !";
    jstring jstring1=env->NewStringUTF(string);
    LOGE("jstring1========= %s",string);
    return jstring1;

}

JNIEXPORT jint JNICALL
Java_com_example_javacallc_JNI_math(JNIEnv *env, jobject instance, jint a, jint b) {
    int c=a*b;
    LOGE("math====== %d",c);
    return c;
}

}


