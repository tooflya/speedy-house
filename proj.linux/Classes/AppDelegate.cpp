#include "AppDelegate.h"

#include <vector>
#include <string>

#include "PreloaderScreen.h"
#include "LevelScreen.h"
#include "Options.h"
#include "AppMacros.h"
#include "Box2DTestBed/Box2dView.h"

USING_NS_CC;
using namespace std;

int Options::CAMERA_WIDTH = 0;
int Options::CAMERA_HEIGHT = 0;
int Options::CAMERA_CENTER_X = 0;
int Options::CAMERA_CENTER_Y = 0;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pDirector->setOpenGLView(pEGLView);

	// Set the design resolution
	pEGLView->setDesignResolutionSize(designResolutionSize.width,
			designResolutionSize.height, kResolutionNoBorder);

	CCSize frameSize = pEGLView->getFrameSize();

	Options::CAMERA_WIDTH = frameSize.width;
	Options::CAMERA_HEIGHT = frameSize.height;
	Options::CAMERA_CENTER_X = frameSize.width / 2;
	Options::CAMERA_CENTER_Y = frameSize.height / 2;

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

	Box2dTestBedScene* pScene = new Box2dTestBedScene();

	CCLayer* pLayer = new LevelScreen();

	pLayer->autorelease();

	//pScene->addChild(pLayer);

	// run
	pDirector->runWithScene(pScene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->pause();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->resume();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
