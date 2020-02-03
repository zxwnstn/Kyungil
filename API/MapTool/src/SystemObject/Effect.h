#pragma once

class Effect
{
public:
	Effect();
	~Effect();
	//����Ʈ �ʱ�ȭ(����Ʈ �̹���, ����Ʈ �������� ���α���, ���α��� FPS, ����Ʈ �ӵ�)
	HRESULT init(class Image* effectImage, int frameW, int frameH, int FPS, float elapsedTime);
	void release();
	void update();
	void render(HDC _hdc);

	//���� ���ϴ� ��ǥ�� ����Ʈ��Ʈ����
	void startEffect(int x, int y);
	//����Ʈ ���߱�
	void stopEffect();
	//����Ʈ ��������� ���°� ��������
	bool getIsRunning() { return _isRunning; }

private:
	Image * _effectImage;		//����Ʈ �̹���
	class Animation* _effectAni;		//����Ʈ �ִϸ��̼�

	int _x, _y;					//����Ʈ ��Ʈ�� ��ǥ
	float _elapsedTime;			//����Ʈ ����ð�(�ӵ�)
	bool _isRunning;			//������̳�?
};

