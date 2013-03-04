#ifndef CONST_SCREEN
#define CONST_SCREEN

#include "cocos2d.h"
#include "../Entities/Entity.cpp"

class Screen : public CCScene
{
    public:
        Entity* mBackground;

        Screen()
        {
			this->scheduleUpdate();
        }
};

#endif;