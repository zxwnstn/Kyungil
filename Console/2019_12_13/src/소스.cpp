#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
	열거형 : enumeration 줄여서 enum
	열거형 타입의 멤버를 선언.
	열거형 타입의 멤버들은 문자로 표현되나 실제로는 정수값이다.

	변수가 가질수 있는 가능한 값들을 나열해 놓은 타입이다.
	어떤 변수가 가질수 있는 범위가 정해져있다면
	정수형 대신 열거형을 쓰는것이 좋다.
	enum myEnum {

	}
	코드의 가독성이 높아진다.
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

//enum의 멤버를 입력받을 수 있다.
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


	//TODO : 열거형을 사용해서 방향키 사용 
	/*Direction dir;
	while (1) {
		char a;
		cin >> a;
		dir = Direction(a);
		switch (dir)
		{
		case Direction::left:
			cout << "왼쪽으로 갑니다." << endl;
			break;
		case Direction::right:
			cout << "오른쪽으로 갑니다" << endl;
			break;
		case Direction::up:
			cout << "위쪽으로 갑니다" << endl;
			break;
		case Direction::down:
			cout << "아래쪽으로 갑니다" << endl;
			break;
		default:
			break;
		}
		break;
	}*/

	/*
	TODO : 
		1. 복습및 포인터
		2. 문자열을 뒤집자.abcdef -> fedcba
		3. 문자열을 뒤집고 짝수번째만 출력하도록
		4. 입력받아서
	*/

	//문자열 뒤집기 예제
	//1. 역문자열 버퍼 추가
	//char str[100];
	//char str_reverse[100];
	//cin >> str;
	//int len = strlen(str);
	//for (int i = 0; i < len; ++i)
	//	str_reverse[i] = str[len - i - 1];
	////뒤집고 출력
	//cout << str_reverse << endl;
	////뒤집고 짝수번째만 출력
	//for (int i = 0; i < len; ++i) 
	//	if (i % 2 == 1)
	//		cout << str_reverse[i];
	//cout << "\n" << endl;

	////2. 추가버퍼를 이용하지 않고
	//memset(str, 0, sizeof(str));
	//cin >> str;
	//len = strlen(str);
	//for (int i = 0; i < len / 2; ++i)
	//	swap(str[i], str[len - i - 1]);
	////뒤집고 출력
	//cout << str << endl;
	////뒤집고 짝수번째만 출력
	//for (int i = 0; i < len; ++i) 
	//	if (i % 2 == 1)
	//		cout << str[i];
	//cout << "\n" << endl;

	////3. 문자열 함수 이용
	//memset(str, 0, sizeof(str));
	//cin >> str;
	////뒤집고 출력
	//_strrev(str);
	//cout << str << endl;
	////뒤집고 짝수번째만 출력
	//len = strlen(str);
	//for (int i = 0; i < len; ++i)
	//	if (i % 2 == 1)
	//		cout << str[i];


	//문자열 함수 이용예제
	//1. strcmp - 리턴값이 0일경우 같음
	char str1[100], str2[100];
	cout << "두 문자열을 입력하세요\n";
	//cin >> str1 >> str2;

	//if (strcmp(str1, str2))
	//	cout << "두 문자열은 같지 않습니다\n";
	//else
	//	cout << "두 문자열은 같습니다\n";

	////2. strcat - 문자열 연결
	//memset(str1, 0, sizeof(str1));
	//memset(str2, 0, sizeof(str1));
	//cin >> str1 >> str2;
	//cout << strcat(str1, str2) << endl;

	////3. 문장입력 받기
	////(1) gets
	//memset(str1, 0, sizeof(str1));
	//gets_s(str1);
	//cout << str1 << endl;

	////(2) scanf
	//memset(str1, 0, sizeof(str1));
	//scanf("%[^\n]", str1);  //NOTICE : [ 안에있는 문자를 제외하고 받겟다 ]
	//cout << str1 << endl;

	////(3) getline
	//memset(str1, 0, sizeof(str1));
	//cin.getline(str1, 100);
	//cout << str1 << endl;

	////4. strtok - 문장을 구분자 기준으로 쪼개기
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

	//arr는 주소값을 담고있지는 않지만 포인터 처럼 동작한다.
	cout << *(++ptr);

	return 0;
}