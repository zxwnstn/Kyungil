#include "player.h"
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <memory>
#include <tchar.h>
using namespace std;

int foo(int a, int b, COLORREF color = RGB(255, 0, 255)) {
	return a + b;
}

class some {
public:
	some(int _a, int _b)
		: a(_a), b(_b)
	{
		std::cout << a << " " << b << std::endl;
		std::cout << "생성자 호출" << std::endl;
	}
	~some()
	{
		std::cout << "소멸자 호출" << std::endl;
	}
	void something() {
		vector<shared_ptr<int>> k;
		shared_ptr<int> a = make_shared<int>(3);
		shared_ptr<int> b = make_shared<int>(3);

		k.push_back(a);
		k.push_back(b);

		for (auto it = k.begin(); it != k.end(); ) {
			it = k.erase(it);
		}
	}
private:
	int a = 3;
	int b = 2;
};

int main() {
	/*player p;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	while (1) {
		std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
		if (sec.count() > 1.f) {
			start = std::chrono::system_clock::now();
			p.update();
			p.render();
		}
	}*/

	tstring s;

	some s(1, 2);
	//s.something();
}