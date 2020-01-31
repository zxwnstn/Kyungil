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
		cout << "=========== �κ� ������ ��� ===============" << endl;
		for (int i = 0; i < inven_items.size(); ++i) 
		{
			cout << inven_items[i] << endl;
		}
		cout << endl;
	}

	void init() {
		inven_items.push_back("���� ��");
		inven_items.push_back("���� �Ź�");
		inven_items.push_back("���� ��ȯ");
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
		return "����";
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
		cout << "�մ��� ���� �ϼ˽��ϴ�." << endl;
	}
	void leaveVisitor() {
		if (visitor != nullptr) {
			visitor = nullptr;
			cout << "�մ��� �������ϴ�." << endl;
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
				cout << "�մ���" << _item << " �������� ����ϴ�" << endl;
				return;
			}
		}
		cout << "�մ��� ���ϴ� �������� �����ϴ�!" << endl;
	}

	void visitor_Sell_Item(Item _item) 
	{
		Item item = visitor->pop_Item(_item);
		
		if (item == "����") {
			cout << "�մ��� �κ� ��Ͽ� " << _item << "�� �����ϴ�" << endl;
		}
		else {
			store_items.push_back(item);
			cout << "�մ��� �κ� ��Ͽ� " << _item << "�� �־����ϴ�, ������ ������ ��Ͽ� �߰��߽��ϴ�" << endl;
		}
	}

	void showStoreItem() {
		cout << "=========== ���� ������ ��� ===============" << endl;
		for (int i = 0; i < store_items.size(); ++i) {
			cout << store_items[i] << endl;
		}
		cout << endl;
	}

	void init() {
		store_items.push_back("�Ұ�");
		store_items.push_back("���");
		store_items.push_back("��ī�ο��");
		store_items.push_back("��ȯ�� ��");
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

	cout << "�̴� �ϰ� ����" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();



	junsooStore.enterVisitor(&youngHwan);

	junsooStore.visitor_Buy_Item("�Ұ�");
	junsooStore.visitor_Buy_Item("���");
	junsooStore.visitor_Buy_Item("��ȯ��ű�");

	cout << "���� ��" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();

	junsooStore.visitor_Sell_Item("���� ��");
	junsooStore.visitor_Sell_Item("��ģ��");

	cout << "���� ��ħ" << endl;
	youngHwan.showItems();
	junsooStore.showStoreItem();

	junsooStore.leaveVisitor();
}