#pragma once

#include "cocos2d.h"

typedef void (cocos2d::CCObject::*SEL_CallFuncD)(void*);
#define callfuncD_selector(_SELECTOR) (SEL_CallFuncD)(&_SELECTOR)

class Handler{
public:
    Handler(cocos2d::CCObject* listener,
            SEL_CallFuncD selector,
            void* data = 0);
    
    void call();
    
private:
    cocos2d::CCObject* listener;
    SEL_CallFuncD selector;
    void* data;
};