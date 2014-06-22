#pragma once

#include "cocos2d.h"
#include "Handler.h"

class Button :public cocos2d::CCLayer{
public:
    Button(const std::string& buttonInactive, const std::string& buttonPressed, Handler* handler, int priority = -255);
    Button(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler, int priority = -255);
    ~Button();
    
    // change images after creation (previous will be removed)
    void setImages(const std::string& buttonInactive, const std::string& buttonPressed);
    void setImages(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    virtual void onEnter();
	virtual void onExit();
    
    void setEnabled(bool enabled);

	virtual void setOpacity(GLubyte opacity);
    void setExtraTouchSize(const cocos2d::CCSize& size);
    
protected:
    Button();

	cocos2d::CCSprite* inactive;
    cocos2d::CCSprite* pressed;
    
    void init(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler, int touchPriority);

	bool hasImages();
    
private:    
    Handler* handler;
    int touchPriority;
    
    bool enabled;
    cocos2d::CCSize extraTouchSize;
    
    cocos2d::CCRect getRect();
    bool containsTouch(cocos2d::CCTouch *pTouch);
};