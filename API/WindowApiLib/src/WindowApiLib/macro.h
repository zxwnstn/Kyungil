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