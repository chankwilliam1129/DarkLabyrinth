#pragma once
class ENEMY_MANAGER :public OBJECTMANAGER, public SINGLETON<ENEMY_MANAGER>
{
public:
	int totalEnemy = 0;
public:
	void init();
	void update();
};

class ENEMYDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN ENEMYDRAW enemyDraw;

class ENEMY :public MOVEALG
{
protected:
	enum SPEED_STATE {
		Wait,
		Tracking,
		Escape,
		Proactive,
		Normal,
		Total
	};

	BASE_ENEMY_SPEED* enemySpeed[Total] =
	{
		&moveWait,
		&moveTracking,
		&moveEscape,
		&moveProactive,
		&moveNormal,
	};

private:
	const float SPEED = 2.0f;
public:
	enum iWORK
	{
		eInjury,
		eSpeed_state
	};
	enum  fWORK
	{
		eHealth_Max,
		eHealth,
		eAttack,
		eSpeed,
	};

public:
	void move(GAME_OBJECT* obj);
	void healthCheck(GAME_OBJECT* obj);
	void speedUpdata(GAME_OBJECT* obj);
	void attack(GAME_OBJECT* obj);
	void judge(GAME_OBJECT* obj);

	void dropMod(GAME_OBJECT* obj);
};
EXTERN ENEMY enemy;