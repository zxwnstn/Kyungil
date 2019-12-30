#pragma once


inline POINT PointMake(int x, int y) {
	return POINT{ x, y };
}

inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2) {
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

inline RECT RectMake(int x, int y, int width, int height) {
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	RECT rc = { x - halfWidth , y - halfHeight, x + halfWidth , y + halfHeight };
	return rc;
}

inline void RectangleDraw(HDC hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x, y, x + width, y + height);
}


inline void RectangleDraw(HDC hdc, RECT rc) {
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}


inline void RectangleDrawCenter(HDC hdc, int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	Rectangle(hdc, x - halfWidth, y - halfHeight, x + halfWidth, y + halfHeight);
}

inline void EllipseDraw(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseDrawCenter(HDC hdc, int x, int y, int width, int height) {
	int halfWidth = width / 2;
	int halfHeight = height / 2;
	Ellipse(hdc, x - halfWidth, y - halfHeight, x + halfWidth, y + halfHeight);
}