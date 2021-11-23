#pragma once
class BASE_ENEMY_SPEED {
public:
	virtual void move(GAME_OBJECT*) = 0;
};

class MOVE_WAIT :public BASE_ENEMY_SPEED {
public:
	void move(GAME_OBJECT*);
};
EXTERN MOVE_WAIT moveWait;

class MOVE_TRACKING :public BASE_ENEMY_SPEED {
public:
	void move(GAME_OBJECT*);
};
EXTERN MOVE_TRACKING moveTracking;

class MOVE_PROACTIVE :public BASE_ENEMY_SPEED {
public:
	void move(GAME_OBJECT*);
};
EXTERN MOVE_PROACTIVE moveProactive;

class MOVE_ESCAPE :public BASE_ENEMY_SPEED {
public:
	void move(GAME_OBJECT*);
};
EXTERN MOVE_ESCAPE moveEscape;

class MOVE_NORMAL :public BASE_ENEMY_SPEED {
public:
	void move(GAME_OBJECT*);
};
EXTERN MOVE_NORMAL moveNormal;