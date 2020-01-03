#include <windows.h>
#include <math.h>
#define MAXBALL 1000
const double A = 0.15;
const double G = 0.05;
const double AR = 0.003;
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("game");
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

struct tag_Ball {

	BOOL Exist; 
	double x, y; 
	int r;
	double dx, dy;
	COLORREF col;
};
tag_Ball arBall[MAXBALL];
HWND hWndMain;
HBITMAP hBit;

void MoveBall();
void NewBall(BOOL bLeft);
void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);

INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hwnd;
	MSG message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);


	hwnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&message, NULL, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT imessage, WPARAM wparam, LPARAM lparam) {

	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR *Mes = TEXT("좌우클릭:공 생성,space:중지,상하:속도,E:삭제,A:자동");
	static BOOL bPause;
	static BOOL bAuto;
	static int Freq;
	int i;
	HBRUSH hBrush, hOldBrush;
	RECT crt;
	HDC hMemDC;
	HBITMAP OldBit;

	switch (imessage) {

	case WM_CREATE:
		hWndMain = hWnd;
		srand(GetTickCount());
		Freq = 20;
		SetTimer(hWnd, 1, Freq, NULL);
		SendMessage(hWnd, WM_TIMER, 1, NULL);
		bPause = FALSE;
		return 0;

	case WM_KEYDOWN:

		switch (wparam) {

		case VK_UP:

			Freq = max(10, Freq - 5);
			SetTimer(hWnd, 1, Freq, NULL);
			break;

		case VK_DOWN:

			Freq = min(200, Freq + 5);
			SetTimer(hWnd, 1, Freq, NULL);
			break;

		case ' ':

			if (bPause) {
				SetTimer(hWnd, 1, Freq, NULL);
			}
			else {
				KillTimer(hWnd, 1);
			}

			bPause = !bPause;
			break;

		case 'E':

			for (i = 0; i < MAXBALL; i++) {
				arBall[i].Exist = FALSE;
			}
			InvalidateRect(hWnd, NULL, TRUE);
			break;

		case 'A':
			bAuto = !bAuto;
			break;
		}
		return 0;

	case WM_TIMER:

		if (bAuto) {
			if (rand() % 8 == 0) NewBall(TRUE);
			if (rand() % 9 == 0)NewBall(FALSE);
		}

		MoveBall(); //공의 움직임 계속 호출

		//더블버퍼링 공식
		hdc = GetDC(hWnd);
		GetClientRect(hWnd, &crt); //영역을 잡아준다.

		//바뀔 그림을 그릴 hBit 생성

		if (hBit == NULL) {//위에서 잡아준 영역만큼 그림을 다시 그릴 hBit를 생성한다.
			hBit = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
		}

		hMemDC = CreateCompatibleDC(hdc);
		OldBit = (HBITMAP)SelectObject(hMemDC, hBit);
		FillRect(hMemDC, &crt, GetSysColorBrush(COLOR_WINDOW));
		SelectObject(hMemDC, GetStockObject(NULL_PEN));


		//그림을 다시 그린다.
		for (i = 0; i < MAXBALL; i++) {
			if (arBall[i].Exist) {

				hBrush = CreateSolidBrush(arBall[i].col);
				hOldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
				Ellipse(hMemDC, int(arBall[i].x - arBall[i].r), int(arBall[i].y - arBall[i].r)
					, int(arBall[i].x + arBall[i].r), int(arBall[i].y + arBall[i].r));
				DeleteObject(SelectObject(hMemDC, hOldBrush));
			}
		}

		SetTextAlign(hMemDC, TA_CENTER);
		TextOut(hMemDC, 300, 10, Mes, lstrlen(Mes));
		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hdc);
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;

	case WM_LBUTTONDOWN:

		if (!bPause) NewBall(FALSE);

		return 0;

	case WM_RBUTTONDOWN:

		if (!bPause) NewBall(FALSE);
		return 0;

	case WM_PAINT:
		//타이머에서 hBit에 그린그림을 다 그린후 PAINT에서 올려준다.
		hdc = BeginPaint(hWnd, &ps);
		DrawBitmap(hdc, 0, 0, hBit);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, imessage, wparam, lparam));
}

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

void MoveBall() {

	int i;
	tag_Ball B;
	RECT crt;

	GetClientRect(hWndMain, &crt);
	for (i = 0; i < MAXBALL; i++) {
		if (arBall[i].Exist) {
			B = arBall[i];

			if (B.dx >= 0) {
				B.dx = max(0, B.dx - AR);
			}
			else {
				B.dx = min(0, B.dx + AR);
			}
			B.x += B.dx;

			if (B.x + B.r >= crt.right) {
				B.x = crt.right - (B.x + B.r - crt.right) - B.r;
				B.dx *= -1;
			}

			if (B.x - B.r <= 0) {
				B.x = 0 - (B.x - B.r) + B.r;
				B.dx *= -1;
			}

			if (B.dy >= 0) {
				B.dy += A;
			}
			else {
				B.dy += A + G;
			}

			B.y += B.dy;

			if (B.y + B.r >= crt.bottom) {
				B.y = crt.bottom - (B.y + B.r - crt.bottom) - B.r;
				B.dy *= -1;
				if (fabs(B.dy) < 1.0) {
					B.Exist = FALSE;
				}
			}

			if (fabs(B.dy) < 0.1) {
				B.Exist = FALSE;
			}
			arBall[i] = B;
		}
	}
}

void NewBall(BOOL bLeft) {

	int i;

	for (i = 0; i < MAXBALL; i++) {
		if (arBall[i].Exist == FALSE) {
			break;
		}
	}; //현재 공의 갯수 조사 지금까지 만들어진 공중에 마지막에 새로운 공 하나 생성한다.  MAXBALL보다 커지는걸 방지

	   //공 하나를 랜덤으로 생성한다.
	if (i != MAXBALL) {
		arBall[i].dx = 2.0 + (rand() % 20) / 10.0;
		if (bLeft) {
			arBall[i].x = 30;
		}
		else {
			arBall[i].x = 570;
			arBall[i].dx *= -1;
		}

		arBall[i].y = 20;
		arBall[i].dy = (rand() % 10) / 10.0;
		arBall[i].r = rand() % 8 + 8;
		arBall[i].col = RGB(rand() % 256, rand() % 256, rand() % 256);
		arBall[i].Exist = TRUE;
	}
}