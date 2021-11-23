#include "All.h"

void SCENEMANAGER::execute(std::shared_ptr<SCENE> scene)
{
	using namespace GameLib;

	bool isFullScreen = true;
	GameLib::init(L"Dark Labyrinth",
		static_cast<int>(system::SCREEN_WIDTH),
		static_cast<int>(system::SCREEN_HEIGHT),
		isFullScreen,60.0);

	ShowCursor(false);
	GameLib::sound::load(L"./Data/Sounds/sounds.xwb");
	SOUNDLOAD::getInstance()->load();
	SPRITELOAD::getInstance()->load();
	while (scene)
	{
		scene = scene->execute();
	}
	SOUNDLOAD::getInstance()->unload();
	GameLib::uninit();
}