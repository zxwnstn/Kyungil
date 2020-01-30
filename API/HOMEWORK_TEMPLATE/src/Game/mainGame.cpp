#include "stdafx.h"
#include "MainGame.h"
#include "GameScene/SampleScene.h"
//#include "../example/ExScene/ExAnimationManagerScene.h"
#include "../example/ExScene/ExEffectManagerScene.h"

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
	//SCENEMANAGER->addScene("animation", new ExAnimationManagerScene);
	SCENEMANAGER->addScene("effect", new ExEffectManagerScene);
	//SCENEMANAGER->changeScene("ex");
	SCENEMANAGER->changeScene("effect");

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