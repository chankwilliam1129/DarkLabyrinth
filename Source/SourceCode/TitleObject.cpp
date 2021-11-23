#include "All.h"
void TITLE_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "TitleManager";
	add(&titleBackground, VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f));
}

void TITLE_MANAGER::draw()
{
	for (auto& it : objectList)
	{
		it->draw();
	}
}

void TITLEBACKGROUND::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["TitleBackground"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuBackground;
		obj->drawPosition = VECTOR2(GameLib::system::SCREEN_WIDTH / 2.0f, GameLib::system::SCREEN_HEIGHT / 2.0f);
		obj->state++;
		TITLE_MANAGER::getInstance()->add(&titleStart, obj->position + VECTOR2(0.0f, 150.0f))->parent = obj;
		break;
	case 1:
		obj->scale = VECTOR2(1.5f, 1.5f) / CAMERA::getInstance()->magnification;
		obj->animation.x = (obj->timer / 8) % 5;
		obj->animation.y = (obj->timer / 8) / 5 % 4;
		break;
	}
}

void TITLEFRAME::move(GAME_OBJECT* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["TitleFrame"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(1280.0f, 720.0f), DRAW_OBJECT::CENTER);
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

void TITLESTART::move(GAME_OBJECT* obj)
{
	using namespace GameLib;
	using namespace input;
	switch (obj->state)
	{
	case 0:
		obj->data = SPRITELOAD::spr["TitleStart"];
		obj->drawAlg = &normalDraw;
		obj->setDraw(VECTOR2(0, 0), VECTOR2(328.0f, 82.0f), DRAW_OBJECT::CENTER);
		obj->zcode = DRAW_LIST::zMenuObject;
		obj->drawPosition = obj->position;
		obj->state++;
		break;
	case 1:
		obj->scale = obj->parent->scale;
		if (hitcheck(obj))
		{
			obj->animation.x =1;
			if (CLICK_MOUSE_LEFT)
			{
				SCENETITLE::getInstance()->changeScene(SCENEGAME::getInstance());
				GameLib::sound::play(17);
			}
		}
		else
		{
			obj->animation.x = 0;
		}
		break;
	}
}

bool TITLESTART::hitcheck(GAME_OBJECT* obj)
{
	if ((obj->position.x - obj->texPivot.x * obj->scale.x * CAMERA::getInstance()->magnification) > MOUSE::getInstance()->mousePos.x)return false;
	if ((obj->position.x + obj->texPivot.x * obj->scale.x * CAMERA::getInstance()->magnification) < MOUSE::getInstance()->mousePos.x)return false;
	if ((obj->position.y - obj->texPivot.y * obj->scale.y * CAMERA::getInstance()->magnification) > MOUSE::getInstance()->mousePos.y)return false;
	if ((obj->position.y + obj->texPivot.y * obj->scale.y * CAMERA::getInstance()->magnification) < MOUSE::getInstance()->mousePos.y)return false;
	return true;
}