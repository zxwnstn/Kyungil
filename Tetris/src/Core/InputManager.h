#pragma once
#include "../etc/Game.h"

class InputManager
{
//for single
public:
	static InputManager* m_pInst;
	static InputManager* GetInst();

	bool init();
	void Destroy();

private:
	InputManager();
	~InputManager();

private:
	char m_cInput;

public:
	MY_INPUT GetInput();


};

