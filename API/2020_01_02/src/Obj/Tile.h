#pragma once
#include "Obj/StaticObj.h"
#include "Collider/ColliderRect.h"

class Tile : public StaticObj
{
private:
	FRECT outerLine;

public:
	Tile(Scene* scene, const FRECT& fRect);
	~Tile();

	virtual void update(float deltaTime) override;
	virtual void render(HDC memDC) override;
	virtual CollisionResult CollisionProc() override;
};
