#include "Handler.h"

using namespace cocos2d;

Handler::Handler(cocos2d::CCObject* listener,
                 SEL_CallFuncD selector,
                 void* data):
    listener(listener), selector(selector), data(data)
{
    
}

void Handler::call()
{
    if(listener && selector){
        (listener->*selector)(data);
    }
}