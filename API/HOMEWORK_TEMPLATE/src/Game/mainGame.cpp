#include "mainGame.h"
#include "Scene/SampleScene.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init();
	
	//add Scene
	SCENEMANAGER->addScene("Sample", new SampleScene);
	SCENEMANAGER->changeScene("Sample");

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

	SCENEMANAGER->render(getMemDC());
	SCENEMANAGER->afterRender(getMemDC());
	if(m_showRect)
		SCENEMANAGER->debugRender(getMemDC());
	if (m_showFPS)
		TIMEMANAGER->render(getMemDC());

	getBackBuffer()->render(getHDC(), 0, 0);
}