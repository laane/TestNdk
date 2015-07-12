//
// Created by jujujuijk on 7/12/15.
//

#include <jni.h>

extern "C" {

JNIEXPORT jint
JNICALL Java_fr_laane_android_testndk_MainActivity_add
        (JNIEnv *env, jclass c, jint a, jint b) {
    return a + b;
}


JNIEXPORT jboolean
JNICALL Java_fr_laane_android_testndk_MainActivity_setArray
        (JNIEnv *env, jclass c, jintArray array) {

    jint size = env->GetArrayLength(array);
    // check if array size >0 and wedont cause exception
    if (size <= 0)
        return JNI_FALSE;

    if (env->ExceptionCheck()) {
#ifndef NDEBUG
      env->ExceptionDescribe();
#endif
          env->ExceptionClear();
      return JNI_FALSE;
    }

    jint* data = new jint[size];

    env->GetIntArrayRegion(array,0,size,data);
        // exception check. Always use exception check
    if(env->ExceptionCheck()) {
    #ifndef NDEBUG
      env->ExceptionDescribe();
    #endif
      env->ExceptionClear();
      delete[] data;
      return JNI_FALSE;
    }

    for (int i = 0; i < size; ++i)
        data[i] = 5;

    // set result to Java array and delete buffer. And exception check of course
    env->SetIntArrayRegion(array,0,size,data);
    delete[] data;

    if(env->ExceptionCheck()) {
#ifndef NDEBUG
          env->ExceptionDescribe();
#endif
          env->ExceptionClear();
      return JNI_FALSE;
        }
    // All is ok
    return JNI_TRUE ;
    }

}
