#include "LevelScreen.h"
#include "testResource.h"
#include "tests.h"

#define LINE_SPACE          40

static CCPoint s_tCurPos = CCPointZero;

LevelScreen::LevelScreen() :
	m_tBeginPos(CCPointZero) {
	// add close menu
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(s_pPathClose,
			s_pPathClose, this, menu_selector(LevelScreen::closeCallback));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);

	pMenu->setPosition(CCPointZero);
	pCloseItem->setPosition(
			ccp(VisibleRect::right().x - 30, VisibleRect::top().y - 30));

	// add menu items for tests
	m_pItemMenu = CCMenu::create();
	for (int i = 0; i < 1; ++i) {
		// #if (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
		//         CCLabelBMFont* label = CCLabelBMFont::create(g_aTestNames[i].c_str(),  "fonts/arial16.fnt");
		// #else
		CCLabelTTF* label = CCLabelTTF::create(g_aTestNames[i].c_str(),
				"Arial", 24);
		// #endif
		CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this,
				menu_selector(LevelScreen::menuCallback));

		m_pItemMenu->addChild(pMenuItem, i + 10000);
		pMenuItem->setPosition(
				ccp(VisibleRect::center().x,
						(VisibleRect::top().y - (i + 1) * LINE_SPACE)));
	}

	m_pItemMenu->setContentSize(
			CCSizeMake(VisibleRect::getVisibleRect().size.width,
					(1 + 1) * (LINE_SPACE)));
	m_pItemMenu->setPosition(s_tCurPos);
	addChild(m_pItemMenu);

	setTouchEnabled(true);

	addChild(pMenu, 1);

}

LevelScreen::~LevelScreen() {
}

void LevelScreen::menuCallback(CCObject * pSender) {

}

void LevelScreen::closeCallback(CCObject * pSender) {
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void LevelScreen::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) {
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*) (*it);

	m_tBeginPos = touch->getLocation();
}

void LevelScreen::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent) {
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*) (*it);

	CCPoint touchLocation = touch->getLocation();
	float nMoveY = touchLocation.y - m_tBeginPos.y;

	CCPoint curPos = m_pItemMenu->getPosition();
	CCPoint nextPos = ccp(curPos.x, curPos.y + nMoveY);

	if (nextPos.y < 0.0f) {
		m_pItemMenu->setPosition(CCPointZero);
		return;
	}

	if (nextPos.y > ((1 + 1) * LINE_SPACE
			- VisibleRect::getVisibleRect().size.height)) {
		m_pItemMenu->setPosition(
				ccp(
						0,
						((1 + 1) * LINE_SPACE
								- VisibleRect::getVisibleRect().size.height)));
		return;
	}

	m_pItemMenu->setPosition(nextPos);
	m_tBeginPos = touchLocation;
	s_tCurPos = nextPos;
}
