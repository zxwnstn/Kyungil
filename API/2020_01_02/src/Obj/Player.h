#pragma once

#include "Obj/DynamicObj.h"

class Player : public DynamicObj
{
public:
	FRECT outerLine;
	float speed;
	float gravity;

public:
	Player(float _left, float _top, float _right, float _bottom, float _speed)
		:outerLine(_left, _top, _right, _bottom), speed(_speed)
	{
		int state = objstate;
		state |= (int)ObjActivateCollider;
		objstate = (ObjState)state;
	}
	~Player();

	virtual void update(float deltaTime) override;
	virtual void render(HDC memDC) override;
	virtual void CollisionProc(CollisionState colliState) override;
};

