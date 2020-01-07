#include "Obj.h"

Obj::Obj(SCENENO _includedScene, const POSITION & pos, OBJNO _objNo)
	:objPos(pos), includedScene(_includedScene), objNo(_objNo)
{
}

Obj::~Obj()
{
}