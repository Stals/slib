#pragma once

#include "cocos2d.h"
using namespace cocos2d;

class ProgressBar : public CCSprite{
public:
	ProgressBar(CCSprite* emptyBar, CCSprite* fullBar);
	ProgressBar(const char* emptyBarFileName, const char* fullBarFileName);

	void setPercent(float percent);

private:
	CCProgressTimer*  fuelBar; 
};

