#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
//
///*
//	포인터 :
//	메모리 주소를 값으로 가지는 변수
//	포인터를 선언할때는 쉬프트8(*애스터리스크)를 붙혀서 사용한다.
//	
//	모든 변수에는 메모리의 주소값을 가지고있다.
//	
//*/
//
//enum Color {
//	BLACK,
//	RED,
//	BLUE
//};
//
//Color operator++(const Color& c) {
//	if (c + 1 > BLUE)
//		return BLUE;
//	return Color((int)c + 1);
//}
//
//int main() {
//	int num = 10;
//	cout << num << endl;
//
//	//&를 붙히면 변수의 주소를 알수있다.
//	cout << &num << endl;
//
//	//포인터 변수에는 일반적인 변수값을 넣을수 없고, 주소값만 넣을수 있다.
//	//int* ptr = reinterpret_cast<int*>(num);
//
//	int* p = &num;
//
//	cout << "p의 값 : " << p << endl;
//	cout << "p의 주소값 : " << &p << endl;
//
//	//역참조를 하면 값을 가져오거나 변경할수 있다.
//	cout << "역참조 : " << *p << endl;
//	*p = 777;
//	cout << "역참조후 " << num << endl;
//
//	//포인터를 역참조해 값을 변경할수 있는 것을 포인터의 핵심이다.
//	int** pp;
//	pp = &p;
//	cout << pp << endl;
//
//	const char* str = "abcde";
//	cout << &str << endl;
//	cout << (int)str << endl;
//	
//	string st_r("sdkfj");
//
//	//16진수, 2진수, 비트, 바이트,
//
//	FILE* myFp;
//	
//
//
//	return 0;
//}

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
//#define SET_START_MONEY
using namespace std;
class myDeck {
public:
	int deck[52];
	int showCards[6];
	char cardShape[4][3] = { "♠","◆","♥","♣" };
	char cardNum[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int turn = 0;

private:
	void shuffle() {
		for (int i = 0; i < 777; ++i) {
			int dest, src;
			dest = rand() % 52;
			src = rand() % 52;
			swap(deck[dest], deck[src]);
		}
	}
	void init() {
		for (int i = 0; i < 52; ++i) {
			deck[i] = i;
		}
		shuffle();
		for (int i = 0; i < 6; ++i) {
			showCards[i] = deck[i];
		}
	}
	void showTurn() {
		cout << turn + 1 << "번째 턴입니다!" << endl;
	}

public:
	myDeck() {
		init();
	}
	~myDeck() {}

	void show() {
		for (int i = 0; i < 5; ++i) {
			int cardSpIdx = showCards[i] / 13;
			int cardNumIdx = showCards[i] % 13;
			cout << cardShape[cardSpIdx] << cardNum[cardNumIdx] << "\t";
		}
		cout << "??" << "\n";
		showTurn();
	}

	void nextSet() {
		for (int i = 0; i < 5; ++i) {
			showCards[i] = showCards[i + 1];
		}	
		turn++;
		showCards[5] = deck[5 + turn];
	}

	bool isEnd() {
		if (47 >= turn) 
			return true;
		return false;
	}

	int getJudge(int player_call) {  // 0 - 패배, 1 - 일반 승리, 2 - 세븐 승리 ,  0 - 하이, 1 - 로우, 2 - 세븐
		if (showCards[5] % 13 > 6) {
			if (player_call == 0) return 1;
			else if (player_call == 1) return 0;
			else if (player_call == 2) return 0;
		}
		else if (showCards[5] % 13 < 6) {
			if (player_call == 0) return 0;
			else if (player_call == 1) return 1;
			else if (player_call == 2) return 0;
		}
		else {
			if (player_call == 0) return 0;
			else if (player_call == 1) return 0;
			else if (player_call == 2) return 2;
		}
	}
};

class Player {
	int money;
	int bet;
	int myCall;

private:
	void setBet() {
		while (1) {
			cin >> bet;
			if (bet > money) {
				cout << "현재 돈 보다 더 큰 금액을 베팅하실수는 없습니다" << endl;
				cout << "다시 입력해 주세요 : ";
			}
			else break;
		}	
	}
	void call() {
		cout << "하이(0), 로우(1), 세븐(2) : ";
		while (1) {
			cin >> myCall;
			if (myCall < 0 || myCall > 2) {
				cout << "잘못된 값을 입력하셧습니다. 다시 입력해 주세요 : ";
			}
			else break;
		}
		
	}

public:
	Player(int _money)
		: money(_money) 
	{}
	void showInfo() {
		cout << "현재 소지금 : " << money << endl;
	}
	
	void betting() {
		cout << "베팅할 금액을 입력해 주세요 : ";
		setBet();
		money -= bet;
		call();
	}
	
	int getMyCall() {
		return myCall;
	}
	bool isEnd() {
		if (money <= 0)
			return true;
		return false;
	}

	void resultHandle(int resultInfo) { // 0 - 패배, 1 - 일반 승리, 2 - 세븐 승리
		if (resultInfo == 1) {
			cout << "승리하셧습니다!" << endl;
			money += bet * 2;
		}
		else if (resultInfo == 2) {
			cout << "세븐!! 승리하셧습니다!" << endl;
			money += bet * 10;
		}
		else if (resultInfo == 0) {
			cout << "패배하셧습니다" << endl;
		}
	}
};


int run(int startMoney) {
	Player player(startMoney);
	myDeck deck;
	while (!player.isEnd() || !deck.isEnd()) {
		deck.show();
		player.showInfo();
		player.betting();
		int resultInfo = deck.getJudge(player.getMyCall());
		player.resultHandle(resultInfo);
		deck.nextSet();
		Sleep(1000);
		system("cls");
	}
	if (player.isEnd())
		return 1;
	return 0;
}

void printStartInfo() {
	cout << "게임 방법 5장의 패를 보고 마지막 패의 숫자를 예측합니다\n"
		<< "베팅을 하고 마지막 숫자가 7보다 클것으로 예상되면 하이! 작을것으로 예상되면 로우!\n"
		<< "그리고 7과 같을것으로 예상되면 세븐! 을 입력합니다.\n"
		<< "예상이 맞을경우 베팅한 금액의 2배를 잃게 되고 틀릴경우 베팅한 금액만큼 잃게 됩니다.\n"
		<< "만약 세븐의 예측이 맞았다면 배팅액의 10배를 얻게 됩니다.\n\n"
		<< "게임에서 한번 등장한 카드는 마지막 카드로 등장하지 않으며,\n"
		<< "덱에 있는 모든 카드를 보게 되거나 파산하면 게임이 종료됩니다.\n";
	system("pause");
	system("cls");
	cout << "그럼 건투를 빌게요~" << endl;
	Sleep(1500);
	system("cls");
}

int main() {
	srand(time(NULL));
	int startMoney = 10000;
	printStartInfo();
	while (1) {		
#ifdef SET_START_MONEY
		cout << "시작 소지금을 입력해 주세요 : ";
		cin >> startMoney;
		system("cls");
#endif
		if (run(startMoney))
			cout << "파산하셧습니다" << endl;
		else
			cout << "덱에 남아 있는 카드를 다쓰셧습니다." << endl;
		Sleep(1000);

		cout << "게임을 다시 하시겟습니까? y/n " << endl;
		char temp;
		cin >> temp;
		if (temp == 'n' || temp == 'N')
			break;
		system("cls");
	}
	cout << "프로그램을 종료합니다" << endl;
	return 0;
}