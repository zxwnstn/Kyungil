#include "stdafx.h"

//if you want to show homeWork2, notation HOMEWORK1 macro
#define HOMEWORK1

HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse = { 0,0 };

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
void setWindowSize(int x, int y, int width, int height);


//winMain
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {

	m_hInstance = hInst;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInst;

#ifdef HOMEWORK1
	wndClass.lpfnWndProc = (WNDPROC)wndProc;
#else
	wndClass.lpfnWndProc = (WNDPROC)wndProc2;
#endif

	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;


	RegisterClass(&wndClass);
	m_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,					
		(HMENU)NULL,
		hInst,
		NULL
	);
	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	ShowWindow(m_hWnd, nCmdShow);

	
	MSG message;
	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

//윈도우 크기조정(클라이언트 영역의 사이즈를 정확히 잡아준다.
void setWindowSize(int x, int y, int width, int height) {

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);
	//위 rect정보로 윈도우 사이즈 설정

	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_SHOWWINDOW);
}

//for homeWork gloabal variables
RECT rc = RectMake(0, 0, 100, 100);
RECT rc2 = RectMake(700, 200, 100, 100);
RECT prisoner = RectMake(35, 35, 25, 25);
RECT barigate = RectMake(400, 200, 150, 150);
const int dx = 5;
const int dy = 5;

//for homeWork Functions
void moveRect(RECT& rc, int direction) {
	switch (direction) {
	case VK_RIGHT:
		rc.left += dx;
		rc.right += dx;
		break;
	case VK_LEFT:
		rc.left -= dx;
		rc.right -= dx;
		break;
	case VK_UP:
		rc.top -= dy;
		rc.bottom -= dy;
		break;
	case VK_DOWN:
		rc.top += dy;
		rc.bottom += dy;
		break;
	}
}
bool safe(RECT rc, int direction) {
	moveRect(rc, direction);
	return ((0 <= rc.left) && (rc.right <= WINSIZEX) && (0 <= rc.top) && (rc.bottom <= WINSIZEY));
}
bool isCollision(RECT rc, int direction) {
	moveRect(rc, direction);
	if (((barigate.top < rc.bottom) && (rc.bottom < barigate.bottom)) ||
		((barigate.top < rc.top) && (rc.top < barigate.bottom)))
	{
		if (((barigate.left < rc.right) && (rc.right < barigate.right)) ||
			((barigate.left < rc.left) && (rc.left < barigate.right)))
			return true;
	}
	return false;
}

//First windowProc - crash and push
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage){
	case WM_CREATE: 
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rc);
		RectangleDraw(hdc, barigate);
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		InvalidateRect(hWnd, NULL, true);
		//for collision
		if (safe(rc, wParam) && !isCollision(rc, wParam)) {
			moveRect(rc, wParam);
		}
		////for push - if you want push Block, erase follow comment
		//else if (safe(rc, wParam) && isCollision(rc, wParam)) {
		//	moveRect(rc, wParam);
		//	moveRect(barigate, wParam);
		//}

		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rc);
		RectangleDraw(hdc, barigate);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY: 
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

//Second windowProc - Prision Rectangle
LRESULT CALLBACK wndProc2(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage){
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rc);
		RectangleDraw(hdc, barigate);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		InvalidateRect(hWnd, NULL, true);

		hdc = BeginPaint(hWnd, &ps);





		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}



