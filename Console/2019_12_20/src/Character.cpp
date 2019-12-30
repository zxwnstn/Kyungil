#include "Character.h"
#include <stdio.h>
#include <iostream>
#include <string>

void Character::show() {
	system("cls");
	printf("ü�� : %d\n", hp);
	printf("���� : %d\n", mp);
	printf("\n");
	printf("���� ���� : %d\n", pAp);
	printf("���� ��� : %d\n", pDp);
	printf("���� ���� : %d\n", mAp);
	printf("���� ��� : %d\n", mDp);
	printf("����ġ : %d\n", exp);
	printf("\n");
	printf("������ : %d\n", gold);
	printf("\n");
	printf("\n--���� �����ϰ� �ִ� ������ ���--\n");
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
