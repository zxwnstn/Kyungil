#pragma once
#include "Object.h"

class Character :
	public Object
{
public:
	Character();
	~Character();

public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

public:
	int getSpeed()			{ return speed; }
	int getBombRange()		{ return bombRange; }
	int getBombLimit()		{ return bombLimit; }
	std::string getName()	{ return name; }

protected:
	int speed;
	int bombRange;
	int bombLimit;
	std::string name;
	UTIL::IRECT collisionRect;
	std::bitset<10> state;

protected:
	Animation* aniUp;
	Animation* aniDown;
	Animation* aniLeft;
	Animation* aniRight;
	Image* img;
};

