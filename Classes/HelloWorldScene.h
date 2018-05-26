#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "SettingScene.h"

class HelloWorldScene: public cocos2d::Layer
{
public:
	static cocos2d::Scene * createScene();

	virtual bool init();
	
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();

	
	void menuItemStartCallback(cocos2d::Ref * pSender);
	void menuItemSettingCallback(cocos2d::Ref * pSender);
	
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);


	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorldScene);
};
#endif // __HELLOWORLD_SCENE_H__
