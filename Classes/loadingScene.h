#ifndef __SCENE_HELLOWORLDSCENE_H__
#define __SCENE_HELLOWORLDSCENE_H__

#include"cocos2d.h"

class loadingScene : public cocos2d::Layer
{
private:

	cocos2d::ProgressTimer* loadProgress;//进度条

	cocos2d::Label* percentLabel;//加载进度label  
	cocos2d::Label* loadLabel;//显示 loading: 的label  

	int m_numSp;//要加载的精灵数目,初始化为 20 张  
	int m_loadedSp;//已加载的精灵数目  

				   //void endLoading(float dt);

public:
	loadingScene() : m_numSp(1), m_loadedSp(0), loadProgress(NULL) {};   //更改图片多少要在m_numSp里改一下数字

	static cocos2d::Scene* createScene();
	virtual bool init();
	void loadSound();

	void loadingCallback(cocos2d::Object* pSender);
	CREATE_FUNC(loadingScene);
};
#endif
