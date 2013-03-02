#include "main.h"
#include "../Classes/AppDelegate.h"
#include "cocos2d.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

USING_NS_CC;

int main(int argc, char **argv) {
	// create the application instance
	AppDelegate app;

	CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	// eglView->setFrameSize(400, 240); // Galaxy 3
	// eglView->setFrameSize(1280, 800); // Google Nexus 7
	// eglView->setFrameSize(1280, 720); // Galaxy S3
	// eglView->setFrameSize(480, 320); // Galaxy GIO
	// eglView->setFrameSize(960, 640); // iPhone 4S
	eglView->setFrameSize(618, 320); // iPhone 5/2
	// eglView->setFrameSize(2048, 1536); // iPad 4
	// eglView->setFrameSize(1280, 768); // Nokia Lumia 920

	return CCApplication::sharedApplication()->run();
}