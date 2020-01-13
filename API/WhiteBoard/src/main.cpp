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
	//manager���� �õ��ϰ� �ִ� ����
	//�ڽ��� ��� m�� �ִ� ������ ��Ҹ� ����°��̴�.
	void eraseTarget()
	{
		//���� m�� ������ �ִ� ���͸� �����´�.
		vector<int>& monstersBullets = m.getBullets();

		//stl ==  stack, queue, deque, map, list, vector //

		for (vector<int>::iterator it = monstersBullets.begin(); it != monstersBullets.end(); )
		{
			//������ ������
			if (*it == 3)
			{
				//�׸��� �и��� erase�� �ϰ� �ִ�.
				it = monstersBullets.erase(it);
				cout << "�Ŵ��� �Դϴ�. Ȯ���� ���� 3�� �������ϴ�." << endl;
			}
			else
			{
				++it;
			}
		}
		//�׷��� �� �Լ������� ���� targetNumber�� ���� �ɱ�??
	}

	//��� m�� ���͸���Ʈ�� Ȯ���ϴ� �Լ�
	void show() {
		m.show();
	}

};




int main() {



	return 0;
}