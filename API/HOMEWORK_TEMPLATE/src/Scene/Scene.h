#pragma once

class Scene {

public:
	Scene() {};
	virtual ~Scene() {};

public:
	virtual bool init() = 0;
	virtual void update(float _deltaTime) = 0;

public:
	virtual void render(HDC hdc) = 0;
	virtual void afterRender(HDC hdc) = 0;
	virtual void debugRender(HDC hdc) = 0;
	virtual void release() = 0;
};

