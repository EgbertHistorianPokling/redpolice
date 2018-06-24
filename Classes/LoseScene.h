#pragma once
#ifndef  _LOSESCENE_H_
#define  _LOSESCENE_H_

#include"cocos2d.h"

class LoseScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene * createScene();

	virtual bool init();
};
#endif