#include "All.h"
void PLAYER::attack(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;
	if (attack_timer == 0.0f)
	{
		if (CLICK_MOUSE_LEFT)
		{
			attack_timer = 30.0f;
			VECTOR2 vec;
			vec.x = -sinf(ToRadian(CAMERA::getInstance()->angle));
			vec.y = -cosf(ToRadian(CAMERA::getInstance()->angle));

			int Multi = (int)PL->getStats(MOD::mMultishot);
			for (int i = 0; i < Multi; i++)
			{
				float angle = (i - (Multi - 1) * 0.5f) * (4.0f);
				PL->add(&playerattack, obj->position)->speed = rotate(vec,angle);
			}
			obj->animation.y = 8;
			obj->timer = 0;
			sound::play(0);
		}
	}
	if (attack_timer > 0.0f)
	{
		attack_timer -= PL->getStats(MOD::mAttackSpeed_Mag);
		if (attack_timer < 0.0f)attack_timer = 0.0f;
	}
}

void PLAYERATTACK::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["PlayerAttack"];
		obj->type = obj->tPLAYER_ATTACK;
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(8, 8), DRAW_OBJECT::CENTER);
		obj->height = 32;
		obj->size = 3;
		obj->zcode = DRAW_LIST::zObject;
		obj->iWork[pReflection] = (int)PL->getStats(MOD::mReflection);
		obj->state++;
		break;
	case 1:
		obj->position += obj->speed * 10;
		obj->JudgeCheck(TERRAIN_MANAGER::getInstance()->objectList);
		obj->JudgeCheck(ENEMY_MANAGER::getInstance()->objectList);

		if (obj->timer % 2)
		{
			EFFECT_MANAGER::getInstance()->add(&playerattackeffect, obj->position - obj->speed * 0.2f);
		}
		judge(obj);
		if (obj->timer >= 100) obj->state = 2;
		break;
	case 2:
		obj->color.w *= 0.8f;
		obj->scale *= 1.15f;
		if (obj->color.w <= 0.1f)
		{
			obj->erase();
		}

	}
}

void PLAYERATTACK::judge(GAME_OBJECT* obj)
{
	for (auto& it : obj->judgeList)
	{
		switch (it->type)
		{
		case GAME_OBJECT::tENEMY:
			causeDamage(it);
			for (int i = 0; i < 10; i++)
			{
				PARTICLE_DATA* pData = new PARTICLE_SPARK;
				VECTOR2 speed = rotate(obj->position - it->position, rand() % 30 - 15 * 1.0f);
				EFFECT_MANAGER::getInstance()->add(pData->create(speed), obj->position);
				delete pData;
			}
			if (obj->iWork[pReflection] > 1)reflect(obj, it);
			else obj->state = 2;
			break;
		case GAME_OBJECT::tWALL_CIRCLE:
		case GAME_OBJECT::tWALL:
			if (obj->iWork[pReflection] > 1)reflect(obj, it);
			else obj->state = 2;
			break;
		case GAME_OBJECT::tLIGHT:
			it->iWork[LIGHT::lPower]++;
			obj->state = 2;
			break;
		case GAME_OBJECT::tBOX:
			obj->state = 2;
			box.dropMod(it);
			break;
		}
	}
	obj->judgeList.clear();
}

void PLAYERATTACK::reflect(GAME_OBJECT* obj , GAME_OBJECT* it)
{
	switch (it->type)
	{
	case GAME_OBJECT::tWALL_CIRCLE:
	case GAME_OBJECT::tENEMY:
		obj->speed = NorVector(obj->position, it->position);
		break;
	case GAME_OBJECT::tWALL:
		if (obj->position.x - obj->size >= it->vWork[TERRAIN2::p0].x && obj->position.x + obj->size <= it->vWork[TERRAIN2::p1].x)
		{
			while (SquareHitCheck(it->vWork[TERRAIN2::p0], it->vWork[TERRAIN2::p1], it->vWork[TERRAIN2::p2], it->vWork[TERRAIN2::p3], obj->position, obj->size))
			{
				obj->position -= obj->speed;
			}
			obj->speed.y *= -1;
		}
		else if (obj->position.y - obj->size >= it->vWork[TERRAIN2::p0].y && obj->position.y + obj->size <= it->vWork[TERRAIN2::p3].y)
		{
			while (SquareHitCheck(it->vWork[TERRAIN2::p0], it->vWork[TERRAIN2::p1], it->vWork[TERRAIN2::p2], it->vWork[TERRAIN2::p3], obj->position, obj->size))
			{
				obj->position -= obj->speed;
			}
			obj->speed.x *= -1;
		}
		else obj->speed *= -1;
		break;
	}
	obj->iWork[pReflection]--;
	
}

void PLAYERATTACK::causeDamage(GAME_OBJECT* enemy)
{
	int chance = rand() % 100;
	float realDamage = PL->getStats(MOD::mDamage_Mag);
	float scale = 1;
	VECTOR4 color = VECTOR4(0.8f, 0.2f, 0.0f, 1.0f);
	if (chance < PL->getStats(MOD::mCritial_Chance))
	{
		realDamage *= PL->getStats(MOD::mCritial_Mag);
		color = VECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
		scale = 2;
		GameLib::sound::play(7);
	}
	
	enemy->fWork[ENEMY::eHealth] -= realDamage;
	GAME_OBJECT* num;
	num = EFFECT_MANAGER::getInstance()->add(&number, enemy->position);
	num->animation.x = (int)realDamage;
	num->height = enemy->height + enemy->size / 2.0f;
	num->color = color;
	num->scale = VECTOR2(1,1)*scale;

	enemy->iWork[ENEMY::eInjury] = 100;

	GameLib::sound::play(7);
}

void PLAYERATTACKEFFECT::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["PlayerAttack"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(8, 8), DRAW_OBJECT::CENTER);
		obj->height = 32;
		obj->size = 3;
		obj->zcode = DRAW_LIST::zObject;
		obj->clearRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->state++;
		break;
	case 1:
		obj->scale *= 0.8f;
		obj->color.w *= 0.90f;
		if (obj->color.w <= 0.05f)obj->erase();
		break;
	}
}

