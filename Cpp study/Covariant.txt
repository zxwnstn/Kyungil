#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class A {
public:
	virtual void print() {
		cout << "A" << endl;
	}

	virtual A* getThis() { 
		cout << "A::getThis" << endl;
		return this; 
	}
};

class B : public A {
public:
	void print() {
		cout << "B" << endl;
	}
	//this func called Covariant return type(공변 반환)
	virtual B* getThis() override { 
		cout << "B::getThis" << endl;
		return this; 
	}

};

int main() {
	A a;
	B b;

	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;


	return 0;
}