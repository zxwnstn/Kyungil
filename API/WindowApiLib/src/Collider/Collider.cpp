#include "Collider.h"

Collider::Collider(OBJNO obj, const POSITION & _collidPosition)
	: includedObj(obj), collidPosition(_collidPosition)
{
}

Collider::~Collider()
{
}
