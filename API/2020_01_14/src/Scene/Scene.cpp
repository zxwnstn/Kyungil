#include "Scene.h"


HRESULT Scene::init()
{
	IMAGEMANAGER->addImage("���", "../Common_Images/�糪.bmp", WINSIZEX, WINSIZEY);
	return S_OK;
}

void Scene::release()
{
	//IMAGEMANAGER->deleteImage("���");
}

void Scene::update(float deltaTime)
{
	
}

void Scene::render()
{
	IMAGEMANAGER->render("���", getMemDC());
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
