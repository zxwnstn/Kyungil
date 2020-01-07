#pragma once
#include "Etc/stdafx.h"

class Image
{
public:
	enum IMAGE_LOAD_KIND {
		LOAD_RESOURCE,			//리소스 로딩
		LOAD_FILE,				//파일로딩
		LOAD_EMPTY,				//빈 비트맵 파일
		LOAD_END
	};

	typedef struct tagImage {
		DWORD		resID;
		HDC			hMemDC;		//메모리
		HBITMAP		hBit;		//비트맵
		HBITMAP		hOBit1;		//기존 비트맵
		int			width;		//이미지 가로
		int			height;		//이미지 세로
		BYTE		loadType;
		float		x, y;
		//bmp 분할
		int			currentFrameX;	//offset x(출력할 x left)
		int			currentFrameY;	//offset y(출력할 y top)
		int			maxFrameX;		//x축 분할수
		int			maxFrameY;		//y축 분할수
		int			FrameWidth;	
		int			FrameHeight;


		tagImage() {
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit1 = NULL;
			x = 0.f;
			y = 0.f;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			FrameWidth = 0;
			FrameHeight = 0;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

	Image();
	~Image();

private:
	LPIMAGE_INFO	_imageInfo;		//이미지 정보
	char			_fileName[255];	//이미지 이름
	bool			_isTrans;		//배경색 날리기
	COLORREF		_transColor;	//배경색 날릴 RGB

public:
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//프레임 이미지 파일로 초기화
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	void setTransColor(bool isTrans, COLORREF transColor);

	//이미지 릴리즈
	void release();

	//일반 렌더
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight);

	//프레임(애니매이션) 렌더
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);


	//이미지 핸들러
	inline HDC getMemDC() { return _imageInfo->hMemDC; }
	inline float getX() { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }
	inline float getY() { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	inline void setCenter(float x, float y) {
		_imageInfo->x = x - (_imageInfo->width) / 2;
		_imageInfo->y = y - (_imageInfo->height) / 2;
	}
	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	//BoudBox
	inline RECT getBoundingBox() {
		RECT rc;
		if (_imageInfo->maxFrameX > 1 || _imageInfo->maxFrameY > 1)
			rc = RectMake(_imageInfo->x, _imageInfo->y, _imageInfo->FrameWidth, _imageInfo->FrameHeight);
		else
			rc = RectMake(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
		return rc;
	}
	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX) {
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}
	inline int getFrameY() { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY) {
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	//getter
	inline int getFrameWidth() { return _imageInfo->FrameWidth; }
	inline int getFrameheight() { return _imageInfo->FrameHeight; }
	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }
	

};

