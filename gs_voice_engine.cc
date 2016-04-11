#include "gs_voice_engine.h"
#include <android/log.h>
#include "webrtc/system_wrappers/interface/trace.h"

#define TAG "GSVoiceEngine"

#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)

GSVoiceEngine::GSVoiceEngine()
:voe_base(NULL)
,voe_netw(NULL)    
,channel_id(-1)
,voe(NULL)
{

}

GSVoiceEngine::~GSVoiceEngine()
{

}

int32_t GSVoiceEngine::Init()
{

    ALOGW("GSVoice start ..................................................");
    voe = VoiceEngine::Create();
    voe_base = VoEBase::GetInterface(voe);
    voe_netw = VoENetwork::GetInterface(voe);
    voe_base->Init();
    channel_id = voe_base->CreateChannel();
    voe_base->StartPlayout(channel_id);
    voe_base->StartPlayout(channel_id);  
    voe_base->StartSend(channel_id);
    voe_base->StartReceive(channel_id);  
    voe_netw->RegisterExternalTransport(channel_id, *this);

    return 0;
}


void GSVoiceEngine::release(){


    if (channel_id < 0){

        return ;
    }

    if (voe_base != NULL){
        voe_base = NULL;
    }

    if (voe_netw != NULL){
        voe_netw ->Release(); 
        voe_netw = NULL; 
    }

    VoiceEngine::Delete(voe);


}
 /// Reflected method
bool GSVoiceEngine::SendRtp(const uint8_t* packet,size_t length,const PacketOptions& options)
{
    ALOGW("GSVoice sendrtp ..................................................");
    voe_netw->ReceivedRTPPacket(channel_id, packet, length);
    return true;
}

bool GSVoiceEngine::SendRtcp(const uint8_t* packet, size_t length)
{
    voe_netw->ReceivedRTCPPacket(channel_id, packet, length);
    return true;
}


void GSVoiceEngine::stop()
{
    
    ALOGW("GSVoice stop ..................................................");
    voe_base->StopReceive(channel_id);  
    voe_base->StopSend(channel_id);  
    voe_base->StopPlayout(channel_id);  
    voe_base->DeleteChannel(channel_id);

    voe_base->Terminate();

    voe_base->Release();
    
    release();
}



