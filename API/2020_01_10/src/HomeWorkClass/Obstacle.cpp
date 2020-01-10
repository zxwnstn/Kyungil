#include "Obstacle.h"



Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

void Obstacle::update(float deltaTime, PlayerState pState)
{
}

void Obstacle::firstRender()
{
}

void Obstacle::secondRender()
{
}

void Obstacle::init(HDC hdc)
{
	memDC = hdc;
	//frontRing = new Image;
	//TODO : adjust image size!
	//frontRing->init("images/frontRing", 0, 0, true, RGB(255, 0, 255));
	//backRing->init("images/backRing", 0, 0, true, RGB(255, 0, 255));
	//incense->init("images/incense", 0, 0, true, RGB(255, 0, 255));
}

void Obstacle::render()
{
}

void Obstacle::release()
{
	//SAFE_DELETE(frontRing);
	//SAFE_DELETE(backRing);
	//SAFE_DELETE(incense);
}
