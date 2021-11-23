#include "All.h"

void SCENECLEAR::update()
{
	using namespace GameLib;
	using namespace input;
	switch (state)
	{
	case 0:
		timer = 0;
		GameLib::setBlendMode(Blender::BS_ALPHA);
		CLEAR_MANAGER::getInstance()->init();
		state++;
		break;
	case 1:
		CLEAR_MANAGER::getInstance()->update();
		break;
	}
	draw();
}

void SCENECLEAR::draw()
{
	CLEAR_MANAGER::getInstance()->draw();
}