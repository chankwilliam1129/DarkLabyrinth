#include "All.h"
void ENEMYHPDRAW::draw(DRAW_OBJECT* obj)
{
	GameLib::sprite_render(obj->data,
		obj->drawPosition.x - obj->texSize.x / 2 *CAMERA::getInstance()->magnification, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y,
		obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w * 0.3f);

	GameLib::sprite_render(obj->data,
		obj->drawPosition.x - obj->texSize.x / 2 *CAMERA::getInstance()->magnification, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y,
		obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);
}

void ENEMYHP::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["EnemyHp"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(20, 3), obj->TOPLEFT);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 20;
		obj->color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
		obj->drawAlg = &enemyHpDraw;
		obj->height = 50;
		obj->color.w = 0.0f;
		if (obj->parent && obj->parent->exist)
		{
			obj->position = obj->parent->position; 
			obj->scale.x = obj->parent->fWork[ENEMY::eHealth] / obj->parent->fWork[ENEMY::eHealth_Max];
		}
		else 
		{ 
			obj->erase(); 
		}
		obj->state++;
		break;
	case 1:
		if (obj->parent && obj->parent->exist)
		{
			obj->position = obj->parent->position;
			obj->scale.x = obj->parent->fWork[ENEMY::eHealth] / obj->parent->fWork[ENEMY::eHealth_Max];
			if (obj->parent->iWork[ENEMY::eInjury])
			{
				obj->color.w = obj->parent->iWork[ENEMY::eInjury] / 30.0f;
				if (obj->color.w > 1.0f)obj->color.w = 1.0f;
				if (obj->color.w < 0.1f)obj->color.w = 0.0f;
			}
			
		}
		else
		{
			obj->erase();
		}
		break;
	}
}