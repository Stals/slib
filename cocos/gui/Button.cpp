#include "Button.h"

using namespace cocos2d;

Button::Button()
{
}

Button::Button(const std::string& buttonInactive, const std::string& buttonPressed, Handler* handler, int touchPriority)
{
    init(CCSprite::create(buttonInactive.c_str()),
         CCSprite::create(buttonPressed.c_str()),
         handler, touchPriority);
}

Button::Button(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler, int touchPriority)
{
    init(buttonInactive, buttonPressed, handler, touchPriority);
}


void Button::init(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed, Handler* handler,  int touchPriority)
{
    this->handler = handler;
    this->touchPriority = touchPriority;
    this->enabled = true;
    
    CCLayer::init();
    autorelease();
    setTouchEnabled(true);

    if(buttonInactive && buttonPressed){
        setImages(buttonInactive, buttonPressed);
    }
}

Button::~Button()
{
    if(handler) delete handler;
}

void Button::setImages(const std::string& buttonInactive, const std::string& buttonPressed)
{
    setImages(CCSprite::create(buttonInactive.c_str()), CCSprite::create(buttonPressed.c_str()));
}

void Button::setImages(cocos2d::CCSprite* buttonInactive, cocos2d::CCSprite* buttonPressed)
{
    if(inactive)
        removeChild(inactive);
    if(pressed)
        removeChild(pressed);
    
    inactive = buttonInactive;
    pressed = buttonPressed;
    
    addChild(inactive);
    addChild(pressed);
    
    pressed->setVisible(false);
    
    this->setContentSize(CCSizeMake(inactive->getContentSize().width * inactive->getScaleX(),
                                    inactive->getContentSize().height * inactive->getScaleY()) );
}


bool Button::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(containsTouch(pTouch)){
        inactive->setVisible(false);
        pressed->setVisible(true);
        return true;
    }
    return false;
}

void Button::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(containsTouch(pTouch)){
        inactive->setVisible(false);
        pressed->setVisible(true);
    
    }else{
        inactive->setVisible(true);
        pressed->setVisible(false);
    }
}

void Button::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    inactive->setVisible(true);
    pressed->setVisible(false);
    
    if(containsTouch(pTouch)){
        if (handler)
        {
            handler->call();
        }
    }
}

void Button::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    inactive->setVisible(true);
    pressed->setVisible(false);
}


void Button::onEnter(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, touchPriority, true);
    CCLayer::onEnter();
}

void Button::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

CCRect Button::getRect()
{
    CCRect rect = this->boundingBox();
    
    rect.origin = getParent()->convertToWorldSpace(rect.origin);
    rect.origin.x -= rect.size.width/2;
    rect.origin.y -= rect.size.height/2;
    
    return rect;
}

bool Button::containsTouch(cocos2d::CCTouch *pTouch)
{
    if(!enabled) return false;
    
    CCPoint point = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    CCRect rect = getRect();
    
     //CCLog("%f, %f, %f, %f", rect.origin.x, rect.origin.y,
     //rect.size.width, rect.size.height);
     //CCLog("%f, %f", point.x, point.y);
    
    
    return rect.containsPoint(point);
}

void Button::setEnabled(bool enabled)
{
    this->enabled = enabled;
}
