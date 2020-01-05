#pragma once
#include "macro.h"
enum Direction{
	eUp,
	eDown,
	eLeft,
	eRight
};


enum ObjState {
	ObjStateNone,
	ObjStateActivate				= BIT(0),
	ObjStateActivateCollider		= BIT(1),
	ObjStateActivateNoneCollider	= BIT(2),
	ObjStateActivateMove			= BIT(3),
	ObjStateActivateNoneMove		= BIT(4),
};

enum ObjType {
	ObjTypeNone,
	ObjTypePlayer					= BIT(0),
	ObjTypePlayerSkill				= BIT(1),
	ObjTypeEnemy					= BIT(2),
	ObjTypeTrap						= BIT(3),
	ObjTypeMissile					= BIT(4),
	ObjTypeGround					= BIT(5),
	ObjTypeBackGround				= BIT(6),
	ObjTypeTeam						= BIT(7),
	ObjTypeTeamSkil					= BIT(8)	
};

enum CollisionState {
	CollidSateNone,
	CollidStateStart,
	CollidStateOnGoing,
	CollidStateRelease
};

enum CollidBoundary {
	CollidBoundNone,
	CollidBoundRect,
	CollidBoundCircle,
	CollidBoundEllipse,
	CollidBoundAnother
};

enum CollisionResult {
	CollidRetNoChange,
	CollidRetAnotherEffect,
	CollidRetMoveBack,
	CollidRetdeleted
};

typedef struct _tagFRactangle {
	float left, top, right, bottom;

	_tagFRactangle()
	{}
	_tagFRactangle(float _left, float _top, float _right, float _bottom)
		: left(_left), top(_top), right(_right), bottom(_bottom)
	{}

}FRECT, *PFRECT;

typedef struct _tagPosition {
	float x, y;
	_tagPosition()
		: x(0.f), y(0.f)
	{}
	_tagPosition(float _x, float _y)
		: x(_x), y(_y)
	{}
	_tagPosition(const _tagPosition& pos)
		: x(pos.x), y(pos.y)
	{}
}POSITION, *PPOSITION;
