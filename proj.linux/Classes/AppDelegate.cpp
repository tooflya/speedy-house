#include <vector>

#include "cocos2d.h"

#include "Screens/Screen.cpp"
#include "Screens/Preloader.cpp"

using namespace std;

typedef struct tagResource {
	cocos2d::CCSize size;
	char directory[100];
} Resource;

static Resource Resources480x320  	= { cocos2d::CCSizeMake(480, 320),  "480x320"   };
static Resource Resources1024x720 	= { cocos2d::CCSizeMake(1024, 720), "1024x720"  };
static Resource Resources2048x1536  = { cocos2d::CCSizeMake(2048, 1536),"2048x1536" };
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480, 320);

class AppDelegate: private cocos2d::CCApplication
{
	public:
		bool applicationDidFinishLaunching()
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

		void applicationDidEnterBackground()
		{
			CCDirector::sharedDirector()->pause();
		}

		void applicationWillEnterForeground()
		{
			CCDirector::sharedDirector()->resume();
		}
};