#include <iostream>
#include <string>
using namespace std;


class pocketmon {
public:
	virtual void meaw() = 0; // 포켓몬이라는 큰 범주는 울음소리를 특정할수 없다. 
};

//포켓몬을 상속받는 클래스들을 만들자.
class firy
	: public pocketmon
{
	//상속 받은 가상 함수 meow를 재정의
	void meaw() override 
	{
		cout << "파이파이!" << endl;
	}
};

class pica
	: public pocketmon
{
	//상속 받은 가상 함수 meow를 재정의
	void meaw() override
	{
		cout << "피카!!" << endl;
	}
};

class cater
	: public pocketmon
{
	//상속 받은 가상 함수 meow를 재정의
	void meaw() override
	{
		cout << "버그버그!" << endl;
	}
};


class player {

public:
	void init() {
		//static 변수 direction에 따라 내가 가질 포켓몬을 미리 결정할수 있다.
		switch (direction)
		{
		case 0:
			myPocketMon = new firy;
			break;
		case 1:
			myPocketMon = new pica;
			break;
		case 2:
			myPocketMon = new cater;
			break;
		}
	}

	//포켓몬의 울음소리를 듣고싶다..
	void goPocket() 
	{
		myPocketMon->meaw();
	}

public:
	static int direction;
	pocketmon* myPocketMon;
};

//static 변수는 반드시 이런식으로 초기화 해줘야 한다.
int player::direction = -1;




int main() {
	//객체가 생성되기 전에도 값을 변경할수 있음
	player::direction = 2;
	//이때 부터 새로운 player는 cater를 가지게 될것이라는 것을 알수 있음

	player* p1 = new player;
	p1->init();

	p1->goPocket();

}