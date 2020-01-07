#pragma once
#include "stdafx.h"
class Image
{
public:
	enum IMAGE_LOAD_KIND{
		LOAD_RESOURCE,	//���ν� �ε�
		LOAD_FILE ,		//���Ϸε�
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
	LPIMAGE_INFO	_imageInfo;	//�̹��� ����
	char			_fileName[255];	//�̹��� �̸�
	bool			_isTrans;	//���� ������
	COLORREF		_transColor;//���� ���� RGB

public:

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height, bool isTrans, COLORREF transColor = RGB(255, 0, 255));
	void setTransColor(bool isTrans, COLORREF transColor);

	void release();
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

};

