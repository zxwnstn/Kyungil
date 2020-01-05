#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class foo {


public:
	foo() {
		cout << "나 생성됨ㅋ" << endl;
	}
	~foo() {
		cout << "나 소멸됨ㅋ" << endl;
	}
};


int main() {
	/*vector<foo*> v1;
	vector<foo*> v2;
	foo* mf = new foo();

	v1.push_back(mf);
	v2.push_back(mf);

	v1.erase(v1.begin());
	v2.erase(v2.begin());
	delete mf;*/


	{
		vector<shared_ptr<foo>> v1;
		vector<shared_ptr<foo>> v2;
		shared_ptr<foo> sharedPtr = make_shared<foo>();
		v1.push_back(sharedPtr);
		v2.push_back(sharedPtr);

		v1.erase(v1.begin());
		v2.erase(v2.begin());

		cout << "debug" << endl;
	}
	



	//delete mf;

}