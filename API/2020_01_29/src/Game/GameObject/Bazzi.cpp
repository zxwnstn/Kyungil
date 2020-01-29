#include "Bazzi.h"



Bazzi::Bazzi()
{
	speed = 2;
	bombLimit = 2;
	bombRange = 1;
	name = "น่ย๎";
	aniUp =		ANIMANAGER->findAnimation("น่ย๎ป๓");
	aniDown =	ANIMANAGER->findAnimation("น่ย๎วฯ");
	aniLeft =	ANIMANAGER->findAnimation("น่ย๎มย");
	aniRight =	ANIMANAGER->findAnimation("น่ย๎ฟ์");
	img = IMAGEMANAGER->findImage("น่ย๎ป๓");
}


Bazzi::~Bazzi()
{
}

bool Bazzi::init()
{
	return false;
}

void Bazzi::update(float _deltaTime)
{
	Character::update(_deltaTime);
}

void Bazzi::afterRender(HDC hdc)
{
}