#pragma once
#include "Obj.h"
class StaticObj :
	public Obj
{
public:
	StaticObj(Scene * curScene, const POSITION& pos)
		:Obj(curScene, pos)
	{
		objstate = ObjStateActivateNoneMove;
	}

	~StaticObj() {};
};

