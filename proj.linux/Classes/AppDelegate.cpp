#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"


		AppDelegate::AppDelegate(){};
		AppDelegate::~AppDelegate(){};
		bool AppDelegate::applicationDidFinishLaunching()
		{
			CCDirector* director 	= CCDirector::sharedDirector();
			CCEGLView*  EGLView 	= CCEGLView::sharedOpenGLView();
			CCSize 	screenSize 		= EGLView->getFrameSize();

			director->setOpenGLView(EGLView);
			EGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);

			vector <string> searchPath;

			if(screenSize.width > Resources1024x720.size.width && false)
			{
				searchPath.push_back(Resources2048x1536.directory);
				director->setContentScaleFactor(Resources2048x1536.size.height / designResolutionSize.height);
			}
			else if(screenSize.width > Resources480x320.size.width && false)
			{
				searchPath.push_back(Resources1024x720.directory);
				director->setContentScaleFactor(Resources1024x720.size.height / designResolutionSize.height);
			}
			else
			{
				searchPath.push_back(Resources480x320.directory);
				director->setContentScaleFactor(Resources480x320.size.height / designResolutionSize.height);
			}

			CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

			director->setDisplayStats(true);
			director->setAnimationInterval(1.0 / 60);

			Screen* pScene = new Preloader();

			director->runWithScene(pScene);

			return true;
		}

		void AppDelegate::applicationDidEnterBackground()
		{
			CCDirector::sharedDirector()->pause();
		}

		void AppDelegate::applicationWillEnterForeground()
		{
			CCDirector::sharedDirector()->resume();
		}

#endif