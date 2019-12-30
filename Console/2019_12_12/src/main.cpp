#include "card.h"
//#define DEBUG_ENABLE
#define RUN_GAME

#ifndef RUN_GAME
/*
	�Լ�
	���� : Ư�����Ŀ� ���� ���������� ����
	���α׷��� : ���ȭ�� ��ɾ� ����

	���α׷��ֿ��� �Լ� �Է°��� ����, �μ�, �Ű���������ϸ�, ������� ��ȯ���̶�� �Ѵ�.(return value)
	�Լ��� ����ϴ� ����
	1. �ݺ����� ���α׷����� ���Ѵ�.
	2. �ڵ� ������ �����ϰ� ���������� �����ϸ� �ڵ尡 ����ȭ �ȴ�.

	�Լ��� ����
	��ȯ�ڷ��� �Լ��̸� (�Ű�������)
	{
		���๮
	}

*/

/*
	����ü
	���� : �������� ����ü
	struct MyStruct{
		int Hp;
		int Cri;
		float Mp;
		int atk;
		string name;
	};
*/

struct tagUnit {
	int Hp;
	float atk;
	bool die;
	string name;
};
// �����̸�, ��������, ��ȭ��ȣ, �������, ����, ��°�, ����, ����ΰ�, �����ϴ� ����, �̻���
struct Person {
	string fatherName;
	int fatherAge;
	string motherName;
	int motherAge;
	string brotherName;
	int brotherAge;
	string phoneCall;
	string adress;
	string favoriteFood;
	bool isHuman;
	string favoriteGame;
	string favoriteStyle;
};

inline int Max(int a, int b) {
	return a > b ? a : b;
}
inline int Min(int a, int b) {
	return a < b ? a : b;
}
#endif

void runCard() {
	Deck deck;
	int playerMoney;
	int cards[3];	   // 0 - ����ī��1, 1 - �÷��̾� ī��, 2 - ����ī��2
	int compareNum[3]; // ����� ������ ī�����
	int bet;
	bool pWin, cWin;
	int turnCnt;
	//������� ������ ��ü ���� ����
	while (1) {
		deck.reset();
		turnCnt = 0;
		playerMoney = 100000;
		cout << "ī�� ������ �����մϴ�!" << endl;
		cout << "\n������ �� : �¸��� ���ñݾ��� 2�踦 ���, �й�� ������ �ݾ׸�ŭ �Ұ� �˴ϴ�. \n �����ϼ��� ��쿡 �¸��ϽŴٸ� 3���� ������ ��� �˴ϴ�." << endl;
		cout << "�� ���� ���۽� ���� ī�� ����� Ȯ���Ҽ� �ֽ��ϴ�.\n" << endl;


		cout << "���� ������ : " << playerMoney << "��" << endl;
		system("pause");
		system("cls");
		//���� ���ӷ���
		while (1) {
			//���� ī�� Ȯ��
			char checkInput;
			cout << "Dealer : ���� ī�带 Ȯ�� �Ͻðٽ��ϱ�? y/n" << endl;
			cin >> checkInput;
			if (checkInput == 'n' || checkInput == 'N') {}
			else {
				deck.print();
				system("pause");
			}
			system("cls");

			//ī�� �ο��ޱ�
			for (int i = 0; i < 3; ++i)
				cards[i] = deck.getCardNum();

			//���� ����
			for (int i = 0; i < 3; ++i)
				compareNum[i] = cards[i] % 13 + 1;
			if ((compareNum[0] < compareNum[1] && compareNum[1] < compareNum[2]) ||
				(compareNum[2] < compareNum[1] && compareNum[1] < compareNum[0])) {
				pWin = true;
				cWin = false;
			}
			else {
				pWin = false;
				cWin = true;
			}

#ifdef DEBUG_ENABLE
			deck.print();
			showCards(cards[0], cards[1], cards[2]);
			cout << "���� ������ : " << playerMoney << "\n" << "��ī��Ʈ : " << turnCnt + 1 << "\n";
#endif

			//ùī�� ����
			cout << "Dealer : " << ++turnCnt << "��° ��! ī�带 �����մϴ�!" << endl;
			showCards(cards[0], 52, 52);

			//���� ����
			int nAddBet = 0;
			bool noMoreBet = false;
			bool forgive = false;
			bool all_In = false;
			int finalBet = 0;
			while (1) {
				char input;
				if (nAddBet == 0) {
					cout << "Dealer : �����Ͻ� �ݾ��� 1000�� �̻����� �����ּ��� 0���� �����Դϴ�(����� 1000�� �谨)." << endl;
					while (1) {
						cin >> bet;
						if (bet > playerMoney)
							cout << "Dealer : ���� ������ ���� �� ū �ݾ��� �ɼ� �����ϴ�." << endl;
						else if (bet == 0) {
							cout << "Dealer : ���̺��� �Ѥ�" << endl;
							forgive = true;
							break;
						}
						else if (bet < 1000)
							cout << "Dealer : �ּ� 1000�� �̻� �����ϼž� �մϴ�" << endl;
						else if (bet == playerMoney) {
							cout << "Dealer : �����ϼ˽��ϴ�! ����� �ٷ� Ȯ���մϴ�!" << endl;
							all_In = true;
							break;
						}
						else break;
					}
					nAddBet++;
					if (forgive || all_In)
						break;
				}
				else if (nAddBet == 1) {
					showCards(cards[0], 52, 52);
					if (playerMoney - bet - 2000 >= 0) {
						cout << "Dealer : �߰� �߰� �� Ȯ���� 2000���Դϴ�. �����Ͻðٽ��ϱ�? y/n" << endl;
						cin >> input;
						if (input == 'y' || input == 'Y') {
							bet += 2000;
							nAddBet++;
						}
						else {
							noMoreBet = true;
							break;
						}
					}
					else {
						cout << "Dealer : �߰� ������ ���� �����ñ��� �ٷ� ��� Ȯ�� �ϰٽ��ϴ�!" << endl;
						break;
					}
				}
				else if (nAddBet == 2) {
					showCards(cards[0], cards[1], 52);
					if (playerMoney - bet - 3000 >= 0) {
						cout << "Dealer : ���� �����Ͻðٽ��ϱ�? y/n" << endl;
						cin >> input;
						if (input == 'y' || input == 'Y') {
							cout << "Dealer : ������ �ݾ��� 3000�� �̻� �����ּ���" << endl;
							cout << "���� �ܾ� : " << playerMoney - bet << endl;
							while (1) {
								cin >> finalBet;
								if (finalBet < 3000)
									cout << "Dealer : 3000�� �̻� �����ּ��� �Ѥ�" << endl;
								else if (playerMoney - finalBet - bet > 0) break;
								else if (playerMoney <= finalBet + bet) {
									cout << "�����ϼ˽��ϴ�!" << endl;
									finalBet = playerMoney - bet;
									bet += finalBet;
									all_In = true;
									break;
								}
							}
							if (all_In) break;
							bet += finalBet;
							nAddBet++;
						}
						else {
							noMoreBet = true;
							break;
						}
					}
					else {
						cout << "Dealer : �߰� ������ ���� �����ñ��� �ٷ� ��� Ȯ�� �ϰٽ��ϴ�!" << endl;
						break;
					}
				}
				else if (nAddBet >= 3) {
					cout << "�и� ���� �����մϴ�!" << endl;
					showCards(cards[0], cards[1], cards[2]);
					break;
				}

				if (noMoreBet) break;
				system("cls");
			} //���÷��� ����

			//��� ����
			if (nAddBet != 3) {
				cout << "�и� ���� �����մϴ�!" << endl;
				system("pause");
				system("cls");
				showCards(cards[0], cards[1], cards[2]);
			}
			cout << "�����Ͻ� �ݾ��� " << bet << "�� �Դϴ�" << endl;
			cout << "�����?!" << endl;
			system("pause");

			if (all_In && pWin) {
				playerMoney += bet * 3;
				cout << "���ӿ��� �¸��ϼ˽��ϴ�." << "\n";
				cout << "���κ��ʽ��� 3���� ������ �޽��ϴ�! " << bet * 3 << "���� �����ϴ�! \n" << "���� ���ӸӴ� : " << playerMoney << endl;
			}
			else if (forgive) {
				playerMoney -= 1000;
				cout << "������ �����ϼ����Ƿ� 1000���� �ҽ��ϴ�" << bet * 3 << "���� �Ҿ����ϴ�!\n" << "���� ���ӸӴ� : " << playerMoney << endl;
			}
			else if (pWin) {
				playerMoney += bet * 2;
				cout << "����� �¸��ϼ˽��ϴ�!\n" << bet * 2 << "���� �����ϴ�!\n" << "���� ���ӸӴ� : " << playerMoney << endl;
			}
			else if (cWin) {
				playerMoney -= bet;
				cout << "����� �й��ϼ˽��ϴ�!\n" << bet << "���� �Ҿ����ϴ�!\n" << "���� ���ӸӴ� : " << playerMoney << endl;
			}
			cout << "\n";

			system("pause");
			//�Ļ� Ȯ��
			if (playerMoney <= 0) {
				cout << "Dealer : �Ļ��뤻" << endl;
				system("pause");
				cout << "����� ��1�� �Դϴ�." << endl;
				system("pause");
				system("cls");
				break;
			}

			//��� ī�带 �� ����Ѱ��
			if (turnCnt >= 17) {
				cout << "ī�带 ���� ����ϼ˽����� ������ �����մϴ�." << endl;
				break;
			}

			//���� ����� ����
			cout << "Dealer : ������� ���Ͻǰ���? y/n" << endl;
			char tempInput;
			cin >> tempInput;
			system("cls");
			if (tempInput == 'n' || tempInput == 'N') {
				if (playerMoney >= 1000) {
					cout << "Dealer : ������� �Ѥ�" << endl;
					break;
				}
				else {
					cout << "Dealer : ���Ť�" << endl;
					break;
				}
			}	
		}
		//�������� �� ���ο� ����
		cout << "\n";
		cout << "���ο� ������ �Ͻðٽ��ϱ�? y/n" << endl;
		char tempIn;
		cin >> tempIn;
		system("cls");
		if (tempIn == 'n' || tempIn == 'N')
			break;
	}
}

int main() {
#ifndef RUN_GAME
	//TODO : �ΰ��� ���� ���ϴ� �Լ�
	//�Է��� 2�� �޾Ƽ� 2���� ���� ��, ������ ū��

	//�Լ�
	int n1, n2;
	cin >> n1 >> n2;
	cout << "ū�� : " << max(n1, n2) << "\n";
	cout << "������ : " << min(n1, n2) << "\n";

	//����ü
	tagUnit marin;
	marin.atk = 6;
	marin.Hp = 40;
	marin.name = "Ÿ��Ŀ��";
	marin.die = false;
	boolalpha(cout);
	cout << marin.name << " " << marin.Hp << " " << marin.atk << " " << marin.die << endl;

	//TODO : ����ü�� �����̸�, ��������, ��ȭ��ȣ, �������, ����, ��°�, ����, �����ϴ� ����, �̻���
	Person Junsoo{ "������", 60, "��游", 57, "�����", 27, "010-7705-7656",
		"���� ���ı� ���ݵ� ��ƾ���Ʈ 5�� 902ȣ", "?", true, "�ð�����", "ȫ���� ������, �ڼҴ�" };
	cout << sizeof(Person) << endl;
	cout << sizeof(string) << endl;

	cout << "�ƹ��� ���� : " << Junsoo.fatherName << endl;
	cout << "�ƹ��� ���� : " << Junsoo.fatherAge << endl;
	cout << "��Ӵ� ���� : " << Junsoo.motherName << endl;
	cout << "��Ӵ� ���� : " << Junsoo.fatherAge << endl;
	cout << "���� ���� : " << Junsoo.brotherName << endl;
	cout << "���� ���� : " << Junsoo.fatherAge << endl;
	cout << "��ȭ��ȣ : " << Junsoo.phoneCall << endl;
	cout << "�ּ� : " << Junsoo.adress << endl;
	cout << "���� �����ϴ� ���� : " << Junsoo.favoriteFood << endl;
	cout << "����ΰ�? : " << Junsoo.isHuman << endl;
	cout << "�����ϴ� ���� : " << Junsoo.favoriteGame << endl;
	cout << "�̻��� : " << Junsoo.favoriteStyle << endl;

#else
	runCard();
#endif
	cout << "���α׷��� �����մϴ�" << endl;

	return 0;
}