#pragma once
#include "Item.h"
#include "Character.h"

class Shop
{
private:
	std::vector<Item>	itemList;
	Character*			visitor;
	bool				shoppingEnd;
	int					inputKey;

private:
	void				resetItem();
	void				render();
	void				showList();
	void				showItemInfo();
	void				getInput();
	void				update();
	void				letShopping();
	bool				isInIdex(int);
	void				buy(ItemIdex, int);

public:
	void				run(Character*);
	void				init();

public:
	Shop();
	~Shop();
};

