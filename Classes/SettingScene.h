#pragma once
#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


class SettingScene : public cocos2d::Layer
{
public:



	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	void menuSoundToggleCallback(cocos2d::Ref * pSender);
	void menuMusicToggleCallback(cocos2d::Ref * pSender);
	void menu0kCallback(cocos2d::Ref * pSender);


	CREATE_FUNC(SettingScene);

};



#endif // _SETTINGS_SCENE_H__