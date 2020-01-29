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
	SCENEMANAGER->addScene("����", new CharacterInfoScene);
	SCENEMANAGER->addScene("����", new CharacterSelectScene);
	SCENEMANAGER->addScene("��", new MapScene);

	IMAGEMANAGER->addImage("�����", "Images/dizni.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("�ٿ�", "Images/dao.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("����", "Images/bazzi.bmp", 216, 256, true);
	IMAGEMANAGER->addImage("�糪", "../Common_Images/�糪.bmp", WINSIZEX, WINSIZEY);

	IMAGEMANAGER->addFrameImage("�ٿ���", "Images/daoRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�ٿ���", "Images/daoLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�ٿ���", "Images/daoUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�ٿ���", "Images/daoDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("�ٿ���", "�ٿ���", 5, false, true);
	ANIMANAGER->addDefAnimation("�ٿ���", "�ٿ���", 5, false, true);
	ANIMANAGER->addDefAnimation("�ٿ���", "�ٿ���", 5, false, true);
	ANIMANAGER->addDefAnimation("�ٿ���", "�ٿ���", 5, false, true);


	IMAGEMANAGER->addFrameImage("����Ͽ�", "Images/dizniRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�������", "Images/dizniLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("����ϻ�", "Images/dizniUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�������", "Images/dizniDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("����Ͽ�", "����Ͽ�", 5, false, true);
	ANIMANAGER->addDefAnimation("�������", "�������", 5, false, true);
	ANIMANAGER->addDefAnimation("����ϻ�", "����ϻ�", 5, false, true);
	ANIMANAGER->addDefAnimation("�������", "�������", 5, false, true);


	IMAGEMANAGER->addFrameImage("�����", "Images/bazziRight.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("������", "Images/bazziLeft.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("�����", "Images/bazziUp.bmp", 308, 60, 6, 1, true);
	IMAGEMANAGER->addFrameImage("������", "Images/bazziDown.bmp", 308, 60, 6, 1, true);
	ANIMANAGER->addDefAnimation("�����", "�����", 5, false, true);
	ANIMANAGER->addDefAnimation("������", "������", 5, false, true);
	ANIMANAGER->addDefAnimation("������", "������", 5, false, true);
	ANIMANAGER->addDefAnimation("�����", "�����", 5, false, true);


	SCENEMANAGER->changeScene("����");

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