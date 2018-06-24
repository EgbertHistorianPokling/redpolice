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

	typedef enum      //����������
	{
		FactoryPG = 0,              //����ս���Ĺ���
		FactoryPZ,
		FactoryEG,                   //�糧
		FactoryEZ,
		SkyscraperG,                  //��Ӫ
		SkyscraperZ,
		BaseG,               //����
		BaseZ,
		MineG,
		MineZ,
		AircraftG,
		AircraftZ,
		ShipG,
		ShipZ,
		Void,
	}BuildingTypes;

	typedef enum      //�뽨���йصļ���
	{
		BulletSkill = 0,   //�����ӵ�
		ExplosionSkill,    //������ը
		GoldSkill,        //�������
		ProduceSkill,       //���������͹��Ӻͼ�����
		ProduceElectricSkill,      //������
		ProduceTankSkill,    //����ս��
	}TypeOfSkills;

	typedef enum    //�����ķ���
	{
		Static = 0,     //��ֹ��
		Moving,      //�ܷ����ܵ�
	}MovementOfBuildings;

	typedef enum    //���˫��
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

		float attackForce;  //������
		float initialHitPoints; //��ʼ����ֵ
		int attackFrequency;  //����Ƶ��
		float constructionTime; //����ʱ��
		int neededGolds; //��Ҫ�Ľ����
		int produceGolds;   //��������õĽ��
		int createBullet; //�����ӵ��ļ��
		int createSoldiers; //��������ʱ��
		int createDogs;  //�������ӵ�ʱ��
		int createTank;   //����ս����ʱ��
		int createEngineers; //������������ʱ��
		int produceElectirc;    //������
		int createGold;           //�������
		bool canAttack;  //�Ƿ���Թ���

		Building::Building(BuildingTypes type);
		static Building* createBuilding(BuildingTypes type);    //��ͬ�����Ļ�����ֵ�趨
		~Building();    //��������

		//Sprite* createBuildings(char name[]);   //��������
		//void runRepeatAction(Vector<SpriteFrame*> plistArray); //�ظ�����

		void explosion(); //��ը����
		void explosion(Point pos);
		void explosionDown(Node * sender);
		//void removeBuilding(); //�Ƴ�����

		void createGoldFromMine(float a);

	};
#endif  //_BUILDING_H__
