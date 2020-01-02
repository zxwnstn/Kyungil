#pragma once
#include "myWinApi.h"
#include "../Manager.h"
//extern LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

class ApplicationCore {
private:
	bool					setUpWindow();
	virtual void			Logic() = 0;

protected:
	static LRESULT CALLBACK dWndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	static bool				m_bLoop;

protected:
	HINSTANCE				m_hInstance;
	HWND					m_hWnd;
	HDC						m_hDc;
	int						m_nCmdShow;
	float					m_fDeltaTime;

public:
	virtual bool			init(const HINSTANCE& hInst, int nCmdShow);
	int						run();

protected:
	virtual void			update();
	virtual void			render();

	ApplicationCore() {}
	~ApplicationCore();
};