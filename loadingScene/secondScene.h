#include"cocos2d.h"

USING_NS_CC;

class secondScene :public cocos2d::Scene
{
public:
	virtual bool init();
	CREATE_FUNC(secondScene);

	static cocos2d::Scene* createScene();

	Layer * m_layer;
};