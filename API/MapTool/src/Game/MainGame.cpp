#include "stdafx.h"
#include "MainGame.h"
#include "GameScene/MapEdit.h"

MainGame::MainGame()
{
}
MainGame::~MainGame()
{
}

HRESULT MainGame::init()
{
	GameNode::init();
	
	//add Scene
	SCENEMANAGER->addScene("MapEddit", new MapEdit);
	SCENEMANAGER->changeScene("MapEddit");

	return S_OK;
}

void MainGame::release()
{
	GameNode::release();
}  

void MainGame::update()
{
	GameNode::update();
	if (KEYMANAGER->isOnceKeyDown(GAME_RECTMODE))
		m_showRect = !m_showRect;
	if (KEYMANAGER->isOnceKeyDown(GAME_SHOWFPS))
		m_showFPS = !m_showFPS;

	TIMEMANAGER->update(60.f);
	deltaTime = TIMEMANAGER->getElapsedTime();
	EFFECTMANAGER->update();
	SCENEMANAGER->update(deltaTime);
	ANIMANAGER->update(deltaTime);
}

void MainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render(getMemDC());
	SCENEMANAGER->afterRender(getMemDC());
	EFFECTMANAGER->render(getMemDC());
	if(m_showRect)
		SCENEMANAGER->debugRender(getMemDC());
	if (m_showFPS)
		TIMEMANAGER->render(getMemDC());

	getBackBuffer()->render(getHDC(), 0, 0);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (SCENEMANAGER->getCurScene()) {
		return SCENEMANAGER->getCurScene()->MainProc(hWnd, iMessage, wParam, lParam);
	}
	else {
		switch (iMessage)
		{
		case WM_MOUSEMOVE:
			m_ptMouse.x = LOWORD(lParam);
			m_ptMouse.y = HIWORD(lParam);
			break;
		case WM_DESTROY:
			m_bLoop = false;
			PostQuitMessage(0);
			break;
		}
		return DefWindowProc(hWnd, iMessage, wParam, lParam);
	}
}