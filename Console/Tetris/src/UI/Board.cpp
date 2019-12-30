#include "Board.h"
#include "../Core/SoundManager.h"
Board* Board::m_pInst = nullptr;

Board::Board()
{
}

Board::~Board()
{
}

Board * Board::GetInst()
{
	if (m_pInst == nullptr)
		return m_pInst = new Board;
	return m_pInst;
}

void Board::Destroy()
{
	if (m_pInst != nullptr)
		delete m_pInst;
}

bool Board::init()
{
	for (int i = 0; i < 3; ++i)
		m_Blocks.push_back(new Block);

	memset(backBuffer, 0, sizeof(backBuffer));
	memset(frontBuffer, 0, sizeof(frontBuffer));

	curDown = *m_Blocks.begin();
	isSettleDown = false;
	m_bDye = false;

	setBack();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	newBlock = true;
	calcGhost();
	setBackG();

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			setCursorPos(short(j) * 2 + offset_width, short(i) + offset_height, hConsole);
			if (backBuffer[i][j] == 0)
				printf("  ");
			else if (backBuffer[i][j] == 1)
				printf("▩");
			else if (backBuffer[i][j] == 2)
				printf("■");
			else if (backBuffer[i][j] == 3)
				printf("□");
		}
	}
	return true;
}

void Board::settleBlock()
{
	setBackZero();
	while (isRange(0, 1)) {
		curDown->moveDown();
	}
	for (int i = 0; i < 4; ++i)
		backBuffer[curDown->m_posArr[i].y][curDown->m_posArr[i].x] = 1;

	m_Blocks.push_back(new Block);
	delete *m_Blocks.begin();
	m_Blocks.pop_front();
	isSettleDown = true;

	curDown = *m_Blocks.begin();

	//종료 검사
	for (int i = 0; i < 2; ++i) {
		for (int j = 4; j < 6; ++j) {
			if (backBuffer[i][j] == 1)
				m_bDye = true;
		}
	}

	newBlock = true;
	setBack();
}

void Board::setBack()
{
	for (int i = 0; i < 4; ++i)
		backBuffer[curDown->m_posArr[i].y][curDown->m_posArr[i].x] = 2;

}

void Board::setBackZero()
{
	for (int i = 0; i < 4; ++i)
		backBuffer[curDown->m_posArr[i].y][curDown->m_posArr[i].x] = 0;
}

bool Board::relocate()
{
	if (isRange(1, 0)) {
		curDown->moveRight();
		return true;
	}
	if (isRange(-1, 0)) {
		curDown->moveLeft();
		return true;
	}
	if (isRange(0, -1)) {
		curDown->moveUp();
		return true;
	}
	if (isRange(0, 1)) {
		curDown->moveDown();
		return true;
	}
	if (isRange(2, 0)) {
		curDown->moveRight();
		curDown->moveRight();
		return true;
	}
	if (isRange(-2, 0)) {
		curDown->moveLeft();
		curDown->moveLeft();
		return true;
	}
	if (isRange(0, -2)) {
		curDown->moveUp();
		curDown->moveUp();
		return true;
	}
	return false;
}

bool Board::checkMadeLine(int _y)
{
	for (int i = 0; i < 10; ++i)
		if (backBuffer[_y][i] != 1)
			return false;
	SoundManager::GetInst()->pop();
	return true;

}

void Board::deleteLine(int _y)
{
	for (int y = _y - 1; y >= 0; --y) {
		for (int x = 0; x < 10; ++x) {
			if (backBuffer[y][x] != 2)
				backBuffer[y + 1][x] = backBuffer[y][x];
		}
	}
}

void Board::calcGhost()
{
	for (int i = 0; i < 4; ++i) {
		ghostArr[i] = curDown->m_posArr[i];
	}

	bool find = false;
	while (1) {
		for (int i = 0; i < 4; ++i) {
			if (ghostArr[i].y + 1 > 19 || backBuffer[ghostArr[i].y + 1][ghostArr[i].x] == 1) {
				find = true;
				break;
			}
		}
		if (find) break;
		for (int i = 0; i < 4; ++i)
			ghostArr[i].moveDown();
	}
}

void Board::setBackZeroG()
{
	for (int i = 0; i < 4; ++i)
		backBuffer[ghostArr[i].y][ghostArr[i].x] = 0;
}

void Board::setBackG()
{
	for (int i = 0; i < 4; ++i)
		backBuffer[ghostArr[i].y][ghostArr[i].x] = 3;
}

void Board::ghostUpdate()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (ghostArr[i].x == curDown->m_posArr[j].x && ghostArr[i].y == curDown->m_posArr[j].y) {
				setBackZeroG();
				setBack();
				return;
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		backBuffer[ghostArr[i].y][ghostArr[i].x] = 3;
	}
}

bool Board::isRange(int dx, int dy)
{
	for (int i = 0; i < 4; ++i) {
		int nextX = curDown->m_posArr[i].x + dx;
		int nextY = curDown->m_posArr[i].y + dy;
		if ((nextX < 0 || nextX >= 10) || (nextY >= 20 || nextY < 0))
			return false;
		if (frontBuffer[nextY][nextX] == 1)
			return false;
	}
	return true;
}

//백버퍼에서 갱신.
void Board::Update(MY_INPUT _Input)
{
	if (!isRange(0, 1))
		settleReady = true;
	else
		settleReady = false;

	if (isSettleDown) {
		isSettleDown = false;
	}

	switch (_Input)
	{
	case eNone:
		break;
	case eUP:
		setBackZero();
		curDown->moveRotate();
		if (!isRange(0, 0)) {
			if(!relocate())
				curDown->moveRotate();
		}
		setBack();
		break;
	case eDown:
		if (settleReady) {
			settleBlock();
		}
		else if (isRange(0, 1)) {
			setBackZero();
			curDown->moveDown();
			setBack();
		}
		break;
	case eLeft:
		if (isRange(-1, 0)) {
			setBackZero();
			curDown->moveLeft();
			setBack();
		}
		break;
	case eRight:
		if (isRange(1, 0)) {
			setBackZero();
			curDown->moveRight();
			setBack();
		}
		break;
	case eSpace:
		settleBlock();
		break;
	case eStop:
		break;
	default:
		break;
	}

	//고스트 업데이트
	if (!settleReady || newBlock == true) {
		if (isSettleDown == false || newBlock == false) {
			setBackZeroG();
		}
		calcGhost();
		ghostUpdate();
	}

	//지우기 검사
	for (int y = 0; y < 20; ++y)
		if (checkMadeLine(y))
			deleteLine(y);

	newBlock = false;
}

void Board::Draw()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 10; ++j) {
			//front Buffer Update
			if (backBuffer[i][j] != frontBuffer[i][j]) {
				frontBuffer[i][j] = backBuffer[i][j]; // 0 - 빈칸, 1 - 블록화된 블록, 2 - 떨어지는 블록, 3 - 고스트 블록
				//front Buffer Rendering
				setCursorPos(short(j) * 2 + offset_width, short(i) + offset_height, hConsole);
				if (frontBuffer[i][j] == 0)
					printf("  ");
				else if (frontBuffer[i][j] == 1)
					printf("▩");
				else if (frontBuffer[i][j] == 2)
					printf("■");
				else if (frontBuffer[i][j] == 3)
					printf("□");
			}
		}
	}
}
