#pragma once
class PLAYERATTACK :public MOVEALG
{
public:
	enum iWork
	{
		pReflection,
	};
public:
	void move(GAME_OBJECT* obj);
	void judge(GAME_OBJECT* obj);
public:
	void causeDamage(GAME_OBJECT* enemy);
	void reflect(GAME_OBJECT* obj, GAME_OBJECT* it);

};
EXTERN PLAYERATTACK playerattack;

class PLAYERATTACKEFFECT :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN PLAYERATTACKEFFECT playerattackeffect;