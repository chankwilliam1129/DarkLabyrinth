#pragma once
class SCENE
{
protected:
	int state = 0;
	int timer = 0;
	std::shared_ptr<SCENE> nextScene = {};

public:
	std::shared_ptr<SCENE> execute();

	virtual void init()
	{
		state = 0;
		timer = 0;
		nextScene = nullptr;
	};

	virtual void uninit() {};
	virtual void update() {};
	virtual void draw() {};

	void changeScene(std::shared_ptr<SCENE>scene) { nextScene = scene; }
	std::shared_ptr<SCENE> getScene() const { return nextScene; }
};
