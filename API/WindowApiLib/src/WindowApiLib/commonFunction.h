#pragma once
#include "macro.h"
#include "type.h"

//Line
inline void DrawLine(const HDC& hdc, int x1, int y1, int x2, int y2) {
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}
inline void DrawLine(const HDC& hdc, const POINT& a, const POINT& b) {
	MoveToEx(hdc, a.x, a.y, NULL);
	LineTo(hdc, b.x, b.y);
}

//Init Rect
inline RECT MakeRect(int x, int y, int width, int height) {
	RECT rc = { x, y, x + width, y + height };
	return rc;
}
inline FRECT MakeFRect(float x, float y, float width, float height) {
	FRECT frc = { x, y, x + width, y + height };
	return frc;
}
inline RECT MakeRectFromCenter(int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	RECT rc = { x - halfWidth , y - halfHeight, x + halfWidth , y + halfHeight };
	return rc;
}

//Draw Rect
inline void DrawRect(const HDC& hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x, y, x + width, y + height);
}
inline void DrawRect(const HDC& hdc, const RECT& rc) {
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
inline void DrawRectFromCenter(const HDC& hdc, int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	Rectangle(hdc, x - halfWidth, y - halfHeight, x + halfWidth, y + halfHeight);
}
inline void DrawRectFromCenter(const HDC& hdc, const RECT& rc) {
	int halfWidth = (rc.left + rc.right) / 2;
	int halfHeight = (rc.top + rc.bottom) / 2;
	Rectangle(hdc, rc.left - halfWidth, rc.top - halfHeight, rc.right + halfWidth, rc.bottom + halfHeight);
}
inline void DrawFRect(const HDC& hdc, const FRECT& frc) {
	Rectangle(hdc, frc.left, frc.top, frc.right, frc.bottom);
}

//Draw Circle
inline void DrawCircle(const HDC& hdc, int x, int y, int r) {
	Ellipse(hdc, x - r, y - r, x + r, y + r);
}
inline void DrawCircle(const HDC& hdc, const POINT& pt, int r) {
	Ellipse(hdc, pt.x - r, pt.y - r, pt.x + r, pt.y + r);
}

//Draw Ellipse
inline void DrawEllipse(const HDC& hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x, y, x + width, y + height);
}
inline void DrawEllipse(const HDC& hdc, const RECT& rc) {
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
inline void DrawEllipseFromCenter(const HDC& hdc, int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	Ellipse(hdc, x - halfWidth, y - halfHeight, x + halfWidth, y + halfHeight);
}

//마우스 충돌
inline bool isCursorInRect(const POINT& pt, const RECT& rect) {
	int x = pt.x;
	int y = pt.y;

	return (((rect.left <= x) && (x <= rect.right)) && ((rect.top <= y) && (y <= rect.bottom)));
}
inline bool isCursorInRect(const LPARAM& lParam, const RECT& _rect) {
	int x = LOWORD(lParam);
	int y = HIWORD(lParam);

	return (((_rect.left <= x) && (x <= _rect.right)) && ((_rect.top <= y) && (y <= _rect.bottom)));
}

//사각 충돌
inline bool isCollision(const RECT& _rect1, const RECT& _rect2) {
	if (_rect1.left < _rect2.right && _rect1.right > _rect2.left)
		if (_rect1.top < _rect2.bottom && _rect1.bottom > _rect2.top)
			return true;
	return false;
}
inline bool isCollision(const FRECT& _rect1, const FRECT& _rect2) {
	if (_rect1.left < _rect2.right && _rect1.right > _rect2.left)
		if (_rect1.top < _rect2.bottom && _rect1.bottom > _rect2.top)
			return true;
	return false;
}

//사각형 벗어남 체크
inline bool isInWindow(const RECT& _rect) {
	return ((0 < _rect.left) && (_rect.right < WINSIZEX) && (0 < _rect.top) && (_rect.bottom < WINSIZEY));
}

inline bool isInWindow(const FRECT& _rect) {
	return ((0 < _rect.left) && (_rect.right < WINSIZEX) && (0 < _rect.top) && (_rect.bottom < WINSIZEY));
}

//내부 외부 사각형 벗어남 체크
inline bool isInRange(const RECT& _inner_rect, const RECT& _outer_rect) {
	return ((_outer_rect.left < _inner_rect.left) && (_inner_rect.right <= _outer_rect.right) && 
		(_outer_rect.top < _inner_rect.top) && (_inner_rect.bottom < _outer_rect.bottom));
}

//rect move
inline void MoveRect(RECT& rect, Direction dir, int deltaDist) {
	switch (dir) {
	case eUp:
		rect.bottom -= deltaDist;
		rect.top -= deltaDist;
		break;
	case eDown:
		rect.bottom += deltaDist;
		rect.top += deltaDist;
		break;
	case eLeft:
		rect.left -= deltaDist;
		rect.right -= deltaDist;
		break;
	case eRight:
		rect.left += deltaDist;
		rect.right += deltaDist;
		break;
	}
}

inline void MoveFRect(FRECT& rect, Direction dir, float deltaDist) {
	switch (dir) {
	case eUp:
		rect.bottom -= deltaDist;
		rect.top -= deltaDist;
		break;
	case eDown:
		rect.bottom += deltaDist;
		rect.top += deltaDist;
		break;
	case eLeft:
		rect.left -= deltaDist;
		rect.right -= deltaDist;
		break;
	case eRight:
		rect.left += deltaDist;
		rect.right += deltaDist;
		break;
	}
}

inline void MoveFRect(FRECT& rect, float dx, float dy) {
	rect.left += dx;
	rect.right += dx;
	rect.bottom += dy;
	rect.top += dy;
}

inline int getRnd(int _max) {
	return rand() % _max;
}
