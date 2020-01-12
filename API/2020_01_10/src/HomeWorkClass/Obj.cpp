#include "Obj.h"

//¸µ
void Ring::update(PlayerState pState, float DeltaTime)
{
	//whats the bug here?
	if (pState & playerRunning) {
		//it's not working
		//collider.left -= (DeltaTime * ObjSpeed) * 2;
		//collider.right -= (DeltaTime * ObjSpeed) * 2;

		//but it's ok
		collider.left -= (DeltaTime * ObjSpeed);
		collider.right -= (DeltaTime * ObjSpeed);
		collider.left -= (DeltaTime * ObjSpeed);
		collider.right -= (DeltaTime * ObjSpeed);
	}
	else {
		collider.left -= DeltaTime * ObjSpeed;
		collider.right -= DeltaTime * ObjSpeed;
	}
}

void Ring::firstRender(HDC memDC)
{
	backRing->render(memDC, collider.left - backRing->getWidth() / 2, collider.top - backRing->getHeight());
}

void Ring::secondRender(HDC memDC)
{
	frontRing->render(memDC, collider.left + backRing->getWidth() / 2, collider.top - backRing->getHeight());
}


//ÇâÃÊ
void Incense::update(PlayerState pState, float DeltaTime)
{
	if (pState & playerRunning) {
		collider.left -= DeltaTime * ObjSpeed;
		collider.right -= DeltaTime * ObjSpeed;
	}
}

void Incense::firstRender(HDC memDC)
{
	img_incense->render(memDC, collider.left - 10, collider.top - 10);
}

void Incense::secondRender(HDC memDC)
{
}


//°ñ
void Goal::update(PlayerState pState, float DeltaTime)
{
	if(pState & playerRunning) {
		collider.left -= DeltaTime * ObjSpeed;
		collider.right -= DeltaTime * ObjSpeed;
	}
}

void Goal::firstRender(HDC memDC)
{
	img_goal->render(memDC, collider.left - 5, collider.top - 10);
}

void Goal::secondRender(HDC memDC)
{
}


