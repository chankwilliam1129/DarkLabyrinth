#include "All.h"
using namespace std;

std::map<std::string, int> SOUNDLOAD::sd;

void SOUNDLOAD::load()
{
	GameLib::music::load(0, L"./Data/Musics/1.wav");
}
void SOUNDLOAD::unload()
{
	GameLib::music::unload(0);
}