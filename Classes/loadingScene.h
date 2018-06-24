#ifndef __SCENE_HELLOWORLDSCENE_H__
#define __SCENE_HELLOWORLDSCENE_H__

#include"cocos2d.h"

class loadingScene : public cocos2d::Layer
{
private:

	cocos2d::ProgressTimer* loadProgress;//������

	cocos2d::Label* percentLabel;//���ؽ���label  
	cocos2d::Label* loadLabel;//��ʾ loading: ��label  

	int m_numSp;//Ҫ���صľ�����Ŀ,��ʼ��Ϊ 20 ��  
	int m_loadedSp;//�Ѽ��صľ�����Ŀ  

				   //void endLoading(float dt);

public:
	loadingScene() : m_numSp(1), m_loadedSp(0), loadProgress(NULL) {};   //����ͼƬ����Ҫ��m_numSp���һ������

	static cocos2d::Scene* createScene();
	virtual bool init();
	void loadSound();

	void loadingCallback(cocos2d::Object* pSender);
	CREATE_FUNC(loadingScene);
};
#endif
