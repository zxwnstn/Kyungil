#include "Dao.h"



Dao::Dao()
{
	speed = 3;
	bombLimit = 1;
	bombRange = 2;
	name = "다오";
	aniUp	= ANIMANAGER->findAnimation("다오상");
	aniDown = ANIMANAGER->findAnimation("다오하");
	aniLeft = ANIMANAGER->findAnimation("다오좌");
	aniRight= ANIMANAGER->findAnimation("다오우");
}


Dao::~Dao()
{
}

bool Dao::init()
{
	return false;
}

void Dao::update(float _deltaTime)
{
	Character::update(_deltaTime);
}

void Dao::afterRender(HDC hdc)
{
}

