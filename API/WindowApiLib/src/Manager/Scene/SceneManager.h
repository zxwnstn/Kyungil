#pragma once
#include "../../WindowApiLib/myWinApi.h"
#include "../../Scene/Scene.h"

class SceneManager
{
protected:
	HWND m_hWnd;
	HDC m_hDc;

private:
	Scene* pCurScene = nullptr;
	Scene* pNextScene = nullptr;
	
private:
	template<class T>
	Scene* CreateScene() {
		return new T;
	}
	void sceneChanger();

public:
	bool init(HWND, HDC);
	void update(float deltaTime);
	void render();

private:
	DECLARE_SINGLE(SceneManager)
};

