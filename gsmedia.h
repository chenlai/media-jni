#ifndef GS_MEDIA_H__
#define GS_MEDIA_H__



typedef struct 
{
	bool loop;
	char ip_address[20];
}aud_cfg_t;


class GSMedia 
{

public:
    static GSMedia* create();
    GSMedia(){
    }
    virtual ~GSMedia() {
        
    }

    virtual int start(aud_cfg_t *aud) = 0;

    virtual void stop() = 0;

};


#endif
