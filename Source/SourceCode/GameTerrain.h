#pragma once
class TERRAIN_MANAGER:public OBJECTMANAGER,public SINGLETON<TERRAIN_MANAGER>
{
public:
	static const int size_X = 192;
	static const int size_Y = 192;
	static const int MAX_X = 64;
	static const int MAX_Y = 64;

public:
	void init();
	void buildWall(int x,int y);
};

class TERRAIN :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN TERRAIN terrain;

class TERRAIN2 :public MOVEALG
{
public:
	enum vWork
	{
		p0,
		p1,
		p2,
		p3,
	};
	void move(GAME_OBJECT* obj);
};
EXTERN TERRAIN2 terrain2;

class WALL :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
	void angleUpdate(GAME_OBJECT* obj);
};
EXTERN WALL wall;

class TREE :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
	void createLeaf(GAME_OBJECT* obj);
};
EXTERN TREE tree;

class LEAF :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN LEAF leaf;

class LIGHT :public MOVEALG
{
public:
	enum iWork
	{
		lPower,
	};
public:
	void move(GAME_OBJECT* obj);
	void soundUpdate(GAME_OBJECT* obj);
};
EXTERN LIGHT light;

class BOX :public MOVEALG
{
public:
	enum iWork
	{
		mDropLevel,
	};
public:
	void move(GAME_OBJECT* obj);
	void dropMod(GAME_OBJECT* obj);
};
EXTERN BOX box;

class BOX2 :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN BOX2 box2;

