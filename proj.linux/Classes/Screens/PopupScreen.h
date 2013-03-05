#ifndef CONST_POPUPSCREEN_H
#define CONST_POPUPSCREEN_H

#include "cocos2d.h"

#include "Entity.h"
#include "EntityManager.h"
#include "Utils.h"

using namespace cocos2d;

class PopupScreen : public CCLayer
{
	class Spiral : public Entity
	{
		protected:
			int mAnimationPositionX1;
			int mAnimationPositionX2;

			float mAnimationPositionTime;

			bool mIsMoved;

		public:
			Spiral() :
				Entity()
				{
				};

			Spiral(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
				Entity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount)
				{
					this->setPosition(ccp(Utils::random(0, 480), Utils::random(0, 320)));
					this->setCurrentFrameIndex(Utils::random(0, 4));

					//this->setVisible(false);
					//this->setScale(0);
				};

			void show()
			{

			}

			virtual Entity* deepCopy()
			{
				return new Spiral("popup-sprite-5.png", 4, 1);
			}
	};
		
	protected:
		float mAnimationTimeElapsed;
		float mAnimationTimeToHide;

		bool mAnimationNeedHide;

		Entity* mBackgroundCircle;
		Entity* mBackground;
		
		EntityManager* mAnimationElements;

	public:
		PopupScreen();
		PopupScreen(CCNode* pParent);

		virtual void init(CCNode* pParent);
		
		void create();
		void show();
		void hide();

		virtual void update(float pDeltaTime);
		virtual void draw();
};

#endif