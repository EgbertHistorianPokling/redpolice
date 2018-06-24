#pragma once
#ifndef __BUILDING_H__
#define __BUILDING_H__

#define FACTORYPG "FactoryPG.png"
#define FACTORYPZ "FactoryPZ.png"
#define SKYSCRAPERG "SkyscraperG.png"
#define SKYSCRAPERZ "SkyscraperZ.png"
#define FACTORYEG "FactoryEG.png"
#define FACTORYEZ "FactoryEZ.png"
#define BASEG "BaseG.png"
#define BASEZ "BaseZ.png"
#define MINEG "MineG.png"
#define MINEZ "MineZ.png"
#define AIRCRAFTG "AircraftG.png"
#define AIRCRAFTZ "AircraftZ.png"
#define SHIPG "ShipG.png"
#define SHIPZ "ShipZ.png"


#include"cocos2d.h"

	USING_NS_CC;

	typedef enum      //建筑的种类
	{
		FactoryPG = 0,              //生产战车的工厂
		FactoryPZ,
		FactoryEG,                   //电厂
		FactoryEZ,
		SkyscraperG,                  //兵营
		SkyscraperZ,
		BaseG,               //基地
		BaseZ,
		MineG,
		MineZ,
		AircraftG,
		AircraftZ,
		ShipG,
		ShipZ,
		Void,
	}BuildingTypes;

	typedef enum      //与建筑有关的技能
	{
		BulletSkill = 0,   //发射子弹
		ExplosionSkill,    //发生爆炸
		GoldSkill,        //产生金币
		ProduceSkill,       //生产工兵和狗子和技术兵
		ProduceElectricSkill,      //生产电
		ProduceTankSkill,    //产生战车
	}TypeOfSkills;

	typedef enum    //建筑的分类
	{
		Static = 0,     //静止的
		Moving,      //能飞能跑的
	}MovementOfBuildings;

	typedef enum    //玩家双方
	{
		EvilGeng = 0,
		KindZhu,
	}TwoParties;

	class Building :public cocos2d::Sprite
	{
	public:
		BuildingTypes buildingTypes;
		TypeOfSkills typeOfSkills;
		MovementOfBuildings movementOfBuildings;
		TwoParties twoParties;

		float attackForce;  //攻击力
		float initialHitPoints; //初始生命值
		int attackFrequency;  //攻击频率
		float constructionTime; //建造时间
		int neededGolds; //需要的金币数
		int produceGolds;   //被打掉后获得的金币
		int createBullet; //发射子弹的间隔
		int createSoldiers; //生产兵的时间
		int createDogs;  //生产狗子的时间
		int createTank;   //生产战车的时间
		int createEngineers; //生产技术兵的时间
		int produceElectirc;    //产生电
		int createGold;           //产生金币
		bool canAttack;  //是否可以攻击

		Building::Building(BuildingTypes type);
		static Building* createBuilding(BuildingTypes type);    //不同建筑的基本数值设定
		~Building();    //析构函数

		//Sprite* createBuildings(char name[]);   //创建建筑
		//void runRepeatAction(Vector<SpriteFrame*> plistArray); //重复动作

		void explosion(); //爆炸动作
		void explosion(Point pos);
		void explosionDown(Node * sender);
		//void removeBuilding(); //移除建筑

		void createGoldFromMine(float a);

	};
#endif  //_BUILDING_H__
