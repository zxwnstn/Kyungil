#pragma once
//게임 내에서 쓰이는 Enum과 구조체 메크로 등을 정의 합니다.

#define TILESIZE 32 //오른쪽 화면 타일 사이즈
#define TILEX 20	//왼쪽화면 타일 사이즈 X
#define TILEY 20	//왼쪽화면 타일 사이즈 Y

#define TILESIZEX TILEX * TILESIZE
#define TILESIZEY TILEY * TILESIZE

//화면 오른쪽 이미지 타일 갯수
#define SAMPLETILEX 20
#define SAMPLETILEY 8

//맵툴에서 사용할 녀석
enum CTRL
{
	CTRL_SAVE,
	CTRL_LOAD,
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_MAP1,
	CTRL_MAP2,
	CTRL_END
};

//지형(EX.밟을때 사운드를 나게 하거나 이동할 수 없는 지역등등)
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//오브젝트(EX :지형위쪽에 배치. 움직이거나 부서지거나 하는 녀석 등등 변화를 줄수 있는 물체)
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
//위치 좌표
enum POS
{
	POS_FLAG1,
	POS_FLAG2,
	POS_TANK1,
	POS_TANK2

};
//타일 구조체
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
//이미지 타일 구조체
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;

};
//현재 타일 구조체
struct tagCurrentTile
{
	int x;
	int y;
};