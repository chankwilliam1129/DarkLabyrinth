#include "All.h"

void NUMBERDRAW::draw(DRAW_OBJECT* obj)
{
	int num = obj->animation.x;
	for (int i = 0; i < obj->animation.y; i++)
	{
		float PosX = obj->drawPosition.x - (i - (obj->animation.y - 1) * 0.5f) * (obj->texSize.x) * (obj->scale.x) * 1.2f * CAMERA::getInstance()->magnification;
		int AnimetionX = num % 10;
		num /= 10;

		GameLib::sprite_render(obj->data,
			PosX, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
			obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
			obj->texPos.x + obj->texSize.x * AnimetionX, 0,
			obj->texSize.x, obj->texSize.y,
			obj->texPivot.x, obj->texPivot.y,
			0,
			obj->color.x, obj->color.y, obj->color.z, obj->color.w);
	}
}

void NUMBER::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Number"];

		obj->texPos = VECTOR2(0, 0);
		obj->texSize = VECTOR2(3, 5);
		obj->texPivot = obj->texSize / 2;
		obj->height = 50.0f;
		obj->speed = VECTOR2(rand() % 10 / 10.0f - 0.5f, rand() % 10 / 10.0f - 0.5f);
		obj->zcode = DRAW_LIST::zNoLight;
		obj->scale *= 1.5f;
		obj->drawAlg = &numberDraw;
		for (int num = obj->animation.x; num != 0; obj->animation.y++)
		{
			num /= 10;
		}
		obj->state++;
	case 1:
		obj->position += obj->speed;
		obj->height += 0.5f;
		if (obj->timer >= 30)obj->state = 2;
		break;
	case 2:
		//obj->scale *= 0.92f;
		obj->color.w *= 0.94f;
		if (obj->color.w < 0.05f)obj->erase();
		break;
	}
}