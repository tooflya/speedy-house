#ifndef CONST_ENTITYMANAGER_H
#define CONST_ENTITYMANAGER_H

#include "cocos2d.h"

using namespace cocos2d;

#include "../Entities/Entity.h"

class EntityManager : public CCArray
{
	protected:
		CCNode* mParent;

		int mLastElementNumber;
		int mCapacity;

	private:
		void init(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen);

	public:
		EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen);

		EntityManager(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen);

		Entity* create();

		void destroy(int pIndex);
};

#endif