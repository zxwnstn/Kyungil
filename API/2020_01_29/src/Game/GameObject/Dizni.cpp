#include "Dizni.h"



Dizni::Dizni()
{
	speed = 5;
	bombLimit = 3;
	bombRange = 1;
	name = "�����";
	aniUp	= ANIMANAGER->findAnimation("����ϻ�");
	aniDown = ANIMANAGER->findAnimation("�������");
	aniLeft = ANIMANAGER->findAnimation("�������");
	aniRight= ANIMANAGER->findAnimation("����Ͽ�");
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