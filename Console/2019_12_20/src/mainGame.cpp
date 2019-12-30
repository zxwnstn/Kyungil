#include "mainGame.h"

void mainGame::run()
{
	while (!m_Board->isEnd()) {
		m_Board->render();
		getInput();
		m_Board->update(input);
		system("cls");
	}
}

void mainGame::init()
{
	m_Board = new Board;
	m_Board->init();
}

void mainGame::getInput()
{
	char tempIn;
	std::cin >> tempIn;
	switch (tempIn){
	case '8':
		input = eUp;
		return;
	case '2':
		input = eDown;
		return;
	case '4':
		input = eLeft;
		return;
	case '6':
		input = eRight;
		return;
	case 'i':
		input = eInventory;
		return;
	case 'a':
		input = eCharacror;
		return;
	case '0':
		input = eExit;
		return;
	}
	input = eNone;
}



mainGame::mainGame()
{
}

mainGame::~mainGame()
{
	delete m_Board;
}