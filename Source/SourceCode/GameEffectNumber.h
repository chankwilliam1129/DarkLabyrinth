#pragma once
class NUMBERDRAW : public DRAWALG
{
	void draw(DRAW_OBJECT* obj);
};
EXTERN NUMBERDRAW numberDraw;

class NUMBER :public MOVEALG
{
public:
	void move(GAME_OBJECT* obj);
};
EXTERN NUMBER number;