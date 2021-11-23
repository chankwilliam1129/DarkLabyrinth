#pragma once
class CAMERA :public  SINGLETON<CAMERA>
{
public:
	VECTOR2 position = { 0,0 };
	float	magnification = 2.0f;
	float	ratio = (GameLib::system::SCREEN_HEIGHT * 1.0f) / (GameLib::system::SCREEN_WIDTH * 1.0f);
	float	angle = 0.0f;


public:
	void update();
	void object_update(DRAW_OBJECT* obj);
};