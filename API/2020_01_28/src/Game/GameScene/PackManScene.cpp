#include "PackManScene.h"

PackManScene::PackManScene()
{
}


PackManScene::~PackManScene()
{
}

bool PackManScene::init()
{
	//resource
	IMAGEMANAGER->addImage("¸Ê", "images/packManBackGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ÆÑ¸Ç", "images/packMan.bmp", 60, 128, 2, 4, true, RGB(255, 0, 255));

	SOUNDMANAGER->addStream("bgm", "sound/CheetahMen.mp3", true);
	SOUNDMANAGER->addSound("ÄÚµüÁö µæ", "sound/getCoddac.mp3");

	backGround = IMAGEMANAGER->findImage("¸Ê");
	
	//obj
	packMan = std::make_shared<PackMan>();
	packMan->init();

	for (int i = 0; i < 17; ++i) {
		for (int j = 0; j < 17; ++j) {
			auto temp = std::make_shared<Coddaczi>(i * 40 + 70, j * 45 + 70);
			if (UTIL::isRectColorSame(backGround->getMemDC(), temp->getRect(), 2, 2))
				coddaczis.push_back(temp);		
		}	
	}
	SOUNDMANAGER->playSound("bgm", Channel::bgm);
	return true;
}

void PackManScene::update(float _deltaTime)
{
	packMan->update(_deltaTime);
	for (auto coddaczi : coddaczis)
		coddaczi->update(_deltaTime);

	for (auto it = coddaczis.begin(); it != coddaczis.end(); ++it) {
		if (UTIL::isRectRectCollision(packMan->getRect(), (*it)->getRect())) {
			coddaczis.erase(it);
			SOUNDMANAGER->playSound("ÄÚµüÁö µæ", Channel::effects);
			SOUNDMANAGER->setVolume(Channel::effects, 0.3f);
			break;
		}
	}
}

void PackManScene::release()
{
	packMan = nullptr;
}

void PackManScene::render(HDC hdc)
{
	UTIL::DrawColorRect(hdc, back, RGB(0, 0, 0));
	backGround->render(hdc);
	packMan->render(hdc);
	for (auto coddaczi : coddaczis)
		coddaczi->render(hdc);
}

void PackManScene::afterRender(HDC hdc)
{
}

void PackManScene::debugRender(HDC hdc)
{
	packMan->debugRender(hdc);
}
