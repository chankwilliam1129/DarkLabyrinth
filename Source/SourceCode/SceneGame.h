#pragma once

class SCENEGAME :public SCENE, public SINGLETON<SCENEGAME>
{
private:
	enum GAMESTATE
	{

		MAIN_START,
		MAIN_UPDATE,
		MENU_START,
		MENU_UPDATE,
		MENU_END,
		MOD_START,
		MOD_UPDATE,
		MOD_END,
		TOTAL,
	};

public:
	int mainTimer = 0;
	int menuTimer = 0;

	MOD* modTarget1 = NULL;
	MOD* modTarget2 = NULL;

	GAME_OBJECT* nearGold = {};
public:
	void init();
	void update();
	void draw();
	void uninit() {};

	void menuModChange();
	void lightUpdate();
	void goldSoundUpdate();
private:
	void mainStart();
	void mainUpdate();
	void menuStart();
	void menuUpdate();
	void menuEnd();
	void modStart();
	void modUpdate();
	void modEnd();

	void(SCENEGAME::* GameStateUpdate[GAMESTATE::TOTAL])() =
	{
		&SCENEGAME::mainStart,
		&SCENEGAME::mainUpdate,
		&SCENEGAME::menuStart,
		&SCENEGAME::menuUpdate,
		&SCENEGAME::menuEnd,
		&SCENEGAME::modStart,
		&SCENEGAME::modUpdate,
		&SCENEGAME::modEnd,
	};

private:
	bool isPaused;
};