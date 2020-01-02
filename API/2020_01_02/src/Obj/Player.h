#pragma once

#include "Obj/DynamicObj.h"

class Player : public DynamicObj
{
public:
	FRECT outerLine;
	float pSpeed = 40;

public:
	FRECT& operator() () {
		return outerLine;
	}

	Player();
	~Player();
};

