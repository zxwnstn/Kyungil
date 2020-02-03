#include "stdafx.h"
#include "keyManager.h"
DEFINITION_SINGLE(KeyManager)

KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

HRESULT KeyManager::init()
{
	//Ű�� ���� �������� ���� ���·� �ʱ�ȭ����
	for (int i = 0; i < KEYMAX; i++){
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}

	playerKey[P1_UP] = VK_UP;
	playerKey[P1_DOWN] = VK_DOWN;
	playerKey[P1_LEFT] = VK_LEFT;
	playerKey[P1_RIGHT] = VK_RIGHT;
	playerKey[P1_EVENT] = VK_SPACE;
	playerKey[P1_USEITEM] = VK_TAB;

	playerKey[GAME_SHOWFPS] = VK_F1;
	playerKey[GAME_RECTMODE] = VK_F2;
	playerKey[GAME_DEBUGMODE] = VK_F3;
	playerKey[GAME_RTT] = VK_F4;
	playerKey[GAME_LMOUSE] = VK_LBUTTON;
	playerKey[GAME_RMOUSE] = VK_RBUTTON;

	return S_OK;
}

void KeyManager::release()
{
}

bool KeyManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState���� Ű�� ���¸� �˾ƿ��� �༮
	//Ű�� ������������ ���������� ȣ��
	//0x8000 �������� �������� ���� ȣ��������� ��������
	if (GetAsyncKeyState(playerKey[key]) & 0x8000) {
		if (!_keyDown[playerKey[key]]) {
			_keyDown.set(playerKey[key], true);
			return true;
		}
	}
	else _keyDown.set(playerKey[key], false);
	return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		_keyUp.set(playerKey[key],true);
	else {
		if (_keyUp[playerKey[key]]){
			_keyUp.set(playerKey[key], false);
			return true;
		}
	}
	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(playerKey[key]) & 0x8000)
		return true;
	return false;
}

bool KeyManager::isToggleKey(int key)
{

	//GetKeyState :���� Ű�� ��ۻ���
	//0x0001������ �������� �ְ� ȣ��������� �ȴ��� ����
	if (GetKeyState(playerKey[key]) & 0x0001)
		return true;
	return false;
}

void KeyManager::setCustomKey(int dest, int userKey)
{
	playerKey[dest] = userKey;
}
