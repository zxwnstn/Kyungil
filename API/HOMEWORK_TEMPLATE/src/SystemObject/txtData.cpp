#include "stdafx.h"
#include "txtData.h"

TxtData::TxtData()
{
}
TxtData::~TxtData()
{
}

bool TxtData::init()
{
	return true;
}

//����¥�� �����͸� ��ƵѰ�(��� �����͸� ���� ������ ©�� �����Ѵ�.)
void TxtData::txtSave(char * saveFileName, std::vector<std::string> vStr)
{

	HANDLE file;
	char str[128];
	DWORD write;
	_tcsncpy_s(str, 128, vectorArrayCombine(vStr), 128);

	file = CreateFile
	(saveFileName,			//������ ���϶Ǵ� �� ��ġ�� �����̸�
		GENERIC_WRITE,		//�����̳� ��ġ�� ����ų� ���� ����� ����
		0,					//���� ���� ����Է�
		NULL,				//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
		CREATE_ALWAYS,		//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL, //�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);				//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����

	WriteFile(file, str, 128, &write, NULL);
	CloseHandle(file);

}
//���� ����� ������(����¥�� �����͸� ��ǥ ������ �� ����)
char * TxtData::vectorArrayCombine(std::vector<std::string> vArray)
{
	char str[128];
	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		_tcsncat_s(str, 128, vArray[i].c_str(), 128);

		if ((i + 1) < vArray.size())
		{
			_tcscat(str, TEXT(","));
		}
	}
	return str;
}

std::vector<std::string> TxtData::txtLoad(char * loadFileName)
{
	HANDLE file;
	char str[128];
	DWORD read;

	file = CreateFile
	(loadFileName,			//������ ���϶Ǵ� �� ��ġ�� �����̸�
		GENERIC_READ,		//�����̳� ��ġ�� ����ų� ���� ����� ����
		0,					//���� ���� ����Է�
		NULL,				//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
		OPEN_EXISTING,		//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL, //�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);				//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����

	ReadFile(file, str, 128, &read, NULL);
	CloseHandle(file);
	return charArraySeperation(str);
}
std::vector<std::string> TxtData::charArraySeperation(char charArray[])
{
	std::vector<std::string>vArray;

	char* seperator = ",";
	char* token;

	token = strtok(charArray, seperator);
	vArray.push_back(token);

	while (NULL!=(token = strtok(NULL, seperator)))
	{
		vArray.push_back(token);
	}
	return vArray;
}
