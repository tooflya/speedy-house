#ifndef CONST_DIFICULT_H
#define CONST_DIFICULT_H

#include "cocos2d.h"

#include "PopupScreen.h"
#include "Utils.h"

using namespace cocos2d;

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
			ChoiseButton(int pX, int pY, const char* pszFileName, CCNode* pParent) :
				Entity(pX, pY, pszFileName, pParent)
				{
					this->setRegisterAsTouchable(true);

					this->mIsAnimationReverse = false;

					this->mAnimationElapsedTime = 1000;
					this->mAnimationTime = Utils::random(1.4, 3.5);

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
			EasyButton(int pX, int pY, const char* pszFileName, CCNode* pParent) :
				ChoiseButton(pX, pY, pszFileName, pParent)
				{
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
			}
	};

	class NormalButton : public ChoiseButton
	{
		public:
			NormalButton(int pX, int pY, const char* pszFileName, CCNode* pParent) :
				ChoiseButton(pX, pY, pszFileName, pParent)
				{
				};

			void onTouch(CCTouch* touch, CCEvent* event)
			{
			}
	};

	class HardButton : public ChoiseButton
	{
		public:
			HardButton(int pX, int pY, const char* pszFileName, CCNode* pParent) :
				ChoiseButton(pX, pY, pszFileName, pParent)
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
			BackButton(int pX, int pY, const char* pszFileName, CCNode* pParent, Difficult* pParentClass) :
				Entity(pX, pY, pszFileName, pParent)
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
		Difficult();
		Difficult(CCNode* pParent);

		virtual void init(CCNode* pParent);
};

#endif