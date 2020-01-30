#pragma once
//����Ʈ Ŭ���� ���漱��
class Effect;

class EffectManager
{
public:
	HRESULT init();
	void release();
	void update();
	void render(HDC _hdc);

	//����Ʈ �߰�(Ű��, �̹��� �̸�, �̹��� ����, ����, �������� ����, ����, FPS, �ӵ�, ���۰���)
	void addEffect(std::string effectKey, char* imageName, int imageW, int imageH, int frameW, int frameH, int fps, float elapsedTime, int buffer);
	void play(std::string effectKey, int x, int y);

private:
	//����Ʈ Ŭ���� ���� �༮
	typedef std::vector<Effect*>vEffect;
	typedef std::vector<Effect*>::iterator viEffect;
	//����Ʈ Ŭ������ ����� �ִ� ���͸� ���� �༮
	typedef std::map<std::string, vEffect> mEffect;
	typedef std::map<std::string, vEffect>::iterator miEffect;
	//��� ����Ʈ�� ������ �༮
	typedef std::vector<mEffect> vTotalEffect;
	typedef std::vector<mEffect>::iterator viTotalEffect;

	//���� ��� ����Ʈ�� ����� �ִ� �༮
	vTotalEffect m_vTotalEffect;

private:
	DECLARE_SINGLE(EffectManager)
};

#define EFFECTMANAGER EffectManager::GetInst()