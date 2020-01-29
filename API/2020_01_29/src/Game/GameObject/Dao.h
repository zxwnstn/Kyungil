#pragma once
#include "Character.h"

class Dao :
	public Character
{
public:
	Dao();
	~Dao();
public:
	bool init() override;
	void update(float _deltaTime) override;

public:
	void afterRender(HDC hdc) override;
};

