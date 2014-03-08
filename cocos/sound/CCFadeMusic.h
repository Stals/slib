#pragma once

#include "cocos2d.h"

//#include "CCActionInterval.h"
using namespace cocos2d;


class CCFadeMusic : public cocos2d::CCActionInterval
{
public:
    enum Type{
        IN,
        OUT
    };
    
    CCFadeMusic();
    
    static CCFadeMusic* actionWithDuration(float d, Type type);
    bool initWithDuration(float d, Type type);
    
    virtual void update(float time);
    
protected:
    Type fadeType;
};
