#include "Scene.h"



Scene::Scene(SCENENO _sceneNo)
	:sceneNo(_sceneNo)
{
}


Scene::~Scene()
{
	for (auto it = objs.begin(); it != objs.end();) {
		it = objs.erase(it);
	}
}


void Scene::eraseObj(std::shared_ptr<Obj> obj)
{
	for (auto it = objs.begin(); it != objs.end(); ++it) {
		if ((*it) == obj) {
			objs.erase(it);
			return;
		}
	}
}