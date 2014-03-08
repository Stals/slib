#pragma once

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
};