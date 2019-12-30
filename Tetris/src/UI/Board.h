#pragma once
#include "../etc/Game.h"
#include "../Obj/Block.h"
class Board
{
//for single
public:
	static Board* GetInst();
	static Board* m_pInst;

	void Destroy();
	bool init();

private:
	Board();
	~Board();

private:
	std::list<Block*> m_Blocks;
	int backBuffer[20][10];
	int frontBuffer[20][10];
	const short offset_width = 30;
	const short offset_height = 5;
	Block* curDown;
	POSITION ghostArr[4];

private:
	bool isRange(int, int);
	void settleBlock();
	void setBack();
	void setBackZero();
	bool isSettleDown;
	bool relocate();
	bool checkMadeLine(int);
	void deleteLine(int);
	void calcGhost();
	void setBackZeroG();
	void setBackG();
	void ghostUpdate();

public:
	void Update(MY_INPUT);
	void Draw();
	bool settleReady;
	bool m_bDye;
	bool newBlock;
};

