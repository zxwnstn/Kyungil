#pragma once
#include"gameNode.h"
#define TILESIZE 32 //������ ȭ�� Ÿ�� ������
#define TILEX 20	//����ȭ�� Ÿ�� ������ X
#define TILEY 20	//����ȭ�� Ÿ�� ������ Y

#define TILESIZEX TILEX * TILESIZE
#define TILESIZEY TILEY * TILESIZE

//ȭ�� ������ �̹��� Ÿ�� ����
#define SAMPLETILEX 20
#define SAMPLETILEY 8

//����(EX.������ ���带 ���� �ϰų� �̵��� �� ���� �������)
enum TERRAIN
{
	TR_CEMENT, TR_DESERT,TR_GRASS,TR_WATER,TR_END
};

//������Ʈ(EX :�������ʿ� ��ġ. �����̰ų� �μ����ų� �ϴ� �༮ ��� ��ȭ�� �ټ� �ִ� ��ü)
enum OBJECT
{
	OBJ_BLOCK1,
	OBJ_BLOCK3,
	OBJ_BLOCKS,
	OBJ_FLAG1,
	OBJ_FLAG2,
	OBJ_TANK1,
	OBJ_TANK2,
	OBJ_NONE
};
//��ġ ��ǥ
enum POS
{
	POS_FLAG1,
	POS_FLAG2,
	POS_TANK1,
	POS_TANK2

};
//Ÿ�� ����ü
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};
//�̹��� Ÿ�� ����ü
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
	
};
//���� Ÿ�� ����ü
struct tagCurrentTile
{
	int x;
	int y;
};
class mainGame :  public gameNode
{
private:
	//���̺�, �ε�, ����, ������Ʈ, ���찳 ����
	HWND _btnSave;
	HWND _btnLoad;
	HWND _btnTerrainDraw;
	HWND _btnObjectDraw;
	HWND _btnEraser;

	HANDLE file;
	DWORD write;
	int pos[2];

	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX* TILEY];
	tagSampleTile _sampleTiles[SAMPLETILEX * SAMPLETILEY];

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�



	void maptoolSetup();
	void setMap();

	void save();
	void load();


	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);

	
};
/*
LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		this->setMap();
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))this->setMap();
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
		//���α׷� ������ ����ڰ� �޴� �׸��� �����ϸ� �߻��ϴ� �޼�����.
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case CTRL_SAVE:
			this->save();
			break;
		case CTRL_LOAD:
			this->load();
			InvalidateRect(hWnd, NULL, FALSE);
			break;
		default:
			this->setCtrSelect(LOWORD(wParam));
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}//end of switch

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
*/