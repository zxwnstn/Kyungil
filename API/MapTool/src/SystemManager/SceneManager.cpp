#include "stdafx.h"
#include "sceneManager.h"
DEFINITION_SINGLE(SceneManager)

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

bool SceneManager::init()
{
	_currentScene = nullptr;
	return true;
}

void SceneManager::release()
{
	for (auto iter = _mSceneList.begin(); iter != _mSceneList.end(); ) {
		if (iter->second != nullptr){
			if (iter->second == _currentScene)
				iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mSceneList.erase(iter);
		}
		else iter++;
	}
	_mSceneList.clear();
}

void SceneManager::update(float deltaTime)
{
	if (_currentScene)
		_currentScene->update(deltaTime);
}

void SceneManager::render(HDC hdc)
{
	if (_currentScene)
		_currentScene->render(hdc);
}

void SceneManager::afterRender(HDC hdc)
{
	if (_currentScene)
		_currentScene->afterRender(hdc);
}

void SceneManager::debugRender(HDC hdc)
{
	if (_currentScene)
		_currentScene->debugRender(hdc);
}

Scene * SceneManager::addScene(std::string sceneName, Scene* scene) {
	
	if(!scene) 
		return nullptr;
	
	_mSceneList.insert(make_pair(sceneName, scene));
	return scene;
}

bool SceneManager::changeScene(std::string sceneName)
{
	miSceneList find = _mSceneList.find(sceneName);

	//못찾으면 E_FAIL
	if (find == _mSceneList.end())
		return false;

	//바꾸려는씬이 현재씬이랑 같아도 E_FAIL
	if (find->second == _currentScene)
		return false;

	//여기까지 왔다면 문제가 없다 즉 씬을 초기화하고 변경하자.
	if (SUCCEEDED(find->second->init()))
	{
		//혹시 기존에 씬이 있다면 릴리즈
		if (_currentScene)_currentScene->release();

		_currentScene = find->second;
		return S_OK;
	}

	return false;
}
