#pragma once
#ifndef  _GAMEPLAYSCENE_H_
#define  _GAMEPLAYSCENE_H_

#include  "cocos2d.h"


class GamePlayScene :public cocos2d::Layer
{
	cocos2d::TMXTiledMap *map;
	cocos2d::TMXLayer *collidable;
	cocos2d::Sprite* InitialCar;
	
public:
	static cocos2d::Scene *createScene();
	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	//void setSpritePosition(cocos2d::Vec2 position);

	void setViewpointCenter(cocos2d::Vec2 position);

	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);

	CREATE_FUNC(GamePlayScene);
};



#endif // _GAMEPLAYSCENE_H_