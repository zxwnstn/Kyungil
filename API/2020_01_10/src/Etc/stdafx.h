// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN 
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//STL
#include<vector>
#include<map>
#include<string>
#include <memory>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
//내가 만든 헤더파일
#include "Common/commonMacroFunction.h"
#include "Manager/Image.h"
#include "Manager/randomFunction.h"
#include "Manager/keyManager.h"
#include "Manager/imageManager.h"
#include "Common/utils.h"
#include "HomeWorkClass/HomeWorkType.h"
using namespace UTIL;


//======================================
//##			매니저들			  ##
//======================================
#define RND				randomFunction::getSingleton()
#define IMAGEMANAGER	imageManager::getSingleton()
#define KEYMANAGER		keyManager::getSingleton()
//======================================
//##			디파인문			  ##
//======================================
#define WINNAME		(LPTSTR)(TEXT("경일 프로그래밍 18기"))
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1208
#define	WINSIZEY	958
#define WINSTYLE	WS_CAPTION | WS_SYSMENU
#define COLOR_MAGENTA RGB(255, 0, 255)


//======================================
//## 메인게임 릴리즈에서 사용하는 녀석##
//======================================
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}

//================================================
//전역변수(인스턴스, 윈도우 핸들, 마우스 좌표)  ##
//================================================
extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;
extern bool m_bLoop;