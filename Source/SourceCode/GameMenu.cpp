#include "All.h"

void MENU_MANAGER::init()
{
	OBJECTMANAGER::init();
	name = "MenuManager";
	add(&menuBackground, VECTOR2(0, 0));

	/*for (int i = 0; i < 10; i++)
	{
		if (i < 3)add(&equipMod, VECTOR2(1000.0f, 200.0f))->iWork[EQUIPMOD::mNum] = i;
		add(&itemMod, VECTOR2(100.0f, 700.0f))->iWork[ITEMMOD::mNum] = i;
	}*/
}

void MENU_MANAGER::draw()
{
	for (auto& it : objectList)
	{
		it->draw();
	}
}