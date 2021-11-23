#pragma once
class SCENECLEAR :public SCENE, public SINGLETON<SCENECLEAR>
{
public:
	void update();
	void draw();
};