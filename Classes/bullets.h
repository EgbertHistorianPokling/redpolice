#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__


#include"cocos2d.h"
#include"building.h"
#include"soldier.h"
#define BulletSpeedRatio 200

//extern __Array * bulletArray;    //�ⲿ�����bulletArray���飬��mainGameScene�ж���

USING_NS_CC;

class Bullet :public cocos2d::Sprite
{
public:
	Building * buildings;
	Point position;

public:
	Vec2 p;
	//Bullet(Building *building, Point point);
	//Bullet(Soldier * soldier, Point point,float a);
	static Bullet* createBullet(const char* spriteFrameName);
	//static Bullet* createBullets(Soldier* soldier, Point point,float a);
	~Bullet();
	void createAircraftBullet(Point point);
	void createTankBullet(Point point);
	void shoot(Soldier *soldier,Vec2 enemyPosition);
	void update(float dt);

	//void collectGold(Node *sender);
};

#endif //__BULLET_H__
