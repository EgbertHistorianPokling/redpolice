#pragma once
#ifndef  _WINSCENE_H_
#define  _WINSCENE_H_

#include"cocos2d.h"

class WinScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene * createScene();

	virtual bool init();
};
#endif