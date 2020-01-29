#include "MainGame.h"
#include "GameScene/CharacterInfoScene.h"
#include "GameScene/MapScene.h"
#include "GameScene/CharacterSelectScene.h"

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
	SCENEMANAGER->addScene("정보", new CharacterInfoScene);
	SCENEMANAGER->addScene("선택", new CharacterSelectScene);
	SCENEMANAGER->addScene("맵", new MapScene);

	IMAGEMANAGER->addImage("디즈니", "Images/dizni.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("다오", "Images/dao.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("배찌", "Images/bazzi.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("사나", "../Common_Images/사나.bmp", WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addFrameImage("다오우", "Images/daoRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("다오좌", "Images/daoLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("다오상", "Images/daoUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("다오하", "Images/daoDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("다오우", "다오우", 5, false, true);
	ANIMANAGER->addDefAnimation("다오좌", "다오좌", 5, false, true);
	ANIMANAGER->addDefAnimation("다오상", "다오상", 5, false, true);
	ANIMANAGER->addDefAnimation("다오하", "다오하", 5, false, true);


	IMAGEMANAGER->addFrameImage("디즈니우", "Images/dizniRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("디즈니좌", "Images/dizniLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("디즈니상", "Images/dizniUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("디즈니하", "Images/dizniDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("디즈니우", "디즈니우", 5, false, true);
	ANIMANAGER->addDefAnimation("디즈니좌", "디즈니좌", 5, false, true);
	ANIMANAGER->addDefAnimation("디즈니상", "디즈니상", 5, false, true);
	ANIMANAGER->addDefAnimation("디즈니하", "디즈니하", 5, false, true);


	IMAGEMANAGER->addFrameImage("배찌우", "Images/bazziRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("배찌좌", "Images/bazziLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("배찌상", "Images/bazziUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("배찌하", "Images/bazziDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("배찌상", "배찌상", 5, false, true);
	ANIMANAGER->addDefAnimation("배찌하", "배찌하", 5, false, true);
	ANIMANAGER->addDefAnimation("배찌좌", "배찌좌", 5, false, true);
	ANIMANAGER->addDefAnimation("배찌우", "배찌우", 5, false, true);


	SCENEMANAGER->changeScene("선택");

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
	SCENEMANAGER->update(deltaTime);
	ANIMANAGER->update(deltaTime);
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