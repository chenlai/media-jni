#ifndef STREAM_H__
#define STREAM_H__

#include <jni.h>

#ifdef __cplusplus
extern "C"{
#endif

void gs_set_jvm(JavaVM *vm);
void gs_set_android_objects(jobject connext);
void voice_start();
void voice_stop();

#ifdef __cplusplus
}
#endif


#endif 