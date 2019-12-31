#include "stdafx.h"

//0. 마우스로 사각형 밀기	- wndProc
//1. 사각형 크기 조절		- wndProc1
//2. 사각형 드래그앤 드랍	- wndProc2
//3. 전자시계				- wndProc3


/*============== choose Macro what you want to see =========================*/
//#define HOMEWORK_MODE0
//#define HOMEWORK_MODE1
//#define HOMEWORK_MODE2
#define HOMEWORK_MODE3
/*====== be careful that make sure that just only one macro Activated =======*/

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
	wndClass.lpfnWndProc = (WNDPROC)wndProc;
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

	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
//마우스와 사각 충돌함수
bool isCursorInRect(LPARAM lParam, RECT& rect) {
	int x = LOWORD(lParam);
	int y = HIWORD(lParam);

	return (((rect.left <= x) && (x <= rect.right)) && ((rect.top <= y) && (y <= rect.bottom)));
}


#ifdef HOMEWORK_MODE0
//mode0
RECT movable = RectMake(0, 0, 100, 100);
RECT nonMovable = RectMake(500, 200, 100, 100);
RECT backRect = movable;
int movableWidth = movable.right - movable.left;
int movableHeight = movable.bottom - movable.top;
int nonMovableWidth = nonMovable.right - nonMovable.left;
int nonMovableHeight = nonMovable.bottom - nonMovable.top;

int distX = (nonMovableWidth + nonMovableWidth) / 2;
int distY = (movableHeight + nonMovableHeight) / 2;

int movableCenterX = (movable.left + movable.right) / 2;
int movableCenterY = (movable.top + movable.bottom) / 2;
int nonMovableCenterX = (nonMovable.left + nonMovable.right) / 2;
int nonMovableCenterY = (nonMovable.top + nonMovable.bottom) / 2;
POINT pt{ 0,0 };
bool isCollision(RECT& movable, RECT& nonmovable) {
	if (((nonmovable.top < movable.bottom) && (movable.bottom < nonmovable.bottom)) ||
		((nonmovable.top < movable.top) && (movable.top < nonmovable.bottom)))
	{
		if (((nonmovable.left < movable.right) && (movable.right < nonmovable.right)) ||
			((nonmovable.left < movable.left) && (movable.left < nonmovable.right)))
		{
			return true;
		}
	}
	return false;
}
bool safe(RECT rc, int direction) {
	return ((0 <= rc.left) && (rc.right <= WINSIZEX) && (0 <= rc.top) && (rc.bottom <= WINSIZEY));
}
bool isInRangeX() {

	if (((nonMovable.left < backRect.left) && (backRect.left < nonMovable.right)) ||
		((nonMovable.left < backRect.right) && (backRect.right < nonMovable.right)))
		return true;
	return false;
}
bool isInRangeY() {
	if (((nonMovable.top < backRect.bottom) && (backRect.bottom < nonMovable.bottom)) ||
		((nonMovable.top < backRect.top) && (backRect.top < nonMovable.bottom)))
		return true;
	return false;
}
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, movable);
		RectangleDraw(hdc, nonMovable);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		break;
	case WM_MOUSEMOVE:
		InvalidateRect(hWnd, NULL, true);

		pt.y = HIWORD(lParam);
		pt.x = LOWORD(lParam);

		backRect = movable;
		movable = RectMakeCenter(pt.x, pt.y, movableWidth, movableHeight);
		movableCenterX = (movable.left + movable.right) / 2;
		movableCenterY = (movable.top + movable.bottom) / 2;
		nonMovableCenterX = (nonMovable.left + nonMovable.right) / 2;
		nonMovableCenterY = (nonMovable.top + nonMovable.bottom) / 2;

		if (isCollision(movable, nonMovable)) {
			if (movableCenterX > nonMovableCenterX && isInRangeY()) { //왼쪽 이동
				nonMovable = RectMakeCenter(
					pt.x - distX, (nonMovable.top + nonMovable.bottom) / 2, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterX < nonMovableCenterX && isInRangeY()) { //오른쪽 이동
				nonMovable = RectMakeCenter(
					pt.x + distX, (nonMovable.top + nonMovable.bottom) / 2, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterY > nonMovableCenterY && isInRangeX()) { //상 이동
				nonMovable = RectMakeCenter(
					(nonMovable.left + nonMovable.right) / 2, pt.y - distY, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterY < nonMovableCenterX && isInRangeX()) { //하 이동
				nonMovable = RectMakeCenter(
					(nonMovable.left + nonMovable.right) / 2, pt.y + distY, nonMovableWidth, nonMovableHeight
				);
			}
		}

		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, movable);
		RectangleDraw(hdc, nonMovable);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#endif

#ifdef HOMEWORK_MODE1
//mode1
RECT rect = { 200, 200, 300, 300 };
bool setReady = false;
bool isDraging = false;

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		InvalidateRect(hWnd, NULL, true);
		
		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rect);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		break;
	case WM_MOUSEMOVE:
		if (!isDraging) {
			if (isCursorInRect(lParam, rect))
				setReady = true;
			else setReady = false;
		}	
		if (isDraging) {
			rect = RECT{ rect.left, rect.top, LOWORD(lParam), HIWORD(lParam) };
			InvalidateRect(hWnd, NULL, true);

			hdc = BeginPaint(hWnd, &ps);
			RectangleDraw(hdc, rect);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_LBUTTONDOWN:
		if (setReady) {
			isDraging = true;
			rect = RECT{ rect.left, rect.top, LOWORD(lParam), HIWORD(lParam) };
		}
		InvalidateRect(hWnd, NULL, true);

		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rect);
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONUP:
		isDraging = false;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#endif

#ifdef HOMEWORK_MODE2
//mode2

int rectWidth = 100;
int rectHeight = 100;

RECT rect{ 0, 0, rectWidth, rectHeight };
bool setReady = false;
bool isDraging = false;

POINT prevCursorPos;

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		InvalidateRect(hWnd, NULL, true);

		hdc = BeginPaint(hWnd, &ps);
		RectangleDraw(hdc, rect);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		break;
	case WM_MOUSEMOVE:
		if (!isDraging) {
			if (isCursorInRect(lParam, rect)) 
				setReady = true;
			else 
				setReady = false;
		}
		else {
			InvalidateRect(hWnd, NULL, true);

			int dx = LOWORD(lParam) - prevCursorPos.x;
			int dy = HIWORD(lParam) - prevCursorPos.y;

			rect = RectMake(rect.left + dx, rect.top + dy, rectWidth, rectHeight);

			prevCursorPos = POINT{ LOWORD(lParam), HIWORD(lParam) };

			hdc = BeginPaint(hWnd, &ps);
			RectangleDraw(hdc, rect);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_LBUTTONDOWN:
		if (setReady) {
			isDraging = true;
			prevCursorPos = POINT{ LOWORD(lParam), HIWORD(lParam) };
		}
		break;
	case WM_LBUTTONUP:
		if (isDraging)
			isDraging = false;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#endif

#ifdef HOMEWORK_MODE3
//mode3

time_t curr_time;
tm *curr_tm;
char timeStr[40];
int timeLapse;

void printTime(HDC& hdc, HWND& hWnd, PAINTSTRUCT& ps) {
	timeLapse = curr_tm->tm_sec;
	wsprintf(timeStr, "%2d : %2d : %2d", curr_tm->tm_hour, curr_tm->tm_min, curr_tm->tm_sec);

	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc, 10, 10, timeStr, strlen(timeStr));
	EndPaint(hWnd, &ps);
}

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	if (timeLapse != curr_tm->tm_sec) {
		InvalidateRect(hWnd, NULL, true);
		printTime(hdc, hWnd, ps);		
	}
	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		printTime(hdc, hWnd, ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#endif
