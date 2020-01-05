#include "Obj.h"

Obj::~Obj()
{
	//includedScene->eraseObj(this);
	//collider erase in this place
	SAFE_DELETE(collider);
}

Obj::Obj(Scene * curScene, const POSITION & pos)
	:objPos(pos)
{
	includedScene = curScene;
}
