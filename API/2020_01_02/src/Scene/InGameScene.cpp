#include "InGameScene.h"
#include "Manager/Input/InputManager.h"
void InGameScene::update(float deltaTime)
{
	if(GET_SINGLE(InputManager)->isStayKeyDown(VK_UP))
		MoveFRect(player(), eUp, deltaTime * player.pSpeed);
	if (GET_SINGLE(InputManager)->isStayKeyDown(VK_DOWN))
		MoveFRect(player(), eDown, deltaTime * player.pSpeed);
	if (GET_SINGLE(InputManager)->isStayKeyDown(VK_LEFT))
		MoveFRect(player(), eLeft, deltaTime * player.pSpeed);
	if (GET_SINGLE(InputManager)->isStayKeyDown(VK_RIGHT))
		MoveFRect(player(), eRight, deltaTime * player.pSpeed);
}

void InGameScene::render(HDC hdc)
{
	DrawFRect(hdc, player());
}

bool InGameScene::init()
{
	player.outerLine = { 0, 0, 100, 100 };
	return true;
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