#include "All.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

void MAPLOAD::load()
{
	std::ifstream inputFile("./Data/Maps/map.csv");
	if (inputFile.fail())
	{
		assert(0 && "LOAD_MAP_FAILED");
	}
	unsigned int x = 0;
	unsigned int y = 0;
	std::string output;

	while (std::getline(inputFile, output))
	{
		std::istringstream iss(output);
		x = 0;
		while (std::getline(iss, output, ','))
		{
			assert(y < 64);
			assert(x < 64);
			map[y][x] = stoi(output);
			x++;
		}
		y++;
	}
}
