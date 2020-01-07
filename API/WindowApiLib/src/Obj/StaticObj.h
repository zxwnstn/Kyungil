#pragma once
#include "Obj.h"
class StaticObj :
	public Obj
{
public:
	StaticObj(SCENENO _includedScene, const POSITION& pos, OBJNO _objNo)
		:Obj(_includedScene, pos, _objNo)
	{
		objstate = ObjStateActivateNoneMove;
	}

	~StaticObj() {};
};

