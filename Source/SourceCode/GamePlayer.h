#pragma once
class PLAYER_MANAGER :public OBJECTMANAGER, public SINGLETON<PLAYER_MANAGER>
{
public:
	GAME_OBJECT* obj = {};
	const float speed = 3.2f;
	float basicStats[MOD::mTOTLE] = {};
	
	MOD equipMod[3] = {};
	MOD itemMod[10] = {};

	int goldTotal = 0;
	int goldGet = 0;
public:
	void init();
	float getStats(int num);
};

class PLAYER :public MOVEALG
{
private:
	float attack_timer = 0.0f;
public:
	enum fWork
	{
		pHealth_Max,
		pHealth,
	};
	enum vWork
	{
		pKnockback,
	};
public:
	void move(GAME_OBJECT* obj);
	void animationReset(GAME_OBJECT* obj);
	void speedUpdata(GAME_OBJECT* obj);
	void attack(GAME_OBJECT* obj);
	void judge(GAME_OBJECT* obj);
};
EXTERN PLAYER player;

#define PL (PLAYER_MANAGER::getInstance())
