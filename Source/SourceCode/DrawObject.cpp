#include "All.h"

void DRAW_OBJECT::setDraw(const VECTOR2 TexPos, const  VECTOR2 TexSize, PIVOTTYPE PivotType)
{
	texPos = TexPos;
	texSize = TexSize;
	switch (PivotType)
	{
	case PIVOTTYPE::CENTER:
		texPivot = TexSize / 2;
		break;
	case PIVOTTYPE::BOTTOM:
		texPivot.x = TexSize.x / 2;
		texPivot.y = TexSize.y;
		break;
	case PIVOTTYPE::TOPRIGHT:
		texPivot.x = TexSize.x;
		texPivot.y = 0;
		break;
	case PIVOTTYPE::TOPLEFT:
		texPivot.x = 0;
		texPivot.y = 0;
		break;
	}
	angle = 0;
	scale = VECTOR2(1, 1);
	color = VECTOR4(1, 1, 1, 1);
	sortDev = 0;
}

void DRAW_OBJECT::reset()
{
	data = nullptr;
	position = {};
	drawPosition = {};
	height = 0;
	texPos = {};
	texSize = {};
	texPivot = {};
	scale = {};
	angle = 0;
	color = {};
	zcode = 0;
	height = 0;
	animation = { 0,0 };
	drawAlg = nullptr;
	sortDev = 0;
}

void DRAW_OBJECT::angleCheck()
{
	if (angle >= 360.0f)angle -= 360.0f;
	if (angle < 0.0f)angle += 360.0f;
}