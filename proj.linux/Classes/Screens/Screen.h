#ifndef CONST_SCREEN_H
#define CONST_SCREEN_H

#include "cocos2d.h"

#include "../Entities/Entity.h"

using namespace cocos2d;


//#include "../Utils/Utils.cpp"

class Screen : public CCScene
{
	public:
		Entity* mBackground;

		Screen();
};

#endif