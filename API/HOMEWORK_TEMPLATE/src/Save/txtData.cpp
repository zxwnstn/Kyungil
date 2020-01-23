#include "txtData.h"
DEFINITION_SINGLE(txtData)

txtData::txtData()
{
}
txtData::~txtData()
{
}

bool txtData::init()
{
	return true;
}

//����¥�� �����͸� ��ƵѰ�(��� �����͸� ���� ������ ©�� �����Ѵ�.)
void txtData::txtSave(TCHAR * saveFileName, std::vector<tstring> vStr)
{

	HANDLE file;
	TCHAR str[128];
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
TCHAR * txtData::vectorArrayCombine(std::vector<tstring> vArray)
{
	TCHAR str[128];
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

std::vector<tstring> txtData::txtLoad(TCHAR * loadFileName)
{
	HANDLE file;
	TCHAR str[128];
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
std::vector<tstring> txtData::charArraySeperation(TCHAR charArray[])
{
	std::vector<tstring>vArray;

	TCHAR* seperator = TEXT(",");
	TCHAR* token;

	token = _tcstok(charArray, seperator);
	vArray.push_back(token);

	while (NULL!=(token = _tcstok(NULL, seperator)))
	{
		vArray.push_back(token);
	}
	return vArray;
}
