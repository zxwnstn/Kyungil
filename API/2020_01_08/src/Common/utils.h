#pragma once

#define PI		3.141592653
#define PI2		PI*2
namespace UTIL
{
	struct FPOINT {
		float x, y;
	};
	struct Circle {
		FPOINT p;
		int radius;
	};
	struct FRECT {
		float left, top, right, bottom;
	};


	//°Å¸®
	float getDistance(float startX, float startY, float endX, float endY);

	float getAngle(float x1, float y1, float x2, float y2);

	bool isCircleCircleCollision(Circle& c1, Circle& c2);

	bool isCircleRectCollision(Circle& c1, FRECT rect);

	bool isRecRectCollision(RECT& rect1, RECT& rect2);

}