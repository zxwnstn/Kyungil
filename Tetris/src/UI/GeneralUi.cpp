#include "GeneralUi.h"

GeneralUi* GeneralUi::m_pInst = nullptr;

GeneralUi * GeneralUi::GetInst()
{
	if (GeneralUi::m_pInst == nullptr)
		return m_pInst = new GeneralUi;
	return m_pInst;
}

bool GeneralUi::init()
{
	memset(backBuffer, 0, sizeof(backBuffer));
	memset(frontBuffer, 0, sizeof(frontBuffer));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//DrawBoard first
	for (int i = 0; i < 3; ++i) {
		for (int j = 3; j < 25; ++j) {
			setCursorPos(short(14) * 2, j, hConsole);
			if (i < 2)
				printf("  ");
			else printf("¢Æ");
			setCursorPos( short((25) * 2), j, hConsole);
			if(i == 0)
				printf("¢Æ");
		}
	}
	for (int i = 0; i < 12; ++i) {
		setCursorPos(short(14 + i) * 2, 25, hConsole);
		printf("¢Æ");
	}
	for (int i = 0; i < 23; ++i) {
		setCursorPos(short(38) * 2, i + 3, hConsole);
		printf("¢Æ");
	}
	for (int i = 0; i < 13; ++i) {
		setCursorPos(short(i + 26) * 2, 6, hConsole);
		printf("¢Æ");
	}

	return true;
}

void GeneralUi::Destroy()
{
	if (m_pInst != nullptr)
		delete m_pInst;
	m_pInst = nullptr;
}

GeneralUi::GeneralUi()
{
}


GeneralUi::~GeneralUi()
{
}

void GeneralUi::Update()
{
}

void GeneralUi::Draw()
{
	//for(int i = 0; i < )
}
