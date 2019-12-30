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
			cout << "크리티컬 어택!" << endl;
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
	cout << "플레이어 이름을 입력해 주세요" << endl;
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
		cout << "케릭터를 선택해 주세요" << endl;
		cout << "1. 바바리안 2. 아마존 3. 드루이드 4. 팔라딘 0게임 끝내기" << endl;
		int selectInput;
		cin >> selectInput;
		if (!selectInput)
			break;

		Charactor* player = CreatePlayer(selectInput);
		Charactor* monster = CreateMonster();

		cout << "전투를 시작합니다!" << endl;
		cout << "당신의 이름은 " << player->getName() << " 이고 " << "상대할 몬스터는 " << monster->getName() << " 입니다\n\n";

		while (1) {
			if (player->isDie()) {
				cout << "당신은 졌습니다 ㅜㅜ\n";
				break;
			}
			if (monster->isDie()) {
				cout << "당신이 승리하였습니다!\n";
				break;
			}
			cout << player->getName() << "의 남은 HP : " << player->getHp() << endl;
			cout << monster->getName() << "의 남은 HP : " << monster->getHp() << endl;

			//플레이어의 공격
			cout << player->getName() << "의 공격!\n";
			monster->getDamage(player->getAtkp());
			cout << monster->getName() << "의 체력은 " << monster->getHp() << "이 되었다." << endl;
			//몬스터의 공격
			if (!monster->isDie()) {
				cout << monster->getName() << "의공격!\n";
				player->getDamage(monster->getAtkp());
				cout << player->getName() << "의 체력은 " << player->getHp() << "이 되었다.\n" << endl;
			}	
		}
		delete monster;
		delete player;


		cout << "\n새로운 게임을 하시겟습니까? y/n" << endl;
		char a;
		cin >> a;
		if (a == 'n' || a == 'N')
			break;
	}
}

void printStar() {
	//prac1
	cout << "출력될 행의 길이를 입력하시요 (exit = 0)" << endl;
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
	cout << "찬호의 연애관 파악하기 ver1.0" << endl;
	cout << "찬호의 이상형 나이를 입력하시오" << endl;
	cin >> girlAge;

	if (girlAge < 20)
		cout << "너는 개쓰레기야" << endl;
	else if (20 <= girlAge && girlAge <= 24)
		cout << "너는 도둑이야" << endl;
	else if (24 < girlAge && girlAge < 29)
		cout << "이정도면 뭐.." << endl;
	else
		cout << "그냥 혼자 살아" << endl;

	TODO : 영어, 수학, 과학, 국어 점수를 입력 받고
	평균 점수 95점 이상이면 A, 85점 이상이면 B, 75점 이상이면 C, 65점 이상이다 D, 65점 미만이면 F를 출력하시오
	int english, math, science, korean;
	cout << "영어, 수학, 과학, 국어점수를 차례대로 입력하시오" << endl;
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
		cout << "정체불명입니다" << endl;


	cout << "디아블로의 세계로 온것을 환영한다." << endl;
	cout << "직업을 골라봐라" << endl;
	cout << "1. 바바리안 2. 소서리스 3. 네크로맨서 4.팔라딘 5.아마존" << endl;
	cout << "선택 : ";

	int selectNum;
	cin >> selectNum;

	switch (selectNum){
	case 1:
		cout << "바바리안을 선택했다" << endl;
		break;
	case 2:
		cout << "소서리스를 선택했다" << endl;
		break;
	case 3:
		cout << "네크로맨서를 선택했다" << endl;
		break;
	case 4:
		cout << "팔라딘을 선택했다" << endl;
		break;
	case 5:
		cout << "아마존을 선택했다" << endl;
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
		break;
	}
	for (int i = 0; i < 5; ++i) {
		cout << "경일 게임 아카데미" << endl;
	}
	*/

	////TODO : 1~100까지의 합 출력
	//int sum = 0;
	//for (int i = 1; i <= 100; ++i)
	//	sum += i;
	//cout << sum << endl;

	////구구단
	//int num;
	//cout << "구구단을 할 숫자를 입력하시오" << endl;
	//cin >> num;
	//for (int i = 1; i < 10; ++i)
	//	cout << num << " x " << i << " = " << num * i << endl;

	////2중포문
	//for (int i = 0; i < 3; ++i)
	//	for (int j = 0; j < 3; ++j)
	//		cout << i << " " << j << endl;

	////짝수 출력하기
	//for (int i = 1; i <= 10; ++i) {
	//	if (i % 2 != 0) continue;
	//	cout << i << endl;
	//}

	//TODO : while
	//1. 정수를 입력받는다. 이때 입력은 무한히 받을수 있다.
	//3. 1~10을 제외한 나머지 숫자를 입력하면 프로그램을 종료합니다.
	/*while (1) {
		int n;
		cout << "숫자를 입력하세요" << endl;
		cin >> n;
		if (n < 1 || n > 10)
			break;
	}*/


	//HOMEWORK 1. 별찍기
	//printStar();
	
	//HOMEWORK 2. 케릭터 게임
	/*
	1. 케릭터를 선택한다(4개중).
	2. 몬스터가 있다.
	3. 케릭터가 몬스터를 공격후 몬스터가 케릭터를 공격한다.
	4. 이용변수 hp, mp, atk, player, mp, atk, def, critical(확률로), monsterHp, monsterMp, MonsterAtk, MonsterDef, MonsterCritical
	*/
	
	int n;
	n = 3;
	n = 11;

	int* pointer = &n;


	cout << "별찍기를 시작합니다!" << endl;
	printStar();
	cout << "페이퍼 알피지를 시작합니다!" << endl;
	runPaperRpg();

	cout << "\n프로그램을 종료합니다" << endl;
	return 0;
}