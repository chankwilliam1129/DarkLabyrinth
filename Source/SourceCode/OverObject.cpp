#include "All.h"

void OVER_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "OverManager";
	add(&overBackground, VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f));
}

void OVER_MANAGER::draw()
{
	for (auto& it : objectList)
	{
		it->draw();
	}
}

void OVERBACKGROUND::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["OverBackground"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f);
		OVER_MANAGER::getInstance()->add(&overGameover, obj->position);
		GameLib::sound::play(11);
		obj->state++;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		break;
	}
}

void OVERGAMEOVER::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;

	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["OverGameover"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(700.0f, 232.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->height = 300.0f;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f);
		obj->state++;
		break;
	case 1:
		if (obj->height > 50)obj->height -= 2.0f;
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		if (CLICK_ENTER)
		{
			SCENEOVER::getInstance()->changeScene(SCENETITLE::getInstance());
		}
		break;
	}
}