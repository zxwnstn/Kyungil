#pragma once
//이펙트 클래스 전방선언
class Effect;

class EffectManager
{
public:
	HRESULT init();
	void release();
	void update();
	void render(HDC _hdc);

	//이펙트 추가(키값, 이미지 이름, 이미지 가로, 세로, 한프레임 가로, 세로, FPS, 속도, 버퍼갯수)
	void addEffect(std::string effectKey, char* imageName, int imageW, int imageH, int frameW, int frameH, int fps, float elapsedTime, int buffer);
	void play(std::string effectKey, int x, int y);

private:
	//이펙트 클래스 담은 녀석
	typedef std::vector<Effect*>vEffect;
	typedef std::vector<Effect*>::iterator viEffect;
	//이펙트 클래스가 담겨져 있는 벡터를 담은 녀석
	typedef std::map<std::string, vEffect> mEffect;
	typedef std::map<std::string, vEffect>::iterator miEffect;
	//모든 이펙트를 관리할 녀석
	typedef std::vector<mEffect> vTotalEffect;
	typedef std::vector<mEffect>::iterator viTotalEffect;

	//실제 모든 이펙트가 담겨져 있는 녀석
	vTotalEffect m_vTotalEffect;

private:
	DECLARE_SINGLE(EffectManager)
};

#define EFFECTMANAGER EffectManager::GetInst()