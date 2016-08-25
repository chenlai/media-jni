#ifndef GS_VOCIE_ENGINE__
#define GS_VOCIE_ENGINE__


#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/voice_engine/include/voe_codec.h"
//#include "webrtc/voice_engine/include/voe_dtmf.h"
#include "webrtc/voice_engine/include/voe_neteq_stats.h"
#include "webrtc/voice_engine/include/voe_network.h"
#include "webrtc/voice_engine/include/voe_rtp_rtcp.h"
#include "webrtc/voice_engine/include/voe_volume_control.h"

#include "webrtc/common_types.h"
#include "gsmedia.h"

#include "webrtc/voice_engine/include/voe_file.h"

#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/test/channel_transport/channel_transport.h"

using namespace webrtc;
using namespace test;



class GSVoiceEngine : 
    public Transport ,
    public GSMedia
{

public:
    GSVoiceEngine();
    virtual ~GSVoiceEngine() ;

/*
 *audio stream
 */

    int start(aud_cfg_t *aud) override;

    void stop() override;
    
    bool SendRtp(const uint8_t* packet,size_t length, const PacketOptions& options)  override;
    bool SendRtcp(const uint8_t* packet,size_t length)  override;

/*
 *    RecvTranport
 */

private:

    void release();
    VoiceEngine* voe;
    VoEBase* voe_base;
    VoENetwork* voe_netw;

    VoiceChannelTransport *channel_transport; 

    int32_t channel_id;
    bool loop;

};


#endif
