#include "MusicFader.h"
#include "SimpleAudioEngine.h"
#include "CCFadeMusic.h"
#include "Sound.h"

#define FADE_OUT 0.5f
#define FADE_IN 2.5f

std::string MusicFader::newTrack;
bool MusicFader::loopTrack = false;

using namespace cocos2d;

MusicFader::MusicFader()
{
    CCNode::init();
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
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(MusicFader::startNew), getInstance(), FADE_OUT, false, FADE_OUT, false);
    }else{
    
        Sound::setMusicVolume(0.f);
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(newTrack.c_str(), loopTrack);
        getInstance()->fadeIn();
    }
}

void MusicFader::fadeIn()
{
    CCFiniteTimeAction* fadeIn = CCEaseIn::create(CCFadeMusic::actionWithDuration(FADE_IN, CCFadeMusic::IN), FADE_IN);
    CCDirector::sharedDirector()->getActionManager()->addAction(fadeIn, getInstance(), false);
}

void MusicFader::fadeOut()
{
    CCFiniteTimeAction* fadeOut = CCEaseIn::create(CCFadeMusic::actionWithDuration(FADE_OUT, CCFadeMusic::OUT), FADE_OUT);
    CCDirector::sharedDirector()->getActionManager()->addAction(fadeOut, getInstance(), false);
    
}

void MusicFader::startNew(float dt)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(newTrack.c_str(), loopTrack);
    fadeIn();
}