#include "InGameScene.h"
#include "Manager/Input/InputManager.h"
void InGameScene::genBox()
{
}
void InGameScene::update(float deltaTime)
{
	timeLapse += deltaTime;
	if (timeLapse > genTime) {
		timeLapse -= genTime;
		if (getRnd(100) < 20) {
			Box b;
			int xPos = getRnd(WINSIZEX - 50);
			b.outerLine.left = xPos;
			b.outerLine.top = 0;
			b.outerLine.right = xPos + 50;
			b.outerLine.bottom = 50;
			DungList.push_back(b);
		}
	}

	FRECT temp = player();
	FRECT temp2 = player();
	
	MoveFRect(temp2, eDown, deltaTime * player.speed);
	if (isInWindow(temp2))
		MoveFRect(player(), eDown, deltaTime * player.speed);

	if (GET_SINGLE(InputManager)->isStayKeyDown(VK_LEFT)) {
		MoveFRect(temp, eLeft, deltaTime * player.speed);
		if (isInWindow(temp))
			MoveFRect(player(), eLeft, deltaTime * player.speed);
	}
	if (GET_SINGLE(InputManager)->isStayKeyDown(VK_RIGHT)) {
		MoveFRect(temp, eRight, deltaTime * player.speed);
		if (isInWindow(temp))
			MoveFRect(player(), eRight, deltaTime * player.speed);
	}

	for (auto it = DungList.begin(); it != DungList.end();) {
		MoveFRect((*it)(), eDown, deltaTime * it->speed);
		if (it->outerLine.bottom > WINSIZEY)
			it = DungList.erase(it);
		else it++;	
	}


}

void InGameScene::render(HDC hdc)
{
	DrawFRect(hdc, player());
	for (auto it = DungList.begin(); it != DungList.end(); ++it) {
		DrawFRect(hdc, (*it)());
	}
}


InGameScene::InGameScene()
{
	
}


InGameScene::~InGameScene()
{
}

Scene* CreateScene() {
	return new InGameScene;
}