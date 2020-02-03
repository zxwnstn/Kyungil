#pragma once
#define KEYMAX 256

class KeyManager {
public:
	HRESULT init();
	void release();

public:
	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	bool isStayKeyDown(int key);
	bool isToggleKey(int key);

public:
	void setCustomKey(int dest, int userKey);

private:
	std::bitset<KEYMAX> _keyUp;
	std::bitset<KEYMAX> _keyDown;

	BYTE playerKey[KEYMAX];

private:
	DECLARE_SINGLE(KeyManager)
};

#define KEYMANAGER KeyManager::GetInst()