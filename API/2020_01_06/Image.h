#pragma once
#include "stdafx.h"
class Image
{
public:
	enum IMAGE_LOAD_KIND{
		LOAD_RESOURCE,	//리로스 로딩
		LOAD_FILE ,		//파일로딩
		LOAD_EMPTY,		//빈 비트맵 파일
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

		tagImage() {
			resID		=	0;
			hMemDC		=	NULL;
			hBit		=	NULL;
			hOBit1		=	NULL;
			width		=	0;
			height		=	0;
			loadType	=	LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

	Image();
	~Image();

private:
	LPIMAGE_INFO	_imageInfo;	//이미지 정보
	char			_fileName[255];	//이미지 이름
	bool			_isTrans;	//배경색 날리기
	COLORREF		_transColor;//배경색 날릴 RGB

public:

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, bool isTrans, COLORREF transColor = RGB(255, 0, 255));
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

};

