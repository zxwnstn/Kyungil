#include "stdafx.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "SystemObject/Effect.h"
DEFINITION_SINGLE(EffectManager)

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

HRESULT EffectManager::init()
{
	return S_OK;
}

void EffectManager::release()
{
	viTotalEffect vIter;		//��� ����Ʈ ������ ����
	miEffect mIter;				//����ƮŬ���� ����ִ� �༮

	for (vIter = m_vTotalEffect.begin(); vIter != m_vTotalEffect.end(); ++vIter)
	{
		//����Ʈ�� ��� �ִ� ��
		for (mIter = vIter->begin(); mIter != vIter->end();)
		{
			if (mIter->second.size() != 0)
			{
				//����Ʈ Ŭ������ ���� ����
				viEffect vArriter;

				for (vArriter = mIter->second.begin(); vArriter != mIter->second.end();)
				{
					//����Ʈ Ŭ���� ������
					(*vArriter)->release();
					SAFE_DELETE(*vArriter);
					vArriter = mIter->second.erase(vArriter);
				}
			}
			else
			{
				++mIter;
			}
		}
	}
}

void EffectManager::update()
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = m_vTotalEffect.begin(); vIter != m_vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			viEffect vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}

}

void EffectManager::render(HDC _hdc)
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = m_vTotalEffect.begin(); vIter != m_vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			viEffect vArrIter;

			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->render(_hdc);
			}
		}
	}
}

void EffectManager::addEffect(std::string effectKey, char * imageName, int imageW, int imageH, int frameW, int frameH, int fps, float elapsedTime, int buffer)
{

	Image* img;
	vEffect vEffectBuffer;	//����Ʈ ����
	mEffect mArrEffect;		//������ ���� ����Ʈ

							//�̹����� �̹����Ŵ����� ����� �Ǿ� �ִٸ�
	if (IMAGEMANAGER->findImage(imageName))
	{
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		img = IMAGEMANAGER->addImage(effectKey, imageName, imageW, imageH, true, RGB(255, 0, 255));
	}

	//���� ũ�⸸ŭ ����Ʈ�� �Ҵ��� �ʱ�ȭ �ؼ� ���ͷ� �����.
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new Effect);
		vEffectBuffer[i]->init(img, frameW, frameH, fps, elapsedTime);
	}

	//���� ��� ����Ʈ ���۸� �ʿ� �ִ´�.
	mArrEffect.insert(make_pair(effectKey, vEffectBuffer));
	//�ʿ� ��� ���͸� ��Ż���Ϳ� ����.
	m_vTotalEffect.push_back(mArrEffect);


}

void EffectManager::play(std::string effectKey, int x, int y)
{
	viTotalEffect vIter;
	miEffect mIter;

	for (vIter = m_vTotalEffect.begin(); vIter != m_vTotalEffect.end(); ++vIter)
	{
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{

			//����Ʈ Ű���� ���ؼ� ���� �ʴٸ� ���� ������ �ѱ���.
			if (!(mIter->first == effectKey))break;


			//����Ʈ Ű���� ��ġ�ϸ� ����Ʈ�� �÷��� ����.
			viEffect vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				if ((*vArrIter)->getIsRunning())
					continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}
}
