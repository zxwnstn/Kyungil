#include "Box.h"


void Box::update(float deltaTime)
{
	MoveFRect(outerLine, eDown, speed * deltaTime);
	if (outerLine.bottom > WINSIZEY)
		life = false;
}

void Box::render(HDC memDC)
{
	DrawFRect(memDC, outerLine);
}

Box::~Box() 
{
}
