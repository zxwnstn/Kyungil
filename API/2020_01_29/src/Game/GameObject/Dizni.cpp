#include "Dizni.h"



Dizni::Dizni()
{
	speed = 5;
	bombLimit = 3;
	bombRange = 1;
	name = "디즈니";
	aniUp	= ANIMANAGER->findAnimation("디즈니상");
	aniDown = ANIMANAGER->findAnimation("디즈니하");
	aniLeft = ANIMANAGER->findAnimation("디즈니좌");
	aniRight= ANIMANAGER->findAnimation("디즈니우");
}


Dizni::~Dizni()
{
}

bool Dizni::init()
{
	return false;
}

void Dizni::update(float _deltaTime)
{
	Character::update(_deltaTime);
}

void Dizni::afterRender(HDC hdc)
{
}