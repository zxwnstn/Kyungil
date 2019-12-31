#include <myWindowApi.h>

//wproc
bool isCursorInRect(LPARAM lParam, RECT& rect) {
	int x = LOWORD(lParam);
	int y = HIWORD(lParam);

	return (((rect.left <= x) && (x <= rect.right)) && ((rect.top <= y) && (y <= rect.bottom)));
}

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