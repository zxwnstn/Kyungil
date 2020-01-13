#pragma once
#include <iostream>
#include <vector>
using namespace std;


class monster {

private:

public:
	vector<int> bullets;
	monster() 
	{
		bullets.push_back(4);
		bullets.push_back(3);
	}

	vector<int>& getBullets() 
	{
		return bullets;
	}


	void show() {
		for (int i = 0; i < bullets.size(); ++i) {
			cout << "in monster! I have" << bullets[i] << endl;
		}
		cout << "show() end!" << endl;
	}
};

class manager {

private:
	int targetNumber = 3;
	monster m;

public:
	//manager에서 시도하고 있는 것은
	//자신의 멤버 m에 있는 벡터의 요소를 지우는것이다.
	void eraseTarget()
	{
		//먼저 m이 가지고 있는 벡터를 가져온다.
		vector<int>& monstersBullets = m.getBullets();

		//stl ==  stack, queue, deque, map, list, vector //

		for (vector<int>::iterator it = monstersBullets.begin(); it != monstersBullets.end(); )
		{
			//조건이 맞을때
			if (*it == 3)
			{
				//그리고 분명히 erase를 하고 있다.
				it = monstersBullets.erase(it);
				cout << "매니저 입니다. 확실히 숫자 3을 지웠습니다." << endl;
			}
			else
			{
				++it;
			}
		}
		//그런데 이 함수에서는 정말 targetNumber가 삭제 될까??
	}

	//멤버 m의 벡터리스트를 확인하는 함수
	void show() {
		m.show();
	}

};




int main() {



	return 0;
}