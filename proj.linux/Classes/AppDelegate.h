#include "CCApplication.h"

#include <vector>
#include <string>

#include "PreloaderScreen.h"
#include "LevelScreen.h"
#include "AppMacros.h"

USING_NS_CC;
using namespace std;

/**
 @brief    The cocos2d Application.

 The reason for implement as private inheritance is to hide some interface call by CCDirector.
 */
class AppDelegate: private cocos2d::CCApplication {
public:

	/**
	 @brief    Implement CCDirector and CCScene init code here.
	 @return true    Initialize success, app continue.
	 @return false   Initialize failed, app terminate.
	 */
	bool applicationDidFinishLaunching() {
		// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);

	// Set the design resolution
	pEGLView->setDesignResolutionSize(designResolutionSize.width,
			designResolutionSize.height, kResolutionNoBorder);

	vector < string > searchPath;

	if (true) {
		searchPath.push_back(Resources.directory);
	}

	// set searching path
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

	// turn on display FPS
	pDirector->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	LevelScreen* pScene = new LevelScreen();

	// run
	pDirector->runWithScene(pScene);

	return true;
	}

	/**
	 @brief  The function be called when the application enter background
	 @param  the pointer of the application
	 */
	void applicationDidEnterBackground() {
		CCDirector::sharedDirector()->pause();

		// if you use SimpleAudioEngine, it must be pause
		// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}

	/**
	 @brief  The function be called when the application enter foreground
	 @param  the pointer of the application
	 */
	void applicationWillEnterForeground() {
		CCDirector::sharedDirector()->resume();

		// if you use SimpleAudioEngine, it must resume here
		// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
};
