#include "stdafx.h"
#include "MapEdit.h"

MapEdit::MapEdit()
{
}
MapEdit::~MapEdit()
{
}
bool MapEdit::init()
{

	IMAGEMANAGER->addFrameImage("tilemap", "../Common_Images/tilemap.bmp", 640, 256, 
		SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	maptoolSetup();

	_currentTile.x = 2;
	_currentTile.y = 0;

	return S_OK;
}

void MapEdit::release()
{
}
void MapEdit::update(float _deltaTime)
{
}

void MapEdit::render(HDC hdc)
{
	//===================================================
	IMAGEMANAGER->render("tilemap", hdc, WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth(), 0);

	for (int i = 0; i<TILEX * TILEY; i++)
	{
		IMAGEMANAGER->frameRender("tilemap", hdc, _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);

		if (_tiles[i].obj == OBJ_NONE)continue;

		IMAGEMANAGER->frameRender("tilemap", hdc, _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].objFrameX, _tiles[i].objFrameY);
	}
}

void MapEdit::afterRender(HDC hdc)
{
}

void MapEdit::debugRender(HDC hdc)
{
}

void MapEdit::maptoolSetup()
{
	CreateWindow("button", "Save", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1000, 600, 100, 30, m_hWnd, HMENU(0), m_hInstance, NULL);
	CreateWindow("button", "Load", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1150, 600, 100, 30, m_hWnd, HMENU(1), m_hInstance, NULL);
	CreateWindow("button", "Terrain", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 850, 350, 100, 30, m_hWnd, HMENU(2), m_hInstance, NULL);
	CreateWindow("button", "OBJ", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 850, 400, 100, 30, m_hWnd, HMENU(3), m_hInstance, NULL);
	CreateWindow("button", "Eraser", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 850, 450, 100, 30, m_hWnd, HMENU(4), m_hInstance, NULL);

	_ctrSelect = CTRL_TERRAINDRAW;

	//¿À¸¥ÂÊ »ùÇÃ ¸Ê ¼ÂÆÃ
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTiles[i* SAMPLETILEX + j].terrainFrameX = j;
			_sampleTiles[i* SAMPLETILEX + j].terrainFrameY = i;

			//ÁÂÇ¥°ª ¼³Á¤
			SetRect(&_sampleTiles[i*SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth()) + j * TILESIZE,
				i* TILESIZE, (WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth()) + j * TILESIZE + TILESIZE,
				i*TILESIZE + TILESIZE);
		}
	}

	//¿ÞÂÊ ¸Ê ¼ÂÆÃ
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			SetRect(&_tiles[i*TILEX + j].rc,
				j * TILESIZE,
				i * TILESIZE,
				j * TILESIZE + TILESIZE,
				i * TILESIZE + TILESIZE);
		}
	}
	//Ã³À½ ±ò·ÁÀÖ´Â Å¸ÀÏ
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tiles[i].terrainFrameX = 3;
		_tiles[i].terrainFrameY = 0;

		_tiles[i].objFrameX = 0;
		_tiles[i].objFrameY = 0;

		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		_tiles[i].obj = OBJ_NONE;
	}

}

void MapEdit::setMap()
{
	//¿À¸¥ÂÊ »ùÇÃ
	for (int i = 0; i < SAMPLETILEX* SAMPLETILEY; i++)
	{
		if (PtInRect(&_sampleTiles[i].rcTile, m_ptMouse))
		{
			_currentTile.x = _sampleTiles[i].terrainFrameX;
			_currentTile.y = _sampleTiles[i].terrainFrameY;
			break;
		}
	}
	//¿ÞÂÊ Å¸ÀÏ
	for (int i = 0; i < TILEX* TILEY; i++)
	{
		if (PtInRect(&_tiles[i].rc, m_ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_OBJDRAW)
			{
				_tiles[i].objFrameX = _currentTile.x;
				_tiles[i].objFrameY = _currentTile.y;

				_tiles[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].objFrameX = 0;
				_tiles[i].objFrameY = 0;
				_tiles[i].obj = OBJ_NONE;
			}
			InvalidateRect(m_hWnd, NULL, false);
			break;
		}
	}
}

//¿©±â Ã¤¿ö¶ó
void MapEdit::save()
{
}

//¿©±âµµ...
void MapEdit::load()
{
}

TERRAIN MapEdit::terrainSelect(int frameX, int frameY)
{
	//½Ã¸àÆ®
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	//Èë¹Ù´Ú
	else if (frameX == 2 && frameY == 0)
	{
		return TR_DESERT;
	}
	//ÀÜµð
	else if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	//¹°
	else if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}
	return TR_GRASS;
}

OBJECT MapEdit::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0)
	{
		return OBJ_TANK1;
	}
	else if (frameX == 0 && frameY == 8)
	{
		return OBJ_TANK2;
	}
	else if (frameX == 0 && frameY == 1)
	{
		return OBJ_BLOCK1;
	}
	else if (frameX == 0 && frameY == 2)
	{
		return OBJ_BLOCK3;
	}
	else if (frameX == 0 && frameY == 3)
	{
		return OBJ_BLOCKS;
	}
	return OBJ_BLOCK1;
}

LRESULT MapEdit::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		setMap();
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			setMap();
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case CTRL_SAVE:
			save();
			break;
		case CTRL_LOAD:
			load();
			InvalidateRect(hWnd, NULL, FALSE);
			break;
		default:
			setCtrSelect(LOWORD(wParam));
			break;
		}
		break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
