#include "Player.h"



void Player::update(float deltaTime)
{
}

void Player::render(HDC memDC)
{
	DrawFRect(memDC, outerLine);
}

Player::~Player()
{
}

