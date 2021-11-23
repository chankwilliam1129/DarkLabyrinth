#include "All.h"
void ENEMY_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "EnemyManager";
	totalEnemy = 0;
}

void ENEMY_MANAGER::update()
{
	int cnt = 0;
	totalEnemy = 0;
	for (auto& it : objectList)
	{
		if (it->RangeCheck(it->updateRange))
		{
			it->move();
			it->angleCheck();
			it->timer++;
		}
		if (!it->RangeCheck(it->clearRange))it->erase();
		if (it->type == GAME_OBJECT::tENEMY)totalEnemy++;
		cnt++;
	}
	objectList.remove_if(existCheck);
}

void ENEMYDRAW::draw(DRAW_OBJECT* obj)
{
	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dOpacity;

	GameLib::sprite_render(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x + obj->texSize.x * obj->animation.x, obj->texPos.y + obj->texSize.y * obj->animation.y, obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		obj->angle,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w);
	
	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dLight;
}

void ENEMY::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Enemy1"];
		obj->type = obj->tENEMY;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(64, 64), obj->BOTTOM);
		obj->animation = iVECTOR2(1, 0);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 20;
		obj->drawAlg = &enemyDraw;
		obj->state++;
		obj->updateRange = 1000.0f;
		obj->drawRange = 600.0f;
		obj->fWork[eHealth] = 60.0f + PL->goldGet * 30.0f;
		obj->fWork[eHealth_Max] = 60.0f + PL->goldGet * 30.0f;
		ENEMY_MANAGER::getInstance()->add(&enemyHp, obj->position)->parent = obj;
		break;
	case 1:
		obj->JudgeCheck(TERRAIN_MANAGER::getInstance()->objectList);
		obj->JudgeCheck(PL->obj);
		speedUpdata(obj);
		attack(obj);
		judge(obj);
		healthCheck(obj);
		obj->animation.x = obj->timer / 12 % 4;
		break;
	}
}
void ENEMY::healthCheck(GAME_OBJECT* obj)
{
	if (obj->fWork[eHealth] > obj->fWork[eHealth_Max])obj->fWork[eHealth] = obj->fWork[eHealth_Max];
	if (obj->fWork[eHealth] <= 0)
	{
		if (!(rand() % 20))dropMod(obj);
		obj->erase();
	}
	if (obj->iWork[eInjury])obj->iWork[eInjury]--;
}

void ENEMY::speedUpdata(GAME_OBJECT* obj) {
	obj->speed = {};
	if(!obj->iWork[eSpeed_state])obj->iWork[eSpeed_state] = rand() % 5;
	enemySpeed[obj->iWork[eSpeed_state]]->move(obj);
	obj->position += obj->speed;
}

void ENEMY::attack(GAME_OBJECT* obj) {
	if (obj->timer % 300 == 1)
	{
		ENEMY_MANAGER::getInstance()->add(&enemyattack, obj->position)->speed = NorVector(PL->obj->position, obj->position);
	}
}

void ENEMY::judge(GAME_OBJECT* obj) {
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
		case GAME_OBJECT::tWALL_CIRCLE:
		case GAME_OBJECT::tLIGHT:
		case GAME_OBJECT::tBOX:
			obj->position = it->position + NorVector(obj->position, it->position) * (obj->size + it->size);
			break;
		default:
			break;
		}
	}
	obj->judgeList.clear();
}


void ENEMY::dropMod(GAME_OBJECT* obj)
{
	int type = rand() % (MOD::mTOTLE - 1) + 1;
	int level = rand() % 100;
	if (level < 6)level = 5;
	else if (level < 17)level = 4;
	else if (level < 35)level = 3;
	else if (level < 62)level = 2;
	else level = 1;

	GAME_OBJECT* it;
	it = ENEMY_MANAGER::getInstance()->add(&modObject, obj->position);
	it->iWork[MODOBJECT::mLevel] = level;
	it->iWork[MODOBJECT::mType] = type;
}