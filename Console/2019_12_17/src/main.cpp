
#include <iostream>
#include <stdlib.h>
using namespace std;
//TODO : �߻�ȭ, ĸ��ȭ, ���, ������ ���� ���


class myGame{
	int m_x;
	int m_y;

public:
	myGame() {}
	~myGame() {}


};


int main()
{
	bool checkBoard[5] = { false, }; 
	int randnum;
	for (int i = 0; i < 5; ++i) {		
		while (1) {
			randnum = rand() % 5;
			if (checkBoard[randnum] == false) {
				checkBoard[randnum] = true;
				cout << randnum << " ";
				break;
			}		
		}	
	}
	
}