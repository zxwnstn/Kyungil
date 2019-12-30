#pragma once
#include <string>
#include "type.h"

class Item {
public:
	std::string name;
	std::string descript;

	int pDp = 0;
	int pAp = 0;
	int mAp = 0;
	int mDp = 0;
	int recoverHp = 0;
	int recoverMp = 0;
	int price = 0;
	int num;
	int type;
	ItemIdex itemidx;
	bool isEquiped;

public:
	Item();
	Item(ItemIdex, int);
	~Item();
	void itemShowInfo();
};

