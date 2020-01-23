#pragma once
#include "stdafx.h"
#include <bitset>
#define KEYMAX 256

class keyManager {
public:
	HRESULT init();
	void release();

public:
	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	bool isStayKeyDown(int key);
	bool isToggleKey(int key);

public:
	void setCustomKey(int dest, int userKey);

private:
	std::bitset<KEYMAX> _keyUp;
	std::bitset<KEYMAX> _keyDown;

	BYTE playerKey[KEYMAX];

private:
	DECLARE_SINGLE(keyManager)
};

