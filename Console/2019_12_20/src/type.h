#pragma once
enum Input {
	eUp,
	eDown,
	eLeft,
	eRight,
	eInventory,
	eCharacror,
	eExit,
	eNone
};

enum ItemIdex {
	//����
	greateSword1, //�������� ���
	poorSword1,   //�������� ����
	greateWand1,  //�������� ������
	poorWand1,    //�߽��� ������
	
	//�尩
	greateGlove1, //������ ������ �尩
	greateGlove2, //��� �������� �尩
	poorGlove1,   //�콼 ö�尩
	poorGlove2,   //���� ���尩

	//����
	greateBody1,  //Ǯ �÷���Ʈ
	greateBody2,  //�������� �κ�
	poorBody1,    //�ݰ� �÷���Ʈ
	poorBody2,    //������ ������ �κ�

	//����
	greateBoots1, //������ ������ ��Ʋ����
	greateBoots2, //������ ��� �Ź�
	poorBoots1,   //�콼 ö ����
	poorBoots2,   //������ �ȭ

	//����
	greateHead1,  //�¾���� ����
	greateHead2,  //��ó���� ����
	poorHead1,    //īī���� ����
	poorHead2,    //������ ���� ��Ŭ��

	//�Ǽ��縮
	greateRing1,  //���� ����
	greateRing2,  //������ ��� �������
	poorRing1,    //���� ����
	poorRing2,    //��� ����

	//�Ҹ�ǰ
	greatePortion1, //�뷮�� ���� ����
	greatePortion2, //�뷮�� ���� ����
	poorPortion1,   //�ҷ��� ���� ����
	poorPortion2,   //�ҷ��� ���� ����
};

#define ITEM_WEPON		0b0000001
#define ITEM_ACCESARRY	0b0000010
#define ITEM_BODY_AMOR	0b0000100
#define ITEM_TOE_AMOR	0b0001000
#define ITEM_HAND_AMOR	0b0010000
#define ITEM_HEAD_AMOR  0b0100000
#define ITME_CONSUMABLE 0b1000000