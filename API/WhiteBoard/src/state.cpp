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
	std::cout << "�÷��̾" << direction[directionPoint] << "���� ���ֽ��ϴ�" << std::endl;
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
