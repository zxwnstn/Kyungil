#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

std::vector<Obj*>* Scene::getObjs()
{
	return &objs;
}
