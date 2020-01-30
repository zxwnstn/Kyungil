#pragma once
#include "SystemObject/Image.h"

class ImageManager {
public:
	HRESULT init();
	void release();

public:
	//키값으로 빈 비트맵 추가
	Image* addImage(std::string strKey, int width, int height);
	Image* addImage(std::string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transCollor = RGB(0, 0, 0));
	Image* addImage(std::string strKey, const char* fileName, int x, int y, int width, int height, bool isTrans = false, COLORREF transCollor = RGB(0, 0, 0));

	//프레임 비트맵 추가
	Image* addFrameImage(std::string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	Image* addFrameImage(std::string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	
	//이미지 찾기, 삭제
	Image* findImage(std::string strkey);
	bool deleteImage(std::string strKey);
	bool deleteAll();

	//Render
	void render(std::string strKey, HDC hdc);
	void render(std::string strKey, HDC hdc, int destX, int destY);
	void render(std::string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//FrameRender
	void frameRender(std::string strKey, HDC hdc, int destX, int destY);
	void frameRender(std::string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//LoopRender
	void loopRender(std::string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(std::string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

private:
	typedef std::map<std::string, class Image*> mapImageList;
	typedef std::map<std::string, Image*>::iterator mapImageIter;
	mapImageList _mImageList;

private:
	DECLARE_SINGLE(ImageManager)
};

#define IMAGEMANAGER ImageManager::GetInst()