#ifndef CONST_ENTITYMANAGER
#define CONST_ENTITYMANAGER

#include "EntityManager.h"

void EntityManager::init(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen)
{
	this->initWithCapacity(pCreateCount);

	this->mParent = pScreen;
	this->mLastElementNumber = -1;
	this->mCapacity = pCreateCount; // TODO: increase to pMaxCount

	for(int i = 0; i < pCreateCount; i++)
	{
		Entity* currentEntity = pEntity->deepCopy();

		currentEntity->setEntityManager(this);
		currentEntity->setEntityManagerId(i);

		this->addObject(currentEntity);
	}
}

EntityManager::EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen)
{
	this->init(pCreateCount, -1, pEntity, pScreen);
}

EntityManager::EntityManager(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen)
{
	this->init(pCreateCount, pMaxCount, pEntity, pScreen);
}

Entity* EntityManager::create()
{
	if (this->mLastElementNumber + 1 < this->mCapacity) {
		this->mLastElementNumber++;

		Entity* object = (Entity*) this->objectAtIndex(this->mLastElementNumber);
		object->create();

		this->mParent->addChild(object);

		return object;
	}

	return NULL;
}

void EntityManager::destroy(int pIndex)
{
	this->mParent->removeChild((Entity*) this->objectAtIndex(pIndex));
}

#endif