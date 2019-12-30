#include "card.h"
//#define DEBUG_ENABLE
#define RUN_GAME

#ifndef RUN_GAME
/*
	함수
	수학 : 특정수식에 따른 미지수들의 관계
	프로그래밍 : 모듈화된 명령어 집합

	프로그램밍에서 함수 입력값을 인자, 인수, 매개변수라고하며, 결과값을 반환값이라고 한다.(return value)
	함수를 사용하는 이유
	1. 반복적인 프로그래밍을 피한다.
	2. 코드 재사용이 용이하고 유지보수가 수월하며 코드가 간략화 된다.

	함수의 형태
	반환자료형 함수이름 (매개변수들)
	{
		실행문
	}

*/

/*
	구조체
	정의 : 변수들의 집합체
	struct MyStruct{
		int Hp;
		int Cri;
		float Mp;
		int atk;
		string name;
	};
*/

struct tagUnit {
	int Hp;
	float atk;
	bool die;
	string name;
};
// 가족이름, 가족나이, 전화번호, 생년월일, 성별, 사는곳, 음식, 사람인가, 좋아하는 게임, 이상형
struct Person {
	string fatherName;
	int fatherAge;
	string motherName;
	int motherAge;
	string brotherName;
	int brotherAge;
	string phoneCall;
	string adress;
	string favoriteFood;
	bool isHuman;
	string favoriteGame;
	string favoriteStyle;
};

inline int Max(int a, int b) {
	return a > b ? a : b;
}
inline int Min(int a, int b) {
	return a < b ? a : b;
}
#endif

void runCard() {
	Deck deck;
	int playerMoney;
	int cards[3];	   // 0 - 딜러카드1, 1 - 플레이어 카드, 2 - 딜러카드2
	int compareNum[3]; // 모양을 제외한 카드숫자
	int bet;
	bool pWin, cWin;
	int turnCnt;
	//재시작을 포함한 전체 게임 루프
	while (1) {
		deck.reset();
		turnCnt = 0;
		playerMoney = 100000;
		cout << "카드 게임을 시작합니다!" << endl;
		cout << "\n간단한 룰 : 승리시 베팅금액의 2배를 얻고, 패배시 베팅한 금액만큼 잃게 됩니다. \n 올인하셧을 경우에 승리하신다면 3배의 보상을 얻게 됩니다." << endl;
		cout << "매 베팅 시작시 사용된 카드 목록을 확인할수 있습니다.\n" << endl;


		cout << "시작 소지금 : " << playerMoney << "원" << endl;
		system("pause");
		system("cls");
		//단일 게임루프
		while (1) {
			//사용된 카드 확인
			char checkInput;
			cout << "Dealer : 사용된 카드를 확인 하시겟습니까? y/n" << endl;
			cin >> checkInput;
			if (checkInput == 'n' || checkInput == 'N') {}
			else {
				deck.print();
				system("pause");
			}
			system("cls");

			//카드 부여받기
			for (int i = 0; i < 3; ++i)
				cards[i] = deck.getCardNum();

			//승패 결정
			for (int i = 0; i < 3; ++i)
				compareNum[i] = cards[i] % 13 + 1;
			if ((compareNum[0] < compareNum[1] && compareNum[1] < compareNum[2]) ||
				(compareNum[2] < compareNum[1] && compareNum[1] < compareNum[0])) {
				pWin = true;
				cWin = false;
			}
			else {
				pWin = false;
				cWin = true;
			}

#ifdef DEBUG_ENABLE
			deck.print();
			showCards(cards[0], cards[1], cards[2]);
			cout << "남은 소지금 : " << playerMoney << "\n" << "턴카운트 : " << turnCnt + 1 << "\n";
#endif

			//첫카드 오픈
			cout << "Dealer : " << ++turnCnt << "번째 턴! 카드를 오픈합니다!" << endl;
			showCards(cards[0], 52, 52);

			//베팅 루프
			int nAddBet = 0;
			bool noMoreBet = false;
			bool forgive = false;
			bool all_In = false;
			int finalBet = 0;
			while (1) {
				char input;
				if (nAddBet == 0) {
					cout << "Dealer : 베팅하실 금액을 1000원 이상으로 적어주세요 0원은 포기입니다(포기시 1000원 삭감)." << endl;
					while (1) {
						cin >> bet;
						if (bet > playerMoney)
							cout << "Dealer : 현재 소지금 보다 더 큰 금액을 걸수 없습니다." << endl;
						else if (bet == 0) {
							cout << "Dealer : 개쫄보쉑 ㅡㅡ" << endl;
							forgive = true;
							break;
						}
						else if (bet < 1000)
							cout << "Dealer : 최소 1000원 이상 베팅하셔야 합니다" << endl;
						else if (bet == playerMoney) {
							cout << "Dealer : 올인하셧습니다! 결과를 바로 확인합니다!" << endl;
							all_In = true;
							break;
						}
						else break;
					}
					nAddBet++;
					if (forgive || all_In)
						break;
				}
				else if (nAddBet == 1) {
					showCards(cards[0], 52, 52);
					if (playerMoney - bet - 2000 >= 0) {
						cout << "Dealer : 중간 추가 패 확인은 2000원입니다. 베팅하시겟습니까? y/n" << endl;
						cin >> input;
						if (input == 'y' || input == 'Y') {
							bet += 2000;
							nAddBet++;
						}
						else {
							noMoreBet = true;
							break;
						}
					}
					else {
						cout << "Dealer : 추가 베팅할 돈이 없으시군요 바로 결과 확인 하겟습니다!" << endl;
						break;
					}
				}
				else if (nAddBet == 2) {
					showCards(cards[0], cards[1], 52);
					if (playerMoney - bet - 3000 >= 0) {
						cout << "Dealer : 최종 베팅하시겟습니까? y/n" << endl;
						cin >> input;
						if (input == 'y' || input == 'Y') {
							cout << "Dealer : 배팅할 금액을 3000원 이상 적어주세요" << endl;
							cout << "현재 잔액 : " << playerMoney - bet << endl;
							while (1) {
								cin >> finalBet;
								if (finalBet < 3000)
									cout << "Dealer : 3000원 이상 적어주세요 ㅡㅡ" << endl;
								else if (playerMoney - finalBet - bet > 0) break;
								else if (playerMoney <= finalBet + bet) {
									cout << "올인하셧습니다!" << endl;
									finalBet = playerMoney - bet;
									bet += finalBet;
									all_In = true;
									break;
								}
							}
							if (all_In) break;
							bet += finalBet;
							nAddBet++;
						}
						else {
							noMoreBet = true;
							break;
						}
					}
					else {
						cout << "Dealer : 추가 베팅할 돈이 없으시군요 바로 결과 확인 하겟습니다!" << endl;
						break;
					}
				}
				else if (nAddBet >= 3) {
					cout << "패를 전부 공개합니다!" << endl;
					showCards(cards[0], cards[1], cards[2]);
					break;
				}

				if (noMoreBet) break;
				system("cls");
			} //베팅루프 종료

			//결과 정리
			if (nAddBet != 3) {
				cout << "패를 전부 공개합니다!" << endl;
				system("pause");
				system("cls");
				showCards(cards[0], cards[1], cards[2]);
			}
			cout << "배팅하신 금액은 " << bet << "원 입니다" << endl;
			cout << "결과는?!" << endl;
			system("pause");

			if (all_In && pWin) {
				playerMoney += bet * 3;
				cout << "게임에서 승리하셧습니다." << "\n";
				cout << "올인보너스로 3배의 보상을 받습니다! " << bet * 3 << "원을 땃습니다! \n" << "남은 게임머니 : " << playerMoney << endl;
			}
			else if (forgive) {
				playerMoney -= 1000;
				cout << "게임을 포기하셧으므로 1000원을 잃습니다" << bet * 3 << "원을 잃었습니다!\n" << "남은 게임머니 : " << playerMoney << endl;
			}
			else if (pWin) {
				playerMoney += bet * 2;
				cout << "당신이 승리하셧습니다!\n" << bet * 2 << "원을 땃습니다!\n" << "남은 게임머니 : " << playerMoney << endl;
			}
			else if (cWin) {
				playerMoney -= bet;
				cout << "당신이 패배하셧습니다!\n" << bet << "원을 잃었습니다!\n" << "남은 게임머니 : " << playerMoney << endl;
			}
			cout << "\n";

			system("pause");
			//파산 확인
			if (playerMoney <= 0) {
				cout << "Dealer : 파산잼ㅋ" << endl;
				system("pause");
				cout << "당신은 병1신 입니다." << endl;
				system("pause");
				system("cls");
				break;
			}

			//모든 카드를 다 사용한경우
			if (turnCnt >= 17) {
				cout << "카드를 전부 사용하셧습으로 게임을 종료합니다." << endl;
				break;
			}

			//베팅 재시작 여부
			cout << "Dealer : 따고백작 안하실거져? y/n" << endl;
			char tempInput;
			cin >> tempInput;
			system("cls");
			if (tempInput == 'n' || tempInput == 'N') {
				if (playerMoney >= 1000) {
					cout << "Dealer : 따고백작 ㅡㅡ" << endl;
					break;
				}
				else {
					cout << "Dealer : 병신ㅋ" << endl;
					break;
				}
			}	
		}
		//게임종료 및 새로운 게임
		cout << "\n";
		cout << "새로운 게임을 하시겟습니까? y/n" << endl;
		char tempIn;
		cin >> tempIn;
		system("cls");
		if (tempIn == 'n' || tempIn == 'N')
			break;
	}
}

int main() {
#ifndef RUN_GAME
	//TODO : 두개의 수를 비교하는 함수
	//입력을 2개 받아서 2개의 수를 비교, 작은거 큰거

	//함수
	int n1, n2;
	cin >> n1 >> n2;
	cout << "큰수 : " << max(n1, n2) << "\n";
	cout << "작은수 : " << min(n1, n2) << "\n";

	//구조체
	tagUnit marin;
	marin.atk = 6;
	marin.Hp = 40;
	marin.name = "타이커스";
	marin.die = false;
	boolalpha(cout);
	cout << marin.name << " " << marin.Hp << " " << marin.atk << " " << marin.die << endl;

	//TODO : 구조체로 가족이름, 가족나이, 전화번호, 생년월일, 성별, 사는곳, 음식, 좋아하는 게임, 이상형
	Person Junsoo{ "강현구", 60, "장경만", 57, "강명수", 27, "010-7705-7656",
		"서울 송파구 오금동 상아아파트 5동 902호", "?", true, "시공조아", "홍수아 성형전, 박소담" };
	cout << sizeof(Person) << endl;
	cout << sizeof(string) << endl;

	cout << "아버지 성함 : " << Junsoo.fatherName << endl;
	cout << "아버지 나이 : " << Junsoo.fatherAge << endl;
	cout << "어머니 성함 : " << Junsoo.motherName << endl;
	cout << "어머니 나이 : " << Junsoo.fatherAge << endl;
	cout << "동생 성함 : " << Junsoo.brotherName << endl;
	cout << "동생 나이 : " << Junsoo.fatherAge << endl;
	cout << "전화번호 : " << Junsoo.phoneCall << endl;
	cout << "주소 : " << Junsoo.adress << endl;
	cout << "가장 좋아하는 음식 : " << Junsoo.favoriteFood << endl;
	cout << "사람인가? : " << Junsoo.isHuman << endl;
	cout << "좋아하는 게임 : " << Junsoo.favoriteGame << endl;
	cout << "이상형 : " << Junsoo.favoriteStyle << endl;

#else
	runCard();
#endif
	cout << "프로그램을 종료합니다" << endl;

	return 0;
}