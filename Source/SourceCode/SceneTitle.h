#pragma once

class SCENETITLE :public SCENE, public SINGLETON<SCENETITLE>
{
public:
	void update();
	void draw();
};