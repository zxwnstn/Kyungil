#pragma once
#include "../etc/Game.h"

class GeneralUi
{
//for single
public:
	static GeneralUi* m_pInst;
	static GeneralUi* GetInst();

	bool init();
	void Destroy();

private:
	GeneralUi();
	~GeneralUi();

private:
	char backBuffer[200][200];
	char frontBuffer[200][200];

public:
	void Update();
	void Draw();

};

