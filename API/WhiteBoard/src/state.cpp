#include "state.h"
#include <iostream>
int HeroState::directionPoint = true;

void DuckingState::inputHandle(player & p, int input)
{
}

void DuckingState::update(player & p)
{
}

void DuckingState::render()
{
}

void StandingState::inputHandle(player & p, int input)
{
}

void StandingState::update(player & p)
{
}

void StandingState::render()
{
	std::cout << "플레이어가" << direction[directionPoint] << "으로 서있습니다" << std::endl;
}

void JumpingState::inputHandle(player & p, int input)
{
}

void JumpingState::update(player & p)
{
}

void JumpingState::render()
{
}

HeroState::HeroState()
{

}

HeroState::~HeroState()
{

}
