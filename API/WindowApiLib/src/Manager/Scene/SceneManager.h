#pragma once
#include "WindowApiLib/myWinApi.h"
#include "Scene/Scene.h"

extern Scene* CreateScene(HDC, SCENENO);

class SceneManager
{
protected:
	HWND	m_hWnd;
	HDC		m_hDc;
	SCENENO createSeed;

private:
	Scene* pCurScene = nullptr;
	Scene* pNextScene = nullptr;

private:
	void sceneChanger();

public:
	bool init(HWND, HDC);
	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	void render();
	Scene* getCurScene() const { return pCurScene; }

private:
	DECLARE_SINGLE(SceneManager)
};

