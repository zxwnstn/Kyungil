#pragma once
#include <Windows.h>
#define WINNAME (LPTSTR)(TEXT("경일프로그래밍 18기"))
#define WINSTARTY	100
#define WINSTARTX	100
#define WINSIZEX	1024
#define WINSIZEY	512
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p) {if(p){delete p; p = nullptr;}}

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_pMouse;