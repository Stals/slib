#include "Sound.h"
#include "SimpleAudioEngine.h"
#include "MusicFader.h"

#define ENGINE CocosDenshion::SimpleAudioEngine::sharedEngine()

std::string Sound::currentMusicFilename = "";
bool Sound::loopCurrentMusic = false;

bool Sound::musicEnabled = true;
bool Sound::effectsEnabled = true;

void Sound::playMusic(const char* filename, bool loop)
{
    currentMusicFilename = filename;
    loopCurrentMusic = loop;
    
    if(isMusicEnabled()){
        CCLOG("Playing '%s'", filename);
        MusicFader::fadeInto(filename, loop);
    }
}

void Sound::stopMusic(){
    ENGINE->stopBackgroundMusic();
}

void Sound::playEffect(const char* filename, bool loop)
{
    if(isEffectsEnabled()){
        ENGINE->playEffect(filename, loop);
    }
}

void Sound::setMusicVolume(float v)
{
    ENGINE->setBackgroundMusicVolume(v);
}

void Sound::setEffectVolume(float v)
{
    ENGINE->setEffectsVolume(v);
}

float Sound::getMusicVolume()
{
    return ENGINE->getBackgroundMusicVolume();
}

float Sound::getEffectVolume()
{
    return ENGINE->getEffectsVolume();
}

bool Sound::isMusicPlaying()
{
    return ENGINE->isBackgroundMusicPlaying();
}

void Sound::setMusicEnabled(bool enabled)
{
    musicEnabled = enabled;
    
    if(enabled){
        if(!currentMusicFilename.empty()){
            MusicFader::fadeInto(currentMusicFilename.c_str(), loopCurrentMusic);
        }
    }else{
        stopMusic();
    }
}

bool Sound::isMusicEnabled()
{
    return musicEnabled;
}

void Sound::setEffectsEnabled(bool enabled)
{
    effectsEnabled = enabled;
}

bool Sound::isEffectsEnabled()
{
    return effectsEnabled;
}

void Sound::preloadEffect(const char* filename)
{
	ENGINE->preloadEffect(filename);
}
