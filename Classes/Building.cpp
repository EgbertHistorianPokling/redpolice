#include"building.h"

#define NAX_COUNT 100

Building::Building(BuildingTypes types)
{
	this->buildingTypes = types;
}

Building* Building::createBuilding(BuildingTypes types)
{
	Building * building = new Building(types);            //ʵ����Building����
	const char*buildingFramName = FACTORYPG;

	switch (types)
	{
	case FactoryPG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceTankSkill;  //���������͹��Ӻ�ս���ͼ�����Ա�Ĺ���
		building->initialHitPoints = 100;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 60;
		building->createTank = 15;

		buildingFramName = FACTORYPG;
		break;
	}
	case FactoryEG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceElectricSkill;
		building->initialHitPoints = 150;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 60;
		building->produceElectirc = 50;       //�������ʱ��

		buildingFramName = FACTORYEG;
		break;
	}
	case SkyscraperG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceSkill;
		building->initialHitPoints = 200;
		building->neededGolds = 100;
		building->produceGolds = 70;
		building->constructionTime = 100;
		building->createSoldiers = 5;
		building->createDogs = 7;
		building->createEngineers = 10;     //�����������Ӻͼ�����Ա��ʱ��

		buildingFramName = SKYSCRAPERG;
		
		break;
	}
	case MineG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = GoldSkill;
		building->initialHitPoints = 300;
		building->neededGolds = 150;
		building->produceGolds = 200;
		building->constructionTime = 150;
		building->createGold = 60;                //������ҵ�ʱ��

		buildingFramName = MINEG;
		break;
	}
	case AircraftG:
	{
		building->movementOfBuildings = Moving;
		building->twoParties = EvilGeng;
		building->typeOfSkills = BulletSkill;
		building->initialHitPoints = 50;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 50;
		building->attackFrequency = 2;           //�����ӵ����ٶ�

		buildingFramName = AIRCRAFTG;
		break;
	}
	case ShipG:
	{
		building->movementOfBuildings = Moving;
		building->twoParties = EvilGeng;
		building->typeOfSkills = BulletSkill;
		building->initialHitPoints = 50;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 50;
		building->attackFrequency = 2;         //�����ӵ����ٶȣ��������ټ�һЩ�����Ĺ��ܣ�

		buildingFramName = SHIPG;
		break;
	}
	case BaseG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->initialHitPoints = 500;
		building->neededGolds = 300;
		buildingFramName = BASEG;
		break;
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	case FactoryPZ:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceTankSkill;  //����ս��
		building->initialHitPoints = 100;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 60;
		building->createTank = 15;

		buildingFramName = FACTORYPZ;
		break;
	}
	case FactoryEZ:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceElectricSkill;
		building->initialHitPoints = 150;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->produceElectirc = 50;
		building->constructionTime = 60;

		buildingFramName = FACTORYEZ;
		break;
	}
	case SkyscraperZ:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceSkill;   //���������͹���
		building->initialHitPoints = 200;
		building->neededGolds = 100;
		building->produceGolds = 70;
		building->constructionTime = 100;
		building->createSoldiers = 5;
		building->createDogs = 7;
		building->createEngineers = 10;     //�����������Ӻͼ�����Ա��ʱ��

		buildingFramName = SKYSCRAPERZ;
		break;
	}
	case MineZ:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = GoldSkill;
		building->initialHitPoints = 300;
		building->neededGolds = 150;
		building->produceGolds = 200;
		building->constructionTime = 150;
		building->createGold = 60;                //������ҵ�ʱ��

		buildingFramName = MINEZ;
		break;
	}
	case AircraftZ:
	{
		building->movementOfBuildings = Moving;
		building->twoParties = EvilGeng;
		building->typeOfSkills = BulletSkill;
		building->initialHitPoints = 50;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 50;
		building->attackFrequency = 2;           //�����ӵ����ٶ�

		buildingFramName = AIRCRAFTZ;
		break;
	}
	case ShipZ:
	{
		building->movementOfBuildings = Moving;
		building->twoParties = EvilGeng;
		building->typeOfSkills = BulletSkill;
		building->initialHitPoints = 50;
		building->neededGolds = 50;
		building->produceGolds = 30;
		building->constructionTime = 50;
		building->attackFrequency = 2;         //�����ӵ����ٶȣ��������ټ�һЩ�����Ĺ��ܣ�

		buildingFramName = SHIPZ;
		break;
	}
	case BaseZ:
	{
		building->movementOfBuildings = Static;
		building->twoParties = KindZhu;
		building->initialHitPoints = 500;

		buildingFramName = BASEZ;
		break;
	}
	default:
		break;
	}
	building->initWithFile(buildingFramName);
	return building;
}

//Sprite* Building::createBuildings(char name[])
//{
//	char temp[100];//֡����
//	Sprite* building = Sprite::create(name);
//	//SpriteFrameCache * cacheFrame = SpriteFrameCache::sharedSpriteFrameCache();
//	//sprintf(temp, "%s_building.png", name);    //��nameת����%s��ʽ,Ȼ��һ�����temp��
//	//cacheFrame->addSpriteFramesWithFile(temp);     //��֡�ļ�����Ӿ���
//	//sprintf(temp, "%s - 1.png", name);                    //��קʱ�Ķ���
//	//this->initWithSpriteFrameName(temp);
//	return building;
//}

void Building::explosion()                                         //��ը����
{
	auto spriteFrameCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame *> framelist;
	for (int i = 0; i < 5; ++i)
	{
		SpriteFrame* sf = SpriteFrame::create(String::createWithFormat("building_boom%d.png", i)->_string, Rect(0, 0, 57, 51));
		framelist.pushBack(sf);
		spriteFrameCache->addSpriteFrame(sf, String::createWithFormat("building_boom%d.png", i)->_string);
	}

	Animation* building_animation = Animation::createWithSpriteFrames(framelist, 0.1f);
	AnimationCache::getInstance()->addAnimation(building_animation, "building_boom");

}

void Building::explosion(Point pos)
{
	auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("building_boom"));
	auto repeat = Repeat::create(animate, 1);
	auto sprite = Sprite::create();
	sprite->setPosition(pos);
	this->addChild(sprite);

	auto callBack = CallFunc::create(CC_CALLBACK_0(Building::explosionDown, this, sprite));
	auto sequence = Sequence::create(repeat, callBack, NULL);
	sprite->runAction(sequence);
}

void Building::explosionDown(Node * sender)            //��ը���������
{
	sender->removeFromParentAndCleanup(true);
}

void Building::createGoldFromMine(float a)
{
	//GoldNumbers = GoldNumbers + 200;         //����һ��ʱ��ѭ���������
}

Building::~Building()   //��������
{
}
