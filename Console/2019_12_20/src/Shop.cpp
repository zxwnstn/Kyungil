#include "Shop.h"
#include <iostream>
#include <time.h>
#include <Windows.h>

Shop::Shop()
{
}


Shop::~Shop()
{
}

void Shop::resetItem()
{
	itemList.clear();
	int rnd;
	bool isAlreadyHave;
	for (int i = 0; i < 8; ++i) {
		isAlreadyHave = false;
		while (1) {
			rnd = rand() % 28;
			if (rnd < 24)
				break;		
		}
		ItemIdex rndIdx = static_cast<ItemIdex>(rnd);
		for (int i = 0; i < itemList.size(); ++i) {
			if (itemList[i].itemidx == rnd) {
				isAlreadyHave = true;
				itemList[i].num++;
				break;
			}
		}
		if (!isAlreadyHave) {
			itemList.push_back(Item(rndIdx, 1));
		}
	}
	itemList.push_back(Item(poorPortion1, 10));
	itemList.push_back(Item(poorPortion2, 10));
}



void Shop::render()
{
	showList();
	if (inputKey == 2) {
		showItemInfo();
	}
}

void Shop::showList()
{
	using namespace std;
	system("cls");
	cout << "===========������ ���=================" << endl;
	for (int i = 0; i < itemList.size(); ++i) {
		cout << i + 1 << ". " << itemList[i].name << " : " << itemList[i].price << " x " << itemList[i].num << endl;
	}
	cout << "\n" << endl;
	cout << "���� ������ : " << visitor->gold << "\n\n";
}

void Shop::showItemInfo()
{
	using namespace std;
	cout << "������� �������� ��� ��ȣ�� �Է��� �ּ���" << endl;
	int tempInput;
	while (1) {
		cin >> tempInput;
		if (isInIdex(tempInput)) {
			system("cls");
			itemList[tempInput - 1].itemShowInfo();
			break;
		}
		else {
			cout << "����� ����� ���ڸ� �Է��ϼ˽��ϴ�" << endl;
		}
	}
	system("pause");
	showList();
}

void Shop::getInput()
{
	using namespace std;
	std::cout << "���� ��� : 1\n���� �������� : 2\n������ �ȱ� : 3\n���������� : 0" << std::endl;
	while (1) {
		std::cin >> inputKey;
		if (0 <= inputKey && inputKey <= 2)
			return;
		cout << "�߸� �Է��ϼ˽��ϴ� �ٽ� �Է��� �ּ���" << endl;
	}
}


void Shop::update()
{
	if (inputKey == 0) {
		shoppingEnd = true;
		return;
	}
	if (inputKey == 1) {
		letShopping();
	}

}

void Shop::letShopping()
{
	using namespace std;
	cout << "������ ������ ��� ��ȣ�� �Է��� �ּ���(���� ��Ҵ� 0)" << endl;
	int tempInput;
	while (1) {
		cin >> tempInput;
		if (tempInput == 0) {
			cout << "�����ϰ� ����Ͻð�~" << endl;
			break;
		}
		else if (isInIdex(tempInput)) {
			auto& wantedItem = itemList[tempInput - 1];
			//�������� �ϳ� �̻��϶�
			char tp;
			if (wantedItem.num > 1) {
				cout << "�ش�������� �ΰ� �̻��ֽ��ϴ�. �ѹ��� �������� ��ðٽ��ϱ�? y/n" << endl;
				cin >> tp;
				//������ ���
				if (tp == 'y' || tp == 'Y') {
					cout << "��� �û�ٽ��ϱ�?" << endl;
					int tempNum;
					while (1) {
						cin >> tempNum;
						if (tempNum < 0 || tempNum > wantedItem.num) {
							cout << "���а����� �ʰ��ϴ� ���� �ϼ�.. �ٽ� �Է��� �ְԳ�.." << endl;
						}
						else break;
					}
					int totalPrice = wantedItem.price * tempNum;
					cout << wantedItem.name << " " << wantedItem.num << "���� " << totalPrice
						<< "�� �Դϴ�, ���� �����Ͻðٽ��ϱ�? y/n\n";
					cin >> tp;
					if (tp == 'Y' || tp == 'y') {
						buy(wantedItem.itemidx, tempNum);
						break;
					}
					else {
						cout << "�����ϰ� ����Ͻð�~" << endl;
						break;
					}
				}
				//�Ѱ� ���
				else {
					cout << wantedItem.name << "��(��) " << wantedItem.price
						<< "�Դϴ�, ���� �����Ͻðٽ��ϱ�? y/n\n";
					cin >> tp;
					//���� Ȯ��
					if (tp == 'y' || tp == 'Y') {
						buy(wantedItem.itemidx, 1);
						break;
					}
					//���� ���
					else {
						cout << "�����ϰ� ����Ͻð�~" << endl;
						break;
					}
				}
			}
			//�������� �Ѱ� �϶�
			else {
				cout << wantedItem.name << "��(��) " << wantedItem.price
					<< "�Դϴ�, ���� �����Ͻðٽ��ϱ�? y/n\n";
				cin >> tp;
				//���� Ȯ��
				if (tp == 'y' || tp == 'Y') {
					buy(wantedItem.itemidx, 1);
					break;
				}
				//���� ���
				else {
					cout << "�����ϰ� ����Ͻð�~" << endl;
					break;
				}
			}	
		}
		else {
			cout << "����� �ʰ��ϴ� ��ȣ�Դϴ�. �ٽ� �Է��� �ּ���" << endl;
		}		
	}
	system("pause");
}

bool Shop::isInIdex(int idx)
{
	if(0 <= idx - 1 && idx - 1 < itemList.size())
		return true;
	return false;
}

void Shop::buy(ItemIdex _idx, int _num)
{
	using namespace std;
	auto it = itemList.begin();
	for (it; it != itemList.end(); ++it) {
		if (it->itemidx == _idx)
			break;
	}
	
	if (visitor->gold > it->price * _num) {
		cout << "������~" << endl;
		it->num -= _num;
		visitor->gold -= _num * it->price;
		visitor->getItem(_idx, _num);
		if (it->num == 0)
			itemList.erase(it);
	}
	else {
		cout << "���� �������ݾ�~" << endl;
	}
}


void Shop::run(Character* crt)
{
	visitor = crt;
	shoppingEnd = false;
	system("cls");
	std::cout << "������� â������ ��ȭ������ ���Ű� ȯ���մϴ�~!" << std::endl;
	system("pause");
	while (!shoppingEnd) {
		render();
		getInput();
		update();
		system("cls");
	}
}

void Shop::init()
{
	srand(time(NULL));
	resetItem();
}
