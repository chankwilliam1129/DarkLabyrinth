#pragma once
class MENU_MANAGER :public OBJECTMANAGER, public SINGLETON<MENU_MANAGER>
{
public:
	void init();
	void draw();
};

