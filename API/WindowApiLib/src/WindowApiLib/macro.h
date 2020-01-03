#pragma once
#include <Windows.h>

//DELETE MACRO
#define SAFE_DELETE(p) {if(p){delete p; p = nullptr;}}

//OVERALL WINDOW SIZE INFO
#define WINNAME (LPTSTR)(TEXT("경일프로그래밍 18기"))
#define WINSTARTY	100
#define WINSTARTX	100
#define WINSIZEX	1024
#define WINSIZEY	512
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define KEYMAX 256

//WinMain Macro
#define DEFINE_WINMAIN(TYPE) \
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {\
Application* app = new TYPE;\
if (!app->init(hInst, nCmdShow)) {\
	SAFE_DELETE(app);\
	return -1;\
}\
\
int iRev = app->run();\
SAFE_DELETE(app);\
return iRev;\
}

#define DEFINE_DWINMAIN(TYPE) \
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdParam, int nCmdShow) {\
\
if (!TYPE::GetInst()->init(hInst, nCmdShow)) {\
	TYPE::GetInst()->Destroy();\
	return -1;\
}\
\
int iRev = TYPE::GetInst()->run();\
TYPE::GetInst()->Destroy();\
return iRev;\
}

//Singleton Macro
#define DECLARE_SINGLE(TYPE) \
static TYPE* mInst; \
\
public: \
	static TYPE* GetInst() {\
		if (!mInst)\
			return mInst = new TYPE;\
		return mInst;\
	}\
	void Destroy() {\
		SAFE_DELETE(mInst);\
	} \
private:\
	TYPE();\
	~TYPE();
	
#define DEFINITION_SINGLE(TYPE) TYPE* TYPE::mInst = nullptr;
#define GET_SINGLE(TYPE) TYPE::GetInst()
#define RELEASE_SINGLE(TYPE) TYPE::GetInst()->Destroy()


//math
#define PI 3.141592
#define GRAVITY 9.8

//bit
#define BIT(x)(1 << x)