#include "All.h"


void PARTICLE::move(GAME_OBJECT* obj)
{

	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Particle"];
		obj->drawAlg = &paritcleDraw;
		obj->type = obj->tEFFECT;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(15, 15), DRAW_OBJECT::CENTER);
		obj->scale = obj->vWork[pScale];
		obj->color = VECTOR4(obj->vWork[pColorXY].x, obj->vWork[pColorXY].y, obj->vWork[pColorZW].x, obj->vWork[pColorZW].y);
		obj->speed = NorVector(obj->vWork[pVector]);
		obj->speed *= obj->fWork[pSpeed];
		obj->height = obj->fWork[pHeight];
		obj->drawRange = obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		obj->clearRange = obj->drawRange;
		obj->state++;
		break;
	case 1:
		
		if (obj->fWork[pVector_Cor] !=0)
		{
			VECTOR2 temppos = obj->vWork[pVector];
			obj->vWork[pVector].x = temppos.x * cosf(ToRadian(obj->fWork[pVector_Cor])) - temppos.y * sinf(ToRadian(obj->fWork[pVector_Cor]));
			obj->vWork[pVector].y = temppos.x * sinf(ToRadian(obj->fWork[pVector_Cor])) + temppos.y * cosf(ToRadian(obj->fWork[pVector_Cor]));
		}

		obj->speed = NorVector(obj->vWork[pVector]);
		obj->fWork[pSpeed] += obj->fWork[pSpeed_Cor];
		obj->fWork[pSpeed] *= obj->fWork[pSpeed_Mag];
		obj->speed *= obj->fWork[pSpeed];

		obj->scale += obj->vWork[pScale_Cor];
		obj->scale.x *= obj->vWork[pScale_Mag].x;
		obj->scale.y *= obj->vWork[pScale_Mag].y;

		obj->height += obj->fWork[pHeight_Speed];
		obj->fWork[pHeight_Speed] += obj->fWork[pHeight_Speed_Cor];

		obj->color.w *= obj->fWork[pColor_Mag];
		break;
	}
	obj->position += obj->speed;
	//obj->drawPosition = obj->position;
	obj->timer++;

	if (obj->timer > obj->iWork[pLife] || obj->height < -2)
	{
		obj->clear();
		//delete data;
		//delete this;
	}
}

