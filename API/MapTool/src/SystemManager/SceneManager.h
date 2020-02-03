#pragma once
#include "Game/GameScene/Scene.h"

class SceneManager {
public:
	bool init();
	void release();

public:
	void update(float deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

public:
	class Scene* addScene(std::string sceneName, Scene* scene);
	bool changeScene(std::string sceneName);
	Scene* getCurScene() { return _currentScene; }

private:
	typedef std::map<std::string, Scene*> mSceneList;
	typedef std::map<std::string, Scene*>::iterator miSceneList;

private:
	Scene* _currentScene = nullptr;
	mSceneList _mSceneList;

private:
	DECLARE_SINGLE(SceneManager)
};

#define SCENEMANAGER SceneManager::GetInst()