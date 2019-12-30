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
	cout << "===========아이템 목록=================" << endl;
	for (int i = 0; i < itemList.size(); ++i) {
		cout << i + 1 << ". " << itemList[i].name << " : " << itemList[i].price << " x " << itemList[i].num << endl;
	}
	cout << "\n" << endl;
	cout << "현재 소지금 : " << visitor->gold << "\n\n";
}

void Shop::showItemInfo()
{
	using namespace std;
	cout << "보고싶은 아이템의 목록 번호를 입력해 주세요" << endl;
	int tempInput;
	while (1) {
		cin >> tempInput;
		if (isInIdex(tempInput)) {
			system("cls");
			itemList[tempInput - 1].itemShowInfo();
			break;
		}
		else {
			cout << "목록을 벗어나는 숫자를 입력하셧습니다" << endl;
		}
	}
	system("pause");
	showList();
}

void Shop::getInput()
{
	using namespace std;
	std::cout << "물건 사기 : 1\n물건 정보보기 : 2\n아이템 팔기 : 3\n상점나가기 : 0" << std::endl;
	while (1) {
		std::cin >> inputKey;
		if (0 <= inputKey && inputKey <= 2)
			return;
		cout << "잘못 입력하셧습니다 다시 입력해 주세요" << endl;
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
	cout << "사고싶은 아이템 목록 번호를 입력해 주세요(구매 취소는 0)" << endl;
	int tempInput;
	while (1) {
		cin >> tempInput;
		if (tempInput == 0) {
			cout << "신중하게 고민하시게~" << endl;
			break;
		}
		else if (isInIdex(tempInput)) {
			auto& wantedItem = itemList[tempInput - 1];
			//상점템이 하나 이상일때
			char tp;
			if (wantedItem.num > 1) {
				cout << "해당아이템은 두개 이상있습니다. 한번에 여러개를 사시겟습니까? y/n" << endl;
				cin >> tp;
				//여러개 사기
				if (tp == 'y' || tp == 'Y') {
					cout << "몇개를 시사겟습니까?" << endl;
					int tempNum;
					while (1) {
						cin >> tempNum;
						if (tempNum < 0 || tempNum > wantedItem.num) {
							cout << "여분개수를 초과하는 숫자 일세.. 다시 입력해 주게나.." << endl;
						}
						else break;
					}
					int totalPrice = wantedItem.price * tempNum;
					cout << wantedItem.name << " " << wantedItem.num << "개는 " << totalPrice
						<< "원 입니다, 정말 구매하시겟습니까? y/n\n";
					cin >> tp;
					if (tp == 'Y' || tp == 'y') {
						buy(wantedItem.itemidx, tempNum);
						break;
					}
					else {
						cout << "신중하게 고민하시게~" << endl;
						break;
					}
				}
				//한개 사기
				else {
					cout << wantedItem.name << "은(는) " << wantedItem.price
						<< "입니다, 정말 구매하시겟습니까? y/n\n";
					cin >> tp;
					//구매 확정
					if (tp == 'y' || tp == 'Y') {
						buy(wantedItem.itemidx, 1);
						break;
					}
					//구매 취소
					else {
						cout << "신중하게 고민하시게~" << endl;
						break;
					}
				}
			}
			//상점템이 한개 일때
			else {
				cout << wantedItem.name << "은(는) " << wantedItem.price
					<< "입니다, 정말 구매하시겟습니까? y/n\n";
				cin >> tp;
				//구매 확정
				if (tp == 'y' || tp == 'Y') {
					buy(wantedItem.itemidx, 1);
					break;
				}
				//구매 취소
				else {
					cout << "신중하게 고민하시게~" << endl;
					break;
				}
			}	
		}
		else {
			cout << "목록을 초과하는 번호입니다. 다시 입력해 주세요" << endl;
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
		cout << "고마우이~" << endl;
		it->num -= _num;
		visitor->gold -= _num * it->price;
		visitor->getItem(_idx, _num);
		if (it->num == 0)
			itemList.erase(it);
	}
	else {
		cout << "돈이 부족하잖아~" << endl;
	}
}


void Shop::run(Character* crt)
{
	visitor = crt;
	shoppingEnd = false;
	system("cls");
	std::cout << "어서오세요 창렬이의 잡화상점에 오신걸 환영합니다~!" << std::endl;
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
