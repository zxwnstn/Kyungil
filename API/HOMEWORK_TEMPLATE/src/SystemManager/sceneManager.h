#pragma once
#include "stdafx.h"
#include "Scene/Scene.h"

class sceneManager {
public:
	bool init();
	void release();

public:
	void update(float deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

public:
	Scene* addScene(std::string sceneName, Scene* scene);
	bool changeScene(std::string sceneName);

private:
	typedef std::map<std::string, Scene*> mSceneList;
	typedef std::map<std::string, Scene*>::iterator miSceneList;

private:
	Scene* _currentScene;
	mSceneList _mSceneList;

private:
	DECLARE_SINGLE(sceneManager)
};

