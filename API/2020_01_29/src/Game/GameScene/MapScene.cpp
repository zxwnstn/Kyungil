#include "MapScene.h"
#include "Game/GameObject/Dao.h"
#include "Game/GameObject/Bazzi.h"
#include "Game/GameObject/Dizni.h"


MapScene::MapScene()
{
}


MapScene::~MapScene()
{
}

bool MapScene::init()
{
	backGround = IMAGEMANAGER->findImage("»ç³ª");
	return true;
}

void MapScene::update(float _deltaTime)
{
	character->update(_deltaTime);
}

void MapScene::release()
{
	character = nullptr;
}

void MapScene::setData(int _type)
{
	CharacterType type = (CharacterType)_type;
	switch (type)
	{
	case CharacterType::eCharacterDao:
		character = std::make_shared<Dao>();
		break;
	case CharacterType::eCharacterDizni:
		character = std::make_shared<Dizni>();
		break;
	case CharacterType::eCharacterBazzi:
		character = std::make_shared<Bazzi>();
		break;
	}
}

void MapScene::render(HDC hdc)
{
	backGround->render(hdc);
	character->render(hdc);
}

void MapScene::afterRender(HDC hdc)
{
}

void MapScene::debugRender(HDC hdc)
{
	character->debugRender(hdc);
}
