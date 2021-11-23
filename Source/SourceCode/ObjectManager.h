#pragma once

class OBJECTMANAGER
{
public:
	std::string name;
	std::list<GAME_OBJECT* >  objectList;
public:
	void init();
	void update();
	void draw();

	GAME_OBJECT* add(MOVEALG* mvAlg, const VECTOR2 pos);
	GAME_OBJECT* add(GAME_OBJECT* obj, const VECTOR2 pos);
};

bool existCheck(GAME_OBJECT* i);