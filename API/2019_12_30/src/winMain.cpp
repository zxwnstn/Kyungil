#include "stdafx.h"

//if you want to show homeWork1, notation HOMEWORK1 macro
//#define HOMEWORK1

HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse = { 0,0 };

#ifdef HOMEWORK1
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
#else
LRESULT CALLBACK wndProc2(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
#endif
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
#ifdef HOMEWORK1
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

	switch (iMessage) {
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

#else
RECT player1 = RectMake(0, 0, 100, 100);
RECT player2 = RectMake(500, 400, 100, 100);
RECT prisoner;
bool isPlayer1Control;
const int psnerWidth = 25;
const int psnerHeight = 25;
const int dx = 5;
const int dy = 5;

void changeControl() {
	isPlayer1Control = !isPlayer1Control;
	if (isPlayer1Control)
		prisoner = RectMakeCenter((player1.left + player1.right) / 2, (player1.top + player1.bottom) / 2, psnerWidth, psnerHeight);
	else
		prisoner = RectMakeCenter((player2.left + player2.right) / 2, (player2.top + player2.bottom) / 2, psnerWidth, psnerHeight);
}
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
bool isCollision(RECT movable, RECT nonmovable, int direction) {
	moveRect(movable, direction);
	if (((nonmovable.top < movable.bottom) && (movable.bottom < nonmovable.bottom)) ||
		((nonmovable.top < movable.top) && (movable.top < nonmovable.bottom)))
	{
		if (((nonmovable.left < movable.right) && (movable.right < nonmovable.right)) ||
			((nonmovable.left < movable.left) && (movable.left < nonmovable.right)))
		{
			changeControl();
			return true;
		}
	}
	return false;
}
bool safe(RECT rc, int direction) {
	moveRect(rc, direction);
	return ((0 <= rc.left) && (rc.right <= WINSIZEX) && (0 <= rc.top) && (rc.bottom <= WINSIZEY));
}
bool isPrisionerCollision(RECT movable, int direction) {
	moveRect(movable, direction);
	return ((prisoner.left <= movable.left) || (prisoner.right >= movable.right)
		|| (prisoner.top <= movable.top) || (prisoner.bottom >= movable.bottom));

}

//Second windowProc - Prision Rectangle
LRESULT CALLBACK wndProc2(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		prisoner = RectMakeCenter((player1.left + player1.right) / 2, (player1.top + player1.bottom) / 2, 25, 25);
		isPlayer1Control = true;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, player1);
		RectangleDraw(hdc, player2);
		RectangleDraw(hdc, prisoner);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		InvalidateRect(hWnd, NULL, true);

		hdc = BeginPaint(hWnd, &ps);

		if (isPlayer1Control) {
			if (safe(player1, wParam) && !isCollision(player1, player2, wParam)) {
				if (isPrisionerCollision(player1, wParam))
					moveRect(prisoner, wParam);
				moveRect(player1, wParam);
			}
		}
		else {
			if (safe(player2, wParam) && !isCollision(player2, player1, wParam)) {
				if (isPrisionerCollision(player2, wParam))
					moveRect(prisoner, wParam);
				moveRect(player2, wParam);
			}
		}
		RectangleDraw(hdc, player1);
		RectangleDraw(hdc, player2);
		RectangleDraw(hdc, prisoner);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif

