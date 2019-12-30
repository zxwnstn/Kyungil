#include <iostream>
#include <stdlib.h>
#include <ctime>
//#define _DEBUG_FLAG
#define RUN_BINGO
//#define RUN_BASE
using namespace std;

//���� ���� Ŭ����
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

//�߱� ����
void runBaseBall() {
	int cpuNum[3];
	int pNum[3];
	bool winFlag = false;
	RndGen rndGen(10, 0);

	while (1) {
		cout << "�߱� ������ �����մϴ�." << endl;
		
		
		//Ÿ�� ���� ����
		rndGen.getRndNum(cpuNum, 3);

#ifdef _DEBUG_FLAG
		//����׿� ���� ���
		for (int i = 0; i < 3; ++i) 
			cout << cpuNum[i] << " ";
		cout << endl;
#endif
		//���� ����
		for (int i = 1; i < 10; ++i) {
			int n;
			cout << i << "ȸ��!" << "����� ������ڸ� 3�ڸ��� �����ֽÿ�" << endl;
			cin >> pNum[0] >> pNum[1] >> pNum[2];
					
			//���� �Ǻ�
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
	
			cout << strike << "��Ÿ����ũ!" << ball << "��!" << endl;
		}
		if (winFlag) 
			cout << "3��Ʈ����ũ! ����� �¸��ϼ˽��ϴ�." << endl;	
		else 
			cout << "9ȸ���� ����Ǿ����ϴ�. ����� �й�" << endl;
		
		cout << "������ ��� �Ͻðٽ��ϱ�? y/n" << endl;
		char input;
		cin >> input;
		if (input == 'n' || input == 'N')
			break;
		winFlag = false;
		system("cls");
	}
}

//���� ����
void checkErase(void* _board, int eraseNum) {
	int* board = (int*)_board;
	for (int i = 0; i < 25; ++i) {
		if (board[i] == eraseNum) {
			board[i] = 0;
			cout << "�ֽ��ϴ�! ���ڸ� ����ϴ�" << endl;
			return;
		}
	}
	cout << "�����ϴ�\n" << endl;
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
		//����
		if (bingableIdx == 10) 
			for (int i = 0; i < 5; ++i)
				if(board[i][i] != 0)
					return board[i][i];

		//�ϻ�
		if (bingableIdx == 11)
			for (int i = 0; i < 5; ++i) 
				if(board[4 - i][i] != 0)
					return board[4 - i][i];
	}
	return -1;
}

int computerAi(const int board[][5]) {
	int bingable[12]{ 0, }; //0~4 : ����, 5~9����, 10 ����, 11 �ϻ� 
	
	int bingableMaxIdx = 0;
	int numZero = 0;

	if (board[2][2] != 0)
		return board[2][2];
	//����
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
	//����
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
	//���� �밢��
	numZero = 0;
	for (int i = 0; i < 5; ++i)
		if (board[i][i] == 0)
			numZero++;
	bingable[10] = numZero;
	if (bingable[10] != 5 && bingable[10] > bingable[bingableMaxIdx]) {
		bingableMaxIdx = 10;
	}

	//�ϻ� �밢��
	numZero = 0;
	for (int i = 0; i < 5; ++i)
		if (board[4 - i][i] == 0)
			numZero++;
	bingable[11] = numZero;
	if (bingable[11] != 5 && bingable[11] > bingable[bingableMaxIdx])
		bingableMaxIdx = 11;


	//�ִ�ġ ��밪 ����
	if (bingable[bingableMaxIdx] == 0)
		return board[2][2];
	else
		return getCpNum(board, bingableMaxIdx);
}

void checkWin(int board[5][5], bool* flag) {
	int numBingo = 0;
	bool isBingo = true;
	//����
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
	//����
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
	//�밢�� ����
	for (int i = 0; i < 5; ++i) {
		if (board[i][i] != 0) {
			isBingo = false;
			break;
		}
	}
	if (isBingo == true)
		numBingo++;
	isBingo = true;
	//�밢�� �ϻ�
	for (int i = 0; i < 5; ++i) {
		if (board[4 - i][i] != 0) {
			isBingo = false;
			break;
		}
	}
	if (isBingo == true)
		numBingo++;
	isBingo = true;

	//�� �÷��� ����
	if (numBingo >= 3)
		*flag = true;
}

//���� run�Լ�
void runBingo() {
	int pBoard[5][5];
	int cpuBorad[5][5];
	bool pWinFlag = 0, cWinFlag = 0;
	RndGen rndGen(50, 1);

	while (1) {
		cout << "��������� �����մϴ�!" << endl;

		//�÷��̾� ������ �Է�
		cout << "�������� �Է��� �ּ��� \n�����Է� : 0, �ڵ��Է� 1" << endl;
		int ipSelect;
		cin >> ipSelect;
		if (ipSelect) 
			rndGen.getRndNum(pBoard, 25);
		else {
			cout << "���� �������� �Է����ּ���!(�� ���ڴ� 1~50����)" << endl;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					cin >> pBoard[i][j];
		}
		

		//��ǻ�� ������ �Է�
		rndGen.getRndNum(cpuBorad, 25);

		system("cls");

		while (1) {
			//�÷��̾� ���� �θ���
			cout << "���" << endl;
			printBoard(pBoard);
			cout << "��ǻ��" << endl;
			printBoard(cpuBorad);

			cout << "������� �Դϴ�!" << endl;
			cout << "���� ���ڸ� �Է��ϼ���^^" << endl;
			int input;
			cin >> input;

			cout << "\n����� �����ǿ�" << input << "�̶�� ���ڴ� ";
			checkErase(pBoard, input);
			cout << "��ǻ���� �����ǿ�" << input << "�̶�� ���ڴ� ";
			checkErase(cpuBorad, input);

			system("pause");
			system("cls");

			checkWin(pBoard, &pWinFlag);
			checkWin(cpuBorad, &cWinFlag);


			cout << "���" << endl;
			printBoard(pBoard);
			cout << "��ǻ��" << endl;
			printBoard(cpuBorad);

			if (pWinFlag || cWinFlag) break;
			

			//��ǻ�� ���� �θ���

			int cpuNum = computerAi(cpuBorad);
			cout << "��ǻ�Ͱ� ���ڸ� �θ��ϴ�!\n" << cpuNum << endl;
			
			cout << "\n����� �����ǿ�" << cpuNum << "�̶�� ���ڴ� ";
			checkErase(pBoard, cpuNum);
			cout << "��ǻ���� �����ǿ�" << cpuNum << "�̶�� ���ڴ� ";
			checkErase(cpuBorad, cpuNum);

			system("pause");
			system("cls");

			cout << "���" << endl;
			printBoard(pBoard);
			cout << "��ǻ��" << endl;
			printBoard(cpuBorad);

			checkWin(pBoard, &pWinFlag);
			checkWin(cpuBorad, &cWinFlag);

			system("cls");

			if (pWinFlag || cWinFlag) break;
		}
		if (pWinFlag && cWinFlag)
			cout << "���ÿ� ���� �ϼ��ϼ˽��ϴ�." << endl;
		else if (pWinFlag)
			cout << "����� �¸��߽��ϴ�" << endl;
		else
			cout << "��ǻ�Ͱ� �¸��߽��ϴ�" << endl;
		cout << "������ ��� �Ͻðٽ��ϱ�? y/n" << endl;
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
	//�迭
	//�ڷᱸ�� �������� �������� �޸� ������ ������.
	//���� ũ���� �������� ���������� �����Ǿ� �ִ�.
	//�迭�� �ݵ�� �ʱ�ȭ�� �ؾ� �Ѵ�. 
	//���� ������ ������ ���� ����.
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

	////TODO �ζ� ��ȣ ������ - 1~45���� 6���� ���� �̱�
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

	// �������� �̰͸��� �˰���.
	// 1. c, c++ ����
	// 2. ����Ƽ ����(���õ�, C#, 
	// 3. stl (vector, list, map)
	// 4. �˰��� 
	// ���� - merge, quick, bubble, ���� 
	// �ڷᱸ�� - tree(bst, redblack), 
	// ���ü��� : ���ھ߱�, ���� ����

	//���� �߱� ����

#ifdef RUN_BASE
	runBaseBall();
#endif // RUN_BASE

	
#ifdef RUN_BINGO
	runBingo();
#endif

	

	cout << "���α׷��� �����մϴ�." << endl;

	return 0;
}