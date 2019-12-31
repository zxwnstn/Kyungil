#pragma once
#include "myWinApi.h"

extern LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

class Application {
private:
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
	int			m_nCmdShow;

private:
	bool		setUpWindow();

public:
	bool		init(const HINSTANCE& hInst, int nCmdShow);
	int			run();
};