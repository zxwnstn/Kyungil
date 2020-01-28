#pragma once
#include "stdafx.h"

class txtData 
{
public:
	bool init();

public:
	//save
	void txtSave(char* saveFileName, std::vector<std::string>vStr);
	char* vectorArrayCombine(std::vector<std::string> vArray);

	//load
	std::vector<std::string>txtLoad(char* loadFileName);
	std::vector<std::string>charArraySeperation(char charArray[]);

private:
	DECLARE_SINGLE(txtData);
};

