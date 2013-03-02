#ifndef __APPMACROS_H__
#define __APPMACROS_H__

#include "cocos2d.h"

#define DESIGN_RESOLUTION_1280X800   0

#define TARGET_DESIGN_RESOLUTION_SIZE  DESIGN_RESOLUTION_1280X800

typedef struct tagResource {
	cocos2d::CCSize size;
	char directory[100];
} Resource;

static Resource Resources = { cocos2d::CCSizeMake(1280, 800), "1280x800" };

#if (TARGET_DESIGN_RESOLUTION_SIZE == DESIGN_RESOLUTION_1280X800)
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1280, 800);
#endif

#define TITLE_FONT_SIZE  (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / Resources.size.width * 36)

#endif
