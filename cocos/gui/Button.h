#pragma once

#include "cocos2d.h"
#include "Handler.h"

class Button :public cocos2d::CCLayer{
public:
    Button(const std::string& buttonInactive, const std::string& buttonPressed, Handler* handler);
    Button(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler);
    ~Button();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    virtual void onEnter();
	virtual void onExit();
    
private:
    cocos2d::CCSprite* inactive;
    cocos2d::CCSprite* pressed;
    
    Handler* handler;
    
    void init(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler);
    
    cocos2d::CCRect getRect();
    bool containsTouch(cocos2d::CCTouch *pTouch);
};