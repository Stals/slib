#pragma once

#include "cocos2d.h"

class Handler{
public:
    Handler(cocos2d::CCObject* listener,
            cocos2d::SEL_MenuHandler selector);
    
    void call(cocos2d::CCObject* obj = NULL);
    
private:
    cocos2d::CCObject* listener;
    cocos2d::SEL_MenuHandler selector;
};