#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include"cocos2d.h"
#include"building.h"

USING_NS_CC;

#define SOLDIERG "soldierG.png"
#define SOLDIERZ "soldierZ.png"
#define DOGG "dogG.png"
#define DOGZ "dogZ.png"
#define ENGINEERG "engineerG.png"
#define ENGINEERZ "engineerZ.png"
#define TANKG "tankG.png"
#define TANKZ "tankZ.png"

typedef enum {
	SoldierG = 0,
	SoldierZ,
	DogG,
	DogZ,
	EngineerG,
	EngineerZ,
	TankG,
	TankZ,
}SoldierType;

typedef enum
{
	EvilGengS = 0,
	KindZhuS,
}TwoPartie;

class Soldier : public cocos2d::Sprite
{
public:
	SoldierType soldierType;
	TwoPartie twoParties;

	float attackForce;
	float initialHitPoints;
	float createTime;
	int neededGold;
	int createGold;

	cocos2d::__Dictionary * dic1;
	cocos2d::__Dictionary * dic2;

	static Soldier* createSoldier(SoldierType type);
	//static Soldier* createBuildingSoldier(Building* type, Point position);

	Soldier(SoldierType types);
	//Soldier(Building* type, Point position);
	~Soldier();

	//void createSoldier(char name[]);
	//void MenuCallBack(Ref* pSender);

};

#endif //__SPRITE_H__
