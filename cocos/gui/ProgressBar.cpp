#include "ProgressBar.h"	

ProgressBar::ProgressBar(CCSprite* emptyBar, CCSprite* fullBar)
{
	CCSprite::init();
	autorelease();

	CCSize size = emptyBar->getContentSize();
	size.width *= emptyBar->getScaleX();
	size.height *= emptyBar->getScaleY();
	setContentSize(size);

	this->setAnchorPoint(ccp(0, 0));	
	
	this->addChild(emptyBar);

	emptyBar->setAnchorPoint(ccp(0.5, 0.5));
	fullBar->setAnchorPoint(ccp(0.5, 0.5));
	
	progressBar = CCProgressTimer::create(fullBar);
	progressBar->setScale(fullBar->getScale());

	progressBar->setType(cocos2d::kCCProgressTimerTypeBar);
	progressBar->setAnchorPoint(ccp(0.5, 0.5));
	progressBar->setBarChangeRate(ccp(1, 0));
	progressBar->setMidpoint(ccp(0, 0));

	this->addChild(progressBar);
	progressBar->setPercentage(100); // Value between 0-100
}

void ProgressBar::setPercent(float percent)
{
	progressBar->setPercentage(percent);
}


ProgressBar::ProgressBar(const char* emptyBarFileName, const char* fullBarFileName)
{
	ProgressBar(CCSprite::create(emptyBarFileName), CCSprite::create(fullBarFileName));
}