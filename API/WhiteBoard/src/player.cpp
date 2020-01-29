#include "player.h"
#include <conio.h>

player::player()
{
	state = new StandingState;
}


player::~player()
{
}

void player::update()
{
	if (kbhit()) {
		char c;
		c = getch();
		switch (c)
		{
		case 'w':
			state->inputHandle(*this, 0);   //상 0
			break;
		case 's':
			state->inputHandle(*this, 1);   //하 1
			break;
		case 'a':
			state->inputHandle(*this, 2);   //좌 2
			break;
		case 'd':
			state->inputHandle(*this, 3);   //우 3
			break;
		}
	}
	else {
		state->inputHandle(*this, -1);   //입력 없음
	}
}

void player::render()
{
	state->render();
}
