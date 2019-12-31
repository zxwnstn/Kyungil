#include <myWindowApi.h>

#define HOMEWORK1
//The Homework1 is crash and push
//if you want to show homeWork2(prison rectangle), denotation HOMEWORK1 macro


#ifdef HOMEWORK1
//gloabal variables
RECT rc = MakeRect(0, 0, 100, 100);
RECT rc2 = MakeRect(700, 200, 100, 100);
RECT prisoner = MakeRect(35, 35, 25, 25);
RECT barigate = MakeRect(400, 200, 150, 150);
const int dx = 5;
const int dy = 5;

//specific Functions
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

//wndProc - crash
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawRect(hdc, rc);
		DrawRect(hdc, barigate);
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
		DrawRect(hdc, rc);
		DrawRect(hdc, barigate);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#else
//global variables
RECT movable = MakeRect(0, 0, 100, 100);
RECT nonMovable = MakeRect(500, 400, 100, 100);
RECT prisoner;
bool isPlayer1Control;
const int psnerWidth = 25;
const int psnerHeight = 25;
int dx = 3;
int dy = 3;

//specific function
void changeControl() {
	isPlayer1Control = !isPlayer1Control;
	if (isPlayer1Control)
		prisoner = MakeRectFromCenter((movable.left + movable.right) / 2, (movable.top + movable.bottom) / 2, psnerWidth, psnerHeight);
	else
		prisoner = MakeRectFromCenter((nonMovable.left + nonMovable.right) / 2, (nonMovable.top + nonMovable.bottom) / 2, psnerWidth, psnerHeight);
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

//windowProc - Prision Rectangle
LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		prisoner = MakeRectFromCenter((movable.left + movable.right) / 2, (movable.top + movable.bottom) / 2, 25, 25);
		isPlayer1Control = true;
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawRect(hdc, movable);
		DrawRect(hdc, nonMovable);
		DrawRect(hdc, prisoner);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_KEYDOWN:
		InvalidateRect(hWnd, NULL, true);

		hdc = BeginPaint(hWnd, &ps);
		if (isPlayer1Control) {
			if (safe(movable, wParam) && !isCollision(movable, nonMovable, wParam)) {
				if (isPrisionerCollision(movable, wParam))
					moveRect(prisoner, wParam);
				moveRect(movable, wParam);
			}
		}
		else {
			if (safe(nonMovable, wParam) && !isCollision(nonMovable, movable, wParam)) {
				if (isPrisionerCollision(nonMovable, wParam))
					moveRect(prisoner, wParam);
				moveRect(nonMovable, wParam);
			}
		}
		DrawRect(hdc, movable);
		DrawRect(hdc, nonMovable);
		DrawRect(hdc, prisoner);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
#endif

DEFINE_WINMAIN(Application)