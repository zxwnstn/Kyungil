#include "Obj.h"

Obj::~Obj()
{
	//includedScene->eraseObj(this);
	//collider erase in this place
}

Obj::Obj(std::shared_ptr<Scene> curScene, const POSITION & pos)
	:objPos(pos)
{
	includedScene = curScene;
}
