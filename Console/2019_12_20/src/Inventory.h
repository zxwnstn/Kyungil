#pragma once
#include "Item.h"
#include "Character.h"
class Inventory
{
private:
	bool		isCheckingInventory;
	int			inputKey;

public:
	Character*	owner;
	void		render();
	void		update();
	void		getInput();

public:
	void		run();
	void		init(Character*);


public:
	Inventory();
	~Inventory();
};

