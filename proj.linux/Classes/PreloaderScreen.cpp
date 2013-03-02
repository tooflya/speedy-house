#include "PreloaderScreen.h"
#include "Options.h"
#include "AppMacros.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Preloader::create() {
	this->scene = CCScene::create();

	CCSprite* background = CCSprite::create("start-preloader-bg.png");

	background->setPosition(
			ccp(background->getContentSize().width / 2,
					background->getContentSize().height / 2));

	this->scene->addChild(background);

	CCProgressTo *to1 = CCProgressTo::create(2, 100);
	CCSize s = CCDirector::sharedDirector()->getWinSize();

	CCProgressTimer *left = CCProgressTimer::create(
			CCSprite::create("preload-screen-fill.png"));
	left->setType(kCCProgressTimerTypeBar);
	left->setMidpoint(ccp(0, 0));
	left->setBarChangeRate(ccp(1, 0));
	left->setPosition(
			ccp(background->getContentSize().width / 2,
					background->getContentSize().height / 2 - 250));
	left->setPercentage(50);

	this->scene->addChild(left);

	return this->scene;
}
