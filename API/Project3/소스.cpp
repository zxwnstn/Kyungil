#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class foo {

public:
	~foo() {
		cout << "�� �Ҹ�� ��" << endl;
	}

	foo() {
		cout << "�⺻��" << endl;
	}
	foo(const foo& _foo) {
		cout << "���� ������" << endl;
	}

	foo(int a, int b) {
		cout << a << " " << b;
		cout << "a b ������" << endl;
	}
	void print() {
		cout << "hi" << endl;
	}
};

void goo() {

	foo f1(1, 3);
	f1.print();
	
	foo f3();

	foo f2 = foo();
	f2.print();
}

void zoo() {
	//v.pop_back();
}

int main() {
	goo();
	zoo();
	
}