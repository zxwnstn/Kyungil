#include "StaticObj.h"



StaticObj::StaticObj()
{
	int state = objstate;
	state |= (int)ObjActivateNoneMove;
	objstate = (ObjState)state;
}


StaticObj::~StaticObj()
{
}
