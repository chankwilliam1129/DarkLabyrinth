#pragma once
class CLEAR_MANAGER :public OBJECTMANAGER, public SINGLETON<CLEAR_MANAGER>
{
public:
	void init();
	void draw();
};

class CLEARBACKGROUND :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN CLEARBACKGROUND clearBackground;

class CLEARCHARACTOR :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN CLEARCHARACTOR clearCharactor;

class CLEARGAMECLEAR :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN CLEARGAMECLEAR clearGameclear;