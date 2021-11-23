#pragma once
#include <map>
class SOUNDLOAD : public SINGLETON <SOUNDLOAD>
{
public:
	static  std::map<std::string, int> sd;
public:
	void load();
	void unload();
};
