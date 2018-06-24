#pragma once
#ifndef  _GAMEPLAYSCENE_H_
#define  _GAMEPLAYSCENE_H_

#include  "cocos2d.h"
#include "Building.h"
#include "soldier.h"
#include "bullets.h"

class GamePlayScene :public cocos2d::Layer
{
	cocos2d::TMXTiledMap *map;
	cocos2d::TMXLayer *collidable;
	cocos2d::Sprite* InitialCar;
	cocos2d::Vec2 touchLocation;
	cocos2d::Sprite* buildMenu;


public:
	Soldier *selSprite;
	static cocos2d::Vector< Soldier *> movableSprites;
	static cocos2d::Vector< Building *> buildingArray;
	static cocos2d::Scene *createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	virtual void update(float dt);

	void collisionWithMap(cocos2d::Vec2 position);

	void setViewpointCenter(cocos2d::Vec2 position);

	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);

	void selectSpriteForTouch(cocos2d::Point touchLocation);

	void shootBullet(float dt);
	CREATE_FUNC(GamePlayScene);
};

class BuildLayer :public cocos2d::Layer 
{
public:
	Label * GoldNumberG;
	char goldNumber[10];
	virtual bool init();

	void flushGoldNumber(float a);
	void setGoldNumber(float a);
	void buildingCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(BuildLayer);
};
#endif // _GAMEPLAYSCENE_H_