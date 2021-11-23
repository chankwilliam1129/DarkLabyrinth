#include "All.h"

void SCENETITLE::update()
{
	using namespace GameLib;
	using namespace input;
	switch (state)
	{
	case 0:
		timer = 0;
		GameLib::setBlendMode(Blender::BS_ALPHA);
		TITLE_MANAGER::getInstance()->init();
		state++;
		break;
	case 1:
		TITLE_MANAGER::getInstance()->update();
		break;
	}
	draw();
}

void SCENETITLE::draw()
{
	TITLE_MANAGER::getInstance()->draw();
}