#pragma once
#include "../etc/Game.h"

class Ui
{
public:
	static Ui* GetInst();
	static Ui* m_pInst;

	bool init();
	void Destroy();

private:
	Ui();
	~Ui();

public:
	void Update(MY_INPUT);
	void Draw();
	bool isEnd();

};

