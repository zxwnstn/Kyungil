#include "mainGame.h"
#include "HomeWorkClass/Scene/SceneBase.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);

	//image init

	SCENEMANAGER->addScene("베이스", new SceneBase);
	SCENEMANAGER->changeScene("베이스");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
}  

void mainGame::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
		m_showRect = !m_showRect;
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
		m_showFPS = !m_showFPS;

	TIMEMANAGER->update(60.f);
	SCENEMANAGER->update(TIMEMANAGER->getElapsedTime());
}

void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	
	SCENEMANAGER->render();

	if (m_showRect)
		SCENEMANAGER->debugRender();

	if (m_showFPS)
		TIMEMANAGER->render(getMemDC());

	getBackBuffer()->render(getHDC(), 0, 0);
}