#pragma once
#include "Scene.h"

class MapEdit : public Scene
{
private:
	//세이브, 로드, 지형, 오브젝트, 지우개 등등등
	HANDLE file;
	DWORD write;
	int pos[2];

	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX* TILEY];
	tagSampleTile _sampleTiles[SAMPLETILEX * SAMPLETILEY];

public:
	MapEdit();
	~MapEdit();

	bool init() override;	
	void release() override;
	void update(float _deltaTime) override;

	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;

	void maptoolSetup();
	void setMap();

	void save();
	void load();
	void setCtrSelect(int num) { _ctrSelect = num; }

public:
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) override;

private:
	int _ctrSelect;
};