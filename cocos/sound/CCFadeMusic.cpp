#include "CCFadeMusic.h"
#include "Sound.h"

CCFadeMusic::CCFadeMusic():fadeType(CCFadeMusic::IN)
{
}

CCFadeMusic* CCFadeMusic::actionWithDuration(float duration, Type type)
{
    CCFadeMusic *p_action = new CCFadeMusic();
    p_action->initWithDuration(duration, type);
    p_action->autorelease();
    
    return p_action;
}

bool CCFadeMusic::initWithDuration(float duration, Type type)
{
    if (CCActionInterval::initWithDuration(duration))
    {
        fadeType = type;
        return true;
    }
    
    return false;
}

void CCFadeMusic::update(float time)
{
    if(fadeType == CCFadeMusic::IN){
        Sound::setMusicVolume(time);
    }else{
        Sound::setMusicVolume(1.f - time);
    }
}