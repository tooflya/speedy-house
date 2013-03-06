#ifndef CONST_ENTITY_H
#define CONST_ENTITY_H

#include "cocos2d.h"

using namespace cocos2d;

class EntityManager;

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

		int id; // For the entities which is childs of EntityManagers
		EntityManager* mEntityManager;

	private:
		void init(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

	public:
		Entity();
		Entity(const char* pszFileName);
		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
		Entity(int pX, int pY, const char* pszFileName);
		Entity(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
		Entity(const char* pszFileName, CCNode* pParent);
		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);
		Entity(int pX, int pY, const char* pszFileName, CCNode* pParent);
		Entity(int pX, int pY, const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

		/**
		 *
		 * Take care about EntityManager
		 *
		 */

		Entity* create();

		void destroy();
		void destroy(bool pManage);

		void setEntityManager(EntityManager* pEntityManager);

		EntityManager* getEntityManager();

		bool hasEntityManager();

		void setEntityManagerId(int pId);

		int getEntityManagerId();

		/**
		 *
		 * Take care about animation
		 *
		 */

		int getCurrentFrameIndex();

		void setCurrentFrameIndex(int pIndex);

		void nextFrameIndex();

		/**
		 *
		 * Checing for touch detector
		 *
		 */

		void onEnter();

		void onExit();

		bool ccTouchBegan(CCTouch* touch, CCEvent* event);

		void ccTouchMoved(CCTouch* touch, CCEvent* event);

		void ccTouchEnded(CCTouch* touch, CCEvent* event);
		bool containsTouchLocation(CCTouch* touch);

		void setRegisterAsTouchable(bool pTouchable);

		virtual void onTouch(CCTouch* touch, CCEvent* event);

		virtual void update(float pDeltaTime);

		/**
		 *
		 * Let's take care about object copy
		 *
		 */

		virtual Entity* deepCopy();
};

#endif