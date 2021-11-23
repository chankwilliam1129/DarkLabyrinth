#include "All.h"

void SCENEOVER::update()
{
	using namespace GameLib;
	using namespace input;
	switch (state)
	{
	case 0:
		timer = 0;
		GameLib::setBlendMode(Blender::BS_ALPHA);
		OVER_MANAGER::getInstance()->init();
		state++;
		break;
	case 1:
		OVER_MANAGER::getInstance()->update();
		break;
	}
	draw();
}

void SCENEOVER::draw()
{
	OVER_MANAGER::getInstance()->draw();
}