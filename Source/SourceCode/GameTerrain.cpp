#include "All.h"

void TERRAIN_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "TerrainManager";
	MAPLOAD::getInstance()->load();
	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			switch (MAPLOAD::getInstance()->map[y][x])
			{
			case 0:
				EFFECT_MANAGER::getInstance()->add(&terrain, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				break;
			case 1:
				buildWall(x, y);
				break;
			case 2:
				EFFECT_MANAGER::getInstance()->add(&terrain, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				add(&tree, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				PL->goldTotal += 1;
				break;
			case 3:
				EFFECT_MANAGER::getInstance()->add(&terrain, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				PL->obj = PL->add(&player, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				break;
			case 4:
				EFFECT_MANAGER::getInstance()->add(&terrain, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				add(&box, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f))->iWork[BOX::mDropLevel] = 1;
				break;
			case 5:
				EFFECT_MANAGER::getInstance()->add(&terrain, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
				add(&box, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f))->iWork[BOX::mDropLevel] = 2;
				break;
			default:
				break;

			}
		}
	}
}

void TERRAIN_MANAGER::buildWall(int x, int y)
{
	GAME_OBJECT* obj = add(&terrain2, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f));
	if ((y == 0 || MAPLOAD::getInstance()->map[y - 1][x] != 1) && y != 0)
	{

		add(&wall, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f - size_Y / 2.0f))->angle = 0.0f;
		obj->type = obj->tWALL;

	}
	if ((x == MAX_X - 1 || MAPLOAD::getInstance()->map[y][x + 1] != 1) && x != MAX_X - 1)
	{
		add(&wall, VECTOR2(x * size_X * 1.0f + size_X / 2.0f, y * size_Y * 1.0f))->angle = 90.0f;
		obj->type = obj->tWALL;
	}
	if ((y == MAX_Y - 1 || MAPLOAD::getInstance()->map[y + 1][x] != 1) && y != MAX_Y - 1)
	{
		add(&wall, VECTOR2(x * size_X * 1.0f, y * size_Y * 1.0f + size_Y / 2.0f))->angle = 180.0f;
		obj->type = obj->tWALL;
	}
	if ((x == 0 || MAPLOAD::getInstance()->map[y][x - 1] != 1) && x != 0)
	{
		add(&wall, VECTOR2(x * size_X * 1.0f - size_X / 2.0f, y * size_Y * 1.0f))->angle = 270.0f;
		obj->type = obj->tWALL;
	}
}

void TERRAIN::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Terrain"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(192.0f,192.0f), obj->CENTER);
		obj->animation = iVECTOR2(rand() % 4, 0);
		obj->zcode = DRAW_LIST::zTerrain;
		obj->size = 98.0f;
		obj->drawAlg = &normalDraw2;
		obj->angle = rand() % 4 * 90.0f;
		obj->state++;
		break;
	case 1:
	{
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;

		float distance = (obj->position.x - PL->obj->position.x) * (obj->position.x - PL->obj->position.x) +
			(obj->position.y - PL->obj->position.y) * (obj->position.y - PL->obj->position.y);
		if (ENEMY_MANAGER::getInstance()->totalEnemy<250 && distance < 3000000 && distance > 640000)
		{
			if (!(rand() % (2000-100*PL->goldGet)))
			{
				ENEMY_MANAGER::getInstance()->add(&enemy, obj->position);
			}
		}
		break;
	}
	case 2:
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		break;
	}
}

void TERRAIN2::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Terrain2"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(192.0f, 192.0f), obj->CENTER);
		obj->animation = iVECTOR2(0, 0);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 96.0f;
		obj->height = 96.0f;
		obj->drawAlg = &normalDraw2;
		if (obj->type == obj->tWALL)
		{
			obj->vWork[p0] = VECTOR2(obj->position.x - obj->size, obj->position.y - obj->size);
			obj->vWork[p1] = VECTOR2(obj->position.x + obj->size, obj->position.y - obj->size);
			obj->vWork[p2] = VECTOR2(obj->position.x + obj->size, obj->position.y + obj->size);
			obj->vWork[p3] = VECTOR2(obj->position.x - obj->size, obj->position.y + obj->size);
		}
		obj->state++;
		break;
	case 1:
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		break;
	}
}

void WALL::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Wall"];
		obj->texPos = VECTOR2(0, 0);
		obj->texSize  = VECTOR2(192.0f, 192.0f);
		obj->texPivot = obj->texSize / 2;
		obj->scale = VECTOR2(1.0f, 1.0f);
		obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		obj->animation = iVECTOR2(rand() % 4, 0);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 192 / 2.0f;
		obj->drawAlg = &normalDraw4;
		obj->type = obj->tWALL_LIGHT;
		obj->state++;
		break;
	case 1:
		angleUpdate(obj);
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		break;
	}
}

void WALL::angleUpdate(GAME_OBJECT* obj)
{
	float angle = obj->angle + CAMERA::getInstance()->angle;
	if (angle >= 360)angle -= 360.0f;
	if (angle < 0)angle += 360.0f;
	if (angle < 90 || angle > 270) obj->color.w = 1.0f;
	else
	{
		obj->color.w = 1.0f;
		obj->sortDev = sinf(ToRadian(angle) / 2.0f) * obj->texPivot.y * CAMERA::getInstance()->ratio * -1.0f *CAMERA::getInstance()->magnification;
	}
}

void TREE::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Tree"];
		obj->drawAlg = &normalDraw3;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(332, 332), DRAW_OBJECT::BOTTOM);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 100.0f;
		obj->angle = rand() % 90 * 1.0f;
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		createLeaf(obj);
		TERRAIN_MANAGER::getInstance()->add(&light, obj->position);
		obj->state++;
		break;
	case 1:
		break;
	}
}

void TREE::createLeaf(GAME_OBJECT* obj)
{
	
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(0.0f, 50.0f))->height = 202 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(0.0f, -50.0f))->height = 202 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(50.0f, 0.0f))->height = 202 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(-50.0f, 0.0f))->height = 202 + rand() % 10 * 1.0f;

	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(60.0f, 60.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(60.0f, -60.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(60.0f, 60.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(-60.0f, 60.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(0.0f, 90.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(0.0f, -90.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(90.0f, 0.0f))->height = 272 + rand() % 10 * 1.0f;
	EFFECT_MANAGER::getInstance()->add(&leaf, obj->position + VECTOR2(-90.0f, 0.0f))->height = 272 + rand() % 10 * 1.0f;
}

void LIGHT::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Light"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(64, 64), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zObject;
		obj->size = 100.0f;
		obj->sortDev = 5.0f;
		obj->type = obj->tLIGHT;
		obj->iWork[lPower] = 0;
		obj->state++;
		break;
	case 1:
		obj->height = 330.0f * obj->iWork[lPower] / 5.0f;
		obj->color.w =0.5f* obj->iWork[lPower] / 5.0f;
		if (obj->iWork[lPower] >= 5)
		{
			obj->state = 2;
			obj->color.w = 1.0f;
			obj->height = 330.0f;
			PL->obj->fWork[PLAYER::pHealth] = PL->obj->fWork[PLAYER::pHealth_Max];
			GameLib::sound::play(5);
			PL->goldGet++;
		}
		else
		{
			soundUpdate(obj);
		}
		break;
	case 2:
		break;
	}
}

void LIGHT::soundUpdate(GAME_OBJECT* obj)
{
	if (!SCENEGAME::getInstance()->nearGold || Length(obj->position, PL->obj->position) < Length(SCENEGAME::getInstance()->nearGold->position, PL->obj->position))
	{
		SCENEGAME::getInstance()->nearGold = obj;
	}
}

void LEAF::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Leaf"];
		obj->type = obj->tWALL_CIRCLE;
		obj->drawAlg = &normalDraw5;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(32, 32), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zObject;
		obj->scale *= 4.0f;
		obj->angle = rand() % 90 * 1.0f;
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		obj->state++;
		break;
	case 1:
		break;
	}
}


void BOX::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Box"];
		obj->setDraw(VECTOR2(0, 0), VECTOR2(36.0f, 36.0f), obj->CENTER);
		obj->animation = iVECTOR2(0, 0);
		obj->zcode = DRAW_LIST::zObject;
		obj->type = obj->tBOX;
		obj->size = 15.0f;
		obj->height = 36.0f;
		obj->drawAlg = &normalDraw2;
		obj->angle = rand() % 90 * 1.0f;
		obj->state++;

		for (int i = 0; i < 4; i++)
		{
			GAME_OBJECT* it;
			it = EFFECT_MANAGER::getInstance()->add(&box2, obj->position + rotate(VECTOR2(0, obj->texPivot.y), obj->angle + 90.0f * i));
			it->angle = 90.0f * i + obj->angle;
			it->parent = obj;
		}
		break;
	case 1:
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		break;
	}
}

void BOX::dropMod(GAME_OBJECT* obj)
{
	int type = rand() % (MOD::mTOTLE - 1) + 1;
	int level = 0;
	switch (obj->iWork[mDropLevel])
	{
	case 1:
		level = 3;
		break;
	case 2:
		level = 5;
		break;
	}

	GAME_OBJECT* it;
	it = ENEMY_MANAGER::getInstance()->add(&modObject, obj->position);
	it->iWork[MODOBJECT::mLevel] = level;
	it->iWork[MODOBJECT::mType] = type;
	obj->erase();
}

void BOX2::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Box"];
		obj->texPos = VECTOR2(0, 0);
		obj->texSize = VECTOR2(36.0f, 36.0f);
		obj->texPivot = obj->texSize / 2;
		obj->scale = VECTOR2(1.0f, 1.0f);
		obj->color = VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		obj->zcode = DRAW_LIST::zObject;
		obj->drawAlg = &normalDraw4;
		obj->height = 18.0f;
		obj->animation.y = rand() % 4 + 1;
		obj->state++;
		break;
	case 1:
		wall.angleUpdate(obj);
		obj->drawRange = GameLib::system::SCREEN_WIDTH / CAMERA::getInstance()->magnification;
		obj->updateRange = obj->drawRange;
		if (!(obj->parent && obj->parent->exist))
		{
			obj->erase();
		}
		break;
	}
}