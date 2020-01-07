#pragma once
#include "Collider.h"

class ColliderRect :
	public Collider
{
private:
	void setColliderBoundFromPos();
	void setColliderBoundFromDelta(float dx, float dy);

private:
	FRECT collisionFiled;

public:
	virtual void upDateCollider(float dx, float dy) override;

	ColliderRect(OBJNO obj, const POSITION& _pos, float width, float height);
	ColliderRect(OBJNO obj, const FRECT& frec);

	~ColliderRect();
};

