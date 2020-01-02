#include "InputManager.h"
DEFINITION_SINGLE(InputManager)



bool InputManager::init()
{
	// Ű�� ���� �������� ���� ���·� �ʱ�ȭ�Ѵ�.
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
	// 0x8000: �������� �������� ���� ȣ��������� ���� ����
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
	// GetKeyState: ���� Ű�� ��ۻ���
	// 0x0001: ������ ���� ���� �ְ� ȣ��������� ���� ����
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}
