#ifndef CONST_PRELOADER
#define CONST_PRELOADER

#include "Preloader.h"

Preloader::Preloader(void)
{
	this->mNumberOfLoadedSprites = 0;
	this->mNumberOfSprites = 1;

	this->mBackground = new Entity(240, 160, "start-preloader-bg.png", this);

	Entity* progressBackgroundLayer1 = new Entity(240, 40, "start-preloader-down.png", this->mBackground);
	Entity* progressBackgroundLayer3 = new Entity("start-preloader-fill.png");

	this->mProgressTimer = CCProgressTimer::create(progressBackgroundLayer3);
	this->mProgressTimer->setType(kCCProgressTimerTypeBar);
	this->mProgressTimer->setMidpoint(ccp(0, 0));
	this->mProgressTimer->setBarChangeRate(ccp(1, 0));
	this->mProgressTimer->setPosition(ccp(240, 160 - 125));
	this->mProgressTimer->setPercentage(0);

	this->mBackground->addChild(this->mProgressTimer);
	Entity* progressBackgroundLayer2 = new Entity(240, 35, "start-preloader-up.png", this->mBackground);

	this->mProgressTimer->runAction(CCProgressTo::create(0.5, 100));

	CCTextureCache::sharedTextureCache()->addImageAsync("start-preloader-bg.png", this, callfuncO_selector(Preloader::loadingCallBack));	
}

void Preloader::loadingCallBack(CCObject *obj)
{
	++mNumberOfLoadedSprites;

	//this->mProgressTimer->setPercentage((int)(((float)mNumberOfLoadedSprites / mNumberOfSprites) * 100));

	if(mNumberOfLoadedSprites == mNumberOfSprites)
	{
		if(this->checkIsTexturesLoaded())
		{
			CCDirector::sharedDirector()->replaceScene(new MainMenu());
		}
	}
	else
	{
				
	}
}

bool Preloader::checkIsTexturesLoaded()
{
	return this->mProgressTimer->getPercentage() >= 100;
}

void Preloader::update(float pDeltaTime)
{
	if(this->checkIsTexturesLoaded())
	{
		CCDirector::sharedDirector()->replaceScene(new MainMenu());
	}
}

#endif