#include <memory>
#include <string.h>
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;


char* ConvertWCtoC(const wchar_t * str)
{
	char* pStr;
	int strSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	pStr = new char[strSize];
	WideCharToMultiByte(CP_ACP, 0, str, -1, pStr, strSize, 0, 0);
	return pStr;
}

void show(char* str) {
	cout << str << endl;
}

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int t = 10;
	while (t--) {
		auto a = ConvertWCtoC(L"slkjdf");
		show(a);
		delete[] a;
	}
}