#include <iostream>
using namespace std;

// 재귀의 종료를 위해 인자없는 Goo 함수가 필요하다.
void Goo()
{
	cout << "Goo 종료" << endl;
}

template <typename T, typename ... Types>
void Goo(T a, Types ... args)
{
	static int n = 0;
	++n;

	cout << n << ": " << typeid(T).name() << " : " << a << endl;

	// 꺼낼 때는 'recursive'한 방법으로 꺼내야 한다.
	// recursive한 방식으로 동작하므로 작은 코드에 대해서만 사용해야한다.
	Goo(args...);
}



int main(int argc, char* argv[])
{
	Goo(1, 3.4, "aa", 5);
	return 0;


}