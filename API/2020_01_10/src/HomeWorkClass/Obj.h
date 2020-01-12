#pragma once
#include "Etc/stdafx.h"


class Obj {
protected:
	RECT collider;
	float ObjSpeed;

public:
	Obj(RECT& _collider, float _speed) {
		collider.left = _collider.left;
		collider.right = _collider.right;
		collider.top = _collider.top;
		collider.bottom = _collider.bottom;

		ObjSpeed = _speed;
	}

	virtual void update(PlayerState pState, float DeltaTime) = 0;
	virtual void firstRender(HDC memDC) = 0;
	virtual void secondRender(HDC memDC) = 0;
	virtual string getType() = 0;
	RECT& getCollier() {
		return collider;
	}
};

class Ring : public Obj {
	Image* frontRing;
	Image* backRing;

public:
	Ring(RECT& collider, Image* front, Image* back, float _speed)
		: Obj(collider, _speed), frontRing(front), backRing(back)
	{}

	void update(PlayerState pState, float DeltaTime) override;
	void firstRender(HDC memDC) override;
	void secondRender(HDC memDC) override;
	string getType() override { return "Ring"; }

};

class Incense : public Obj {
	Image* img_incense;

public:
	Incense(RECT& collider, Image* img, float _speed = 20.f)
		: Obj(collider, _speed), img_incense(img)
	{}

	void update(PlayerState pState, float DeltaTime) override;
	void firstRender(HDC memDC) override;
	void secondRender(HDC memDC) override;
	string getType() override { return "Incense"; }
};

class Goal : public Obj {
	Image* img_goal;

public:
	Goal(RECT& collider, Image* img, float _speed = 20.f)
		: Obj(collider, _speed), img_goal(img)
	{}

	void update(PlayerState pState, float DeltaTime) override;
	void firstRender(HDC memDC) override;
	void secondRender(HDC memDC) override;
	string getType() override { return "Goal"; }
};