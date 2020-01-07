#pragma once
#include "Obj.h"

class DynamicObj :
	public Obj
{
protected:
	POSITION prevPos;
	float	 dx;
	float	 dy;

public:
	DynamicObj(SCENENO _includedScene, const POSITION & pos, OBJNO _objNo)
		:Obj(_includedScene, pos, _objNo)
	{
		objstate = ObjStateActivateMove;
		prevPos = pos;
	}

	~DynamicObj() {};
};

