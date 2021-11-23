#pragma once
class ENEMYATTACK :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
	void judge(GAME_OBJECT* obj);
public:
	void causeDamage(GAME_OBJECT* obj, GAME_OBJECT* player);
};
EXTERN ENEMYATTACK enemyattack;