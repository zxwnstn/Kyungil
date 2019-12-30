#include "Character.h"
#include <stdio.h>
#include <iostream>
#include <string>

void Character::show() {
	system("cls");
	printf("체력 : %d\n", hp);
	printf("마나 : %d\n", mp);
	printf("\n");
	printf("물리 공격 : %d\n", pAp);
	printf("물리 방어 : %d\n", pDp);
	printf("마법 공격 : %d\n", mAp);
	printf("마법 방어 : %d\n", mDp);
	printf("경험치 : %d\n", exp);
	printf("\n");
	printf("소지금 : %d\n", gold);
	printf("\n");
	printf("\n--현재 소지하고 있는 아이템 목록--\n");
	for (auto &e : characterItemList)
		std::cout << e.name << " x " << e.num << "\n";

	system("pause");
}

void Character::letEquip()
{
}

void Character::run()
{
	show();
}

void Character::itemUpdate(std::string _temName, int inOrOut)
{
	
}

void Character::getItem(ItemIdex _idx, int num)
{
	for (auto &e : characterItemList) {
		if (e.itemidx == _idx) {
			e.num += num;
			return;
		}
	}
	characterItemList.push_back(Item(_idx, num));
}

void Character::disItem()
{
}

void Character::equipItem(int itemType)
{
	if (itemType & equipState) {

	}
}

void Character::useItem()
{
}


Character::Character(int _money)
	:hp(100), mp(60), gold(_money), pAp(8), pDp(2), mAp(5), mDp(0), exp(0), equipState(0)
{
}

Character::~Character()
{
}
