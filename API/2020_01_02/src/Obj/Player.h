#pragma once

#include "Obj/DynamicObj.h"

class Player : public DynamicObj
{
public:
	FRECT outerLine;
	float pSpeed = 100;

public:
	FRECT& operator() () {
		return outerLine;
	}

	Player();
	~Player();
};

