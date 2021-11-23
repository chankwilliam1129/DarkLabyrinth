#pragma once
#include <map>

class SPRITELOAD : public SINGLETON <SPRITELOAD>
{
public:
	static  std::map<std::string, GameLib::Sprite*> spr;
public:
	void load();
};