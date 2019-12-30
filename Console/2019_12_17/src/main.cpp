
#include <iostream>
#include <stdlib.h>
using namespace std;
//TODO : 추상화, 캡슐화, 상속, 다형성 상세히 기술


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