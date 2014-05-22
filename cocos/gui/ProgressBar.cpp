#include "ProgressBar.h"	

ProgressBar::ProgressBar(CCSprite* emptyBar, CCSprite* fullBar)
{
	CCSprite::init();
	CCSize size = emptyBar->getContentSize();
	size.width *= emptyBar->getScaleX();
	size.height *= emptyBar->getScaleY();

	setContentSize(size);
	this->setAnchorPoint(ccp(0, 0));
	
	
	this->addChild(emptyBar);
	//this->addChild(fullBar);
	emptyBar->setAnchorPoint(ccp(0.5, 0.5));
	fullBar->setAnchorPoint(ccp(0.5, 0.5));


	autorelease();
	
	fuelBar = CCProgressTimer::create(fullBar);
	fuelBar->setScale(fullBar->getScale());

	fuelBar->setType(cocos2d::kCCProgressTimerTypeBar);
	fuelBar->setAnchorPoint(ccp(0.5, 0.5));
	fuelBar->setBarChangeRate(ccp(1,0));
	fuelBar->setTag(1); 
	fuelBar->setMidpoint(ccp(0, 0));

	this->addChild(fuelBar);
	fuelBar->setPercentage(100); // Value between 0-100
}

void ProgressBar::setPercent(float percent)
{
	fuelBar->setPercentage(percent);
}


ProgressBar::ProgressBar(const char* emptyBarFileName, const char* fullBarFileName)
{
	//ProgressBar(CCSprite::create(emptyBarFileName), CCSprite::create(fullBarFileName));
}