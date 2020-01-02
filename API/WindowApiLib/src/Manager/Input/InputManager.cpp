#include "InputManager.h"
DEFINITION_SINGLE(InputManager)



bool InputManager::init()
{
	// 키가 전부 눌려있지 않은 상태로 초기화한다.
	for (int i = 0; i < KEYMAX; i++) {
		keyUp.set(i, false);
		keyDown.set(i, false);
	}
	return true;
}

void InputManager::release()
{
}

bool InputManager::isOnceKeyDown(int key)
{
	// 0x8000: 이전에는 누른적이 없고 호출시점에서 누른 상태
	if (GetAsyncKeyState(key) & 0x8000) {
		if (!keyDown[key]) {
			keyDown.set(key, true);
			return true;
		}
	}
	else
		keyDown.set(key, false);
	return false;
}

bool InputManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		keyUp.set(key, true);
	else if (keyUp[key]) {
		keyUp.set(key, false);
		return true;
	}
	return false;
}

bool InputManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool InputManager::isToggleKey(int key)
{
	// GetKeyState: 현재 키의 토글상태
	// 0x0001: 이전에 누른 적이 있고 호출시점에서 누른 상태
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}
