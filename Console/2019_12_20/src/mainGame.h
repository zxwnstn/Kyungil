#pragma once
#include "Board.h"
#include <iostream>
#include "type.h"
using namespace std;

class mainGame
{
private:
	Board*		m_Board;
	Input		input;

private:
	void		getInput();

public:
	void		run();
	void		init();
	
public:
	mainGame();
	~mainGame();
};

