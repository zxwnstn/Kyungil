#include "Dao.h"



Dao::Dao()
{
	speed = 3;
	bombLimit = 1;
	bombRange = 2;
	name = "�ٿ�";
	aniUp	= ANIMANAGER->findAnimation("�ٿ���");
	aniDown = ANIMANAGER->findAnimation("�ٿ���");
	aniLeft = ANIMANAGER->findAnimation("�ٿ���");
	aniRight= ANIMANAGER->findAnimation("�ٿ���");
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

