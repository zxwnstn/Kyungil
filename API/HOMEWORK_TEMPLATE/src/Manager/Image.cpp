#include "Image.h"

//for alpha blending library
#pragma comment(lib, "msimg32.lib")

Image::Image()
	: _imageInfo(NULL), _isTrans(false), _transColor(RGB(0, 0, 0))
{
}


Image::~Image()
{
	SAFE_DELETE(_imageInfo);
}

HRESULT Image::init(int width, int height)
{
	if (_imageInfo != nullptr) {
		release();
	}

	HDC hdc = GetDC(m_hWnd);
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit1 = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_isTrans = false;
	_transColor = RGB(0, 0, 0);

	if (_imageInfo->hBit == NULL) {
		release();
		return E_FAIL;
	}


	return S_OK;
}

HRESULT Image::init(const char * fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL)
		return E_FAIL;
	if (_imageInfo != NULL)
		release();
	for (int i = 0; i < 255; ++i) {
		if (fileName[i] == NULL) {
			break;
		}
		_fileName[i] = fileName[i];
	}
	HDC hdc = GetDC(m_hWnd);
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit1 = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);
	strcpy_s(_fileName, len + 1, fileName);
	_isTrans = isTrans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL) {
		release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::init(const char * fileName, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL)
		return E_FAIL;
	if (_imageInfo != NULL)
		release();
	for (int i = 0; i < 255; ++i) {
		if (fileName[i] == NULL) {
			break;
		}
		_fileName[i] = fileName[i];
	}

	HDC hdc = GetDC(m_hWnd);
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit1 = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->currentFrameY = frameY - 1;
	_imageInfo->FrameWidth = width / frameX;
	_imageInfo->FrameHeight = height / frameY;
	_imageInfo->currentFrameX = frameX;
	_imageInfo->currentFrameY = frameY;

	int len = strlen(fileName);
	strcpy_s(_fileName, len + 1, fileName);
	_isTrans = isTrans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL) {
		release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::init(const char * fileName, int x, int y, int width, int height, int frameX, int frameY, bool isTrans, COLORREF transColor)
{
	if (fileName == NULL)
		return E_FAIL;
	if (_imageInfo != NULL)
		release();
	for (int i = 0; i < 255; ++i) {
		if (fileName[i] == NULL) {
			break;
		}
		_fileName[i] = fileName[i];
	}

	HDC hdc = GetDC(m_hWnd);
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(m_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit1 = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;
	_imageInfo->currentFrameY = frameY - 1;
	_imageInfo->FrameWidth = width / frameX;
	_imageInfo->FrameHeight = height / frameY;
	_imageInfo->currentFrameX = frameX;
	_imageInfo->currentFrameY = frameY;

	int len = strlen(fileName);
	strcpy_s(_fileName, len + 1, fileName);
	_isTrans = isTrans;
	_transColor = transColor;

	if (_imageInfo->hBit == NULL) {
		release();
		return E_FAIL;
	}
	return S_OK;
}

void Image::setTransColor(bool isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void Image::release()
{
	if (_imageInfo) {
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit1);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SAFE_DELETE(_imageInfo);
		
		_isTrans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void Image::render(HDC hdc)
{
	if (_isTrans) {
		//비트맵을 불러올때, 특정색상을 제외하고 복사하는 함수
		GdiTransparentBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC,
							   0, 0, _imageInfo->width, _imageInfo->height, _transColor);
	}
	else {
		//SRCCOPY : 가로세로를 재정의해서 복사하겟다.
		//DC간 데이터를 고속 복사
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 
					0, 0, SRCCOPY);
	}
}

void Image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans) {
		GdiTransparentBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC,
							   0, 0, _imageInfo->width, _imageInfo->height, _transColor);
	}
	else {
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC,
					0, 0, SRCCOPY);
	}
}

//dest는 뿌릴곳 src는 뿌려올곳(?)
void Image::render(HDC hdc, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight)
{
	if (_isTrans) {
		GdiTransparentBlt(hdc, destX, destY, srcWidth, srcHeight, _imageInfo->hMemDC,
		srcX, srcY, srcWidth, srcHeight, _transColor);
	}
	else {
		BitBlt(hdc, destX, destY, srcWidth, srcHeight, _imageInfo->hMemDC,
			srcX, srcY, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, int destX, int destY)
{
	if (_isTrans) {
		GdiTransparentBlt(hdc, destX, destY, _imageInfo->FrameWidth, _imageInfo->FrameHeight, _imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->FrameWidth, _imageInfo->currentFrameY * _imageInfo->FrameHeight, 
			_imageInfo->FrameWidth, _imageInfo->FrameHeight, _transColor);
	}
	else {
		BitBlt(hdc, destX, destY, _imageInfo->FrameWidth, _imageInfo->FrameHeight, _imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->FrameWidth, _imageInfo->currentFrameY * _imageInfo->FrameHeight, SRCCOPY);
	}
}

void Image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;
	if (_isTrans) {
		GdiTransparentBlt(hdc, destX, destY, _imageInfo->FrameWidth, _imageInfo->FrameHeight, _imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->FrameWidth, _imageInfo->currentFrameY * _imageInfo->FrameHeight,
			_imageInfo->FrameWidth, _imageInfo->FrameHeight, _transColor);
	}
	else {
		BitBlt(hdc, destX, destY, _imageInfo->FrameWidth, _imageInfo->FrameHeight, _imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->FrameWidth, _imageInfo->currentFrameY * _imageInfo->FrameHeight, SRCCOPY);
	}
}
