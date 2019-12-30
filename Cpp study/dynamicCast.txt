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

	A* ref = &b;
	b.getThis()->print();
	ref->getThis()->print();

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref->getThis()).name() << endl;


	//static cast  : 될수있는 한 밀어 붙인다.
	//dynamic cast : 경우를 보고 캐스트한다(런타임에서 잡아준다).
	auto* dynamic_cast_ptr = dynamic_cast<A*>(&b);
	if(dynamic_cast_ptr != nullptr)//캐스팅 실패시 nullptr을 넣어줌
		dynamic_cast_ptr->print();
	else {
		cout << "dynamic cast fail" << endl;
	}

	return 0;
}