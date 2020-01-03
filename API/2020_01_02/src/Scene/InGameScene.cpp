#include "InGameScene.h"
#include "Manager/Input/InputManager.h"


//플래피버드
//두더지
//슈팅대전 스킬(6개)

void InGameScene::genDung()
{
	int xPos = getRnd(WINSIZEX - 50);
	Box* b = new Box(xPos, 0, xPos + 10, 10, 400.f);
	objs.push_back(b);
}


void InGameScene::update(float deltaTime)
{
	timeLapse += deltaTime;
	if (timeLapse > genTime) {
		timeLapse -= genTime;
		if (getRnd(100) < 70)
			genDung();
	}

	for (auto& e : objs) {
		e->update(deltaTime);
	}

	for (auto it = objs.begin(); it != objs.end(); ) {
		if ((*it)->life == false) {
			delete *it;
			it = objs.erase(it);
		}
		else ++it;
	}
}

void InGameScene::render(HDC hdc)
{
	HBITMAP bit = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	SelectObject(memDC, bit);
	
	//DrawRect(memDC, 0, 0, WINSIZEX, WINSIZEY);
	for (int i = 0; i < objs.size(); ++i)
		objs[i]->render(memDC);

	BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, memDC, 0, 0, SRCCOPY);
	DeleteObject(bit);
}

InGameScene::InGameScene(HDC hdc)
{
	memDC = CreateCompatibleDC(hdc);
	Obj* p = new Player(200.f, 450.f, 250.f, 500.f, 500.f);
	objs.push_back(p);
}


InGameScene::~InGameScene()
{
	for (int i = 0; i < objs.size(); ++i){
		delete objs[i];
	}
}

Scene* CreateScene(HDC hdc) {
	return new InGameScene(hdc);
}