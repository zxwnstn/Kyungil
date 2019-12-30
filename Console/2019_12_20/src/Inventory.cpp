#include "Inventory.h"



void Inventory::render()
{
}

void Inventory::update()
{
}

void Inventory::getInput()
{
}

void Inventory::run()
{
	isCheckingInventory = true;
	while (!isCheckingInventory) {
		render();
		getInput();
		update();
	}
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::init(Character * _crt)
{
	owner = _crt;
}
