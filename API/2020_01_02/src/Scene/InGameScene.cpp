#include "InGameScene.h"
#include "../Obj/Player.h"
#include "../Obj/Tile.h"
#include "Manager/Input/InputManager.h"


//플래피버드
//두더지
//슈팅대전 스킬(6개)

void InGameScene::genDung()
{
	
}


void InGameScene::update(float deltaTime)
{
	for (auto& e : objs) 
		e->update(deltaTime);
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
	objs.push_back(new Player(this, FRECT(10.f, 0.f, 110.f, 100.f), 400.f));
	objs.push_back(new Tile(this, FRECT(0.f, 400.f, 300.f, 450.f)));
	//objs.push_back(new Tile(this, FRECT(800.f, 500.f, 1200.f, 550.f)));
}


InGameScene::~InGameScene()
{
	for (int i = 0; i < objs.size(); ++i)
		delete objs[i];
	
}

Scene* CreateScene(HDC hdc) {
	return new InGameScene(hdc);
}