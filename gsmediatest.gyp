#gsmedia

{

    'targets': [
        {
            'target_name' : 'gsmediatest',
            'type' : 'shared_library',
            'include_dirs' : [
                '<(DEPTH)',
            ],

            'dependencies': [
                '<(webrtc_root)/common.gyp:webrtc_common',
                '<(webrtc_root)/common_audio/common_audio.gyp:common_audio',
                '<(webrtc_root)/modules/modules.gyp:audio_coding_module',
                '<(webrtc_root)/modules/modules.gyp:audio_conference_mixer',
                '<(webrtc_root)/modules/modules.gyp:audio_device',
                '<(webrtc_root)/modules/modules.gyp:audio_processing',
                '<(webrtc_root)/modules/modules.gyp:webrtc_utility',
                '<(webrtc_root)/system_wrappers/system_wrappers.gyp:*',
                '<(webrtc_root)/voice_engine/voice_engine.gyp:voice_engine',
                '<(webrtc_root)/test/test.gyp:channel_transport',
            ],

            'libraries': [
                '-lz',
                '-llog',
                '-ldl',
                
            ],
            'cflags' : [
                '-Wall',
                '-fPIC',
                '-Werror',
                '-Os', 
                '-U_FORTIFY_SOURCE',
                '-fvisibility=default',
                #   '-Wl,--no-warn-shared-textrel',
            ],

            'sources' : [
              'gs_voice_engine.cc',
              'gs_voice_engine.h',
              'gsmedia.cc', 
              'gsmedia.h', 
              'stream.cc',
              'stream.h',
              #'gsmediatest-jni.cc',
            ],

        },      
    ],

}


