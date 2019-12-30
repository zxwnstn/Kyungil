#pragma once
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

char cardStr[][5]{
		"◆1", "◆2","◆3","◆4","◆5","◆6","◆7","◆8","◆9","◆10","◆J","◆Q","◆K",
		"♥1", "♥2", "♥3", "♥4", "♥5", "♥6", "♥7", "♥8", "♥9", "♥10", "♥J", "♥Q", "♥K",
		"♠1", "♠2", "♠3","♠4","♠5","♠6","♠7","♠8","♠9","♠10","♠J","♠Q","♠K",
		"♣1", "♣2","♣3","♣4","♣5","♣6","♣7","♣8","♣9","♣10","♣J","♣Q","♣K", "??"
};

void showCards(int dealer1, int player, int dealer2) {
	std::cout << "당신 : " << cardStr[player] << "\n"
		"딜러 : " << cardStr[dealer1] << " " << cardStr[dealer2] << "\n" << std::endl;
}

class Deck {
	bool isUsed[52]{ 0, };
	
public:
	Deck()
	{
		srand(time(NULL));
	}
	~Deck() {}
	void reset() {
		memset(isUsed, 0, sizeof(isUsed));
	}

	int getCardNum() {
		while (1) {
			int n = rand() % 52;
			if (isUsed[n] == false) {
				isUsed[n] = true;
				return n;
			}
		}
	}
	void print() {
		int remainCnt = 0;
		for (int i = 0; i < 52; ++i) {
			if (i != 0 && i % 13 == 0)
				std::cout << "\n";
			if (!isUsed[i]){
				remainCnt++;
				std::cout << cardStr[i] << "\t";
			}
			else std::cout << "used\t";
		}
		std::cout << "\n" << "남은 카드수 : " << remainCnt << "\n";
	}
};

