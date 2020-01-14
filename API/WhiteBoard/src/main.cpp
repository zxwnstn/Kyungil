#include <iostream>
#include <vector>
using namespace std;

struct foo {
	int a, b;

	void show() {
		cout << a << " " << b << endl;
	}
};


int main() 
{
	vector<foo*> v;
	for (int i = 0; i < 4; ++i) {
		foo* k = new foo;
		k->a = i;
		k->b = i + 1;
		v.push_back(k);
	}
	for (int i = 0; i < 4; ++i) {
		v[i]->show();
	}

	for (auto it = v.begin(); it != v.end(); ++it) 
	{
		if ((*it)->a == 1) {
			delete *it;
			*it = nullptr;
			it = v.erase(it);
		}
	}
	cout << "ok" << endl;
}