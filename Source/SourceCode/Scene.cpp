#include "All.h"

using namespace std;

shared_ptr<SCENE> SCENE::execute()
{
	using namespace GameLib;
	using namespace input;

	init();
	MOUSE::getInstance()->init();

	while (GameLib::gameLoop(false))
	{
		MOUSE::getInstance()->isDraw = true;
		input::update();
		update();
		GameLib::clear(VECTOR4(121.0f/255.0f, 103.0f / 255.0f, 85.0f / 255.0f, 1.0f));
		draw();
		DRAW_LIST::getInstance()->draw();
		MOUSE::getInstance()->draw();
		GameLib::present(1, 0);
		if (nextScene) { break; }
	}
	uninit();
	return nextScene;
}