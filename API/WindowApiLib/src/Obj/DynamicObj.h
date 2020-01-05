#pragma once
#include "Obj.h"

class DynamicObj :
	public Obj
{
protected:
	POSITION prevPos;


public:
	DynamicObj(std::shared_ptr<Scene> scene, const POSITION & pos)
		:Obj(scene, pos)
	{
		objstate = ObjStateActivateMove;
	}

	~DynamicObj() {};
};

