#pragma once
#include "Item.h"
#include <vector>
class Character
{
	int					hp;
	int					mp;
	int					pAp;  //���� ����
	int					pDp;  //���� ���
	int					mAp;  //���� ����
	int					mDp;  //���� ���
	int					exp;  //����ġ
	std::vector<Item>	characterItemList;
	std::vector<Item>	characterEquipList;

public:
	int					gold;
	int					equipState;

private:
	void				show();
	void				letEquip();
	void				equipItem(int);

public:
	void				run();
	void				itemUpdate(std::string, int);
	void				getItem(ItemIdex, int);	
	void				disItem();
	void				useItem();

public:
	Character(int);
	~Character();
};

