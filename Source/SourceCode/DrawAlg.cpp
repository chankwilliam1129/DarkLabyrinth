#include "All.h"

void NORMALDRAW::draw(DRAW_OBJECT* obj)
{

	GameLib::sprite_render(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification, 
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);
}

void NORMALDRAW2::draw(DRAW_OBJECT* obj)
{
	GameLib::sprite_render2(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y*CAMERA::getInstance()->ratio * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(CAMERA::getInstance()->angle + obj->angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);
}

void NORMALDRAW3::draw(DRAW_OBJECT* obj)
{
	float angle = CAMERA::getInstance()->angle + obj->angle;
	while (angle > 90.0f)
	{
		angle -= 90.0f;
	}

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(angle + 270.0f),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(angle + 180.0f),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(angle + 90.0f),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);
}

void NORMALDRAW4::draw(DRAW_OBJECT* obj)
{
	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(CAMERA::getInstance()->angle + obj->angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);
}

void NORMALDRAW5::draw(DRAW_OBJECT* obj)
{
	using namespace GameLib;
	setBlendMode(Blender::BS_ADD);

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(CAMERA::getInstance()->angle + obj->angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(CAMERA::getInstance()->angle + obj->angle + 90.0f),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	GameLib::sprite_render2(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->ratio * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(CAMERA::getInstance()->angle + obj->angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);

	setBlendMode(Blender::BS_ALPHA);
}
void PARTICLEDRAW::draw(DRAW_OBJECT* obj)
{
	using namespace GameLib;

	setBlendMode(Blender::BS_ADD);
	sprite_render(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification, 
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);
	setBlendMode(Blender::BS_ALPHA);

}