#include "All.h"

void MODOBJECT::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Mod"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(72, 72), obj->BOTTOM);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 5;
		obj->fWork[mHeight_Speed] = 3;
		obj->animation.y = obj->iWork[mType] - 1;
		obj->scale = VECTOR2(0.25f, 0.25f);
		obj->height = 4;
		obj->drawAlg = &modDraw;
		GameLib::sound::play(8);
		obj->state++;
		break;
	case 1:
		obj->height += obj->fWork[mHeight_Speed];
		obj->fWork[mHeight_Speed] -= 0.2f;
		if (obj->height <= 0)
		{
			obj->height = 0;
			obj->state++;
		}
		break;
	case 2:
		obj->angle += 3;
		if (circleHitCheck(obj->position, obj->size, PL->obj->position, PL->obj->size))
		{
			for (int i = 0; i < 10; i++)
			{
				if (PL->itemMod[i].type == 0)
				{
					PL->itemMod[i].type = obj->iWork[mType];
					PL->itemMod[i].level = obj->iWork[mLevel];
					GameLib::sound::play(9);
					obj->erase();
					break;
				}
			}
		}

		break;
	}
}

void MODDRAW::draw(DRAW_OBJECT* obj)
{
	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dNormal;
	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(obj->angle),
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);
	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dLight;
}