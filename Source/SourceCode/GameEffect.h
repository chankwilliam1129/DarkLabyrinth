#pragma once
class EFFECT_MANAGER :public OBJECTMANAGER, public SINGLETON<EFFECT_MANAGER>
{
public:
	void init();
};

class RAIN :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN RAIN Rain;


