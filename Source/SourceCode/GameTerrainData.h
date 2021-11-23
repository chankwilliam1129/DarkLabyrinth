#pragma once

class MAPLOAD : public SINGLETON <MAPLOAD>
{
public:
	int map[64][64] = {};
public:
	void load();
};