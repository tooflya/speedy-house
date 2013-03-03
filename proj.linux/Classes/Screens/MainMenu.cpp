#include "cocos2d.h"
#include "../Entities/Entity.cpp"

using namespace cocos2d;

class MainMenu : public Screen
{
	private:
		CCSprite* mBackground2;
		CCSprite* mSocialButtonsBackground;

		CCSprite* mPlayButton;
		CCSprite* mShopButton;
		CCSprite* mAchievementsButton;
		CCSprite* mSettingsButton;
		CCSprite* mMoreGamesButton;
		CCSprite* mTwitterButton;
		CCSprite* mFacebookButton;

	public:
		MainMenu(void)
		{
			this->mBackground = CCSprite::create("main-menu-bg.png");
			this->mBackground->setPosition(ccp(240, 160));
			this->addChild(this->mBackground);

			this->mBackground2 = CCSprite::create("main-menu-bg-spots.png");
			this->mBackground2->setPosition(ccp(240, 160));
			this->mBackground->addChild(this->mBackground2);

			this->mShopButton = CCSprite::create("main-menu-btn-shop.png");
			this->mShopButton->setPosition(ccp(200, 120));
			this->mBackground2->addChild(this->mShopButton);

			this->mAchievementsButton = CCSprite::create("main-menu-btn-achievement.png");
			this->mAchievementsButton->setPosition(ccp(280, 120));
			this->mBackground2->addChild(this->mAchievementsButton);

			this->mPlayButton = CCSprite::create("main-menu-btn-play.png");
			this->mPlayButton->setPosition(ccp(240, 160));
			this->mBackground2->addChild(this->mPlayButton);

			this->mSettingsButton = CCSprite::create("main-menu-btn-settings.png");
			this->mSettingsButton->setPosition(ccp(40, 40));
			this->mBackground2->addChild(this->mSettingsButton);

			this->mSocialButtonsBackground = CCSprite::create("main-menu-soc-bg.png");
			this->mSocialButtonsBackground->setPosition(ccp(380, 40));
			this->mBackground2->addChild(this->mSocialButtonsBackground);

			this->mMoreGamesButton = CCSprite::create("main-menu-btn-more.png");
			this->mMoreGamesButton->setPosition(ccp(320, 40));
			this->mBackground2->addChild(this->mMoreGamesButton);

			this->mTwitterButton = CCSprite::create("main-menu-btn-tw.png");
			this->mTwitterButton->setPosition(ccp(380, 40));
			this->mBackground2->addChild(this->mTwitterButton);

			this->mFacebookButton = CCSprite::create("main-menu-btn-fb.png");
			this->mFacebookButton->setPosition(ccp(440, 40));
			this->mBackground2->addChild(this->mFacebookButton);

    		Entity* entity = new Entity("main-menu-btn-sound-sprite.png", 1, 2);
    		entity->sprite()->setPosition(ccp(100, 100));
			this->mBackground2->addChild(entity->sprite());
		}
};