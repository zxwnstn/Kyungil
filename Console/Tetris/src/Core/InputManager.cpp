#include "InputManager.h"

InputManager* InputManager::m_pInst = nullptr;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputManager * InputManager::GetInst()
{
	if (m_pInst == nullptr)
		return m_pInst = new InputManager;
	return m_pInst;
}

bool InputManager::init()
{
	return true;
}

void InputManager::Destroy()
{
	if (m_pInst != nullptr)
		delete m_pInst;
	m_pInst = nullptr;
}


MY_INPUT InputManager::GetInput()
{
	if (_kbhit()) {
		m_cInput = _getch(); 
		if (m_cInput == -32) {
			//NOTICE : 방향키 상 72, 하80, 좌75, 우77
			m_cInput = _getch();
			switch (m_cInput){
			case 72:
				return eUP;
			case 80:
				return eDown;
			case 75:
				return eLeft;
			case 77:
				return eRight;
			default:
				return eNone;
			}
		}
		else {
			switch (m_cInput){
			case 'p':
				return eStop;
			case ' ':
				return eSpace;
			}
		}
	}
	return eNone;
}
