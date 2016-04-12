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
 #define JNIEXPORT __attribute__((visibility("default"))) 
 #endif

 #define JOW(rettype, name) extern "C" rettype JNIEXPORT JNICALL \
  Java_com_example_hellojni_##name

#define CONNECT_JAVA_PACKAGE "com.example.hellojni"

//static JavaVM* m_vm = 0;


JOW(void, HelloJni_startJNI) ( JNIEnv* env,jobject thiz )
{
	voice_start();
    return;
}

JOW(void,  HelloJni_stopJNI)( JNIEnv* env, jobject thiz )
{

	voice_stop();
    return;
}

JOW(void , HelloJni_init)(JNIEnv* env, jobject thiz, jobject context)
{
    gs_set_android_objects(context);
}

// static const JNINativeMethod gMethods[] = {
//     {"startJNI", "()V", (void *)startJNI},
//     {"stopJNI", "()V", (void *)stopJNI},
//     {"init", "(Landroid/content/Context)V", (void *)init},
// };

// static int registerMethods(JNIEnv* env)
// {
//     jclass clazz;

//     /* look up the class */
//     clazz = env->FindClass(CONNECT_JAVA_PACKAGE);

//     if (clazz == NULL) {
//         ALOGW("Can't find class %s\n", CONNECT_JAVA_PACKAGE);
//         return -1;
//     }

//     /* register all the methods */
//     if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) != JNI_OK)
//     {
//         ALOGW("Failed registering methods for %s\n", CONNECT_JAVA_PACKAGE);
//         env->DeleteLocalRef(clazz);
//         return -1;
//     }

//     env->DeleteLocalRef(clazz);

//     /* fill out the rest of the ID cache */
//     return 0;
// }

/*
 * This is called by the VM when the shared library is first loaded.
 */
jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = NULL;
    jint result = -1;
    ALOGW("--------------JNI_OnLoad---------------------");
    gs_set_jvm(vm);
    // m_vm = vm;
    // if (m_vm->GetEnv((void**) &env, JNI_VERSION_1_4) == JNI_OK)
    // {
    //     if (registerMethods(env) != 0)
    //     {
    //         ALOGW("ERROR: PlatformLibrary native registration failed\n");
    //         goto fail;
    //     }
        
    // }
    // /* success -- return valid version number */

    result = JNI_VERSION_1_4;

fail:
    return result;
}



