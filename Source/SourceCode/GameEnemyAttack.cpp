#include "All.h"
void ENEMYATTACK::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["EnemyAttack"];
		obj->type = obj->tENEMT_ATTACK;
		obj->drawAlg = &enemyDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(7, 7), DRAW_OBJECT::CENTER);
		obj->height = 32;
		obj->size = 4;
		obj->zcode = DRAW_LIST::zObject;
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->state++;
		break;
	case 1:
		obj->position += obj->speed *3.0f;
		obj->JudgeCheck(TERRAIN_MANAGER::getInstance()->objectList);
		obj->JudgeCheck(PL->obj);
		judge(obj);
		if (obj->timer >= 500)
		{
			obj->erase();
		}
		break;
	}
}

void ENEMYATTACK::judge(GAME_OBJECT* obj)
{
	for (auto& it : obj->judgeList)
	{
		switch (it->type)
		{
		case GAME_OBJECT::tPLAYER:
			causeDamage(obj,it);
			for (int i = 0; i < 10; i++)
			{
				PARTICLE_DATA* pData = new PARTICLE_SPARK;
				VECTOR2 speed = rotate(obj->position - it->position, rand() % 30 - 15 * 1.0f);
				EFFECT_MANAGER::getInstance()->add(pData->create(speed), obj->position);
				delete pData;
			}
			obj->erase();
			break;
		case GAME_OBJECT::tLIGHT:
		case GAME_OBJECT::tWALL_CIRCLE:
		case GAME_OBJECT::tWALL:
		case GAME_OBJECT::tBOX:
			for (int i = 0; i < 10; i++)
			{
				PARTICLE_DATA* pData = new PARTICLE_SPARK;
				VECTOR2 speed = rotate(obj->position - it->position, rand() % 30 - 15 * 1.0f);
				EFFECT_MANAGER::getInstance()->add(pData->create(speed), obj->position);
				delete pData;
			}
			obj->erase();
			break;
		}
	}
	obj->judgeList.clear();
}

void ENEMYATTACK::causeDamage(GAME_OBJECT* obj,GAME_OBJECT* player)
{
	player->fWork[PLAYER::pHealth] -= 5.0f + 5.0f * PL->goldGet;
	player->vWork[PLAYER::pKnockback] = NorVector(player->position, obj->position) * 5.0f;
	GameLib::sound::play(1);
}
