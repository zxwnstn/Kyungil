#pragma once
#include "Etc/stdafx.h"


class Image
{
public:
	enum IMAGE_LOAD_KIND {
		LOAD_RESOURCE,	//���ν� �ε�
		LOAD_FILE,		//���Ϸε�
		LOAD_EMPTY,		//�� ��Ʈ�� ����
		LOAD_END
	};

	typedef struct tagImage {
		DWORD		resID;
		HDC			hMemDC;		//�޸�
		HBITMAP		hBit;		//��Ʈ��
		HBITMAP		hOBit1;		//���� ��Ʈ��
		int			width;		//�̹��� ����
		int			height;		//�̹��� ����
		BYTE		loadType;
		float		x, y;
		int			currentFrameX;
		int			currentFrameY;
		int			maxFrameX;
		int			maxFrameY;
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
	LPIMAGE_INFO	_imageInfo;	//�̹��� ����
	char			_fileName[255];	//�̹��� �̸�
	bool			_isTrans;	//���� ������
	COLORREF		_transColor;//���� ���� RGB

public:

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));

	//������ �̹��� ���Ϸ� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	HRESULT init(const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool isTrans = false, COLORREF transColor = RGB(255, 0, 255));
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();

	//�Ϲ� ����
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight);

	//������ ����
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	//�̹��� �ڵ鷯
	inline float getX() { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }
	inline float getY() { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y; }

	inline void setCenter(float x, float y) {
		_imageInfo->x = x - (_imageInfo->width) / 2;
		_imageInfo->y = y - (_imageInfo->height) / 2;
	}
	inline int getWidth() { return _imageInfo->width; }
	inline int getHeight() { return _imageInfo->height; }

	//BoudBox
	inline RECT getBoundingBox() {
		RECT rc = RectMakeCenter(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
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

