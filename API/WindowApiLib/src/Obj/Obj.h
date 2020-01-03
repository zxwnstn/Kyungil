#pragma once
#include "WindowApiLib/type.h"
#include "WindowApiLib/myWinApi.h"
#include "Collider/Collider.h"

class Obj
{
protected:
	Collider* collider;

public:
	virtual void render(HDC) = 0;
	virtual void update(float) = 0;

public:
	Obj();
	virtual ~Obj();
	bool life = true;
};

