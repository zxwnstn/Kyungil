#include "Collider.h"

Collider::Collider(std::shared_ptr<Obj> obj, const POSITION & _collidPosition)
	: includedObj(obj), collidPosition(_collidPosition)
{
}

Collider::~Collider()
{
}
