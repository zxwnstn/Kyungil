#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

typedef string Item;

class Inventory 
{
public:
	void showInven() 
	{
		cout << "=========== 인벤 아이템 목록 ===============" << endl;
		for (int i = 0; i < inven_items.size(); ++i) 
		{
			cout << inven_items[i] << endl;
		}
		cout << endl;
	}

	void init() {
		inven_items.push_back("낡은 검");
		inven_items.push_back("낡은 신발");
		inven_items.push_back("낡은 영환");
	}


	Item pop_item(Item _item)
	{
		for (auto it = inven_items.begin(); it != inven_items.end(); ++it) 
		{
			if (*it == _item) {
				inven_items.erase(it);
				return _item;
			}
		}
		return "없음";
	}

	void push_item(Item _item) {
		inven_items.push_back(_item);
	}

private:
	vector<Item> inven_items;

};




class person {

public:
	void push_Item(Item _item){
		inven.push_item(_item);
	}

	Item pop_Item(Item _item) {
		Item item = inven.pop_item(_item);
		return item;
	}

	void init() {
		inven.init();
		gold = 500;
	}

	void showItems() {
		inven.showInven();
	}

private:
	Inventory inven;
	int gold;
};




class store {
public:
	void enterVisitor(person* _visitor) {
		visitor = _visitor;
		cout << "손님이 입장 하셧습니다." << endl;
	}
	void leaveVisitor() {
		if (visitor != nullptr) {
			visitor = nullptr;
			cout << "손님이 떠낫습니다." << endl;
		}
	}

	void visitor_Buy_Item(Item _item) 
	{
		for (auto it = store_items.begin(); it != store_items.end(); ++it) 
		{
			if (*it == _item) 
			{
				store_items.erase(it);
				visitor->push_Item(_item);
				cout << "손님이" << _item << " 아이템을 샀습니다" << endl;
				return;
			}
		}
		cout << "손님이 원하는 아이템이 없습니다!" << endl;
	}

	void visitor_Sell_Item(Item _item) 
	{
		Item item = visitor->pop_Item(_item);
		
		if (item == "없음") {
			cout << "손님의 인벤 목록에 " << _item << "이 없습니다" << endl;
		}
		else {
			store_items.push_back(item);
			cout << "손님의 인벤 목록에 " << _item << "이 있었습니다, 상점의 아이템 목록에 추가했습니다" << endl;
		}
	}

	void showStoreItem() {
		cout << "=========== 상점 아이템 목록 ===============" << endl;
		for (int i = 0; i < store_items.size(); ++i) {
			cout << store_items[i] << endl;
		}
		cout << endl;
	}

	void init() {
		store_items.push_back("소검");
		store_items.push_back("대검");
		store_items.push_back("날카로운검");
		store_items.push_back("영환이 검");
	}

private:
	person* visitor = nullptr;
	vector<Item> store_items;
};


int main() {
	person youngHwan;
	youngHwan.init();

	store junsooStore;
	junsooStore.init();

	cout << "이닛 하고 직후" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();



	junsooStore.enterVisitor(&youngHwan);

	junsooStore.visitor_Buy_Item("소검");
	junsooStore.visitor_Buy_Item("대검");
	junsooStore.visitor_Buy_Item("태환사신기");

	cout << "쇼핑 중" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();

	junsooStore.visitor_Sell_Item("낡은 검");
	junsooStore.visitor_Sell_Item("미친놈");

	cout << "쇼핑 마침" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();

	junsooStore.leaveVisitor();
}