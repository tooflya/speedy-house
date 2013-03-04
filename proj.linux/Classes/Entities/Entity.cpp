#ifndef CONST_ENTITY
#define CONST_ENTITY

#include "cocos2d.h"

#include <iostream>
#include <functional>

using namespace cocos2d;

class Entity : public CCSprite, public CCTargetedTouchDelegate
{
	protected:
		int mWidth;
		int mHeight;

		int mFrameWidth;
		int mFrameHeight;

		int mFramesCount;

		int mHorizontalFramesCount;
		int mVerticalFramesCount;

		int mCurrentFrameIndex;

		int* mFramesCoordinatesX;
		int* mFramesCoordinatesY;

		bool mWasTouched;
		bool mIsRegisterAsTouchable;

		float mAnimationScaleDownTime;
		float mAnimationScaleUpTime;

		float mAnimationScaleDownFactor;
		float mAnimationScaleUpFactor;

	public:
		Entity(const char* pszFileName)
		{
			this->initWithFile(pszFileName);
		}

		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
		{
			this->initWithFile(pszFileName);

			this->mWidth  = this->getTextureRect().size.width;
			this->mHeight = this->getTextureRect().size.height;

			this->mFrameWidth = this->mWidth / pHorizontalFramesCount;
			this->mFrameHeight = this->mHeight / pVerticalFramesCount; 

			this->mFramesCount = pHorizontalFramesCount * pVerticalFramesCount;

			this->mHorizontalFramesCount = pHorizontalFramesCount;
			this->mVerticalFramesCount   = pVerticalFramesCount;

			this->mWasTouched = false;

			/**
			 *
			 * We must remember all coordinates of each frame
			 * for quick get x and y of it.
			 *
			 */

			this->mFramesCoordinatesX = new int[this->mVerticalFramesCount];
			this->mFramesCoordinatesY = new int[this->mHorizontalFramesCount];

			int counter = 0;

			for(int i = 0; i < this->mVerticalFramesCount; i++)
			{
				for(int j = 0; j < this->mHorizontalFramesCount; j++, counter++)
				{
					this->mFramesCoordinatesX[counter] = j * (this->mWidth / this->mHorizontalFramesCount);
					this->mFramesCoordinatesY[counter] = i * (this->mHeight / this->mVerticalFramesCount);
				}
			}

			/**
			 *
			 * Setting zero frame
			 *
			 */

			this->setCurrentFrameIndex(0);

			/**
			 *
			 *
			 * Take care about an animations
			 *
			 */

			this->mAnimationScaleDownTime = 0.2;
			this->mAnimationScaleUpTime = 0.2;

			this->mAnimationScaleDownFactor = 0.7;
			this->mAnimationScaleUpFactor = 1.0;

			this->mIsRegisterAsTouchable = false;
		}

		int getCurrentFrameIndex()
		{
			return this->mCurrentFrameIndex;
		}

		void setCurrentFrameIndex(int pIndex)
		{
			if(pIndex < this->mHorizontalFramesCount * this->mVerticalFramesCount && pIndex >= 0)
			{
				this->setTextureRect(CCRectMake(this->mFramesCoordinatesX[pIndex], this->mFramesCoordinatesY[pIndex], this->mWidth / this->mHorizontalFramesCount, this->mHeight / this->mVerticalFramesCount));

				this->mCurrentFrameIndex = pIndex;
			}
			else
			{
				this->setCurrentFrameIndex(0);
			}
		}

		void nextFrameIndex()
		{
			int potencialNextFrame = this->getCurrentFrameIndex() +1;

			this->setCurrentFrameIndex(potencialNextFrame > this->mFramesCount ? 0 : potencialNextFrame);
		}

		/**
		 *
		 * Checing for touch detector
		 *
		 */

		void onEnter()
		{
		    CCDirector* pDirector = CCDirector::sharedDirector();
		    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
		    CCSprite::onEnter();
		}

		void onExit()
		{
		    CCDirector* pDirector = CCDirector::sharedDirector();
		    pDirector->getTouchDispatcher()->removeDelegate(this);
		    CCSprite::onExit();
		}

		bool ccTouchBegan(CCTouch* touch, CCEvent* event)
		{
			if(!this->mIsRegisterAsTouchable)
			{
				return false;
			}

    		if(containsTouchLocation(touch))
    		{
				this->mWasTouched = true;

				this->runAction(CCScaleTo::create(this->mAnimationScaleDownTime, this->mAnimationScaleDownFactor));

				return true;
			}

		    return false;
		}

		void ccTouchMoved(CCTouch* touch, CCEvent* event)
		{
			if(!containsTouchLocation(touch))
			{
				if(this->mWasTouched)
				{
					if(this->getScale() < this->mAnimationScaleUpFactor)
					{
						this->runAction(CCScaleTo::create(this->mAnimationScaleUpTime, this->mAnimationScaleUpFactor));

						this->mWasTouched = false;
					}
				}
			}
		}

		void ccTouchEnded(CCTouch* touch, CCEvent* event)
		{
			if(this->mWasTouched)
			{
				this->onTouch(touch, event);

				this->runAction(CCScaleTo::create(this->mAnimationScaleUpTime, this->mAnimationScaleUpFactor));
			}

			this->mWasTouched = false;
		}

		bool containsTouchLocation(CCTouch* touch)
		{
		    return CCRectMake(-this->mFrameWidth/ 2, -this->mFrameHeight / 2, this->mFrameWidth, this->mFrameHeight).containsPoint(convertTouchToNodeSpaceAR(touch));
		}

		virtual void onTouch(CCTouch* touch, CCEvent* event)
		{
		}

		void setRegisterAsTouchable(bool pTouchable)
		{
			this->mIsRegisterAsTouchable = pTouchable;
		}
};

#endif