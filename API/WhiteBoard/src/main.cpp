#include <iostream>
#include <string>
using namespace std;


class pocketmon {
public:
	virtual void meaw() = 0; // ���ϸ��̶�� ū ���ִ� �����Ҹ��� Ư���Ҽ� ����. 
};

//���ϸ��� ��ӹ޴� Ŭ�������� ������.
class firy
	: public pocketmon
{
	//��� ���� ���� �Լ� meow�� ������
	void meaw() override 
	{
		cout << "��������!" << endl;
	}
};

class pica
	: public pocketmon
{
	//��� ���� ���� �Լ� meow�� ������
	void meaw() override
	{
		cout << "��ī!!" << endl;
	}
};

class cater
	: public pocketmon
{
	//��� ���� ���� �Լ� meow�� ������
	void meaw() override
	{
		cout << "���׹���!" << endl;
	}
};


class player {

public:
	void init() {
		//static ���� direction�� ���� ���� ���� ���ϸ��� �̸� �����Ҽ� �ִ�.
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

	//���ϸ��� �����Ҹ��� ���ʹ�..
	void goPocket() 
	{
		myPocketMon->meaw();
	}

public:
	static int direction;
	pocketmon* myPocketMon;
};

//static ������ �ݵ�� �̷������� �ʱ�ȭ ����� �Ѵ�.
int player::direction = -1;




int main() {
	//��ü�� �����Ǳ� ������ ���� �����Ҽ� ����
	player::direction = 2;
	//�̶� ���� ���ο� player�� cater�� ������ �ɰ��̶�� ���� �˼� ����

	player* p1 = new player;
	p1->init();

	p1->goPocket();

}