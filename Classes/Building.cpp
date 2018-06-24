#include"building.h"

#define NAX_COUNT 100

Building::Building(BuildingTypes types)
{
	this->buildingTypes = types;
}

Building* Building::createBuilding(BuildingTypes types)
{
	Building * building = new Building(types);            //实例化Building对象
	const char*buildingFramName = FACTORYPG;

	switch (types)
	{
	case FactoryPG:
	{
		building->movementOfBuildings = Static;
		building->twoParties = EvilGeng;
		building->typeOfSkills = ProduceTankSkill;  //生产工兵和狗子和战车和技术人员的工厂
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
		building->produceElectirc = 50;       //生产电的时间

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
		building->createEngineers = 10;     //生产工兵狗子和技术人员的时间

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
		building->createGold = 60;                //生产金币的时间

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
		building->attackFrequency = 2;           //发射子弹的速度

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
		building->attackFrequency = 2;         //发射子弹是速度（船可以再加一些其他的功能）

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
		building->typeOfSkills = ProduceTankSkill;  //生产战车
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
		building->typeOfSkills = ProduceSkill;   //生产工兵和狗子
		building->initialHitPoints = 200;
		building->neededGolds = 100;
		building->produceGolds = 70;
		building->constructionTime = 100;
		building->createSoldiers = 5;
		building->createDogs = 7;
		building->createEngineers = 10;     //生产工兵狗子和技术人员的时间

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
		building->createGold = 60;                //生产金币的时间

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
		building->attackFrequency = 2;           //发射子弹的速度

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
		building->attackFrequency = 2;         //发射子弹是速度（船可以再加一些其他的功能）

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
//	char temp[100];//帧缓存
//	Sprite* building = Sprite::create(name);
//	//SpriteFrameCache * cacheFrame = SpriteFrameCache::sharedSpriteFrameCache();
//	//sprintf(temp, "%s_building.png", name);    //将name转换成%s格式,然后一起放入temp中
//	//cacheFrame->addSpriteFramesWithFile(temp);     //从帧文件中添加精灵
//	//sprintf(temp, "%s - 1.png", name);                    //拖拽时的动作
//	//this->initWithSpriteFrameName(temp);
//	return building;
//}

void Building::explosion()                                         //爆炸动画
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

void Building::explosionDown(Node * sender)            //爆炸后清除精灵
{
	sender->removeFromParentAndCleanup(true);
}

void Building::createGoldFromMine(float a)
{
	//GoldNumbers = GoldNumbers + 200;         //按照一定时间循环这个函数
}

Building::~Building()   //析构函数
{
}
