#pragma once
#include "Common/singletonBase.h"
#include "Image.h"

class imageManager :public singletonBase<imageManager>
{
private:
	typedef map<string, class Image*> mapImageList;
	typedef map<string, Image*>::iterator mapImageIter;
	
	mapImageList _mImageList;

public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	//Ű������ �� ��Ʈ�� �߰�
	Image* addImage(string strKey, int width, int height);
	Image* addImage(string strKey, const char* fileName, int width, int height, bool isTrans, COLORREF transCollor);
	Image* addImage(string strKey, const char* fileName, int x, int y, int width, int height, bool isTrans, COLORREF transCollor);

	//������ ��Ʈ�� �߰�
	Image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	Image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transCollor);
	
	//�̹��� ã��, ����
	Image* findImage(string strkey);
	bool deleteImage(string strKey);
	bool deleteAll();

	//render
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

};

