#ifndef CONST_ENTITY
#define CONST_ENTITY

#include "Entity.h"
#include "EntityManager.h"
#include "Preloader.h"

void Entity::init(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
	this->initWithFile(pszFileName);

	if(pParent)
	{
		pParent->addChild(this);
	}

	this->setPosition(ccp(pX, pY));

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

	this->mAnimationScaleDownFactor = 0.8;
	this->mAnimationScaleUpFactor = 1.0;

	this->mIsRegisterAsTouchable = false;

	this->scheduleUpdate();
}


Entity::Entity()
{
}

Entity::Entity(const char* pszFileName)
{
	this->init(0, 0, pszFileName, 1, 1, NULL);
}

Entity::Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
	this->init(0, 0, pszFileName, pHorizontalFramesCount, pVerticalFramesCount, NULL);
}

Entity::Entity(int pX, int pY, const char* pszFileName)
{
	this->init(pX, pY, pszFileName, 1, 1, NULL);
}

Entity::Entity::Entity(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
	this->init(pX, pY, pszFileName, pHorizontalFramesCount, pVerticalFramesCount, NULL);
}

Entity::Entity(const char* pszFileName, CCNode* pParent)
{
	this->init(0, 0, pszFileName, 1, 1, pParent);
}

Entity::Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
	this->init(0, 0, pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
}

Entity::Entity(int pX, int pY, const char* pszFileName, CCNode* pParent)
{
	this->init(pX, pY, pszFileName, 1, 1, pParent);
}

Entity::Entity(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
	this->init(pX, pY, pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
}

/**
 *
 * Take care about EntityManager
 *
 */

Entity* Entity::create()
{
	return this;
}

void Entity::destroy()
{
	if(this->hasEntityManager())
	{
		this->getEntityManager()->destroy(this->id);
	}
}

void Entity::setEntityManager(EntityManager* pEntityManager)
{
	this->mEntityManager = pEntityManager;
}

EntityManager* Entity::getEntityManager()
{
	return this->mEntityManager;
}

bool Entity::hasEntityManager()
{
	return this->mEntityManager != NULL;
}

void Entity::setEntityManagerId(int pId)
{
	this->id = pId;
}

int Entity::getEntityManagerId()
{
	return this->id;
}

/**
 *
 * Take care about animation
 *
 */

int Entity::getCurrentFrameIndex()
{
	return this->mCurrentFrameIndex;
}

void Entity::setCurrentFrameIndex(int pIndex)
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

void Entity::nextFrameIndex()
{
	int potencialNextFrame = this->getCurrentFrameIndex() + 1;

	this->setCurrentFrameIndex(potencialNextFrame > this->mFramesCount ? 0 : potencialNextFrame);
}

/**
 *
 * Checing for touch detector
 *
 */

void Entity::onEnter()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void Entity::onExit()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

bool Entity::ccTouchBegan(CCTouch* touch, CCEvent* event)
		{
	if(!this->mIsRegisterAsTouchable || !this->isVisible())
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

void Entity::ccTouchMoved(CCTouch* touch, CCEvent* event)
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

void Entity::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	if(this->mWasTouched)
	{
		this->onTouch(touch, event);

		this->runAction(CCScaleTo::create(this->mAnimationScaleUpTime, this->mAnimationScaleUpFactor));
	}

	this->mWasTouched = false;
}

bool Entity::containsTouchLocation(CCTouch* touch)
{
	return CCRectMake(-this->mFrameWidth/ 2, -this->mFrameHeight / 2, this->mFrameWidth, this->mFrameHeight).containsPoint(convertTouchToNodeSpaceAR(touch));
}

void Entity::setRegisterAsTouchable(bool pTouchable)
{
	this->mIsRegisterAsTouchable = pTouchable;
}

void Entity::onTouch(CCTouch* touch, CCEvent* event)
{
}

void Entity::update(float pDeltaTime)
{
	this->setVisible(this->getParent()->isVisible());
}

/**
 *
 * Let's take care about object copy
 *
 */

Entity* Entity::deepCopy()
{
	return this;
}

#endif