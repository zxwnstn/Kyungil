#include "Etc/stdafx.h"
#include "Game/mainGame.h"
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console" )

mainGame mg;
HINSTANCE m_hInstance;
HWND m_hWnd;
POINT m_ptMouse;
bool m_bLoop = true;
LPTSTR m_lpszClass = TEXT("경일 프로그래밍 18기");

//메인게임

//윈도우 클래스 이름
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	m_hInstance = hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = m_lpszClass;
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
		hInstance,			
		NULL);

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
	ShowWindow(m_hWnd, nCmdShow);

	if (FAILED(mg.init()))
	{
		return 0;
	}
	MSG message;

	LARGE_INTEGER tSeconds;
	LARGE_INTEGER tTimePrev;
	LARGE_INTEGER tTimeCur;
	QueryPerformanceFrequency(&tSeconds);
	QueryPerformanceCounter(&tTimePrev);
	HDC hdc = GetDC(m_hWnd);

	double accumulate = 0.0;
	double minDelta = 0.01;
	while (m_bLoop) {
		while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		QueryPerformanceCounter(&tTimeCur);
		float DeltaTime = (tTimeCur.QuadPart - tTimePrev.QuadPart) / (float)tSeconds.QuadPart;
		tTimePrev = tTimeCur;
		accumulate += DeltaTime;
		if (accumulate >= minDelta) {
			mg.update(accumulate);
			mg.render(hdc);
			accumulate -= minDelta;
		}
	}
	//getMessage
	/*while (true)
	{
		if (GetMessage(&message, NULL, 0, 0))
		{
			if (message.message == WM_QUIT)
				break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
		}
	}*/
	

	//메시지 루프를 다돌면 해제하자.
	mg.release();
	return message.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam){
	return mg.MainProc(hWnd, iMessage, wParam, lParam);
}

void setWindowSize(int x, int y, int width, int height){
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);
	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}