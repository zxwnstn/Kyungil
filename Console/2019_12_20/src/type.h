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
	//무기
	greateSword1, //집행자의 대검
	poorSword1,   //여행자의 도검
	greateWand1,  //대현자의 지팡이
	poorWand1,    //견습용 지팡이
	
	//장갑
	greateGlove1, //강인한 전사의 장갑
	greateGlove2, //상급 마법사의 장갑
	poorGlove1,   //녹슨 철장갑
	poorGlove2,   //해진 면장갑

	//갑바
	greateBody1,  //풀 플레이트
	greateBody2,  //대현자의 로브
	poorBody1,    //금간 플레이트
	poorBody2,    //대현자 지망생 로브

	//부츠
	greateBoots1, //위대한 전사의 배틀부츠
	greateBoots2, //마력이 깃든 신발
	poorBoots1,   //녹슨 철 부츠
	poorBoots2,   //가벼운 운동화

	//투구
	greateHead1,  //태양신의 투구
	greateHead2,  //부처님의 지혜
	poorHead1,    //카카시의 복면
	poorHead2,    //나뭇잎 마을 서클릿

	//악세사리
	greateRing1,  //절대 반지
	greateRing2,  //마력이 긷든 절대반지
	poorRing1,    //예쁜 반지
	poorRing2,    //어여쁜 반지

	//소모품
	greatePortion1, //대량의 힐링 포션
	greatePortion2, //대량의 마나 포션
	poorPortion1,   //소량의 힐링 포션
	poorPortion2,   //소량의 마나 포션
};

#define ITEM_WEPON		0b0000001
#define ITEM_ACCESARRY	0b0000010
#define ITEM_BODY_AMOR	0b0000100
#define ITEM_TOE_AMOR	0b0001000
#define ITEM_HAND_AMOR	0b0010000
#define ITEM_HEAD_AMOR  0b0100000
#define ITME_CONSUMABLE 0b1000000