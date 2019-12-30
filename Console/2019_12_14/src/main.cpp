#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int MinimumPasswordLength = 10;

std::string encrpytPassword(const std::string & password) {
	using namespace std;
	string encrypted;
	if (password.length() < MinimumPasswordLength) {
		throw logic_error("password is too short");
	}
	//do Something

	return encrypted;
}

enum Color {
	Red,
	Blue,
	Green 
};

struct mySt {
	int a;
	int b;
};


void print(char str[100]) {
	for (int i = 0; i < 100; ++i)
	{
		if (i % 10 != 0 && i != 0)
		{
			cout << str[i];
		}
		else
			cout << endl;
	}
	cout << endl;
}


int main() {

	srand(time(NULL));
	char str[100];
	for (int i = 0; i < 100; ++i) {
		if (i < 30)
		{
			str[i] = '#';
		}
		else str[i] = '.';
	}
	print(str);
	
	int dest, temp, src;
	for (int i = 0; i < 777; ++i) 
	{
		dest = rand() % 100;
		src = rand() % 100;

		temp = str[dest];
		str[dest] = str[src];
		str[src] = temp;
	}
	print(str);

	int str2[100] = { 0, };


	system("pause");
	return 0;
}