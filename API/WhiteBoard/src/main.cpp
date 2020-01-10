#pragma once
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class parent {
protected:
	int a;
	int b;

	int mainternenceScore;
	int score;

public:
	void show() {
		cout << "a : " << a << "b : " << b << endl;
	}
	int d, c;

	parent()
	{
		cout << "parent Constructor" << endl;
	}

	~parent() {
		cout << "parent Destructor" << endl;
	}

};



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	




	return 0;
}