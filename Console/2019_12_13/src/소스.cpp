#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
	������ : enumeration �ٿ��� enum
	������ Ÿ���� ����� ����.
	������ Ÿ���� ������� ���ڷ� ǥ���ǳ� �����δ� �������̴�.

	������ ������ �ִ� ������ ������ ������ ���� Ÿ���̴�.
	� ������ ������ �ִ� ������ �������ִٸ�
	������ ��� �������� ���°��� ����.
	enum myEnum {

	}
	�ڵ��� �������� ��������.
*/

enum Color {
	Red, 
	Green = 1000,
	Blue,
	Black,
	White
};

enum Direction {
	left = (int)'a',
	right = (int)'d',
	up = (int)'w',
	down = (int)'s',
};

//enum�� ����� �Է¹��� �� �ִ�.
enum Motion {
	L_Walk,
	L_Running,
	R_Walk,
	R_Running,
};

int main() {
	/*cout << Color::Red << endl;
	cout << Color::Green << endl;
	cout << Color::Blue << endl;
	cout << Color::Black << endl;
	cout << Color::White << endl;*/


	//TODO : �������� ����ؼ� ����Ű ��� 
	/*Direction dir;
	while (1) {
		char a;
		cin >> a;
		dir = Direction(a);
		switch (dir)
		{
		case Direction::left:
			cout << "�������� ���ϴ�." << endl;
			break;
		case Direction::right:
			cout << "���������� ���ϴ�" << endl;
			break;
		case Direction::up:
			cout << "�������� ���ϴ�" << endl;
			break;
		case Direction::down:
			cout << "�Ʒ������� ���ϴ�" << endl;
			break;
		default:
			break;
		}
		break;
	}*/

	/*
	TODO : 
		1. ������ ������
		2. ���ڿ��� ������.abcdef -> fedcba
		3. ���ڿ��� ������ ¦����°�� ����ϵ���
		4. �Է¹޾Ƽ�
	*/

	//���ڿ� ������ ����
	//1. �����ڿ� ���� �߰�
	//char str[100];
	//char str_reverse[100];
	//cin >> str;
	//int len = strlen(str);
	//for (int i = 0; i < len; ++i)
	//	str_reverse[i] = str[len - i - 1];
	////������ ���
	//cout << str_reverse << endl;
	////������ ¦����°�� ���
	//for (int i = 0; i < len; ++i) 
	//	if (i % 2 == 1)
	//		cout << str_reverse[i];
	//cout << "\n" << endl;

	////2. �߰����۸� �̿����� �ʰ�
	//memset(str, 0, sizeof(str));
	//cin >> str;
	//len = strlen(str);
	//for (int i = 0; i < len / 2; ++i)
	//	swap(str[i], str[len - i - 1]);
	////������ ���
	//cout << str << endl;
	////������ ¦����°�� ���
	//for (int i = 0; i < len; ++i) 
	//	if (i % 2 == 1)
	//		cout << str[i];
	//cout << "\n" << endl;

	////3. ���ڿ� �Լ� �̿�
	//memset(str, 0, sizeof(str));
	//cin >> str;
	////������ ���
	//_strrev(str);
	//cout << str << endl;
	////������ ¦����°�� ���
	//len = strlen(str);
	//for (int i = 0; i < len; ++i)
	//	if (i % 2 == 1)
	//		cout << str[i];


	//���ڿ� �Լ� �̿뿹��
	//1. strcmp - ���ϰ��� 0�ϰ�� ����
	char str1[100], str2[100];
	cout << "�� ���ڿ��� �Է��ϼ���\n";
	//cin >> str1 >> str2;

	//if (strcmp(str1, str2))
	//	cout << "�� ���ڿ��� ���� �ʽ��ϴ�\n";
	//else
	//	cout << "�� ���ڿ��� �����ϴ�\n";

	////2. strcat - ���ڿ� ����
	//memset(str1, 0, sizeof(str1));
	//memset(str2, 0, sizeof(str1));
	//cin >> str1 >> str2;
	//cout << strcat(str1, str2) << endl;

	////3. �����Է� �ޱ�
	////(1) gets
	//memset(str1, 0, sizeof(str1));
	//gets_s(str1);
	//cout << str1 << endl;

	////(2) scanf
	//memset(str1, 0, sizeof(str1));
	//scanf("%[^\n]", str1);  //NOTICE : [ �ȿ��ִ� ���ڸ� �����ϰ� �ްٴ� ]
	//cout << str1 << endl;

	////(3) getline
	//memset(str1, 0, sizeof(str1));
	//cin.getline(str1, 100);
	//cout << str1 << endl;

	////4. strtok - ������ ������ �������� �ɰ���
	//memset(str1, 0, sizeof(str1));
	//gets_s(str1);
	//char* ptr = strtok(str1, " ");
	//while (ptr != NULL) {
	//	cout << ptr << endl;
	//	ptr = strtok(NULL, " ");
	//}
	
	int arr[4];
	for (int i = 0; i < 4; ++i) {
		arr[i] = i;
	}

	goo();

	char str[4];
	cin >> str;
	
	int* ptr = arr;

	//arr�� �ּҰ��� ��������� ������ ������ ó�� �����Ѵ�.
	cout << *(++ptr);

	return 0;
}