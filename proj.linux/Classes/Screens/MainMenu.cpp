#ifndef CONST_MAINMENU
#define CONST_MAINMENU

#include "cocos2d.h"
#include "Difficult.cpp"

class MainMenu : public Screen
{
	class SoundButton : public Entity
	{
		protected:
			int mAnimationPositionX1;
			int mAnimationPositionX2;

			float mAnimationPositionTime;

			bool mIsMoved;

		public:
			SoundButton(const char* pszFileName) :
				Entity(pszFileName, 1, 1)
				{
					this->setRegisterAsTouchable(true);
				};

			SoundButton(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
				Entity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount)
				{
					this->setRegisterAsTouchable(true);

					this->mAnimationPositionX1 = 40;
					this->mAnimationPositionX2 = 100;

					this->mAnimationPositionTime = 0.3;

					this->mIsMoved = false;

					this->setPosition(ccp(mAnimationPositionX1, 40));
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				this->nextFrameIndex();
			}

			void move()
			{
				if(this->mIsMoved)
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX1, 40)));

					this->mIsMoved = false;
				}
				else
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX2, 40)));

					this->mIsMoved = true;
				}
			}
	};

	class MusicButton : public Entity
	{
		protected:
			int mAnimationPositionX1;
			int mAnimationPositionX2;

			float mAnimationPositionTime;

			bool mIsMoved;

		public:
			MusicButton(const char* pszFileName) :
				Entity(pszFileName, 1, 1)
				{
					this->setRegisterAsTouchable(true);
				};

			MusicButton(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
				Entity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount)
				{
					this->setRegisterAsTouchable(true);

					this->mAnimationPositionX1 = 40;
					this->mAnimationPositionX2 = 150;

					this->mAnimationPositionTime = 0.3;

					this->mIsMoved = false;

					this->setPosition(ccp(mAnimationPositionX1, 40));
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				this->nextFrameIndex();
			}

			void move()
			{
				if(this->mIsMoved)
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX1, 40)));

					this->mIsMoved = false;
				}
				else
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX2, 40)));

					this->mIsMoved = true;
				}
			}
	};

	class CreditsButton : public Entity
	{
		protected:
			int mAnimationPositionX1;
			int mAnimationPositionX2;

			float mAnimationPositionTime;

			bool mIsMoved;

		public:
			CreditsButton(const char* pszFileName) :
				Entity(pszFileName, 1, 1)
				{
					this->setRegisterAsTouchable(true);

					this->mAnimationPositionX1 = 40;
					this->mAnimationPositionX2 = 200;

					this->mAnimationPositionTime = 0.3;

					this->mIsMoved = false;

					this->setPosition(ccp(mAnimationPositionX1, 40));
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				this->nextFrameIndex();
			}

			void move()
			{
				if(this->mIsMoved)
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX1, 40)));

					this->mIsMoved = false;
				}
				else
				{
					this->runAction(CCMoveTo::create(this->mAnimationPositionTime, ccp(this->mAnimationPositionX2, 40)));

					this->mIsMoved = true;
				}
			}
	};

	class SettingsButton : public Entity
	{
		protected:
			float mAnimationRotationAngle;
			float mAnimationRotationTime;

			bool mIsRotated;

			MainMenu* mParentClass;
		public:
			SettingsButton(const char* pszFileName, MainMenu* pParentClass) :
				Entity(pszFileName, 1, 1)
				{
					this->mParentClass = pParentClass;

					this->setRegisterAsTouchable(true);

					this->mAnimationRotationTime  = 0.3;
					this->mAnimationRotationAngle = 720.0;

					this->mIsRotated = false;
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				if(this->mIsRotated)
				{
					this->runAction(CCRotateTo::create(this->mAnimationRotationTime, -this->mAnimationRotationAngle));

					this->mParentClass->mSoundButton->move();
					this->mParentClass->mMusicButton->move();
					this->mParentClass->mCreditsButton->move();

					this->mIsRotated = false;
				}
				else
				{
					this->runAction(CCRotateTo::create(this->mAnimationRotationTime, this->mAnimationRotationAngle));

					this->mParentClass->mSoundButton->move();
					this->mParentClass->mMusicButton->move();
					this->mParentClass->mCreditsButton->move();

					this->mIsRotated = true;
				}
			}
	};

	class PlayButton : public Entity
	{
		protected:
			MainMenu* mParentClass;

		public:
			PlayButton(const char* pszFileName, MainMenu* pParentClass) :
				Entity(pszFileName, 1, 1)
				{
					this->mParentClass = pParentClass;

					this->setRegisterAsTouchable(true);
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				this->mParentClass->mDifficultScreen->show();
			}
	};

	protected:
		CCSprite* mBackground2;
		CCSprite* mSocialButtonsBackground;

		PlayButton* mPlayButton;
		SoundButton* mShopButton;
		SoundButton* mAchievementsButton;
		SettingsButton* mSettingsButton;
		SoundButton* mMoreGamesButton;
		SoundButton* mTwitterButton;
		SoundButton* mFacebookButton;
		SoundButton* mSoundButton;
		MusicButton* mMusicButton;
		CreditsButton* mCreditsButton;

		Difficult* mDifficultScreen;

	public:
		MainMenu(void)
		{
			this->mBackground = new Entity("main-menu-bg.png");
			this->mBackground->setPosition(ccp(240, 160));
			this->addChild(this->mBackground);

			this->mBackground2 = CCSprite::create("main-menu-bg-spots.png");
			this->mBackground2->setPosition(ccp(240, 160));
			this->mBackground->addChild(this->mBackground2);

			this->mShopButton = new SoundButton("main-menu-btn-shop.png");
			this->mShopButton->setPosition(ccp(200, 120));
			this->mBackground2->addChild(this->mShopButton);

			this->mAchievementsButton = new SoundButton("main-menu-btn-achievement.png");
			this->mAchievementsButton->setPosition(ccp(280, 120));
			this->mBackground2->addChild(this->mAchievementsButton);

			this->mPlayButton = new PlayButton("main-menu-btn-play.png", this);
			this->mPlayButton->setPosition(ccp(240, 160));
			this->mBackground2->addChild(this->mPlayButton);

			this->mSocialButtonsBackground = CCSprite::create("main-menu-soc-bg.png");
			this->mSocialButtonsBackground->setPosition(ccp(380, 40));
			this->mBackground2->addChild(this->mSocialButtonsBackground);

			this->mMoreGamesButton = new SoundButton("main-menu-btn-more.png");
			this->mMoreGamesButton->setPosition(ccp(320, 40));
			this->mBackground2->addChild(this->mMoreGamesButton);

			this->mTwitterButton = new SoundButton("main-menu-btn-tw.png");
			this->mTwitterButton->setPosition(ccp(380, 40));
			this->mBackground2->addChild(this->mTwitterButton);

			this->mFacebookButton = new SoundButton("main-menu-btn-fb.png");
			this->mFacebookButton->setPosition(ccp(440, 40));
			this->mBackground2->addChild(this->mFacebookButton);

			this->mSoundButton = new SoundButton("main-menu-btn-sound-sprite.png", 1, 2);
			this->mBackground2->addChild(this->mSoundButton);

			this->mMusicButton = new MusicButton("main-menu-btn-melody-sprite.png", 1, 2);
			this->mBackground2->addChild(this->mMusicButton);

			this->mCreditsButton = new CreditsButton("main-menu-btn-credits.png");
			this->mBackground2->addChild(this->mCreditsButton);

			this->mSettingsButton = new SettingsButton("main-menu-btn-settings.png", this);
			this->mSettingsButton->setPosition(ccp(40, 40));
			this->mBackground2->addChild(this->mSettingsButton);

			/**
			 *
			 * Popup screen management
			 *
			 */

			 this->mDifficultScreen = new Difficult();

			 this->addChild(this->mDifficultScreen);
		}
};

#endif