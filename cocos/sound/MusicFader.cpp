#include "MusicFader.h"
#include "SimpleAudioEngine.h"
#include "CCFadeMusic.h"
#include "Sound.h"

#define FADE_TIME 1.5f // seconds to 0 volume

std::string MusicFader::newTrack;
bool MusicFader::loopTrack = false;

using namespace cocos2d;

MusicFader::MusicFader()
{
    CCNode::init();
}

MusicFader::~MusicFader()
{
    int i = 0;
}

MusicFader* MusicFader::getInstance()
{
    static MusicFader fader;
    return &fader;
}

void MusicFader::fadeInto(const char* filename, bool loop)
{
    newTrack = filename;
    loopTrack = loop;
    
    if(Sound::isMusicPlaying()){
        getInstance()->fadeOut();
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(MusicFader::startNew), getInstance(), FADE_TIME, false, FADE_TIME, false);
    }else{
    
        Sound::setMusicVolume(0.f);
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(newTrack.c_str(), loopTrack);
        getInstance()->fadeIn();
    }
}

void MusicFader::fadeIn()
{
    CCFiniteTimeAction* fadeIn = CCEaseIn::create(CCFadeMusic::actionWithDuration(FADE_TIME, CCFadeMusic::IN), FADE_TIME);
    
    CCDirector::sharedDirector()->getActionManager()->addAction(fadeIn, getInstance(), false);
}

void MusicFader::fadeOut()
{
    CCFiniteTimeAction* fadeOut = CCEaseIn::create(CCFadeMusic::actionWithDuration(FADE_TIME, CCFadeMusic::OUT), FADE_TIME);
    CCDirector::sharedDirector()->getActionManager()->addAction(fadeOut, getInstance(), false);
    
}

void MusicFader::startNew(float dt)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(newTrack.c_str(), loopTrack);
    fadeIn();
}