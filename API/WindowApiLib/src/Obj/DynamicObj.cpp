#include "DynamicObj.h"



DynamicObj::DynamicObj()
{
	int state = objstate;
	state |= (int)ObjActivateMove;
	objstate = (ObjState)state;
}


DynamicObj::~DynamicObj()
{
}
