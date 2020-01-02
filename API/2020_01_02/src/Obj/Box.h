#pragma once
#include "Obj/StaticObj.h"
class Box : public StaticObj
{
public:
	FRECT outerLine;
	float speed = 400;


public:
	FRECT& operator()() {
		return outerLine;
	}


	Box();
	~Box();
};

