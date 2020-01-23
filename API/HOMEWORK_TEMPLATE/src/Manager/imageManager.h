#pragma once
#include "stdafx.h"

class ImageManager {
public:
	HRESULT init();
	void release();

public:
	//키값으로 빈 비트맵 추가
	Image* addImage(tstring strKey, int width, int height);
	Image* addImage(tstring strKey, const TCHAR* fileName, int width, int height, bool isTrans = false, COLORREF transCollor = RGB(0, 0, 0));
	Image* addImage(tstring strKey, const TCHAR* fileName, int x, int y, int width, int height, bool isTrans = false, COLORREF transCollor = RGB(0, 0, 0));

	//프레임 비트맵 추가
	Image* addFrameImage(tstring strKey, const TCHAR* fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	Image* addFrameImage(tstring strKey, const TCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	
	//이미지 찾기, 삭제
	Image* findImage(tstring strkey);
	bool deleteImage(tstring strKey);
	bool deleteAll();

	//Render
	void render(tstring strKey, HDC hdc);
	void render(tstring strKey, HDC hdc, int destX, int destY);
	void render(tstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//FrameRender
	void frameRender(tstring strKey, HDC hdc, int destX, int destY);
	void frameRender(tstring strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//LoopRender
	void loopRender(tstring strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(tstring strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

private:
	typedef std::map<tstring, class Image*> mapImageList;
	typedef std::map<tstring, Image*>::iterator mapImageIter;
	mapImageList _mImageList;

private:
	DECLARE_SINGLE(ImageManager)
};

