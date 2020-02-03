#pragma once

class Animation
{
public:
	Animation();
	~Animation();

public:
	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	//ó������ ������ �ִϸ��̼� ����

public:
	void setDefPlayFrame(bool reverse = false, bool loop = false);
	//�迭�� ����� �ִ� �ֵ鸸
	void setPlayFrame(int* playArr, int arrLen, bool loop = false);
	//���۰� �������� ���ؼ�
	void setPlayFrame(int start, int end, bool reverse =  false, bool loop = false);
	//�ʴ� ���� Ƚ��
	void setFPS(int framePerSec);
	//������ ������Ʈ Ÿ��
	void frameUpdate(float elapsedTime);

public:
	void start();
	void stop();
	void pause();
	void resume();

public:
	POINT getFramePos()		{ return _frameList[_playList[_nowPlayIndex]]; }
	int getFrameWidth()		{ return _frameWidth; }
	int getFrameHeight()	{ return _frameHeight; }
	bool isPlay()			{ return _play; }
	
private:
	std::vector<POINT> _frameList;			//��������ġ���
	std::vector<int> _playList;				//�÷��� ���

	int _frameNum;							//������ ����
	int _frameWidth;
	int _frameHeight;

	bool _loop;
	bool _play;

	float _frameUpdateSec;					//������ ������Ʈ
	float _elapsedSec;						//������ ����ð�
	DWORD _nowPlayIndex;					//���� �÷��� �ε���
};