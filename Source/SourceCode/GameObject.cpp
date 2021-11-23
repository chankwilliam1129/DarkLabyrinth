#include "All.h"

using namespace std;

void GAME_OBJECT::init()
{
	clear();
}

void GAME_OBJECT::move()
{
	if (mvAlg) 
	{
		mvAlg->move(this); 
	}
}

void GAME_OBJECT::draw()
{
	if (data && color.w >0.0f)
	{
		DRAW_LIST::getInstance()->add(this);
	}
}

void GAME_OBJECT::clear()
{
	reset();
	exist = false;
	timer = 0;
	state = 0;
	size = 0;
	position = {};
	mvAlg = nullptr;

	drawRange = 0.0f;
	updateRange = 0.0f;
	clearRange = 0.0f;

	for (int i = 0; i < 16; i++)
	{
		iWork[i] = { 0 };
		fWork[i] = { 0 };
		vWork[i] = { VECTOR2(0,0) };
	}
}

void GAME_OBJECT::erase()
{
	exist = false;
}

bool GAME_OBJECT::RangeCheck(float range)
{
	if (range == 0.0f)
	{
		return true;
	}
	float length;
	length = (CAMERA::getInstance()->position.x - position.x) * (CAMERA::getInstance()->position.x - position.x) +
		(CAMERA::getInstance()->position.y - position.y) * (CAMERA::getInstance()->position.y - position.y);
	return length < (range* range) ? true : false;
}

void GAME_OBJECT::JudgeCheck(GAME_OBJECT* it)
{
	switch (it->type)
	{
	case tNOTHING:
		break;
	case tWALL:
		if (WallCheck(it))
		{
			judgeList.push_back(it);
		}
		break;
	default:
		if (circleHitCheck(it->position, it->size, position, size))
		{
			judgeList.push_back(it);
		}
	}
}

void GAME_OBJECT::JudgeCheck(std::list<GAME_OBJECT* > list)
{
	for (auto& it : list)
	{
		if (it == this) { continue; }
		JudgeCheck(it);
	}
}



bool GAME_OBJECT::WallCheck(GAME_OBJECT* it)
{
	if ((it->position.x - position.x) * (it->position.x - position.x) > (it->size * 2) * (it->size * 2))return false;
	if ((it->position.y - position.y) * (it->position.y - position.y) > (it->size * 2) * (it->size * 2))return false;
	return SquareHitCheck(it->vWork[TERRAIN2::p0], it->vWork[TERRAIN2::p1], it->vWork[TERRAIN2::p2], it->vWork[TERRAIN2::p3], position, size);
}