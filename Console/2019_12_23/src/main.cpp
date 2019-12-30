// Power2_inline_asm.c
// compile with: /EHsc
// processor: x86
#include <iostream>
#include <vector>
#include "Çì´õ.h"
#include <string>
using namespace std;

class Item {
public:
	ItemNumber itemNum;
	string name;
	string description;
	int atkP = 0;
	int defP = 0;
	int price;

	Item(ItemNumber _itemNum)
	{
		itemNum = _itemNum;
		switch (_itemNum)
		{
		case greateBoots:
			name = "±×·¹ÀÌÆ® ºÎÃ÷";
			description = "´Ü´ÜÇÑ ºÎÃ÷´Ù";
			defP = 30;
			price = 3000;
			break;
		case poorBoots:
			name = "°ÅÁö ºÎÃ÷";
			description = "ÇìÁø ºÎÃ÷´Ù";
			defP = 10;
			price = 300;
			break;
		case greateHelmet:
			name = "±×·¹ÀÌÆ® Çï¸ä";
			description = "´Ü´ÜÇÑ Çï¸äÀÌ´Ù";
			defP = 20;
			price = 2000;
			break;
		case poorHelmet:
			name = "°ÅÁö Çï¸ä";
			description = "ÇìÁø Çï¸äÀÌ´Ù";
			defP = 5;
			price = 200;
			break;
		}
	}
	~Item()
	{}

	void print() {
		cout << name << "\n";
		cout << description << "\n";
		cout << defP << "\n";
		cout << price << "\n";
	}
};


int main(void)
{
	vector<Item> v;
	v.push_back(Item(greateBoots));
	v.push_back(Item(poorBoots));
	v.push_back(Item(greateHelmet));
	v.push_back(Item(poorHelmet));

	vector<int> 
		itemList;
	itemList;

	for (int i = 0; i < v.size(); ++i) {
		v[i].print();
	}


	return 0;
}
