#include <myWindowApi.h>
/*============== choose Macro what you want to see =========================*/

//#define HOMEWORK_MODE0				//마우스로 사각형 밀기
//#define HOMEWORK_MODE1				//사각형 크기 조절	
//#define HOMEWORK_MODE2				//사각형 드래그앤 드랍
#define HOMEWORK_MODE3					//전자시계

/*====== be careful that make sure that just only one macro Activated =======*/

#ifdef HOMEWORK_MODE0
//global variables
RECT movable = MakeRect(0, 0, 100, 100);
RECT nonMovable = MakeRect(500, 200, 100, 100);
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

//specific Function
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

//wndProc - push Rectangle with Mouse
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawRect(hdc, movable);
		DrawRect(hdc, nonMovable);
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
		movable = MakeRectFromCenter(pt.x, pt.y, movableWidth, movableHeight);
		movableCenterX = (movable.left + movable.right) / 2;
		movableCenterY = (movable.top + movable.bottom) / 2;
		nonMovableCenterX = (nonMovable.left + nonMovable.right) / 2;
		nonMovableCenterY = (nonMovable.top + nonMovable.bottom) / 2;

		if (isCollision(movable, nonMovable)) {
			if (movableCenterX > nonMovableCenterX && isInRangeY()) { //왼쪽 이동
				nonMovable = MakeRectFromCenter(
					pt.x - distX, (nonMovable.top + nonMovable.bottom) / 2, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterX < nonMovableCenterX && isInRangeY()) { //오른쪽 이동
				nonMovable = MakeRectFromCenter(
					pt.x + distX, (nonMovable.top + nonMovable.bottom) / 2, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterY > nonMovableCenterY && isInRangeX()) { //상 이동
				nonMovable = MakeRectFromCenter(
					(nonMovable.left + nonMovable.right) / 2, pt.y - distY, nonMovableWidth, nonMovableHeight
				);
			}
			else if (movableCenterY < nonMovableCenterX && isInRangeX()) { //하 이동
				nonMovable = MakeRectFromCenter(
					(nonMovable.left + nonMovable.right) / 2, pt.y + distY, nonMovableWidth, nonMovableHeight
				);
			}
		}

		hdc = BeginPaint(hWnd, &ps);
		DrawRect(hdc, movable);
		DrawRect(hdc, nonMovable);
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
//global variables
RECT rect = { 200, 200, 300, 300 };
bool setReady = false;
bool isDraging = false;

//wndProc - Rectangle resize
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
		DrawRect(hdc, rect);
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
			DrawRect(hdc, rect);
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
		DrawRect(hdc, rect);
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
//global variables
int rectWidth = 100;
int rectHeight = 100;

RECT rect{ 0, 0, rectWidth, rectHeight };
bool setReady = false;
bool isDraging = false;

POINT prevCursorPos;

//wndProc - Drag and Drop
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
		DrawRect(hdc, rect);
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

			rect = MakeRect(rect.left + dx, rect.top + dy, rectWidth, rectHeight);

			prevCursorPos = POINT{ LOWORD(lParam), HIWORD(lParam) };

			hdc = BeginPaint(hWnd, &ps);
			DrawRect(hdc, rect);
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
//global variables
time_t curr_time;
tm *curr_tm;
char timeStr[40];
int prevTime;

//specific Function
void printTime(HDC& hdc, HWND& hWnd, PAINTSTRUCT& ps) {
	prevTime = curr_tm->tm_sec;
	wsprintf(timeStr, "%2d : %2d : %2d", curr_tm->tm_hour, curr_tm->tm_min, curr_tm->tm_sec);

	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc, 10, 10, timeStr, strlen(timeStr));
	EndPaint(hWnd, &ps);
}

//wndProc - Timer
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	if (prevTime != curr_tm->tm_sec) {
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

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {
	Application* app = new Application;
	if (!app->init(hInst, nCmdShow)) {
		delete app;
		return -1;
	}

	int iRev = app->run();
	delete app;
	return iRev;
}