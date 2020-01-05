#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
	for (auto it = objs.begin(); it != objs.end();) {
		if(*it != nullptr)
			it = objs.erase(it);
	}
}


void Scene::eraseObj(Obj * obj)
{
	for (auto it = objs.begin(); it != objs.end(); ++it) {
		if ((*it) == obj) {
			delete *it;
			objs.erase(it);
			return;
		}
	}
}