#include "SceneManager.h"
#include "Manager.h"

DEFINITION_SINGLE(SceneManager)


bool SceneManager::init(HWND hwnd, HDC hdc)
{
	m_hDc = hdc;
	m_hWnd = hwnd;
	createSeed = 0;

	pCurScene = CreateScene(hdc, createSeed++);

	return true;
}

void SceneManager::update(float deltaTime)
{
	pCurScene->update(deltaTime);
}

void SceneManager::lateUpdate(float deltaTime)
{
	pCurScene->lateUpdate(deltaTime);
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
	delete pCurScene;
	delete pNextScene;
}
