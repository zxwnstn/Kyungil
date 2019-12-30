#pragma once
#include "Item.h"
#include <vector>
class Character
{
	int					hp;
	int					mp;
	int					pAp;  //물리 공격
	int					pDp;  //물리 방어
	int					mAp;  //마법 공격
	int					mDp;  //마법 방어
	int					exp;  //경험치
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

