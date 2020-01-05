#pragma once
#include "Obj.h"
class StaticObj :
	public Obj
{
public:
	StaticObj(std::shared_ptr<Scene> curScene, const POSITION& pos)
		:Obj(curScene, pos)
	{
		objstate = ObjStateActivateNoneMove;
	}

	~StaticObj() {};
};

