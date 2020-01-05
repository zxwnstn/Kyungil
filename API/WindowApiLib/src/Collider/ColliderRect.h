#pragma once
#include "Collider.h"

class ColliderRect :
	public Collider
{
private:
	void setColliderBoundFromPos();

private:
	FRECT collisionFiled;

public:
	virtual void upDateCollider() override;

	ColliderRect(std::shared_ptr<Obj> obj, const POSITION& _pos, float width, float height);
	ColliderRect(std::shared_ptr<Obj> obj, const FRECT& frec);

	~ColliderRect();
};

