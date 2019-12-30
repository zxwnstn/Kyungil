#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
//
///*
//	������ :
//	�޸� �ּҸ� ������ ������ ����
//	�����͸� �����Ҷ��� ����Ʈ8(*�ֽ��͸���ũ)�� ������ ����Ѵ�.
//	
//	��� �������� �޸��� �ּҰ��� �������ִ�.
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
//	//&�� ������ ������ �ּҸ� �˼��ִ�.
//	cout << &num << endl;
//
//	//������ �������� �Ϲ����� �������� ������ ����, �ּҰ��� ������ �ִ�.
//	//int* ptr = reinterpret_cast<int*>(num);
//
//	int* p = &num;
//
//	cout << "p�� �� : " << p << endl;
//	cout << "p�� �ּҰ� : " << &p << endl;
//
//	//�������� �ϸ� ���� �������ų� �����Ҽ� �ִ�.
//	cout << "������ : " << *p << endl;
//	*p = 777;
//	cout << "�������� " << num << endl;
//
//	//�����͸� �������� ���� �����Ҽ� �ִ� ���� �������� �ٽ��̴�.
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
//	//16����, 2����, ��Ʈ, ����Ʈ,
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
	char cardShape[4][3] = { "��","��","��","��" };
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
		cout << turn + 1 << "��° ���Դϴ�!" << endl;
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

	int getJudge(int player_call) {  // 0 - �й�, 1 - �Ϲ� �¸�, 2 - ���� �¸� ,  0 - ����, 1 - �ο�, 2 - ����
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
				cout << "���� �� ���� �� ū �ݾ��� �����ϽǼ��� �����ϴ�" << endl;
				cout << "�ٽ� �Է��� �ּ��� : ";
			}
			else break;
		}	
	}
	void call() {
		cout << "����(0), �ο�(1), ����(2) : ";
		while (1) {
			cin >> myCall;
			if (myCall < 0 || myCall > 2) {
				cout << "�߸��� ���� �Է��ϼ˽��ϴ�. �ٽ� �Է��� �ּ��� : ";
			}
			else break;
		}
		
	}

public:
	Player(int _money)
		: money(_money) 
	{}
	void showInfo() {
		cout << "���� ������ : " << money << endl;
	}
	
	void betting() {
		cout << "������ �ݾ��� �Է��� �ּ��� : ";
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

	void resultHandle(int resultInfo) { // 0 - �й�, 1 - �Ϲ� �¸�, 2 - ���� �¸�
		if (resultInfo == 1) {
			cout << "�¸��ϼ˽��ϴ�!" << endl;
			money += bet * 2;
		}
		else if (resultInfo == 2) {
			cout << "����!! �¸��ϼ˽��ϴ�!" << endl;
			money += bet * 10;
		}
		else if (resultInfo == 0) {
			cout << "�й��ϼ˽��ϴ�" << endl;
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
	cout << "���� ��� 5���� �и� ���� ������ ���� ���ڸ� �����մϴ�\n"
		<< "������ �ϰ� ������ ���ڰ� 7���� Ŭ������ ����Ǹ� ����! ���������� ����Ǹ� �ο�!\n"
		<< "�׸��� 7�� ���������� ����Ǹ� ����! �� �Է��մϴ�.\n"
		<< "������ ������� ������ �ݾ��� 2�踦 �Ұ� �ǰ� Ʋ����� ������ �ݾ׸�ŭ �Ұ� �˴ϴ�.\n"
		<< "���� ������ ������ �¾Ҵٸ� ���þ��� 10�踦 ��� �˴ϴ�.\n\n"
		<< "���ӿ��� �ѹ� ������ ī��� ������ ī��� �������� ������,\n"
		<< "���� �ִ� ��� ī�带 ���� �ǰų� �Ļ��ϸ� ������ ����˴ϴ�.\n";
	system("pause");
	system("cls");
	cout << "�׷� ������ ���Կ�~" << endl;
	Sleep(1500);
	system("cls");
}

int main() {
	srand(time(NULL));
	int startMoney = 10000;
	printStartInfo();
	while (1) {		
#ifdef SET_START_MONEY
		cout << "���� �������� �Է��� �ּ��� : ";
		cin >> startMoney;
		system("cls");
#endif
		if (run(startMoney))
			cout << "�Ļ��ϼ˽��ϴ�" << endl;
		else
			cout << "���� ���� �ִ� ī�带 �پ��˽��ϴ�." << endl;
		Sleep(1000);

		cout << "������ �ٽ� �Ͻðٽ��ϱ�? y/n " << endl;
		char temp;
		cin >> temp;
		if (temp == 'n' || temp == 'N')
			break;
		system("cls");
	}
	cout << "���α׷��� �����մϴ�" << endl;
	return 0;
}