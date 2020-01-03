#pragma once
enum Direction{
	eUp,
	eDown,
	eLeft,
	eRight
};

enum class CollisionState {
	eStart,
	eOnGoing,
	eRelease,
	eNone
};

typedef struct _tagFRactangle {
	float left, top, right, bottom;

	_tagFRactangle(float _left, float _top, float _right, float _bottom)
		: left(_left), top(_top), right(_right), bottom(_bottom)
	{}

}FRECT, *PFRECT;

