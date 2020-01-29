#include "Character.h"



Character::Character()
{
	state.flip((int)CharacterState::eCharacterDown);
	collisionRect = UTIL::IRectMake(100, 100, 100, 100);
}


Character::~Character()
{
}

bool Character::init()
{
	return true;
}

void Character::update(float _deltaTime)
{
	if (KEYMANAGER->isStayKeyDown(P1_LEFT)) {
		collisionRect.moveLeft(speed);
		state.reset();
		state.flip((int)CharacterState::eCharacterLeft);
		state.flip((int)CharacterState::eCharacterMoveLeft);
	}
	else if (KEYMANAGER->isStayKeyDown(P1_RIGHT)) {
		collisionRect.moveRight(speed);
		state.reset();
		state.flip((int)CharacterState::eCharacterRight);
		state.flip((int)CharacterState::eCharacterMoveRight);
	}
	else if (KEYMANAGER->isStayKeyDown(P1_UP)) {
		collisionRect.moveUp(speed);
		state.reset();
		state.flip((int)CharacterState::eCharacterUp);
		state.flip((int)CharacterState::eCharacterMoveUp);
	}
	else if (KEYMANAGER->isStayKeyDown(P1_DOWN)) {
		collisionRect.moveDown(speed);
		state.reset();
		state.flip((int)CharacterState::eCharacterDown);
		state.flip((int)CharacterState::eCharacterMoveDown);
	}
	else if (KEYMANAGER->isOnceKeyDown(P1_EVENT)) {

	}
	else {
		for (int i = 4; i < 7; ++i) {
			state.reset(i);
		}
	}

}

void Character::render(HDC hdc)
{
	for (int i = 4; i < 7; ++i) {
		if (state[i]) {
			switch (CharacterState(i))
			{
			case CharacterState::eCharacterMoveDown:
				if(!aniDown->isPlay())
					aniDown->start();
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniDown);
				break;
			case CharacterState::eCharacterMoveUp:
				if (!aniUp->isPlay())
					aniUp->start();
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniUp);
				break;
			case CharacterState::eCharacterMoveLeft:
				if (!aniLeft->isPlay())
					aniLeft->start();
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniLeft);


				break;
			case CharacterState::eCharacterMoveRight:
				if (!aniRight->isPlay())
					aniRight->start();
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniRight);
				break;
			}
		}
	}
	for (int i = 0; i < 1; ++i) {
		if (state[i]) {
			switch (CharacterState(i))
			{
			case CharacterState::eCharacterDown:
				aniDown->start();
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniDown);
				break;
			case CharacterState::eCharacterUp:
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniUp);
				aniUp->start();
				break;
			case CharacterState::eCharacterLeft:
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniLeft);
				aniLeft->start();
				break;
			case CharacterState::eCharacterRight:
				img->aniRender(hdc, collisionRect.left, collisionRect.top, aniRight);
				aniRight->start();
				break;
			}
		}
	}
	
}

void Character::afterRender(HDC hdc)
{
}

void Character::debugRender(HDC hdc)
{
	UTIL::DrawColorRect(hdc, collisionRect, true, RGB(255, 0, 0));
}
