#include "CharacterSelectScene.h"



CharacterSelectScene::CharacterSelectScene()
{
}


CharacterSelectScene::~CharacterSelectScene()
{
}

bool CharacterSelectScene::init()
{
	bazziRect = UTIL::RectMake(100, 200, 216, 256);
	daoRect = UTIL::RectMake(400, 200, 216, 256);
	dizniRect = UTIL::RectMake(700, 200, 216, 256);

	bazziImg = IMAGEMANAGER->findImage("¹èÂî");
	daoImg = IMAGEMANAGER->findImage("´Ù¿À");
	dizniImg = IMAGEMANAGER->findImage("µðÁî´Ï");


	return true;
}

void CharacterSelectScene::update(float _deltaTime)
{
	if (UTIL::isPointRectCollision(m_ptMouse, bazziRect))
		mouseSettedBazzi = true;
	else mouseSettedBazzi = false;

	if (UTIL::isPointRectCollision(m_ptMouse, daoRect))
		mouseSettedDao = true;
	else mouseSettedDao = false;

	if (UTIL::isPointRectCollision(m_ptMouse, dizniRect))
		mouseSettedDizni = true;
	else mouseSettedDizni = false;


	if (mouseSettedDao && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)) {
		SCENEMANAGER->changeScene("¸Ê");
		SCENEMANAGER->getCurScene()->setData(0);
	}
	if (mouseSettedDizni && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)) {
		SCENEMANAGER->changeScene("¸Ê");
		SCENEMANAGER->getCurScene()->setData(1);
	}
	if (mouseSettedBazzi && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)) {
		SCENEMANAGER->changeScene("¸Ê");
		SCENEMANAGER->getCurScene()->setData(2);
	}
}

void CharacterSelectScene::release()
{
}

void CharacterSelectScene::render(HDC hdc)
{
	UTIL::DrawColorRect(hdc, bazziRect, true, RGB(188, 255, 255));
	UTIL::DrawColorRect(hdc, daoRect, true, RGB(188, 255, 255));
	UTIL::DrawColorRect(hdc, dizniRect, true, RGB(188, 255, 255));

	bazziImg->render(hdc, bazziRect.left, bazziRect.top);
	daoImg->render(hdc, daoRect.left, daoRect.top);
	dizniImg->render(hdc, dizniRect.left, dizniRect.top);
}

void CharacterSelectScene::afterRender(HDC hdc)
{
}

void CharacterSelectScene::debugRender(HDC hdc)
{
	/*UTIL::DrawColorRect(hdc, bazziRect, RGB(255, 0, 0));
	UTIL::DrawColorRect(hdc, daoRect, RGB(0, 255, 0));
	UTIL::DrawColorRect(hdc, dizniRect, RGB(0, 0, 255));*/
}
