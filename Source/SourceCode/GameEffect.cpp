#include "All.h"

void EFFECT_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "EffectManager";
}

void RAIN::move(GAME_OBJECT* obj)
{

	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Particle"];
		obj->drawAlg = &paritcleDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(4, 4), DRAW_OBJECT::CENTER);
		obj->scale = VECTOR2(0.3f, 0.3f);
		obj->color = VECTOR4(0.0f, 0.2f, 0.7f, 0.1f);
		obj->height = 300;
		obj->zcode = DRAW_LIST::zObject;
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		obj->clearRange = obj->drawRange;
		obj->state++;
		break;
	case 1:
		obj->color.w += 0.005f;
		obj->height -= 3;
		if (obj->height < 0)
		{
			for (int i = 0; i < 8; i++)
			{
				PARTICLE_DATA* pData = new PARTICLE_RAIN;
				EFFECT_MANAGER::getInstance()->add(pData->create(rotate(VECTOR2(1, 1), rand() % 360 * 1.0f)), obj->position);
				delete pData;
			}
			obj->erase();
		}
		break;
	}
}
