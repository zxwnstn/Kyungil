#include "MainGame.h"
#include "GameScene/SampleScene.h"

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
	SCENEMANAGER->addScene("Sample", new SampleScene);
	SCENEMANAGER->changeScene("Sample");

	return S_OK;
}

void MainGame::release()
{
	GameNode::release();
}  

void MainGame::update()
{
	if (KEYMANAGER->isOnceKeyDown(GAME_RECTMODE))
		m_showRect = !m_showRect;
	if (KEYMANAGER->isOnceKeyDown(GAME_SHOWFPS))
		m_showFPS = !m_showFPS;

	TIMEMANAGER->update(60.f);
	SCENEMANAGER->update(TIMEMANAGER->getElapsedTime());
}

void MainGame::render()
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