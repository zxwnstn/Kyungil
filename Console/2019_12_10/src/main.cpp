#include <iostream>
#include <stdlib.h>
#include <ctime>
//#define _DEBUG_FLAG
#define RUN_BINGO
//#define RUN_BASE
using namespace std;

//난수 추출 클래스
class RndGen {
	int* rndArr = nullptr;
	int n;

	void shuffle() {
		int dest, src, temp;
		for (int i = 0; i < 777; ++i) {
			dest = rand() % n;
			src = rand() % n;

			temp = rndArr[dest];
			rndArr[dest] = rndArr[src];
			rndArr[src] = temp;
		}
	}

public:

	RndGen(int _n, int startNum = 0)
		: n(_n)
	{
		rndArr = new int[n];
		for (int i = 0; i < n; ++i) {
			rndArr[i] = startNum + i;
		}
	}
	~RndGen() {
		delete[] rndArr;
	}

	void getRndNum(void* _arr, int _size) {
		shuffle();
		int* arr = (int*)_arr;
		for (int i = 0; i < _size; ++i) {
			arr[i] = rndArr[i];
		}
	}
	
	int getOneNumber() {
		shuffle();
		return rndArr[0];
	}
};

//야구 게임
void runBaseBall() {
	int cpuNum[3];
	int pNum[3];
	bool winFlag = false;
	RndGen rndGen(10, 0);

	while (1) {
		cout << "야구 게임을 시작합니다." << endl;
		
		
		//타겟 숫자 지정
		rndGen.getRndNum(cpuNum, 3);

#ifdef _DEBUG_FLAG
		//디버그용 숫자 출력
		for (int i = 0; i < 3; ++i) 
			cout << cpuNum[i] << " ";
		cout << endl;
#endif
		//게임 시작
		for (int i = 1; i < 10; ++i) {
			int n;
			cout << i << "회차!" << "당신의 예상숫자를 3자리를 적어주시오" << endl;
			cin >> pNum[0] >> pNum[1] >> pNum[2];
					
			//조건 판별
			int strike = 0;
			int ball = 0;
			for (int i = 0; i < 3; ++i) {
				if (cpuNum[i] == pNum[i]) {
					strike++;
					continue;
				}
				for (int j = 0; j < 3; ++j) {
					if (i == j) continue;
					if (cpuNum[i] == pNum[j])
						ball++;
				}
			}
			if (strike == 3) {
				winFlag = true;
				break;
			}
	
			cout << strike << "스타라이크!" << ball << "볼!" << endl;
		}
		if (winFlag) 
			cout << "3스트라이크! 당신이 승리하셧습니다." << endl;	
		else 
			cout << "9회차가 종료되었습니다. 당신의 패배" << endl;
		
		cout << "게임을 계속 하시겟습니까? y/n" << endl;
		char input;
		cin >> input;
		if (input == 'n' || input == 'N')
			break;
		winFlag = false;
		system("cls");
	}
}

//빙고 게임
void checkErase(void* _board, int eraseNum) {
	int* board = (int*)_board;
	for (int i = 0; i < 25; ++i) {
		if (board[i] == eraseNum) {
			board[i] = 0;
			cout << "있습니다! 숫자를 지웁니다" << endl;
			return;
		}
	}
	cout << "없습니다\n" << endl;
}

void printBoard(void* _board) {
	int* board = (int*)_board;
	for (int i = 0; i < 25; ++i) {
		cout << board[i] << "\t";
		if ((i + 1) % 5 == 0 && i != 0)
			cout << "\n";
	}
	cout << "\n";
}

int getCpNum(const int board[][5], int bingableIdx) {
	if (bingableIdx < 5) {
		int line = bingableIdx;
		for (int i = 0; i < 5; ++i) 
			if (board[line][i] != 0) 
				return board[line][i];
	}
	else if (bingableIdx < 10) {
		int line = bingableIdx - 5;
		for (int i = 0; i < 5; ++i)
			if (board[i][line] != 0)
				return board[i][line];
	}
	else {
		//상하
		if (bingableIdx == 10) 
			for (int i = 0; i < 5; ++i)
				if(board[i][i] != 0)
					return board[i][i];

		//하상
		if (bingableIdx == 11)
			for (int i = 0; i < 5; ++i) 
				if(board[4 - i][i] != 0)
					return board[4 - i][i];
	}
	return -1;
}

int computerAi(const int board[][5]) {
	int bingable[12]{ 0, }; //0~4 : 가로, 5~9세로, 10 상하, 11 하상 
	
	int bingableMaxIdx = 0;
	int numZero = 0;

	if (board[2][2] != 0)
		return board[2][2];
	//가로
	for (int i = 0; i <= 4; ++i) {
		numZero = 0;
		for (int j = 0; j <= 4; ++j) {
			if (board[i][j] == 0)
				numZero++;
		}
		bingable[i] = numZero;
		if (bingable[i] != 5 && bingable[i] > bingable[bingableMaxIdx]) {
			bingableMaxIdx = i;
		}
	}
	//세로
	for (int i = 0; i <= 4; ++i) {
		numZero = 0;
		for (int j = 0; j <= 4; ++j) {
			if (board[j][i] == 0)
				numZero++;
		}
		bingable[i + 5] = numZero;
		if (bingable[i + 5] != 5 && bingable[i + 5] > bingable[bingableMaxIdx]) {
			bingableMaxIdx = i + 5;
		}
	}
	//상하 대각선
	numZero = 0;
	for (int i = 0; i < 5; ++i)
		if (board[i][i] == 0)
			numZero++;
	bingable[10] = numZero;
	if (bingable[10] != 5 && bingable[10] > bingable[bingableMaxIdx]) {
		bingableMaxIdx = 10;
	}

	//하상 대각선
	numZero = 0;
	for (int i = 0; i < 5; ++i)
		if (board[4 - i][i] == 0)
			numZero++;
	bingable[11] = numZero;
	if (bingable[11] != 5 && bingable[11] > bingable[bingableMaxIdx])
		bingableMaxIdx = 11;


	//최대치 기대값 추출
	if (bingable[bingableMaxIdx] == 0)
		return board[2][2];
	else
		return getCpNum(board, bingableMaxIdx);
}

void checkWin(int board[5][5], bool* flag) {
	int numBingo = 0;
	bool isBingo = true;
	//가로
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] != 0) {
				isBingo = false;
				break;
			}
		}
		if (isBingo == true) 
			numBingo++;
		isBingo = true;
	}
	//세로
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j][i] != 0) {
				isBingo = false;
				break;
			}
		}
		if (isBingo == true) 
			numBingo++;
		isBingo = true;
	}
	//대각선 상하
	for (int i = 0; i < 5; ++i) {
		if (board[i][i] != 0) {
			isBingo = false;
			break;
		}
	}
	if (isBingo == true)
		numBingo++;
	isBingo = true;
	//대각선 하상
	for (int i = 0; i < 5; ++i) {
		if (board[4 - i][i] != 0) {
			isBingo = false;
			break;
		}
	}
	if (isBingo == true)
		numBingo++;
	isBingo = true;

	//윈 플래그 설정
	if (numBingo >= 3)
		*flag = true;
}

//빙고 run함수
void runBingo() {
	int pBoard[5][5];
	int cpuBorad[5][5];
	bool pWinFlag = 0, cWinFlag = 0;
	RndGen rndGen(50, 1);

	while (1) {
		cout << "빙고게임을 시작합니다!" << endl;

		//플레이어 빙고판 입력
		cout << "빙고판을 입력해 주세요 \n직적입력 : 0, 자동입력 1" << endl;
		int ipSelect;
		cin >> ipSelect;
		if (ipSelect) 
			rndGen.getRndNum(pBoard, 25);
		else {
			cout << "직접 빙고판을 입력해주세요!(단 숫자는 1~50까지)" << endl;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					cin >> pBoard[i][j];
		}
		

		//컴퓨터 빙고판 입력
		rndGen.getRndNum(cpuBorad, 25);

		system("cls");

		while (1) {
			//플레이어 숫자 부르기
			cout << "당신" << endl;
			printBoard(pBoard);
			cout << "컴퓨터" << endl;
			printBoard(cpuBorad);

			cout << "당신차례 입니다!" << endl;
			cout << "지울 숫자를 입력하세요^^" << endl;
			int input;
			cin >> input;

			cout << "\n당신의 빙고판에" << input << "이라는 숫자는 ";
			checkErase(pBoard, input);
			cout << "컴퓨터의 빙고판에" << input << "이라는 숫자는 ";
			checkErase(cpuBorad, input);

			system("pause");
			system("cls");

			checkWin(pBoard, &pWinFlag);
			checkWin(cpuBorad, &cWinFlag);


			cout << "당신" << endl;
			printBoard(pBoard);
			cout << "컴퓨터" << endl;
			printBoard(cpuBorad);

			if (pWinFlag || cWinFlag) break;
			

			//컴퓨터 숫자 부르기

			int cpuNum = computerAi(cpuBorad);
			cout << "컴퓨터가 숫자를 부릅니다!\n" << cpuNum << endl;
			
			cout << "\n당신의 빙고판에" << cpuNum << "이라는 숫자는 ";
			checkErase(pBoard, cpuNum);
			cout << "컴퓨터의 빙고판에" << cpuNum << "이라는 숫자는 ";
			checkErase(cpuBorad, cpuNum);

			system("pause");
			system("cls");

			cout << "당신" << endl;
			printBoard(pBoard);
			cout << "컴퓨터" << endl;
			printBoard(cpuBorad);

			checkWin(pBoard, &pWinFlag);
			checkWin(cpuBorad, &cWinFlag);

			system("cls");

			if (pWinFlag || cWinFlag) break;
		}
		if (pWinFlag && cWinFlag)
			cout << "동시에 빙고를 완성하셧습니다." << endl;
		else if (pWinFlag)
			cout << "당신이 승리했습니다" << endl;
		else
			cout << "컴퓨터가 승리했습니다" << endl;
		cout << "게임을 계속 하시겟습니까? y/n" << endl;
		char input;
		cin >> input;
		if (input == 'n' || input == 'N')
			break;
		cWinFlag = pWinFlag = false;
		system("cls");
	}

}



int main() {
	srand(time(NULL));
	//배열
	//자료구의 일종으로 연속적인 메모리 공간을 가진다.
	//같은 크기의 변수들이 연속적으로 나열되어 있다.
	//배열은 반드시 초기화를 해야 한다. 
	//하지 않으면 쓰레기 값이 들어간다.
	//int numArr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//cout << numArr << endl;
	//for (int i = 0; i <= 10; ++i)
	//	cout << numArr[i] << endl;

	//int numArr2[] = { 1, 2, 3, 4, 5 };
	//
	//char name[10] = "123456789";

	////Array shuffle
	
	//int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int dest, sour, temp;

	//for (int i = 0; i < 777; ++i) {
	//	dest = rand() % 10;
	//	sour = rand() % 10;

	//	temp = num[dest];
	//	num[dest] = num[sour];
	//	num[sour] = temp;
	//}

	////TODO 로또 번호 생성기 - 1~45까지 6개의 숫자 뽑기
	//bool isUsed[46]{ 0, };
	//int myLotto[6];
	//int k = 0;
	//for (int i = 0; i < 6;) {
	//	int getNumber = rand() % 45 + 1;
	//	if (!isUsed[getNumber]) {
	//		isUsed[getNumber] = true;
	//		myLotto[k++] = getNumber;
	//		i++;
	//	}
	//}
	//for (int i = 0; i < 6; ++i) {
	//	cout << myLotto[i] << endl;
	//}

	// 면접에서 이것만은 알고가자.
	// 1. c, c++ 전반
	// 2. 유니티 전반(숙련도, C#, 
	// 3. stl (vector, list, map)
	// 4. 알고리즘 
	// 정렬 - merge, quick, bubble, 삽입 
	// 자료구조 - tree(bst, redblack), 
	// 오늘숙제 : 숫자야구, 빙고 게임

	//숫자 야구 게임

#ifdef RUN_BASE
	runBaseBall();
#endif // RUN_BASE

	
#ifdef RUN_BINGO
	runBingo();
#endif

	

	cout << "프로그램을 종료합니다." << endl;

	return 0;
}