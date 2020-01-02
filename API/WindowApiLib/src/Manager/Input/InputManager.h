#pragma once
#include "../../WindowApiLib/myWinApi.h"

class InputManager
{
private:
	std::bitset<KEYMAX> keyUp;
	std::bitset<KEYMAX> keyDown;

public:
	bool init();
	void release();
	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	bool isStayKeyDown(int key);
	bool isToggleKey(int key);

private:
	DECLARE_SINGLE(InputManager)

};

