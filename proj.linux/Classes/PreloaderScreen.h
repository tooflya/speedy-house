#include "cocos2d.h"

using namespace cocos2d;

class PreloaderScreen  : public CCScene {
public:
	PreloaderScreen(void) {
	CCSprite* background = CCSprite::create("start-preloader-bg.png");

	background->setPosition(
			ccp(background->getContentSize().width / 2,
					background->getContentSize().height / 2));

	this->addChild(background);


	CCProgressTimer *left = CCProgressTimer::create(
			CCSprite::create("preload-screen-fill.png"));
	left->setType(kCCProgressTimerTypeBar);
	left->setMidpoint(ccp(0, 0));
	left->setBarChangeRate(ccp(1, 0));
	left->setPosition(
			ccp(background->getContentSize().width / 2,
					background->getContentSize().height / 2 - 250));
	left->setPercentage(50);

	this->addChild(left);
	}
};
