#pragma once
#include "Character.h"

class Dizni
	: public Character
{
public:
	Dizni();
	~Dizni();

public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void afterRender(HDC hdc) override;
};

