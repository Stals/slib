#include "Handler.h"

using namespace cocos2d;

Handler::Handler(cocos2d::CCObject* listener,
                 cocos2d::SEL_MenuHandler selector):
    listener(listener), selector(selector)
{
    
}

void Handler::call(CCObject* obj)
{
    if(listener && selector){
        (listener->*selector)(obj);
    }
}