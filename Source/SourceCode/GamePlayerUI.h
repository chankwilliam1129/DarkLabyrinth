#pragma once
class PLAYERHPDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN PLAYERHPDRAW playerHpDraw;

class PLAYERHP :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN PLAYERHP playerHp;