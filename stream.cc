#include "gsmedia.h"

#include "stream.h"

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

