#pragma once
#include <string>

class Sound{
public:
    
    static void playMusic(const char* filename, bool loop = false);
    static void stopMusic();
    
    static void playEffect(const char* filename, bool loop = false);
    
    static void setMusicVolume(float v);
    static float getMusicVolume();
    
    static void setEffectVolume(float v);
    static float getEffectVolume();
    
    static bool isMusicPlaying();
    
    static void setMusicEnabled(bool enabled);
    static bool isMusicEnabled();
    
    static void setEffectsEnabled(bool enabled);
    static bool isEffectsEnabled();

	static void preloadEffect(const char* filename);
    
private:
    static std::string currentMusicFilename;
    static bool loopCurrentMusic;
    
    static bool musicEnabled;
    static bool effectsEnabled;
};