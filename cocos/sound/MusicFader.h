#pragma once

#include <string>
#include "cocos2d.h"

class MusicFader :public cocos2d::CCNode{
public:
    static void fadeInto(const char* filename, bool loop);
    
private:
    MusicFader();
    ~MusicFader();
    static MusicFader* getInstance();
    
    
    void fadeIn();
    void fadeOut();
    
    void startNew(float dt);
    
    static std::string newTrack;
    static bool loopTrack;
};