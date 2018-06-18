#pragma once
#ifndef  _GAMEPLAYSCENE_H_
#define  _GAMEPLAYSCENE_H_

#include  "cocos2d.h"


class GamePlayScene :public cocos2d::Layer
{
	cocos2d::TMXTiledMap *map;
	cocos2d::TMXLayer *collidable;
	cocos2d::Sprite* InitialCar;
	cocos2d::Vec2 touchLocation;

public:

	cocos2d::Sprite * selSprite;
	cocos2d::Sprite * sprite0;
	cocos2d::Vector<cocos2d::Sprite *> movableSprites;
	
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

	cocos2d::Vec2 tilePosFromLocation(cocos2d::CCPoint location, cocos2d::CCTMXTiledMap *tilemap);

	CREATE_FUNC(GamePlayScene);
};


#endif // _GAMEPLAYSCENE_H_