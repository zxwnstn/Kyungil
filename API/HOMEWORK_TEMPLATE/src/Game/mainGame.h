#pragma once
#include "Common/GameNode.h"

class MainGame :  public GameNode
{
private:

public:
	MainGame();
	~MainGame();

	HRESULT init() override;	
	void release() override;
	void update() override;
	void render() override;
};

