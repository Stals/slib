#include "Sound.h"
#include "SimpleAudioEngine.h"
#include "MusicFader.h"

#define ENGINE CocosDenshion::SimpleAudioEngine::sharedEngine()

void Sound::playMusic(const char* filename, bool loop)
{
    MusicFader::fadeInto(filename, loop);
}

void Sound::stopMusic(){
    ENGINE->stopBackgroundMusic();
}

void Sound::playEffect(const char* filename, bool loop)
{
    ENGINE->playEffect(filename, loop);
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

