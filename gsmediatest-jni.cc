/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include <android/log.h>

#define TAG "JNILOG"

#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#include "stream.h"

#ifndef JNIEXPORT
#define JNIEXPORT  __attribute__((visibility("default"))) 
#endif 


 #define JOW(rettype, name) extern "C" rettype JNIEXPORT JNICALL \
  Java_com_example_hellojni_##name


/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */

JOW(jstring, HelloJni_startJNI) ( JNIEnv* env,
                                                  jobject thiz )
{
	ALOGW("Java_com_example_hellojni_HelloJni_startJNI ..............");
	voice_start();
//    return (*env)->NewStringUTF(env, "Voice Engine Start");
	return NULL;
}
JOW(jstring, HelloJni_stopJNI) ( JNIEnv* env,
                                                  jobject thiz )
{
	ALOGW("Java_com_example_hellojni_HelloJni_stopJNI ..............");

    voice_stop();
  //  return (*env)->NewStringUTF(env, "Voice Engine Stop");
    return NULL;
}

