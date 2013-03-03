#include "cocos2d.h"
#include "VisibleRect.h"
#include "Test.h"
#include "Car.h"



Settings settings;

class Test;
class Box2DView : public CCLayer
{
    Test*        m_test;
public:
    Box2DView(void) {

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCPoint visibleOrigin = pDirector->getVisibleOrigin();
    CCSize visibleSize = pDirector->getVisibleSize();

    setTouchEnabled(true);

    schedule(schedule_selector(Box2DView::update));
TestEntry g_testEntries[] =
{
    {"Car", Car::Create}
};

    m_test = g_testEntries->createFcn();

    this->autorelease();

    this->setScale(35);
    this->setAnchorPoint(ccp(0, 0));
    this->setPosition(
            ccp(visibleOrigin.x + visibleSize.width / 2,
                    visibleOrigin.y + visibleSize.height / 3));
    }
   
    void update(float pDeltaTime) {

    m_test->Step(&settings);
    }

    void draw() {

    CCLayer::draw();

    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position);

    kmGLPushMatrix();

    m_test->m_world->DrawDebugData();

    kmGLPopMatrix();

    CHECK_GL_ERROR_DEBUG();
    }
};









class LevelScreen : public CCScene
{
public:
	LevelScreen(void) {

Box2DView* view = new Box2DView();
    
    this->addChild(view, 0);
    }
};