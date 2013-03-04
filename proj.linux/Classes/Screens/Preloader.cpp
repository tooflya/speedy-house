#include "cocos2d.h"

#include "Screens/MainMenu.cpp"

class Preloader : public Screen
{
	private:
    	int mNumberOfSprites;
    	int mNumberOfLoadedSprites;

    	CCProgressTimer* mProgressTimer;

	public:
		Preloader(void)
		{
			this->mNumberOfLoadedSprites = 0;
			this->mNumberOfSprites = 1;

			this->mBackground = new Entity("start-preloader-bg.png");
			this->mBackground->setPosition(ccp(240, 160));
			this->addChild(this->mBackground);

			CCSprite* progressBackgroundLayer1 = CCSprite::create("start-preloader-down.png");
			CCSprite* progressBackgroundLayer2 = CCSprite::create("start-preloader-up.png");
			CCSprite* progressBackgroundLayer3 = CCSprite::create("start-preloader-fill.png");
			progressBackgroundLayer1->setPosition(ccp(240, 160 - 120));
			progressBackgroundLayer2->setPosition(ccp(240, 160 - 125));
			this->mBackground->addChild(progressBackgroundLayer1);

			this->mProgressTimer = CCProgressTimer::create(progressBackgroundLayer3);
			this->mProgressTimer->setType(kCCProgressTimerTypeBar);
			this->mProgressTimer->setMidpoint(ccp(0, 0));
			this->mProgressTimer->setBarChangeRate(ccp(1, 0));
			this->mProgressTimer->setPosition(ccp(240, 160 - 125));
			this->mProgressTimer->setPercentage(0);

			this->mBackground->addChild(this->mProgressTimer);
			this->mBackground->addChild(progressBackgroundLayer2);

			this->mProgressTimer->runAction(CCProgressTo::create(0.1, 100));

			CCTextureCache::sharedTextureCache()->addImageAsync("start-preloader-bg.png", this, callfuncO_selector(Preloader::loadingCallBack));
		
		}

		void loadingCallBack(CCObject *obj)
		{
    		++mNumberOfLoadedSprites;

    		//this->mProgressTimer->setPercentage((int)(((float)mNumberOfLoadedSprites / mNumberOfSprites) * 100));

    		if (mNumberOfLoadedSprites == mNumberOfSprites)
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

		bool checkIsTexturesLoaded()
		{
			return this->mProgressTimer->getPercentage() >= 100;
		}

		virtual void update(float pDeltaTime)
		{
    		if(this->checkIsTexturesLoaded())
    		{
    			CCDirector::sharedDirector()->replaceScene(new MainMenu());
    		}
		}
};