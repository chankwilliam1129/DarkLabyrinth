#pragma once
class DRAW_LIST : public SINGLETON<DRAW_LIST>
{
public:
	enum zcode
	{
		zBackground,
		zTerrain,
		zShadow,
		zObject,
		zEffect,
		zNoLight,
		zMenuBackground,
		zMenuObject,
		z8,
		z9,
		zTotal,
	};
private:
	static const int list_max = zTotal;
	std::list<DRAW_OBJECT*> drawlist[list_max];

public:
	void add(DRAW_OBJECT* obj);
	void draw();
};