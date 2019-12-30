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
		name = "�������� ���";
		pAp = 13;
		mAp = 3;
		price = 15000;
		break;
	case poorSword1:
		type = ITEM_WEPON;
		name = "�������� ����";
		pAp = 4;
		mAp = 0;
		price = 250;
		break;
	case greateWand1:
		type = ITEM_WEPON;
		name = "�������� ������";
		pAp = 3;
		mAp = 10;
		price = 17000;
		break;
	case poorWand1:
		type = ITEM_WEPON;
		name = "�߽��� ������";
		pAp = 0;
		mAp = 2;
		price = 750;
		break;
	case greateGlove1:
		type = ITEM_HAND_AMOR;
		name = "������ ������ �尩";
		pDp = 5;
		mDp = 4;
		price = 700;
		break;
	case greateGlove2:
		type = ITEM_HAND_AMOR;
		name = "��� �������� �尩";
		pDp = 5;
		mDp = 8;
		price = 900;
		break;
	case poorGlove1:
		type = ITEM_HAND_AMOR;
		name = "�콼 ö�尩";
		pDp = 2;
		mDp = 1;
		price = 200;
		break;
	case poorGlove2:
		type = ITEM_HAND_AMOR;
		name = "���� ���尩";
		pDp = 1;
		mDp = 2;
		price = 200;
		break;
	case greateBody1:
		type = ITEM_BODY_AMOR;
		name = "Ǯ �÷���Ʈ";
		pDp = 10;
		mDp = 4;
		price = 2700;
		break;
	case greateBody2:
		type = ITEM_BODY_AMOR;
		name = "�������� �κ�";
		pDp = 7;
		mDp = 12;
		price = 3200;
		break;
	case poorBody1:
		type = ITEM_BODY_AMOR;
		name = "�ݰ� �÷���Ʈ";
		pDp = 5;
		mDp = 2;
		price = 700;
		break;
	case poorBody2:
		type = ITEM_BODY_AMOR;
		name = "������ ������ �κ�";
		pDp = 3;
		mDp = 3;
		price = 500;
		break;
	case greateBoots1:
		type = ITEM_TOE_AMOR;
		name = "������ ������ ��Ʋ����";
		pDp = 3;
		mDp = 3;
		price = 2000;
		break;
	case greateBoots2:
		type = ITEM_TOE_AMOR;
		name = "������ ��� �Ź�";
		pDp = 1;
		mDp = 4;
		price = 1700;
		break;
	case poorBoots1:
		type = ITEM_TOE_AMOR;
		name = "�콼 ö ����";
		pDp = 2;
		mDp = 1;
		price = 500;
		break;
	case poorBoots2:
		type = ITEM_TOE_AMOR;
		name = "������ �ȭ";
		pDp = 1;
		mDp = 1;
		price = 300;
		break;
	case greateHead1:
		type = ITEM_HEAD_AMOR;
		name = "�¾���� ����";
		pDp = 10;
		mDp = 13;
		price = 3000;
		break;
	case greateHead2:
		type = ITEM_HEAD_AMOR;
		name = "��ó���� ����";
		pDp = 8;
		mDp = 15;
		price = 3000;
		break;
	case poorHead1:
		type = ITEM_HEAD_AMOR;
		name = "īī���� ����";
		pDp = 2;
		mDp = 4;
		price = 1000;
		break;
	case poorHead2:
		type = ITEM_HEAD_AMOR;
		name = "������ ���� ��Ŭ��";
		pDp = 1;
		mDp = 2;
		price = 200;
		break;
	case greateRing1:
		type = ITEM_ACCESARRY;
		name = "���� ����";
		pAp = 10;
		mAp = 10;
		pDp = 10;
		mDp = 10;
		price = 20000;
		break;
	case greateRing2:
		type = ITEM_ACCESARRY;
		name = "������ ��� �������";
		pAp = 10;
		mAp = 10;
		pDp = 10;
		mDp = 20;
		price = 30000;
		break;
	case poorRing1:
		type = ITEM_ACCESARRY;
		name = "���� ����";
		mDp = 3;
		price = 1000;
		break;
	case poorRing2:
		type = ITEM_ACCESARRY;
		name = "��� ����";
		mDp = 2;
		price = 800;
		break;
	case greatePortion1:
		type = ITME_CONSUMABLE;
		name = "�뷮�� ���� ����";
		recoverHp = 100;
		price = 500;
		break;
	case greatePortion2:
		type = ITME_CONSUMABLE;
		name = "�뷮�� ���� ����";
		recoverMp = 100;
		price = 500;
		break;
	case poorPortion1:
		type = ITME_CONSUMABLE;
		name = "�ҷ��� ���� ����";
		recoverHp = 10;
		price = 50;
		break;
	case poorPortion2:
		type = ITME_CONSUMABLE;
		name = "�ҷ��� ���� ����";
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
	printf("���� ���� : %d\n", pAp);
	printf("���� ��� : %d\n", pDp);
	printf("���� ���� : %d\n", mAp);
	printf("���� ��� : %d\n", mDp);
	printf("�Ǹ� ���� : %d\n", price);
}
