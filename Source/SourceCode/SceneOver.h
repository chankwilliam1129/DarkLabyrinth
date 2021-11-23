#pragma once

class SCENEOVER :public SCENE, public SINGLETON<SCENEOVER>
{
public:
	void update();
	void draw();
};