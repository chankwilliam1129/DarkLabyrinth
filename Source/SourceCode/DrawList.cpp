#include "All.h"

using namespace std;

void DRAW_LIST::add(DRAW_OBJECT* obj)
{
	if (obj->zcode > list_max) obj->zcode = 0;
	drawlist[obj->zcode].push_back(obj);
}

bool drawlistsort(const DRAW_OBJECT* a, const DRAW_OBJECT* b) {
	if (a->drawPosition.y + a->sortDev == b->drawPosition.y + b->sortDev) return a->drawPosition.x >= b->drawPosition.x;
	return a->drawPosition.y + a->sortDev < b->drawPosition.y + b->sortDev;
}

void DRAW_LIST::draw()
{
	for (int i = 0; i < list_max; i++)
	{
		if (drawlist[i].empty())continue;

		drawlist[i].sort(drawlistsort);

		int cnt = 0;

		for (auto& it : drawlist[i])
		{
			if (i == zNoLight)GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dNormal;
			if (it->drawAlg)
			{
				it->drawAlg->draw(it);
				cnt++;
			}
		}
		drawlist[i].clear();
	}
}