#pragma once
#include "state.h"

class player
{
private:
	HeroState* state;
	
public:
	player();
	~player();

	void update();
	void render();
};

