#include <iostream>
#include <vector>
using namespace std;

const int WIDTH = 300;
const int HEIGHT = 200;

enum Terrain {
	TERRAIN_GRASS,
	TERRAIN_HILL,
	TERRAIN_RIVER
};

class TerrainB {
	int movementCost;
	bool isWater;
	Terrain terrain;

public:
	TerrainB() 
	{}
	TerrainB(int _movementCost, bool _isWater, Terrain _terrain)
		: movementCost(_movementCost), isWater(_isWater), terrain(_terrain)
	{}

	int getMovementCost() const {
		return movementCost;
	}
	bool isWater() const {
		return isWater;
	}
	const Terrain& getTexture() const {
		return terrain;
	}
};

int getRndNum(const int _bound) {
	return rand() % _bound;
}

class WorldB {
private:
	TerrainB grassTerrain_;
	TerrainB hillTerrain_;
	TerrainB riverTerrain_;

private:
	TerrainB* tiles[WIDTH][HEIGHT]; //

public:
	WorldB()
		: grassTerrain_(1, false, TERRAIN_GRASS),
		hillTerrain_(3, false, TERRAIN_HILL),
		riverTerrain_(2, true, TERRAIN_RIVER)
	{}

	void generateTerrain() {
		//�淮 ����
		//���� Ÿ�� ��ü�� 3���μ� �ʿ� �ִ� ��� Ÿ����
		//�� 3���� ��ü�� �����ͷ� ������ ���̴�.
		//������ �������� �ʿ��� �����ʹ� ���� ����
		//�̷��� ����ϴ°��� �淮 �����̶� �Ѵ�.
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				if (getRndNum(10) == 0) 
					tiles[i][j] = &hillTerrain_;
				else
					tiles[i][j] = &grassTerrain_;
			}
		}
		int x = getRndNum(WIDTH);
		for (int y = 0; y < HEIGHT; ++y)
			tiles[y][x] = &riverTerrain_;
	}

	const TerrainB& getTile(int x, int y) const {
		return *tiles[y][x];
	}
};