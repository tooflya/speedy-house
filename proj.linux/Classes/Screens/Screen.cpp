#include "cocos2d.h"

using namespace cocos2d;

class Screen : public CCScene
{
    public:

        CCSprite* mBackground;

        Screen()
        {
			this->scheduleUpdate();
        }

        ~Screen()
        {

        }

        virtual void update(float pDeltaTime)
        {

        }
};