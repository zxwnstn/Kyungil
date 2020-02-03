#include "stdafx.h"
#include "UTILS.h"

namespace UTIL
{
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY -  startY;
		return sqrtf(x * x + y * y);
	}

	float getAngle(float src_x, float src_y, float tar_x, float tar_y)
	{
		float dx = src_x - tar_x;
		float dy = src_y - tar_y;
		float angle =0.f;
		float distance = sqrtf(dx * dx + dy * dy);

		if (dx < 0 && dy < 0)
			angle = PI2 - acosf(dx / distance);
		if (dx < 0 && dy > 0)
			angle = PI + acosf(dx / distance);
		if (dx > 0 && dy > 0)
			angle = acosf(dx / distance);
		if (dx > 0 && dy < 0)
			angle = PI - acosf(dx / distance);

		return angle;
	}

	bool isCircleCircleCollision(Circle& c1, Circle& c2) {
		float dist = getDistance(c1.p.x, c1.p.y, c2.p.x, c2.p.y);
		if (dist <= c1.radius + c2.radius)
			return true;
		return false;
	}

	bool isCircleRectCollision(Circle & c1, FRECT rect)
	{
		rect.left -= c1.radius;
		rect.top -= c1.radius;
		rect.right += c1.radius;
		rect.bottom += c1.radius;

		if (rect.left <= c1.p.x  && c1.p.x <= rect.right)
			if(rect.top <= c1.p.y  && c1.p.y <= rect.bottom)
				return true;

		return false;
	}

	bool isRectRectCollision(const RECT & rect1, const RECT & rect2)
	{
		if (rect1.left < rect2.right && rect1.right > rect2.left &&
			rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
			return true;
		}
		return false;
	}
	bool isRectRectCollision(const RECT & rect1, const FRECT & rect2)
	{
		if (rect1.left < rect2.right && rect1.right > rect2.left &&
			rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
			return true;
		}
		return false;
	}


	bool isRectRectCollision(const FRECT & rect1, const FRECT & rect2)
	{
		if (rect1.left < rect2.right && rect1.right > rect2.left &&
			rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
			return true;
		}
		return false;
	}

	bool isRectRectCollision(const IRECT & rect1, const IRECT & rect2)
	{
		if (rect1.left < rect2.right && rect1.right > rect2.left &&
			rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
			return true;
		}
		return false;
	}
	bool isRectRectCollision(const IRECT & rect1, const RECT & rect2)
	{
		if (rect1.left < rect2.right && rect1.right > rect2.left &&
			rect1.top < rect2.bottom && rect1.bottom > rect2.top) {
			return true;
		}
		return false;
	}

	bool isPointRectCollision(const POINT & point, const RECT & rect)
	{
		if ((rect.left < point.x && point.x < rect.right) &&
			(rect.top < point.y && point.y < rect.bottom))
			return true;
		return false;
	}

	bool isPointRectCollision(const POINT & point, const FRECT & rect)
	{
		if ((rect.left < point.x && point.x < rect.right) &&
			(rect.top < point.y && point.y < rect.bottom))
			return true;
		return false;
	}

	bool isPointRectCollision(const FPOINT & point, const RECT& rect) {
		if ((rect.left < point.x && point.x < rect.right) &&
			(rect.top < point.y && point.y < rect.bottom))
			return true;
		return false;
	}

	bool isPointRectCollision(const FPOINT & point, const FRECT& rect) {
		if ((rect.left < point.x && point.x < rect.right) &&
			(rect.top < point.y && point.y < rect.bottom))
			return true;
		return false;
	}

	bool isPointRectCollision(const POINT & point, const IRECT & rect)
	{
		if ((rect.left <= point.x && point.x <= rect.right) &&
			(rect.top <= point.y && point.y <= rect.bottom))
			return true;
		return false;
	}

	bool isPixelColorSame(HDC _targetImgDC, const POINT & _destPos, COLORREF _targetColor)
	{
		COLORREF originColor = GetPixel(_targetImgDC, _destPos.x, _destPos.y);

		if (originColor != _targetColor)
			return false;
		return true;
	}

	bool isPixelColorSame(HDC _targetImgDC, const int _x, const int _y, COLORREF _targetColor)
	{
		COLORREF originColor = GetPixel(_targetImgDC, _x, _y);

		if (originColor != _targetColor)
			return false;
		return true;
	}

	bool isRectColorSame(HDC _targetImgDC, const RECT& rect, int _divisionX, int _divisionY, COLORREF _targetColor)
	{
		assert(_divisionX >= 0);
		assert(_divisionY >= 0);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		float divisionWidth = width / _divisionX;
		float divisionHeight = height / _divisionY;


		for (float i = rect.left; i <= rect.right; i += divisionWidth) {
			for (float j = rect.top; j <= rect.bottom; j += divisionHeight) {
				COLORREF originColor = GetPixel(_targetImgDC, i, j);
				if (originColor != _targetColor)
					return false;
			}
		}
		return true;
	}

	bool isRectColorSame(HDC _targetImgDC, const IRECT& rect, int _divisionX, int _divisionY, COLORREF _targetColor)
	{
		assert(_divisionX >= 0);
		assert(_divisionY >= 0);

		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		float divisionWidth = width / _divisionX;
		float divisionHeight = height / _divisionY;


		for (float i = rect.left; i <= rect.right; i += divisionWidth) {
			for (float j = rect.top; j <= rect.bottom; j += divisionHeight) {
				COLORREF originColor = GetPixel(_targetImgDC, i, j);
				if (originColor != _targetColor)
					return false;
			}
		}
		return true;
	}


	bool operator==(const IRECT& rect1, const IRECT& rect2) {
		if (rect1.left == rect2.left && rect1.right == rect2.right &&
			rect1.top == rect2.top && rect1.bottom == rect2.bottom)
			return true;
		return false;
	}

	void _tagIrect::moveUp(int dist) {
		top -= dist;
		bottom -= dist;
	}
	void _tagIrect::moveDown(int dist) {
		top += dist;
		bottom += dist;
	}
	void _tagIrect::moveLeft(int dist) {
		left -= dist;
		right -= dist;
	}
	void _tagIrect::moveRight(int dist) {
		left += dist;
		right += dist;
	}
	void _tagIrect::reset() {
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

	//포인트
	POINT PointMake(int x, int y)
	{
		POINT pt = { x ,y };
		return pt;
	}

	//선그리는 함수
	void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
	{
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
	}

	//RECT만들기(좌상단 기준)
	RECT RectMake(int x, int y, int width, int height)
	{
		RECT rc = { x,y, x + width, y + height };
		return rc;
	}

	FRECT FRectMake(float x, float y, float width, float height)
	{
		UTIL::FRECT rc = { x,y, x + width, y + height };
		return rc;
	}

	//RECT만들기(중심점으로 부터)
	RECT RectMakeCenter(int x, int y, int width, int height)
	{
		RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
		return rc;
	}

	FRECT FRectMakeCenter(float x, float y, float width, float height)
	{
		FRECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

		return rc;
	}

	//사각형 그리기
	void RectangleMake(HDC hdc, int x, int y, int width, int height)
	{
		Rectangle(hdc, x, y, x + width, y + height);
	}

	void drawRect(HDC hdc, const RECT & rect)
	{
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}

	void DrawColorRect(HDC hdc, const RECT & rect, bool _cleanEdge, COLORREF color) {
		HBRUSH oldBrush, curBrush;
		HGDIOBJ oldPen;
		curBrush = CreateSolidBrush(color);
		oldBrush = (HBRUSH)SelectObject(hdc, curBrush);

		SelectObject(hdc, curBrush);
		if (_cleanEdge)
			oldPen = SelectObject(hdc, GetStockObject(NULL_PEN));

		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

		SelectObject(hdc, oldBrush);
		if (_cleanEdge)
			SelectObject(hdc, oldPen);

		DeleteObject(curBrush);
	}

	//사각형 그리기(중심점)
	void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
	{
		Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
	}

	void DrawRect(HDC hdc, const RECT & rect) {
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}

	//원그리기
	void EllipseMake(HDC hdc, int x, int y, int width, int height)
	{
		Ellipse(hdc, x, y, x + width, y + height);
	}

	//원그리기(중심점)
	void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
	{
		Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
	}

	//IRECT
	void DrawColorRect(HDC hdc, const IRECT & rect, bool _cleanEdge, COLORREF color) {
		HBRUSH oldBrush, curBrush;
		HGDIOBJ oldPen;
		curBrush = CreateSolidBrush(color);
		oldBrush = (HBRUSH)SelectObject(hdc, curBrush);

		SelectObject(hdc, curBrush);
		if (_cleanEdge)
			oldPen = SelectObject(hdc, GetStockObject(NULL_PEN));

		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

		SelectObject(hdc, oldBrush);
		if (_cleanEdge)
			SelectObject(hdc, oldPen);

		DeleteObject(curBrush);
	}

	void drawRect(HDC hdc, const UTIL::IRECT & rect)
	{
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}

	IRECT IRectMake(int x, int y, int width, int height)
	{
		IRECT rc = { x,y, x + width, y + height };
		return rc;
	}

	IRECT IRectMakeCenter(int x, int y, int width, int height)
	{
		IRECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
		return rc;
	}

	int getInt(int num)
	{
		return rand() % num;
	}

	int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
}