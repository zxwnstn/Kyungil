#pragma once
//======================================
//##			매니저들			  ##
//======================================
#include "SystemManager/imageManager.h"
#include "SystemManager/keyManager.h"
#include "SystemManager/sceneManager.h"
#include "SystemManager/SoundManager.h"
#include "SystemManager/timeManager.h"

#define IMAGEMANAGER	ImageManager::GetInst()
#define KEYMANAGER		keyManager::GetInst()
#define SCENEMANAGER	sceneManager::GetInst()
#define SOUNDMANAGER	SoundManager::GetInst()
#define TIMEMANAGER		timeManager::GetInst()
