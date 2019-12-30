#include "Core.h"
#include "../UI/Ui.h"
#include "InputManager.h"
#include "../UI/Board.h"
#include "SoundManager.h"

Core* Core::m_pInst = nullptr;

Core::Core()
{
}

Core::~Core()
{
}

Core * Core::GetInst()
{
	if (m_pInst == nullptr)
		return m_pInst = new Core;
	return m_pInst;
}

void Core::Destroy()
{
	if(m_pInst != nullptr)
		delete m_pInst;
	m_pInst = nullptr;
}

bool Core::init()
{
	m_bLoop = true;
	srand(time(NULL));
	turnCnt = 1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cCursor;
	cCursor.bVisible = 0;
	cCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &cCursor);

	if (!Ui::GetInst()->init())
		return false;
	if (!InputManager::GetInst()->init())
		return false;
	if (!SoundManager::GetInst()->init())
		return false;
	
	double temp = 0.3;
	for (int i = 0; i < 5; ++i) {		
		dropTime[i] = temp;
		temp -= 0.05;
	}

	return true;
}

int Core::run()
{
	time_t start, end;
	double result;
	MY_INPUT mInput;
	while (m_bLoop) {
		start = clock();
		SoundManager::GetInst()->play();
		while (1) {			
			mInput = InputManager::GetInst()->GetInput();
			Ui::GetInst()->Update(mInput);
			if (Ui::GetInst()->isEnd()) 
				break;
			Ui::GetInst()->Draw();
			end = clock();
			if (Board::GetInst()->settleReady && mInput != eNone) {
				start = end;
			}
			result = (end - start) / CLOCKS_PER_SEC;
			if (result > dropTime[turnCnt - 1]) {
				Board::GetInst()->Update(eDown);
				start = end;
			}
		}
		system("pause");
		system("cls");
		printf("you die");
	}
	return 1;
}
