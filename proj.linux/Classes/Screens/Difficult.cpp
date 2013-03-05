#ifndef CONST_DIFICULT
#define CONST_DIFICULT

#include "Difficult.h"


		Difficult::Difficult()
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


#endif