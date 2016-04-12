#include "gsmedia.h"

#include "stream.h"
#include <sys/system_properties.h>
#include <pthread.h>
#include "base/common.h"
#include "voice_engine/include/voe_base.h"

GSMedia *stream;

#define EXPORT  __attribute__((visibility("default"))) 


void EXPORT voice_start(){
	stream = GSMedia::create();
	stream->Init();
}


void EXPORT voice_stop(){
	stream->stop();
	delete stream;
}

static JavaVM *gs_vm = NULL;


EXPORT void gs_set_jvm(JavaVM *vm)
{
  	gs_vm = vm;
}

EXPORT void gs_set_android_objects(jobject connext){

  	webrtc::VoiceEngine::SetAndroidObjects(gs_vm, connext);

}


