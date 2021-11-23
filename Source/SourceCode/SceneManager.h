#pragma once
class SCENEMANAGER :public SINGLETON<SCENEMANAGER>
{
public:
	void execute(std::shared_ptr<SCENE>);
};