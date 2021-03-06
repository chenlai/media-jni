#include "gsmedia.h"

#include "stream.h"
#include <sys/system_properties.h>
#include <pthread.h>
#include "base/common.h"
#include "voice_engine/include/voe_base.h"

GSMedia *stream;

#define EXPORT  __attribute__((visibility("default"))) 


static aud_cfg_t conf{
	.loop = false,
	.ip_address = {0},

};


void EXPORT voice_start(){
	stream = GSMedia::create();
	stream->start(&conf);

}

void EXPORT setLoop(int loop){

	conf.loop = loop;

}

void EXPORT setIP(char *ipaddr){

	if (ipaddr != NULL){
		strcpy(conf.ip_address, ipaddr);
	}

}


// void EXPORT setLoop(){



// }


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


