#pragma once
class OVER_MANAGER :public OBJECTMANAGER, public SINGLETON<OVER_MANAGER>
{
public:
	void init();
	void draw();
};

class OVERBACKGROUND :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN OVERBACKGROUND overBackground;

class OVERGAMEOVER :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN OVERGAMEOVER overGameover;