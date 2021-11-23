#include "All.h"

void MENUBACKGROUND::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuBackground"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::TOPLEFT);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->state++;
		MENU_MANAGER::getInstance()->add(&menuBackground2, obj->position)->parent = obj;
		MENU_MANAGER::getInstance()->add(&menuPlayerBack, obj->position + VECTOR2(138, 80)*1.5f)->parent = obj;
		MENU_MANAGER::getInstance()->add(&menuWeaponBack, obj->position + VECTOR2(590, 80) * 1.5f)->parent = obj;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f)/CAMERA::getInstance()->magnification;
		break;
	}
}
void MENUBACKGROUND2::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuBackground2"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::TOPLEFT);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->sortDev = 1;
		obj->state++;
		break;
	case 1:
		obj->scale = obj->parent->scale;
		break;
	}
}

void MENUPLAYERBACK::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuPlayerBack"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(388.0f, 472.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->position += obj->texPivot * 1.5f;
		obj->drawPosition = obj->position;
		obj->sortDev = 2;
		MENU_MANAGER::getInstance()->add(&menuPlayerFrame, obj->position)->parent = obj;
		MENU_MANAGER::getInstance()->add(&menuPlayer, obj->position)->parent = obj;
		MENU_MANAGER::getInstance()->add(&menuPlayerBeat, obj->position + VECTOR2(0.0f,300.0f))->parent = obj;

		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}
void MENUPLAYERFRAME::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuPlayerFrame"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(396.0f, 480.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->sortDev = 3;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}
void MENUPLAYER::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["Player"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(64.0f, 64.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->sortDev = 3;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(8.0f, 8.0f) / CAMERA::getInstance()->magnification;
		obj->animation.x = obj->timer / 12 % 4;
		break;
	}
}
void MENUPLAYERBEAT::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuPlayerBeat"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(388.0f, 48.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->sortDev = 3;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		obj->scale = obj->parent->scale;
		if (obj->timer / 600 % 2)obj->texPos.x--;
		else obj->texPos.x++;
		break;
	}
}

void MENUWEAPONBACK::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuWeaponBack"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(564.0f, 564.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->position += obj->texPivot * 1.5f;
		obj->drawPosition = obj->position;
		obj->sortDev = 2;
		MENU_MANAGER::getInstance()->add(&menuWeaponFrame, obj->position + VECTOR2(0.0f, -218.0f))->parent = obj;
		MENU_MANAGER::getInstance()->add(&menuWeaponFrame2, obj->position + VECTOR2(0.0f, 218.0f))->parent = obj;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void MENUWEAPONFRAME::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuWeaponFrame"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(572.0f, 280.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		obj->sortDev = 3;
		MENU_MANAGER::getInstance()->add(&menuWeaponGun, obj->position + VECTOR2(0.0f, -65.0f));
		MENU_MANAGER::getInstance()->add(&menuEquipFrame, obj->position + VECTOR2(-220.0f, 80.0f))->iWork[MENUEQUIPFRAME::mNum] = 0;
		MENU_MANAGER::getInstance()->add(&menuEquipFrame, obj->position + VECTOR2(0.0f, 80.0f))->iWork[MENUEQUIPFRAME::mNum] = 1;
		MENU_MANAGER::getInstance()->add(&menuEquipFrame, obj->position + VECTOR2(220.0f, 80.0f))->iWork[MENUEQUIPFRAME::mNum] = 2;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void MENUEQUIPFRAME::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuEquipFrame"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(80, 80.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		MENU_MANAGER::getInstance()->add(&equipMod, obj->position)->parent = obj;
		obj->sortDev = 1000.0f;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void MENUITEMFRAME::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuItemFrame"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(80, 80.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = obj->position;
		MENU_MANAGER::getInstance()->add(&itemMod, obj->position)->parent = obj;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.0f, 1.0f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void MENUWEAPONGUN::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuWeaponGun"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(196.0f, 104.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->drawPosition = obj->position;
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}


void MENUWEAPONFRAME2::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuWeaponFrame2"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(286.0f, 140.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->drawPosition = obj->position;
		obj->sortDev = 3;
		for (int i = 0; i < 10; i++)
		{ 
			float sizeX = 150.0f;
			float sizeY = 80.0f;
			float PosX = obj->position.x - (2.0f * sizeX) + i % 5 * sizeX;
			float PosY = obj->position.y - sizeY + i / 5 * sizeY * 2 + 16.0f;
			MENU_MANAGER::getInstance()->add(&menuItemFrame, VECTOR2(PosX, PosY))->iWork[MENUEQUIPFRAME::mNum] = i;
		}
		MENU_MANAGER::getInstance()->add(&menuDrop, VECTOR2(GameLib::system::SCREEN_WIDTH - 100.0f, GameLib::system::SCREEN_HEIGHT - 162.0f));
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(3.0f, 3.0f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void EQUIPMOD::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuMod"];
		obj->drawAlg = &modObjectDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(72, 72), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->angle = 0;
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		setPos(obj);
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;

		if (Hitcheck(obj))
		{
			obj->zcode = DRAW_LIST::z8;
		}

		if (CLICK_MOUSE_LEFT && Hitcheck(obj) && PL->equipMod[obj->parent->iWork[mNum]].type)
		{
			SCENEGAME::getInstance()->modTarget1 = &PL->equipMod[obj->parent->iWork[mNum]];
		}
		if (OUT_MOUSE_LEFT && Hitcheck(obj))
		{
			SCENEGAME::getInstance()->modTarget2 = &PL->equipMod[obj->parent->iWork[mNum]];
		}

		if (SCENEGAME::getInstance()->modTarget1 == &PL->equipMod[obj->parent->iWork[mNum]])
		{
			obj->drawPosition.x = MOUSE::getInstance()->mousePos.x * 1.0f;
			obj->drawPosition.y = MOUSE::getInstance()->mousePos.y * 1.0f;
			obj->zcode = DRAW_LIST::z9;
		}
		else if (Hitcheck(obj))
		{
			setPos(obj);
			obj->zcode = DRAW_LIST::z8;
		}
		else
		{
			setPos(obj);
		}
		break;
	}
}
void EQUIPMOD::setPos(GAME_OBJECT* obj)
{
	loadMod(obj);
	obj->position = obj->parent->position;
	obj->drawPosition = obj->position;
	obj->zcode = DRAW_LIST::zMenuObject;
}
void EQUIPMOD::loadMod(GAME_OBJECT* obj)
{
	obj->iWork[mLevel] = PL->equipMod[obj->parent->iWork[mNum]].level;
	obj->iWork[mType] = PL->equipMod[obj->parent->iWork[mNum]].type;
	obj->animation = iVECTOR2(obj->iWork[mLevel], obj->iWork[mType]);
}

bool EQUIPMOD::Hitcheck(GAME_OBJECT* obj)
{
	if ((obj->position.x - obj->texPivot.x * obj->scale.x * CAMERA::getInstance()->magnification) > MOUSE::getInstance()->mousePos.x)return false;
	if ((obj->position.x + obj->texPivot.x * obj->scale.x * CAMERA::getInstance()->magnification) < MOUSE::getInstance()->mousePos.x)return false;
	if ((obj->position.y - obj->texPivot.y * obj->scale.y * CAMERA::getInstance()->magnification) > MOUSE::getInstance()->mousePos.y)return false;
	if ((obj->position.y + obj->texPivot.y * obj->scale.y * CAMERA::getInstance()->magnification) < MOUSE::getInstance()->mousePos.y)return false;
	return true;
}

void ITEMMOD::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuMod"];
		obj->drawAlg = &modObjectDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(72, 72), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->angle = 0;
		obj->scale = obj->parent->scale;
		setPos(obj);
		obj->state++;
		break;
	case 1:
		obj->scale = obj->parent->scale;
		

		if (CLICK_MOUSE_LEFT && equipMod.Hitcheck(obj) && PL->itemMod[obj->parent->iWork[mNum]].type)
		{
			SCENEGAME::getInstance()->modTarget1 = &PL->itemMod[obj->parent->iWork[mNum]];
		}
		if (OUT_MOUSE_LEFT && equipMod.Hitcheck(obj))
		{
			SCENEGAME::getInstance()->modTarget2 = &PL->itemMod[obj->parent->iWork[mNum]];
		}

		if (SCENEGAME::getInstance()->modTarget1 == &PL->itemMod[obj->parent->iWork[mNum]])
		{
			obj->drawPosition.x = MOUSE::getInstance()->mousePos.x * 1.0f;
			obj->drawPosition.y = MOUSE::getInstance()->mousePos.y * 1.0f;
			obj->zcode = DRAW_LIST::z9;
		}
		else if (equipMod.Hitcheck(obj))
		{
			setPos(obj);
			obj->zcode = DRAW_LIST::z8;
		}
		else
		{
			setPos(obj);
		}
		break;
	}
}
void ITEMMOD::setPos(GAME_OBJECT* obj)
{
	loadMod(obj);
	obj->position = obj->parent->position;
	obj->drawPosition = obj->position;
	obj->zcode = DRAW_LIST::zMenuObject;
}
void ITEMMOD::loadMod(GAME_OBJECT* obj)
{
	obj->iWork[mLevel] = PL->itemMod[obj->parent->iWork[mNum]].level;
	obj->iWork[mType] = PL->itemMod[obj->parent->iWork[mNum]].type;
	obj->animation = iVECTOR2(obj->iWork[mLevel], obj->iWork[mType]);
}
void MODOBJECTDRAW::draw(DRAW_OBJECT* obj)
{
	GameLib::sprite_render3(obj->data,
		obj->drawPosition.x, obj->drawPosition.y - obj->height * CAMERA::getInstance()->magnification,
		obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
		obj->texPos.x, obj->texPos.y + obj->texSize.x * obj->animation.y, 
		obj->texSize.x, obj->texSize.y,
		obj->texPivot.x, obj->texPivot.y,
		ToRadian(obj->angle + 180) ,
		obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);

	if (obj->animation.y)
	{
		for (int i = 0; i < obj->animation.x; i++)
		{
			float PosX = obj->drawPosition.x - (i - (obj->animation.x - 1) * 0.5f) * (14.0f) * (obj->scale.x) * CAMERA::getInstance()->magnification;
			float PosY = obj->drawPosition.y + 25.0f * CAMERA::getInstance()->magnification * obj->scale.y;
			GameLib::sprite_render3(obj->data,
				PosX, PosY,
				obj->scale.x * CAMERA::getInstance()->magnification, obj->scale.y * CAMERA::getInstance()->magnification,
				obj->texSize.x, 0.0f,
				13.0f, 13.0f,
				6.5f, 6.5f,
				0.0f,
				obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);
		}

		if (obj->zcode == DRAW_LIST::z8)
		{
			float texPivot = 0.0f;
			if (MOUSE::getInstance()->mousePos.x > 1420)texPivot = 432.0f;
			GameLib::sprite_render3(obj->data,
				MOUSE::getInstance()->mousePos.x * 1.0f, MOUSE::getInstance()->mousePos.y * 1.0f, 
				1.0f, 1.0f,
				obj->texSize.x, obj->texPos.y + obj->texSize.x * obj->animation.y,
				432.0f, obj->texSize.y,
				texPivot, 0.0f,
				ToRadian(obj->angle + 180),
				obj->color.x, obj->color.y, obj->color.z, obj->color.w, CAMERA::getInstance()->ratio);
		}
	}
}

void MENUDROP::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["MenuDrop"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(36, 36), DRAW_OBJECT::CENTER);
		obj->drawPosition = obj->position;
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->angle = 0;
		obj->state++;
		break;
	case 1:
		if (SCENEGAME::getInstance()->modTarget1 && equipMod.Hitcheck(obj))
		{
			obj->scale = VECTOR2(2.0f, 2.0f);
			if (OUT_MOUSE_LEFT)
			{
				SCENEGAME::getInstance()->modTarget1->level = 0;
				SCENEGAME::getInstance()->modTarget1->type = 0;
			}
		}
		else
		{
			obj->scale = VECTOR2(1.5f, 1.5f);
		}
	}
}