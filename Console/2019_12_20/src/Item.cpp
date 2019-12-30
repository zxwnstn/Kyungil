#include "Item.h"
#include <stdio.h>

Item::Item()
{
}

Item::Item(ItemIdex _itemIdx, int _num = 1)
{
	isEquiped = false;
	itemidx = _itemIdx;
	num = _num;
	switch (_itemIdx)
	{
	case greateSword1:
		type = ITEM_WEPON;
		name = "집행자의 대검";
		pAp = 13;
		mAp = 3;
		price = 15000;
		break;
	case poorSword1:
		type = ITEM_WEPON;
		name = "여행자의 도검";
		pAp = 4;
		mAp = 0;
		price = 250;
		break;
	case greateWand1:
		type = ITEM_WEPON;
		name = "대현자의 지팡이";
		pAp = 3;
		mAp = 10;
		price = 17000;
		break;
	case poorWand1:
		type = ITEM_WEPON;
		name = "견습용 지팡이";
		pAp = 0;
		mAp = 2;
		price = 750;
		break;
	case greateGlove1:
		type = ITEM_HAND_AMOR;
		name = "강인한 전사의 장갑";
		pDp = 5;
		mDp = 4;
		price = 700;
		break;
	case greateGlove2:
		type = ITEM_HAND_AMOR;
		name = "상급 마법사의 장갑";
		pDp = 5;
		mDp = 8;
		price = 900;
		break;
	case poorGlove1:
		type = ITEM_HAND_AMOR;
		name = "녹슨 철장갑";
		pDp = 2;
		mDp = 1;
		price = 200;
		break;
	case poorGlove2:
		type = ITEM_HAND_AMOR;
		name = "해진 면장갑";
		pDp = 1;
		mDp = 2;
		price = 200;
		break;
	case greateBody1:
		type = ITEM_BODY_AMOR;
		name = "풀 플레이트";
		pDp = 10;
		mDp = 4;
		price = 2700;
		break;
	case greateBody2:
		type = ITEM_BODY_AMOR;
		name = "대현자의 로브";
		pDp = 7;
		mDp = 12;
		price = 3200;
		break;
	case poorBody1:
		type = ITEM_BODY_AMOR;
		name = "금간 플레이트";
		pDp = 5;
		mDp = 2;
		price = 700;
		break;
	case poorBody2:
		type = ITEM_BODY_AMOR;
		name = "대현자 지망생 로브";
		pDp = 3;
		mDp = 3;
		price = 500;
		break;
	case greateBoots1:
		type = ITEM_TOE_AMOR;
		name = "위대한 전사의 배틀부츠";
		pDp = 3;
		mDp = 3;
		price = 2000;
		break;
	case greateBoots2:
		type = ITEM_TOE_AMOR;
		name = "마력이 깃든 신발";
		pDp = 1;
		mDp = 4;
		price = 1700;
		break;
	case poorBoots1:
		type = ITEM_TOE_AMOR;
		name = "녹슨 철 부츠";
		pDp = 2;
		mDp = 1;
		price = 500;
		break;
	case poorBoots2:
		type = ITEM_TOE_AMOR;
		name = "가벼운 운동화";
		pDp = 1;
		mDp = 1;
		price = 300;
		break;
	case greateHead1:
		type = ITEM_HEAD_AMOR;
		name = "태양신의 투구";
		pDp = 10;
		mDp = 13;
		price = 3000;
		break;
	case greateHead2:
		type = ITEM_HEAD_AMOR;
		name = "부처님의 지혜";
		pDp = 8;
		mDp = 15;
		price = 3000;
		break;
	case poorHead1:
		type = ITEM_HEAD_AMOR;
		name = "카카시의 복면";
		pDp = 2;
		mDp = 4;
		price = 1000;
		break;
	case poorHead2:
		type = ITEM_HEAD_AMOR;
		name = "나뭇잎 마을 서클릿";
		pDp = 1;
		mDp = 2;
		price = 200;
		break;
	case greateRing1:
		type = ITEM_ACCESARRY;
		name = "절대 반지";
		pAp = 10;
		mAp = 10;
		pDp = 10;
		mDp = 10;
		price = 20000;
		break;
	case greateRing2:
		type = ITEM_ACCESARRY;
		name = "마력이 긷든 절대반지";
		pAp = 10;
		mAp = 10;
		pDp = 10;
		mDp = 20;
		price = 30000;
		break;
	case poorRing1:
		type = ITEM_ACCESARRY;
		name = "예쁜 반지";
		mDp = 3;
		price = 1000;
		break;
	case poorRing2:
		type = ITEM_ACCESARRY;
		name = "어여쁜 반지";
		mDp = 2;
		price = 800;
		break;
	case greatePortion1:
		type = ITME_CONSUMABLE;
		name = "대량의 힐링 포션";
		recoverHp = 100;
		price = 500;
		break;
	case greatePortion2:
		type = ITME_CONSUMABLE;
		name = "대량의 마나 포션";
		recoverMp = 100;
		price = 500;
		break;
	case poorPortion1:
		type = ITME_CONSUMABLE;
		name = "소량의 힐링 포션";
		recoverHp = 10;
		price = 50;
		break;
	case poorPortion2:
		type = ITME_CONSUMABLE;
		name = "소량의 마나 포션";
		recoverMp = 10;
		price = 50;
		break;
	}
}

Item::~Item()
{
}

void Item::itemShowInfo()
{
	printf("%s\n", name.c_str());
	printf("물리 공격 : %d\n", pAp);
	printf("물리 방어 : %d\n", pDp);
	printf("마법 공격 : %d\n", mAp);
	printf("마법 방어 : %d\n", mDp);
	printf("판매 가격 : %d\n", price);
}
