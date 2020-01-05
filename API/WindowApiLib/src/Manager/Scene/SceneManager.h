#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Scene/Scene.h"

extern std::shared_ptr<Scene> CreateScene(HDC);

class SceneManager
{
protected:
	HWND m_hWnd;
	HDC m_hDc;

private:
	std::shared_ptr<Scene> pCurScene = nullptr;
	std::shared_ptr<Scene> pNextScene = nullptr;

private:
	void sceneChanger();

public:
	bool init(HWND, HDC);
	void update(float deltaTime);
	void render();
	std::shared_ptr<Scene> getCurScene() const { return pCurScene; }

private:
	DECLARE_SINGLE(SceneManager)
};

