#ifndef CONST_POPUPSCREEN
#define CONST_POPUPSCREEN

#include "PopupScreen.h"


		PopupScreen::PopupScreen()
		{
			this->mBackgroundCircle = new Entity("circle.png");
			this->mBackgroundCircle->setPosition(ccp(240, 160));
			this->mBackgroundCircle->setScale(2);
			this->addChild(this->mBackgroundCircle);

			this->mAnimationTimeElapsed = 0;
			this->mAnimationTimeToHide = 0.3;

			this->mAnimationNeedHide = false;

			this->mAnimationElements = new EntityManager(100, new Spiral(), this);
			this->mAnimationElements->create()->destroy();
			this->scheduleUpdate();
		}

		void PopupScreen::create()
		{
			this->mBackground->setScale(0);
			this->setVisible(false);
		}

		void PopupScreen::show()
		{
			this->setVisible(true);

			this->mBackground->runAction(CCScaleTo::create(this->mAnimationTimeToHide, 1.0));
			this->mBackgroundCircle->runAction(CCScaleTo::create(this->mAnimationTimeToHide, 0));
		}

		void PopupScreen::hide()
		{
			this->mBackground->runAction(CCScaleTo::create(this->mAnimationTimeToHide, 0));
			this->mBackgroundCircle->runAction(CCScaleTo::create(this->mAnimationTimeToHide, 2));

			this->mAnimationNeedHide = true;
		}

		void PopupScreen::update(float pDeltaTime)
		{
			if(this->mAnimationNeedHide)
			{
				this->mAnimationTimeElapsed += pDeltaTime;

				if(this->mAnimationTimeElapsed >= this->mAnimationTimeToHide)
				{
					this->setVisible(false);

					this->mAnimationNeedHide = false;
					this->mAnimationTimeElapsed = 0;
				}
			}

			
		}

		void PopupScreen::draw()
		{
			if(this->isVisible())
			{
				int x = this->mBackgroundCircle->getPosition().x;
				int y = this->mBackgroundCircle->getPosition().y;

				int width = this->mBackgroundCircle->getTextureRect().size.width * this->mBackgroundCircle->getScale();
				int height = this->mBackgroundCircle->getTextureRect().size.height * this->mBackgroundCircle->getScale();

				int padding = 5;
				int size = 1000;

				CCPoint vertices1[] = {
					ccp(x - width / 2 + padding, y - height - size),
					ccp(x - size - width / 2 + padding, y - height),
					ccp(x - size - width / 2 + padding, y + height + height / 2),
					ccp(x - width / 2 + padding, y + height + height / 2 + size)
				};

				CCPoint vertices2[] = {
					ccp(x + width/2 - padding, y - height - size),
					ccp(x + size + width / 2 - padding, y - height),
					ccp(x + size + width / 2 - padding, y + height + height / 2),
					ccp(x + width/2 - padding, y + height + height / 2 + size)
				};

				CCPoint vertices3[] = {
					ccp(x - width / 2, y - height / 2),
					ccp(x, y - height - size),
					ccp(x + width / 2, y - height / 2),
					ccp(x, y - height - size)
				};

				CCPoint vertices4[] = {
					ccp(x - width / 2, y + height / 2),
					ccp(x, y - height + size),
					ccp(x + width / 2, y + height / 2),
					ccp(x, y - height + size)
				};

				ccDrawSolidPoly(vertices1, 4, ccc4f(255.0f / 255.0f, 252.0f / 255.0f, 232.0f / 255.0f, 1));
				ccDrawSolidPoly(vertices2, 4, ccc4f(255.0f / 255.0f, 252.0f / 255.0f, 232.0f / 255.0f, 1));
				ccDrawSolidPoly(vertices3, 4, ccc4f(255.0f / 255.0f, 252.0f / 255.0f, 232.0f / 255.0f, 1));
				ccDrawSolidPoly(vertices4, 4, ccc4f(255.0f / 255.0f, 252.0f / 255.0f, 232.0f / 255.0f, 1));
			}
		}


#endif