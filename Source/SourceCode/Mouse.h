#pragma once
class MOUSE : public SINGLETON<MOUSE>
{
public:
	POINT mousePos = {};
	VECTOR2 movement = {};
	bool isDraw = true;
public:
	void init();
	void update();
	void resetPos();
	void draw();
};