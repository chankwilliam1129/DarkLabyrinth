#pragma once
class GAME_OBJECT;

class MOVEALG
{
public:
	virtual void move(GAME_OBJECT* obj) = 0;
};

class GAME_OBJECT : public DRAW_OBJECT
{
public:
	enum OBJECT_TYPE
	{
		tNOTHING,
		tPLAYER,
		tPLAYER_ATTACK,
		tENEMY,
		tENEMT_ATTACK,
		tMOD,
		tBOX,
		tLIGHT,
		tWALL,
		tWALL_CIRCLE,
		tWALL_LIGHT,
		tEFFECT,
		tTotal,
	};

public:
	bool exist = false;
	int state = 0;
	int timer = 0;
	int type = 0;
	float size = 0;
	VECTOR2 speed = {};

	MOVEALG* mvAlg = nullptr;
	GAME_OBJECT* parent = nullptr;

	int iWork[16] = { 0 };
	float fWork[16] = { 0 };
	VECTOR2 vWork[16] = { VECTOR2(0,0) };

	std::list<GAME_OBJECT*>  judgeList;

	float drawRange = 0;
	float updateRange = 0;
	float clearRange = 0;

public:
	void init();
	void move();
	void draw();
	void clear();
	void erase();
	bool RangeCheck(float range);
	bool WallCheck(GAME_OBJECT* obj);
	void JudgeCheck(GAME_OBJECT* it);
	void JudgeCheck(std::list<GAME_OBJECT* > list);
};
