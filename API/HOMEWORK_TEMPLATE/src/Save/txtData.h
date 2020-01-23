#pragma once
#include "stdafx.h"

class txtData 
{
public:
	bool init();

public:
	//save
	void txtSave(TCHAR* saveFileName, std::vector<tstring>vStr);
	TCHAR* vectorArrayCombine(std::vector<tstring> vArray);

	//load
	std::vector<tstring>txtLoad(TCHAR* loadFileName);
	std::vector<tstring>charArraySeperation(TCHAR charArray[]);

private:
	DECLARE_SINGLE(txtData);
};

