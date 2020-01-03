#pragma once
#include "Obj/DynamicObj.h"
class Box : public DynamicObj
{
private:
	FRECT outerLine;
	float speed;

public:
	Box(float left, float top, float right, float bottom, float _speed)
		: outerLine(left, top, right, bottom), speed(_speed)
	{
		outerLine = colliderRect;
	}
	~Box();

	virtual void update(float deltaTime) override;
	virtual void render(HDC memDC) override;

};

