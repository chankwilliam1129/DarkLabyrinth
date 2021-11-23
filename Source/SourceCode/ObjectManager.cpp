#include "All.h"
bool existCheck(GAME_OBJECT* i)
{
	if (!i->exist)
	{
		i->clear();
		delete i;
		return true;
	}
	return false;
}

void OBJECTMANAGER::init()
{
	objectList.clear();
}

void OBJECTMANAGER::update() 
{
	int cnt = 0;
	for (auto& it : objectList)
	{
		if (it->RangeCheck(it->updateRange))
		{
			it->move();
			it->angleCheck();
			it->timer++;
		}
		if (!it->RangeCheck(it->clearRange))it->erase();
		cnt++;
	}
	objectList.remove_if(existCheck);
}

void OBJECTMANAGER::draw()
{
	for (auto& it : objectList)
	{
		if (it->RangeCheck(it->drawRange))
		{
			CAMERA::getInstance()->object_update(it);

			it->draw();
		}
	}
}

GAME_OBJECT* OBJECTMANAGER::add(MOVEALG* mvAlg, const VECTOR2 pos)
{
	GAME_OBJECT* obj = new GAME_OBJECT;
	obj->exist = true;
	obj->mvAlg = mvAlg;
	obj->position = pos;
	objectList.push_back(obj);
	return *objectList.rbegin();
}

GAME_OBJECT* OBJECTMANAGER::add(GAME_OBJECT* obj, const VECTOR2 pos)
{
	obj->exist = true;
	obj->position = pos;
	objectList.push_back(obj);
	return *objectList.rbegin();
}