#ifndef GS_MEDIA_H__
#define GS_MEDIA_H__

class GSMedia 
{

public:
    static GSMedia* create();
    GSMedia(){
    }
    virtual ~GSMedia() {
        
    }

    virtual int Init() = 0;

    virtual void stop() = 0;

};


#endif