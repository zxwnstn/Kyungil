#include "Bazzi.h"



Bazzi::Bazzi()
{
	speed = 2;
	bombLimit = 2;
	bombRange = 1;
	name = "����";
	aniUp =		ANIMANAGER->findAnimation("�����");
	aniDown =	ANIMANAGER->findAnimation("������");
	aniLeft =	ANIMANAGER->findAnimation("������");
	aniRight =	ANIMANAGER->findAnimation("�����");
	img = IMAGEMANAGER->findImage("�����");
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