#pragma once
//======================================
//##			매니저들			  ##
//======================================
#include "Manager/imageManager.h"
#include "Manager/keyManager.h"
#include "Manager/NetworkManager.h"
#include "Manager/sceneManager.h"
#include "Manager/SoundManager.h"
#include "Manager/timeManager.h"

#define IMAGEMANAGER	ImageManager::GetInst()
#define KEYMANAGER		keyManager::GetInst()
#define NETWORKMANAGER	NetworkManager::GetInst()
#define SCENEMANAGER	sceneManager::GetInst()
#define SOUNDMANAGER	SoundManager::GetInst()
#define TIMEMANAGER		timeManager::GetInst()
