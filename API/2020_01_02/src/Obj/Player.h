#pragma once

#include "Obj/DynamicObj.h"

class Player : public DynamicObj
{
public:
	FRECT outerLine;
	float speed;
	float gravity;

public:
	FRECT& operator() () {
		return outerLine;
	}

	Player();
	~Player();
};

