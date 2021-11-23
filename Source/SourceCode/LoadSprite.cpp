#include "All.h"

using namespace std;

std::map<std::string, GameLib::Sprite*> SPRITELOAD::spr;

void SPRITELOAD::load()
{
	sprite_load(&spr["Player"],				L"./Data/Images/player/player.png");
	sprite_load(&spr["PlayerAttack"],		L"./Data/Images/player/player_attack.png");
	sprite_load(&spr["PlayerHp"],			L"./Data/Images/player/player_hp.png");

	sprite_load(&spr["TitleBackground"],	L"./Data/Images/title/t_back.png");
	sprite_load(&spr["TitleFrame"],			L"./Data/Images/title/t_frame.png");
	sprite_load(&spr["TitleStart"],			L"./Data/Images/title/t_start.png");

	sprite_load(&spr["OverBackground"],		L"./Data/Images/over/o_back.png");
	sprite_load(&spr["OverGameover"],		L"./Data/Images/over/o_gameover.png");

	sprite_load(&spr["ClearBackground"],	L"./Data/Images/clear/c_back.png");
	sprite_load(&spr["ClearCharactor"],		L"./Data/Images/clear/c_char.png");
	sprite_load(&spr["ClearGameClear"],		L"./Data/Images/clear/c_gameclear.png");

	sprite_load(&spr["MenuBackground"],		L"./Data/Images/menu/m_back.png");
	sprite_load(&spr["MenuBackground2"],	L"./Data/Images/menu/menu.png");
	sprite_load(&spr["MenuBackground2"],	L"./Data/Images/menu/menu.png");
	sprite_load(&spr["MenuPlayerBack"],		L"./Data/Images/menu/p_back.png");
	sprite_load(&spr["MenuPlayerFrame"],	L"./Data/Images/menu/p_frame.png");
	sprite_load(&spr["MenuPlayerBeat"],		L"./Data/Images/menu/p_beat.png");
	sprite_load(&spr["MenuPlayerHolo"],		L"./Data/Images/menu/p_holo.png");
	sprite_load(&spr["MenuWeaponBack"],		L"./Data/Images/menu/w_back.png");
	sprite_load(&spr["MenuWeaponFrame"],	L"./Data/Images/menu/w_frame.png");
	sprite_load(&spr["MenuEquipFrame"],		L"./Data/Images/menu/w_equipframe.png");
	sprite_load(&spr["MenuWeaponGun"],		L"./Data/Images/menu/w_gun.png");
	sprite_load(&spr["MenuWeaponFrame2"],	L"./Data/Images/menu/w_frame_2.png");
	sprite_load(&spr["MenuItemFrame"],		L"./Data/Images/menu/w_itemframe.png");
	sprite_load(&spr["MenuMod"],			L"./Data/Images/menu/w_mod.png");
	sprite_load(&spr["MenuDrop"],			L"./Data/Images/menu/w_drop.png");

	sprite_load(&spr["Mod"],				L"./Data/Images/object/mod.png");

	sprite_load(&spr["Enemy1"],				L"./Data/Images/enemy/enemy.png");
	sprite_load(&spr["EnemyHp"],			L"./Data/Images/enemy/enemy_hp.png");
	sprite_load(&spr["EnemyAttack"],		L"./Data/Images/enemy/enemy_attack.png");

	sprite_load(&spr["Particle"],			L"./Data/Images/effect/partial.png");
	sprite_load(&spr["Number"],				L"./Data/Images/effect/number.png");

	sprite_load(&spr["Mouse"],				L"./Data/Images/mouse/mouse.png");

	sprite_load(&spr["Terrain"],			L"./Data/Images/terrain/terrain.png");
	sprite_load(&spr["Terrain2"],			L"./Data/Images/terrain/terrain2.png");
	sprite_load(&spr["Tree"],				L"./Data/Images/terrain/tree.png");
	sprite_load(&spr["Leaf"],				L"./Data/Images/terrain/leaf.png");
	sprite_load(&spr["Light"],				L"./Data/Images/terrain/light.png");
	sprite_load(&spr["Box"],				L"./Data/Images/terrain/box.png");
	sprite_load(&spr["Wall"],				L"./Data/Images/terrain/wall.png");
}