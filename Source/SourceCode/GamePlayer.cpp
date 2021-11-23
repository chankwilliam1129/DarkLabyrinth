#include "All.h"
void PLAYER_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "PlayerManager";
	obj = {};
	for (int i = 0; i < 10; i++)
	{
		if (i < 3)equipMod[i] = {};
		itemMod[i] = {};
	}
	basicStats[MOD::mCritial_Chance] = 10.0f;
	basicStats[MOD::mCritial_Mag] = 2.0f;
	basicStats[MOD::mDamage_Mag] = 20.0f;
	basicStats[MOD::mMultishot] = 1.0f;
	basicStats[MOD::mReflection] = 1.0f;
	basicStats[MOD::mAttackSpeed_Mag] = 1.0f;

	goldGet = 0;
	goldTotal = 0;
}

float PLAYER_MANAGER::getStats(int num)
{
	float equipStats = 1.0f;
	for (int i = 0; i < 3; i++)
	{
		if (equipMod[i].type != num) continue;
		switch (equipMod[i].type)
		{
		case MOD::mNONE:
			break;
		case MOD::mMultishot:
		case MOD::mReflection:
			equipStats += 1.0f * equipMod[i].level;
			break;
		case MOD::mDamage_Mag:
		case MOD::mCritial_Chance:
		case MOD::mCritial_Mag:
		case MOD::mAttackSpeed_Mag:
			equipStats += 0.2f * equipMod[i].level;
			break;
		default:
			break;
		}
	}
	return basicStats[num] * equipStats;
}

void PLAYER::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Player"];
		obj->type = obj->tPLAYER;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(64, 64), obj->BOTTOM);
		obj->animation = iVECTOR2(1, 0);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 16;
		obj->drawAlg = &normalDraw;
		obj->state++;

		obj->fWork[pHealth] = 200.0f;
		obj->fWork[pHealth_Max] = 200.0f;
		PLAYER_MANAGER::getInstance()->add(&playerHp, VECTOR2(20.0f, 20.0f))->parent = obj;
		break;
	case 1:
		animationReset(obj);
		speedUpdata(obj);
		attack(obj);
		CAMERA::getInstance()->position = obj->position;
		obj->JudgeCheck(ENEMY_MANAGER::getInstance()->objectList);
		judge(obj);
		obj->JudgeCheck(TERRAIN_MANAGER::getInstance()->objectList);
		judge(obj);
		if (obj->fWork[pHealth] <= 0)
		{
			obj->state = 2;
			obj->timer = 0;
			obj->animation.y = 11;
			GameLib::sound::play(2);
		}
		break;
	case 2:
		obj->animation.x = obj->timer / 15;
		if (obj->timer >= 60) SCENEGAME::getInstance()->changeScene(SCENEOVER::getInstance());
		break;

	}
}

void PLAYER::animationReset(GAME_OBJECT* obj)
{
	if (obj->vWork[pKnockback] != VECTOR2(0.0f, 0.0f))
	{
		obj->animation.y = 10;
		VECTOR2 speed = rotate(NorVector(obj->vWork[pKnockback]), -CAMERA::getInstance()->angle);
		if (speed.y > 0.5) obj->animation.x = 1;
		else if (speed.y < -0.5)obj->animation.x = 0;
		else if (speed.x > 0)obj->animation.x = 3;
		else obj->animation.x = 2;
	}
	else
	{
		if (attack_timer == 0.0f)
		{
			if (obj->animation.y >= 8)obj->animation.y = 3;
			else if (obj->animation.y >= 4) obj->animation.y -= 4;
			obj->animation.x = obj->timer / 10 % 4;
		}
		else
		{
			obj->animation.x = (int)attack_timer / 15;
		}
	}
}

void PLAYER::speedUpdata(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;

	if (obj->vWork[pKnockback] != VECTOR2(0.0f, 0.0f))
	{
		obj->position += obj->vWork[pKnockback];
		obj->vWork[pKnockback] *= 0.9f;
		if (obj->vWork[pKnockback].x * obj->vWork[pKnockback].x + obj->vWork[pKnockback].y * obj->vWork[pKnockback].y < 1.0f)
		{
			obj->vWork[pKnockback] = {0,0};
		}
	}
	else
	{

		VECTOR2 speed = {};
		obj->speed = {};
		if (HOLD_UP)	speed.y -= 1;
		if (HOLD_DOWN)	speed.y += 1;
		if (HOLD_LEFT)	speed.x -= 1;
		if (HOLD_RIGHT)	speed.x += 1;

		if (speed.x == -1) obj->animation.y = 6;
		if (speed.x == 1) obj->animation.y = 5;
		if (speed.y == -1) obj->animation.y = 7;
		if (speed.y == 1) obj->animation.y = 4;
		if (speed != VECTOR2(0.0f, 0.0f) && attack_timer)
		{
			obj->animation.y = 9;
		}
		if (speed != VECTOR2(0.0f, 0.0f))
		{
			obj->speed = rotate(NorVector(speed), -CAMERA::getInstance()->angle);
			obj->speed *= PL->speed;
			if (attack_timer) obj->speed *= 0.7f;
			if (!(obj->timer % 20))GameLib::sound::play(3);
		}

		obj->position += obj->speed;
	}
}

void PLAYER::judge(GAME_OBJECT* obj)
{
	for (auto& it : obj->judgeList)
	{
		switch (it->type)
		{
		case GAME_OBJECT::tWALL:
			if (obj->position.y < it->vWork[TERRAIN2::p0].y) obj->position.y = it->vWork[TERRAIN2::p0].y - obj->size - 1;
			else if (obj->position.y > it->vWork[TERRAIN2::p2].y) obj->position.y = it->vWork[TERRAIN2::p2].y + obj->size + 1;
			else if (obj->position.x < it->vWork[TERRAIN2::p0].x) obj->position.x = it->vWork[TERRAIN2::p0].x - obj->size - 1;
			else if (obj->position.x > it->vWork[TERRAIN2::p2].x) obj->position.x = it->vWork[TERRAIN2::p2].x + obj->size + 1;
			else
			{
				while (SquareHitCheck(it->vWork[TERRAIN2::p0], it->vWork[TERRAIN2::p1], it->vWork[TERRAIN2::p2], it->vWork[TERRAIN2::p3], obj->position, obj->size))
				{
					if (obj->speed.x || obj->speed.y) { obj->position -= obj->speed; }
					else obj->position.y--;
				}
			}
			break;
		case GAME_OBJECT::tENEMY:
		case GAME_OBJECT::tBOX:
		case GAME_OBJECT::tWALL_CIRCLE:
		case GAME_OBJECT::tLIGHT:
			obj->position = it->position + NorVector(obj->position, it->position) * (obj->size + it->size);
			break;
		default:
			break;
		}
	}
	obj->judgeList.clear();
}

