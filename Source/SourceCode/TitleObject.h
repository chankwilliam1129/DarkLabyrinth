#pragma once
class TITLE_MANAGER :public OBJECTMANAGER, public SINGLETON<TITLE_MANAGER>
{
public:
	void init();
	void draw();
};

class TITLEBACKGROUND :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN TITLEBACKGROUND titleBackground;

class TITLEFRAME :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN TITLEFRAME titleFrame;

class TITLESTART :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
	bool hitcheck(GAME_OBJECT* obj);
};
EXTERN TITLESTART titleStart;