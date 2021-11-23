#pragma once
class MENUBACKGROUND :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUBACKGROUND menuBackground;

class MENUBACKGROUND2 :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUBACKGROUND2 menuBackground2;

class MENUPLAYERBACK :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUPLAYERBACK menuPlayerBack;

class MENUPLAYERFRAME :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUPLAYERFRAME menuPlayerFrame;

class MENUPLAYER :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUPLAYER menuPlayer;

class MENUPLAYERBEAT :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUPLAYERBEAT menuPlayerBeat;

class MENUWEAPONBACK :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUWEAPONBACK menuWeaponBack;

class MENUWEAPONFRAME :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUWEAPONFRAME menuWeaponFrame;

class MENUEQUIPFRAME :public MOVEALG
{
public:
	enum iWork
	{
		mNum,
	};
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUEQUIPFRAME menuEquipFrame;

class MENUITEMFRAME :public MOVEALG
{
public:
	enum iWork
	{
		mNum,
	};
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUITEMFRAME menuItemFrame;

class MENUWEAPONGUN :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUWEAPONGUN menuWeaponGun;

class MENUWEAPONFRAME2 :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUWEAPONFRAME2 menuWeaponFrame2;

class EQUIPMOD :public MOVEALG
{
public:
	enum iWork
	{
		mNum,
		mLevel,
		mType,
	};
public:
	void move(GAME_OBJECT* obj);
	void setPos(GAME_OBJECT* obj);
	void loadMod(GAME_OBJECT* obj);
	bool Hitcheck(GAME_OBJECT* obj);
};
EXTERN EQUIPMOD equipMod;

class ITEMMOD :public MOVEALG
{
public:
	enum iWork
	{
		mNum,
		mLevel,
		mType,
	};
public:
	void move(GAME_OBJECT* obj);
	void setPos(GAME_OBJECT* obj);
	void loadMod(GAME_OBJECT* obj);
};
EXTERN ITEMMOD itemMod;
class MODOBJECTDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN MODOBJECTDRAW modObjectDraw;

class MENUDROP :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN MENUDROP menuDrop;
