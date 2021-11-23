#include "All.h"

void PLAYERHPDRAW::draw(DRAW_OBJECT* obj)
{
	GameLib::sprite_render(obj->data,
		obj->position.x, obj->position.y,
		obj->scale.x, obj->scale.y,
		obj->texPos.x, obj->texPos.y,
		511.0f, 76.0f,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);

	GameLib::sprite_render(obj->data,
		obj->position.x + 65.0f * obj->scale.x, obj->position.y,
		obj->scale.x, obj->scale.y,
		obj->texPos.x + 65.0f, obj->texPos.y + obj->texSize.y,
		obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);

	for (int i = 0; i < PL->goldTotal; i++)
	{
		int animationX = 1;
		if (i < PL->goldGet)animationX = 0;
		GameLib::sprite_render(obj->data,
			obj->position.x + 550.0f + 50.0f * i , obj->position.y+30.0f,
			obj->scale.x, obj->scale.y,
			obj->texPos.x + 40.0f * animationX, obj->texPos.y + obj->texSize.y * 2, 
			40.0f, 40.0f,
			20.0f, 20.0f,
			obj->angle,
			obj->color.x, obj->color.y, obj->color.z, obj->color.w);
	}
}

void PLAYERHP::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["PlayerHp"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(511.0f, 76.0f), obj->TOPLEFT);
		obj->zcode = DRAW_LIST::zNoLight;
		obj->drawAlg = &playerHpDraw;
		if (obj->parent && obj->parent->exist)
		{
			obj->texSize.x = obj->parent->fWork[PLAYER::pHealth] / obj->parent->fWork[PLAYER::pHealth_Max] * 420.0f;
			if (obj->texSize.x < 0.0f)obj->texSize.x = 0.0f;
		}
		obj->state++;
		break;
	case 1:
		if (obj->parent && obj->parent->exist)
		{
			obj->texSize.x = obj->parent->fWork[PLAYER::pHealth] / obj->parent->fWork[PLAYER::pHealth_Max] * 420.0f;
			if (obj->texSize.x < 0.0f)obj->texSize.x = 0.0f;
		}
		break;
	}
}