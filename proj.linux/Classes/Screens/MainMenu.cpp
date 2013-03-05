#ifndef CONST_MAINMENU
#define CONST_MAINMENU

#include "MainMenu.h"

MainMenu::MainMenu(void)
{
	this->mBackground 				= new Entity(240, 160, 		 "main-menu-bg.png", this);
	this->mBackground2 				= new Entity(240, 160, 		 "main-menu-bg-spots.png", this);
	this->mShopButton 				= new Entity(200, 120, 		 "main-menu-btn-shop.png", this->mBackground2);
	this->mAchievementsButton 		= new Entity(280, 120, 		 "main-menu-btn-achievement.png", this->mBackground2);
	this->mPlayButton 				= new PlayButton(240, 160, 	 "main-menu-btn-play.png", this, this->mBackground2);
	this->mSocialButtonsBackground 	= new Entity(380, 40, 		 "main-menu-soc-bg.png", this->mBackground2);
	this->mMoreGamesButton 			= new Entity(320, 40, 		 "main-menu-btn-more.png", this->mBackground2);
	this->mTwitterButton 			= new Entity(380, 40, 		 "main-menu-btn-tw.png", this->mBackground2);
	this->mFacebookButton 			= new Entity(440, 40, 		 "main-menu-btn-fb.png", this->mBackground2);
	this->mSoundButton 				= new SoundButton(			 "main-menu-btn-sound-sprite.png", 1, 2, this->mBackground2);
	this->mMusicButton 				= new MusicButton(			 "main-menu-btn-melody-sprite.png", 1, 2, this->mBackground2);
	this->mCreditsButton 			= new CreditsButton(		 "main-menu-btn-credits.png", this->mBackground2);
	this->mSettingsButton 			= new SettingsButton(40, 40, "main-menu-btn-settings.png", this, this->mBackground2);

	/**
	 *
	 * Popup screen management
	 *
	 */

	this->mDifficultScreen = new Difficult(this);
}

#endif