#pragma once
//게임 내에서 쓰이는 Enum과 구조체 등을 정의 합니다.

enum class CharacterType {
	eCharacterDao,
	eCharacterDizni,
	eCharacterBazzi
};

enum class CharacterState {
	eCharacterUp,
	eCharacterDown,
	eCharacterLeft,
	eCharacterRight,
	eCharacterMoveUp,
	eCharacterMoveDown,
	eCharacterMoveLeft,
	eCharacterMoveRight,
};