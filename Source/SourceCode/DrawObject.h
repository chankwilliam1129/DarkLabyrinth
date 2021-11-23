#pragma once

class DRAW_OBJECT;

class iVECTOR2
{
public:
	int x;
	int y;
	iVECTOR2(int x, int y) : x(x), y(y) {}
	iVECTOR2 operator*(int f) const { return iVECTOR2(x * f, y * f); }
	iVECTOR2 operator+(const iVECTOR2& v) const { return iVECTOR2(x + v.x, y + v.y); }
	bool operator != (const iVECTOR2& v) const { return (x != v.x) || (y != v.y); }
	bool operator == (const iVECTOR2& v) const { return (x == v.x) && (y == v.y); }
};

class DRAWALG
{
public:
	virtual void draw(DRAW_OBJECT* obj) = 0;
};

class DRAW_OBJECT
{
public:
	enum PIVOTTYPE
	{
		CENTER,
		BOTTOM,
		TOPRIGHT,
		TOPLEFT,
	};

public:
	GameLib::Sprite* data = nullptr;

	VECTOR2	position = {};

	VECTOR2	drawPosition = {};
	float   height = 0;
	VECTOR2	texPos = {};
	VECTOR2	texSize = {};
	VECTOR2	texPivot = {};
	VECTOR2 scale = {};
	float	angle = 0;
	VECTOR4 color = {};
	int		zcode = 0;
	DRAWALG* drawAlg = nullptr;
	iVECTOR2 animation = iVECTOR2(0, 0);
	float	sortDev = 0;

	void setDraw(const VECTOR2 TexPos, const  VECTOR2 TexSize, PIVOTTYPE PivotType);
	void reset();
	void angleCheck();
};