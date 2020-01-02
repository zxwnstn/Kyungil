#include "SceneManager.h"
#include "../Input/InputManager.h"

DEFINITION_SINGLE(SceneManager)


bool SceneManager::init(HWND hwnd, HDC hdc)
{
	m_hDc = hdc;
	m_hWnd = hwnd;

	pCurScene = CreateScene();

	return true;
}

void SceneManager::update(float deltaTime)
{
	pCurScene->update(deltaTime);
}

void SceneManager::render()
{
	pCurScene->render(m_hDc);
}

void SceneManager::sceneChanger()
{
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	SAFE_DELETE(pCurScene);
	SAFE_DELETE(pNextScene);
}
