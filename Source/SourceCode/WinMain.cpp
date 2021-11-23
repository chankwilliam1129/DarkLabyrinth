#include "All.h"

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	SCENEMANAGER::getInstance()->execute(SCENETITLE::getInstance());
	return 0;
}