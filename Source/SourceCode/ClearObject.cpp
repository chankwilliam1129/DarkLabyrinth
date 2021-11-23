#include "All.h"
void CLEAR_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "ClearManager";
	add(&clearBackground, VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f));
}

void CLEAR_MANAGER::draw()
{
	for (auto& it : objectList)
	{
		it->draw();
	}
}

void CLEARBACKGROUND::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["ClearBackground"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f);
		obj->state++;
		CLEAR_MANAGER::getInstance()->add(&clearCharactor, obj->position)->parent = obj;
		CLEAR_MANAGER::getInstance()->add(&clearGameclear, obj->position)->parent = obj;
		GameLib::sound::play(12);
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void CLEARCHARACTOR::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["ClearCharactor"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(438.0f, 720.0f), DRAW_OBJECT::BOTTOM);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->sortDev = 1;
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f - 200.0f, GameLib::system::SCREEN_HEIGHT);
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void CLEARGAMECLEAR::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;

	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["ClearGameClear"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(327.0f, 127.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->height = 300.0f;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f + 500.0f, GameLib::system::SCREEN_HEIGHT / 2.0f);
		obj->state++;
		break;
	case 1:
		if (obj->height > 50)obj->height -= 2.0f;
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		if (CLICK_ENTER)
		{
			SCENECLEAR::getInstance()->changeScene(SCENETITLE::getInstance());
		}
		break;
	}
}