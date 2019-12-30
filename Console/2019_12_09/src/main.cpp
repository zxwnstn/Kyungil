#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Charactor
{
	int mHp;
	string mName;
	int mAtkPoint;
	int mDefPoint;
	int mMp;
	int mCritical;

public:
	Charactor(int _hp, string _name, int _atkPoint, int _defPoint, int _mp, int _critical)
		:mHp(_hp), mName(_name), mAtkPoint(_atkPoint), mDefPoint(_defPoint), mMp(_mp), mCritical(_critical)
	{}
	virtual ~Charactor()
	{}

	int getAtkp() {
		if (rand() % 100 <= mCritical) {
			cout << "ũ��Ƽ�� ����!" << endl;
			return mAtkPoint * 2;
		}
		return mAtkPoint;
	}
	int getDefPoint() {
		return mDefPoint;
	}
	string getName() {
		return mName;
	}
	bool isDie() {
		if (!mHp)
			return true;
		return false;
	}
	void getDamage(int _damage) {
		mHp -= _damage + mDefPoint;
		if (mHp < 0)
			mHp = 0;
	}
	int getHp() {
		return mHp;
	}
};

class Babarian : public Charactor{
public:
	Babarian(const string& _name) 
		: Charactor(300, _name, 20, 10, 50, 10)
	{}
};
class Amazon : public  Charactor {
public:
	Amazon(const string& _name)
		: Charactor(150, _name, 20, 5, 70, 50)
	{}
};
class Druid : public  Charactor {
public:
	Druid(const string& _name)
		: Charactor(200, _name, 20, 5, 100, 10)
	{}
};
class Paladin : public Charactor {
public:
	Paladin(const string& _name)
		: Charactor(250, _name, 30, 7, 70, 20)
	{}
};
class Monster1 : public Charactor {
public:
	Monster1()
		: Charactor(300, string("GreatPig"), 10, 0, 50, 10)
	{}
};
class Monster2 : public Charactor {
public:
	Monster2()
		: Charactor(60, string("Moai"), 30, 0, 50, 10)
	{}
};
class Monster3 : public Charactor {
public:
	Monster3()
		: Charactor(150, string("yourFace"), 15, 20, 50, 10)
	{}
};

Charactor* CreatePlayer(int selectNum) {
	string name;
	cout << "�÷��̾� �̸��� �Է��� �ּ���" << endl;
	cin >> name;
	if (selectNum == 1)
		return new Babarian(name);
	if (selectNum == 2)
		return new Amazon(name);
	if (selectNum == 3)
		return new Druid(name);
	if (selectNum == 4)
		return new Paladin(name);
}

Charactor* CreateMonster() {
	int selectNum = rand() % 3;
	if(selectNum == 0)
		return new Monster1();
	if (selectNum == 1)
		return new Monster2();
	if (selectNum == 2)
		return new Monster3();
}

void runPaperRpg() {
	srand(time(NULL));
	while (1) {
		cout << "�ɸ��͸� ������ �ּ���" << endl;
		cout << "1. �ٹٸ��� 2. �Ƹ��� 3. ����̵� 4. �ȶ�� 0���� ������" << endl;
		int selectInput;
		cin >> selectInput;
		if (!selectInput)
			break;

		Charactor* player = CreatePlayer(selectInput);
		Charactor* monster = CreateMonster();

		cout << "������ �����մϴ�!" << endl;
		cout << "����� �̸��� " << player->getName() << " �̰� " << "����� ���ʹ� " << monster->getName() << " �Դϴ�\n\n";

		while (1) {
			if (player->isDie()) {
				cout << "����� �����ϴ� �̤�\n";
				break;
			}
			if (monster->isDie()) {
				cout << "����� �¸��Ͽ����ϴ�!\n";
				break;
			}
			cout << player->getName() << "�� ���� HP : " << player->getHp() << endl;
			cout << monster->getName() << "�� ���� HP : " << monster->getHp() << endl;

			//�÷��̾��� ����
			cout << player->getName() << "�� ����!\n";
			monster->getDamage(player->getAtkp());
			cout << monster->getName() << "�� ü���� " << monster->getHp() << "�� �Ǿ���." << endl;
			//������ ����
			if (!monster->isDie()) {
				cout << monster->getName() << "�ǰ���!\n";
				player->getDamage(monster->getAtkp());
				cout << player->getName() << "�� ü���� " << player->getHp() << "�� �Ǿ���.\n" << endl;
			}	
		}
		delete monster;
		delete player;


		cout << "\n���ο� ������ �Ͻðٽ��ϱ�? y/n" << endl;
		char a;
		cin >> a;
		if (a == 'n' || a == 'N')
			break;
	}
}

void printStar() {
	//prac1
	cout << "��µ� ���� ���̸� �Է��Ͻÿ� (exit = 0)" << endl;
	cout << "prac1" << endl;
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j)
				cout << '*';
			cout << '\n';
		}
	}

	//prac2
	cout << "prac2" << endl;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = n; i >= 1; --i) {
			for (int j = 1; j <= n; ++j) {
				if (i <= j)
					cout << '*';
				else
					cout << ' ';
			}
			cout << '\n';
		}
	}

	//prac3
	std::cout << "prac3" << endl;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = n; i >= 1; --i) {
			for (int j = i; j > 0; --j)
				cout << '*';
			cout << '\n';
		}
	}
	//prac4
	cout << "prac4" << endl;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = n; i >= 1; --i) {
			for (int j = n; j >= 1; --j) {
				if (j > i)
					cout << ' ';
				else
					cout << '*';
			}
			cout << '\n';
		}
	}
}

int main() {

	/*

	int girlAge;
	cout << "��ȣ�� ���ְ� �ľ��ϱ� ver1.0" << endl;
	cout << "��ȣ�� �̻��� ���̸� �Է��Ͻÿ�" << endl;
	cin >> girlAge;

	if (girlAge < 20)
		cout << "�ʴ� ���������" << endl;
	else if (20 <= girlAge && girlAge <= 24)
		cout << "�ʴ� �����̾�" << endl;
	else if (24 < girlAge && girlAge < 29)
		cout << "�������� ��.." << endl;
	else
		cout << "�׳� ȥ�� ���" << endl;

	TODO : ����, ����, ����, ���� ������ �Է� �ް�
	��� ���� 95�� �̻��̸� A, 85�� �̻��̸� B, 75�� �̻��̸� C, 65�� �̻��̴� D, 65�� �̸��̸� F�� ����Ͻÿ�
	int english, math, science, korean;
	cout << "����, ����, ����, ���������� ���ʴ�� �Է��Ͻÿ�" << endl;
	cin >> english >> math >> science >> korean;

	float average = (english + math + science + korean) / 4.f;

	if (average >= 95)
		cout << "A" << endl;
	else if (average >= 85)
		cout << "B" << endl;
	else if (average >= 75)
		cout << "C" << endl;
	else if (average >= 65)
		cout << "D" << endl;
	else if (0 <= average && average < 65)
		cout << "F" << endl;
	else
		cout << "��ü�Ҹ��Դϴ�" << endl;


	cout << "��ƺ���� ����� �°��� ȯ���Ѵ�." << endl;
	cout << "������ ������" << endl;
	cout << "1. �ٹٸ��� 2. �Ҽ����� 3. ��ũ�θǼ� 4.�ȶ�� 5.�Ƹ���" << endl;
	cout << "���� : ";

	int selectNum;
	cin >> selectNum;

	switch (selectNum){
	case 1:
		cout << "�ٹٸ����� �����ߴ�" << endl;
		break;
	case 2:
		cout << "�Ҽ������� �����ߴ�" << endl;
		break;
	case 3:
		cout << "��ũ�θǼ��� �����ߴ�" << endl;
		break;
	case 4:
		cout << "�ȶ���� �����ߴ�" << endl;
		break;
	case 5:
		cout << "�Ƹ����� �����ߴ�" << endl;
		break;
	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
	for (int i = 0; i < 5; ++i) {
		cout << "���� ���� ��ī����" << endl;
	}
	*/

	////TODO : 1~100������ �� ���
	//int sum = 0;
	//for (int i = 1; i <= 100; ++i)
	//	sum += i;
	//cout << sum << endl;

	////������
	//int num;
	//cout << "�������� �� ���ڸ� �Է��Ͻÿ�" << endl;
	//cin >> num;
	//for (int i = 1; i < 10; ++i)
	//	cout << num << " x " << i << " = " << num * i << endl;

	////2������
	//for (int i = 0; i < 3; ++i)
	//	for (int j = 0; j < 3; ++j)
	//		cout << i << " " << j << endl;

	////¦�� ����ϱ�
	//for (int i = 1; i <= 10; ++i) {
	//	if (i % 2 != 0) continue;
	//	cout << i << endl;
	//}

	//TODO : while
	//1. ������ �Է¹޴´�. �̶� �Է��� ������ ������ �ִ�.
	//3. 1~10�� ������ ������ ���ڸ� �Է��ϸ� ���α׷��� �����մϴ�.
	/*while (1) {
		int n;
		cout << "���ڸ� �Է��ϼ���" << endl;
		cin >> n;
		if (n < 1 || n > 10)
			break;
	}*/


	//HOMEWORK 1. �����
	//printStar();
	
	//HOMEWORK 2. �ɸ��� ����
	/*
	1. �ɸ��͸� �����Ѵ�(4����).
	2. ���Ͱ� �ִ�.
	3. �ɸ��Ͱ� ���͸� ������ ���Ͱ� �ɸ��͸� �����Ѵ�.
	4. �̿뺯�� hp, mp, atk, player, mp, atk, def, critical(Ȯ����), monsterHp, monsterMp, MonsterAtk, MonsterDef, MonsterCritical
	*/
	
	int n;
	n = 3;
	n = 11;

	int* pointer = &n;


	cout << "����⸦ �����մϴ�!" << endl;
	printStar();
	cout << "������ �������� �����մϴ�!" << endl;
	runPaperRpg();

	cout << "\n���α׷��� �����մϴ�" << endl;
	return 0;
}