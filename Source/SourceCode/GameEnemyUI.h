#pragma once
class ENEMYHPDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN ENEMYHPDRAW enemyHpDraw;

class ENEMYHP :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN ENEMYHP enemyHp;