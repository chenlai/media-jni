#include "gsmedia.h"
#include "gs_voice_engine.h"


GSMedia *GSMedia::create(){
	return new GSVoiceEngine();
}
