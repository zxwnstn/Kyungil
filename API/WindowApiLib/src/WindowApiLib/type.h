#pragma once
#include "macro.h"
enum Direction{
	eUp,
	eDown,
	eLeft,
	eRight
};

enum CollisionState {
	CollidStart,
	CollidOnGoing,
	CollidRelease,
	CollidNone
};

enum ObjState {
	ObjnonActivate,
	ObjActivate = BIT(0),
	ObjActivateCollider = BIT(1),
	ObjActivateNoneCollider = BIT(2),
	ObjActivateMove = BIT(3),
	ObjActivateNoneMove = BIT(4)
};

typedef struct _tagFRactangle {
	float left, top, right, bottom;

	_tagFRactangle()
	{}
	_tagFRactangle(float _left, float _top, float _right, float _bottom)
		: left(_left), top(_top), right(_right), bottom(_bottom)
	{}

}FRECT, *PFRECT;

