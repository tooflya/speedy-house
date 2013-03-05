#ifndef CONST_DIFICULT
#define CONST_DIFICULT

#include "cocos2d.h"
#include "PopupScreen.cpp"

int random(float min, float max) {
	return min + (float) rand() / ((float) RAND_MAX / (max - min));
}

class Difficult : public PopupScreen
{
	class ChoiseButton : public Entity
	{
		protected:
			float mAnimationTime;
			float mAnimationElapsedTime;
			float mAnimationPosition;

			bool mIsAnimationReverse;

		public:
			ChoiseButton(const char* pszFileName) :
				Entity(pszFileName, 1, 1)
				{
					this->setRegisterAsTouchable(true);

					this->mIsAnimationReverse = false;

					this->mAnimationElapsedTime = 1000;
					this->mAnimationTime = random(1.4, 3.5);

					this->mAnimationPosition = 0;
				};

			virtual void update(float pDeltaTime)
			{
				if(this->mAnimationPosition == 0)
				{
					this->mAnimationPosition = this->getPosition().y;
				}
				else
				{
					this->mAnimationElapsedTime += pDeltaTime;

					if(this->mAnimationElapsedTime >= this->mAnimationTime)
					{
						this->mAnimationElapsedTime = 0;

						if(this->mIsAnimationReverse)
						{
							this->runAction(CCMoveTo::create(this->mAnimationTime, ccp(this->getPosition().x, this->mAnimationPosition + 5)));
						}
						else
						{
							this->runAction(CCMoveTo::create(this->mAnimationTime, ccp(this->getPosition().x, this->mAnimationPosition - 5)));
						}

						this->mIsAnimationReverse = !this->mIsAnimationReverse;
					}
				}
			}
	};

	class EasyButton : public ChoiseButton
	{
		public:
			EasyButton(const char* pszFileName) :
				ChoiseButton(pszFileName)
				{
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
			}
	};

	class NormalButton : public ChoiseButton
	{
		public:
			NormalButton(const char* pszFileName) :
				ChoiseButton(pszFileName)
				{
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
			}
	};

	class HardButton : public ChoiseButton
	{
		public:
			HardButton(const char* pszFileName) :
				ChoiseButton(pszFileName)
				{
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
			}
	};

	class BackButton : public Entity
	{
		protected:
			Difficult* mParentClass;

		public:
			BackButton(const char* pszFileName, Difficult* pParentClass) :
				Entity(pszFileName, 1, 1)
				{
					this->mParentClass = pParentClass;

					this->setRegisterAsTouchable(true);
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
				this->mParentClass->hide();
			}
	};

	private:
		EasyButton* mEasyButton;
		NormalButton* mNormalButton;
		HardButton* mHardButton;

		BackButton* mBackButton;

	public:
		Difficult()
		{
			this->mBackground = new Entity("difficulty-menu-popup.png");

			this->mEasyButton   = new EasyButton("difficulty-menu-btn-easy.png");
			this->mNormalButton = new NormalButton("difficulty-menu-btn-normal.png");
			this->mHardButton   = new HardButton("difficulty-menu-btn-expert.png");

			this->mBackButton   = new BackButton("difficulty-menu-btn-back.png", this);

			this->mBackground->setPosition(ccp(240, 160));

			this->mEasyButton->setPosition(ccp(165, 200));
			this->mHardButton->setPosition(ccp(165, 100));
			this->mNormalButton->setPosition(ccp(165, 150));

			this->mBackButton->setPosition(ccp(40, 40));

			this->addChild(this->mBackground);

			this->mBackground->addChild(this->mHardButton);
			this->mBackground->addChild(this->mEasyButton);
			this->mBackground->addChild(this->mNormalButton);

			this->addChild(this->mBackButton);

			this->create();
		}
};

#endif