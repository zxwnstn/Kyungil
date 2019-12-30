#include "Ui.h"
#include "Board.h"
#include "GeneralUi.h"
Ui* Ui::m_pInst = nullptr;

Ui::Ui()
{
}

Ui::~Ui()
{
}


void Ui::Update(MY_INPUT _mInput)
{
	Board::GetInst()->Update(_mInput);
	GeneralUi::GetInst()->Update();
}

void Ui::Draw()
{
	Board::GetInst()->Draw();
	GeneralUi::GetInst()->Draw();
}

Ui * Ui::GetInst()
{
	if (m_pInst == nullptr)
		return m_pInst = new Ui;
	return m_pInst;
}

bool Ui::init()
{
	if (!GeneralUi::GetInst()->init())
		return false;
	if (!Board::GetInst()->init())
		return false;

	return true;
}

bool Ui::isEnd()
{
	bool ret = Board::GetInst()->m_bDye;
	return ret;
}

void Ui::Destroy()
{
	if (m_pInst != nullptr)
		delete m_pInst;
	m_pInst = nullptr;
}


