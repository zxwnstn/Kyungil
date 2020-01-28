#include "Coddaczi.h"


Coddaczi::Coddaczi(int x, int y)
{
	rect = UTIL::RectMakeCenter(x, y, 8, 8);
}

Coddaczi::~Coddaczi()
{
}

bool Coddaczi::init()
{
	return false;
}

void Coddaczi::update(float _deltaTime)
{
}

void Coddaczi::render(HDC hdc)
{
	UTIL::DrawColorRect(hdc, rect, RGB(255, 255, 0));
}

void Coddaczi::afterRender(HDC hdc)
{
}

void Coddaczi::debugRender(HDC hdc)
{
}
