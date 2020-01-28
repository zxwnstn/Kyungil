#pragma once
#include "Common/gameNode.h"

class mainGame :  public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	HRESULT init() override;	
	void release() override;
	void update() override;
	void render() override;
};

