#pragma once
#include "Scene.h"
#include "Game/GameObject/Character.h"

class MapScene :
	public Scene
{
public:
	MapScene();
	~MapScene();

public:
	bool init() override;
	void update(float _deltaTime) override;
	void release() override;
	void setData(int type) override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

private:
	std::shared_ptr<Character> character;
	Image* backGround = nullptr;
};

