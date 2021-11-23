#include "All.h"

void SCENEGAME::init()
{
	using namespace GameLib;
	SCENE::init();
	PLAYER_MANAGER::getInstance()->init();
	ENEMY_MANAGER::getInstance()->init();
	EFFECT_MANAGER::getInstance()->init();
	TERRAIN_MANAGER::getInstance()->init();
	MENU_MANAGER::getInstance()->init();
	modTarget1 = NULL;
	modTarget2 = NULL;
	nearGold = {};
	isPaused = false;
	GameLib::music::play(0, true);
}

void SCENEGAME::goldSoundUpdate()
{
	if (PL->obj && nearGold)
	{
		VECTOR2 vec = NorVector(nearGold->position, PL->obj->position);
		vec = rotate(vec, CAMERA::getInstance()->angle);
		GameLib::music::setPan(0, vec.x);

		float volume = Length(nearGold->position, PL->obj->position);
		volume = (3500.0f - volume) / 3500.0f;
		volume = (std::max)((std::min)(volume, 1.0f), 0.1f);
		GameLib::music::setVolume(0, volume);
	}
}

void SCENEGAME::update()
{
	using namespace GameLib;
	(this->*GameStateUpdate[state])();
	CAMERA::getInstance()->update();
	timer++;
}

void SCENEGAME::draw()
{

}

void SCENEGAME::lightUpdate()
{
	GameLib::Sprite::cb.light_count = 0;

	for (auto& it : PLAYER_MANAGER::getInstance()->objectList)
	{
		if (it->type == GAME_OBJECT::tPLAYER)
		{
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y + it->height * CAMERA::getInstance()->magnification, 200.0f, 1.0f);
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
			GameLib::Sprite::cb.light_count++;
		}
		else if (it->type == GAME_OBJECT::tPLAYER_ATTACK)
		{
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y + it->height * CAMERA::getInstance()->magnification, 200.0f, it->color.w);
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
			GameLib::Sprite::cb.light_count++;
		}
	}
	for (auto& it : TERRAIN_MANAGER::getInstance()->objectList)
	{
		if (it->type == GAME_OBJECT::tWALL_LIGHT)
		{
			if (Length(it->position, PL->obj->position) < 1000.0f)
			{
				GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y - it->height * CAMERA::getInstance()->magnification, 50.0f, 0.2f);
				GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
				GameLib::Sprite::cb.light_count++;
			}
		}
		else if (it->type == GAME_OBJECT::tLIGHT)
		{
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y - it->height * CAMERA::getInstance()->magnification, -100.0f, it->color.w * 1.0f);
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
			GameLib::Sprite::cb.light_count++;

			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y, 0.0f, it->color.w * 3.0f);
			GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
			GameLib::Sprite::cb.light_count++;
		}
	}

	for (auto& it : ENEMY_MANAGER::getInstance()->objectList)
	{
		if (it->type == GAME_OBJECT::tENEMY)
		{
			if (it->iWork[ENEMY::eInjury] >10 && Length(it->position, PL->obj->position) < 1000.0f)
			{
				float light = it->iWork[ENEMY::eInjury] / 50.0f;
				GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count] = VECTOR4(it->drawPosition.x, it->drawPosition.y - it->height * CAMERA::getInstance()->magnification, 50.0f, light*0.2f);
				GameLib::Sprite::cb.light[GameLib::Sprite::cb.light_count].y *= 1920.0f / 1080.0f;
				GameLib::Sprite::cb.light_count++;
			}
		}
	}

}

void SCENEGAME::mainStart()
{
	using namespace GameLib;
	mainTimer = 0;

	state = GAMESTATE::MAIN_UPDATE;
}

void SCENEGAME::mainUpdate()
{
	using namespace GameLib;
	using namespace input;

	if (CLICK_ENTER)
	{
		state = MENU_START;
		return;
	}

	nearGold = {};

	ENEMY_MANAGER::getInstance()->update();
	PLAYER_MANAGER::getInstance()->update();
	TERRAIN_MANAGER::getInstance()->update();
	EFFECT_MANAGER::getInstance()->update();
	MOUSE::getInstance()->update();

	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dLight;

	PLAYER_MANAGER::getInstance()->draw();
	ENEMY_MANAGER::getInstance()->draw();
	TERRAIN_MANAGER::getInstance()->draw();
	EFFECT_MANAGER::getInstance()->draw();

	lightUpdate();
	goldSoundUpdate();
	if (PL->goldGet == PL->goldTotal)
	{
		changeScene(SCENECLEAR::getInstance());
	}
}

void SCENEGAME::menuStart()
{
	using namespace GameLib;
	menuTimer = 0;
	state = GAMESTATE::MENU_UPDATE;
	modTarget1 = NULL;
	modTarget2 = NULL;
	GameLib::sound::play(15);
}

void SCENEGAME::menuUpdate()
{
	using namespace GameLib;
	using namespace input;
	if (CLICK_ENTER)
	{
		state = MENU_END;
		return;
	}
	MENU_MANAGER::getInstance()->update();
	menuModChange();
	if (!modTarget1) modTarget2 = NULL;
	if (OUT_MOUSE_LEFT)
	{
		modTarget1 = NULL;
		modTarget2 = NULL;
	}
	GameLib::Sprite::pixelType = GameLib::Sprite::PixelType::dNormal;
	MENU_MANAGER::getInstance()->draw();

}

void SCENEGAME::menuModChange()
{
	if (!modTarget1 || !modTarget2) return;
	if (modTarget1 == modTarget2)return;
	
	MOD temp;
	temp.level = modTarget1->level;
	temp.type = modTarget1->type;

	modTarget1->level = modTarget2->level;
	modTarget1->type = modTarget2->type;

	modTarget2->level =temp.level;
	modTarget2->type = temp.type;

	modTarget1 = NULL;
	modTarget2 = NULL;

	GameLib::sound::play(9);
}

void SCENEGAME::menuEnd()
{
	using namespace GameLib;
	state = GAMESTATE::MAIN_UPDATE;
	MOUSE::getInstance()->resetPos();
	modTarget1 = NULL;
	modTarget2 = NULL;
	GameLib::sound::play(16);
}

void SCENEGAME::modStart()
{
	using namespace GameLib;
	state = GAMESTATE::MOD_UPDATE;
}

void SCENEGAME::modUpdate()
{
	using namespace GameLib;
	using namespace input;
	if (CLICK_MOUSE_LEFT)
	{
		state = MENU_UPDATE;
		return;
	}
}

void SCENEGAME::modEnd()
{
	using namespace GameLib;
	state = GAMESTATE::MENU_UPDATE;
}