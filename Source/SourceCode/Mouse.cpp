#include "All.h"
void MOUSE::init()
{
	isDraw = true;
}
void MOUSE::update()
{
	isDraw = false;
	using namespace GameLib;
	using namespace input;

	GetCursorPos(&mousePos);

	movement.x = GameLib::system::SCREEN_WIDTH / 2.0f - mousePos.x;

	CAMERA::getInstance()->angle += movement.x / 15.0f;

	resetPos();
}

void MOUSE::resetPos()
{
	SetCursorPos((int)GameLib::system::SCREEN_WIDTH / 2, (int)GameLib::system::SCREEN_HEIGHT / 2);
}

void MOUSE::draw()
{
	if (isDraw)
	{
		GetCursorPos(&mousePos);
		GameLib::sprite_render(SPRITELOAD::spr["Mouse"], (float)mousePos.x, (float)mousePos.y, 1, 1, 0, 0, 17, 17);
	}
}