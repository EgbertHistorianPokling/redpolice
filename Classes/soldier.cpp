#include"soldier.h"

Soldier::Soldier(SoldierType types)
{

}

Soldier*Soldier::createSoldier(SoldierType type)
{
	Soldier * soldier = new Soldier(type);
	const char*SoldierFramName = SOLDIERG;

	switch (type)
	{
	case SoldierG:
	{
		soldier->twoParties = EvilGengS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 5;
		soldier->createGold = 4;
		soldier->createTime = 5;

		SoldierFramName = SOLDIERG;
		break;
	}
	case SoldierZ:
	{
		soldier->twoParties = KindZhuS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 5;
		soldier->createGold = 4;
		soldier->createTime = 5;

		SoldierFramName = SOLDIERZ;
		break;
	}
	case DogG:
	{
		soldier->twoParties = EvilGengS;
		soldier->initialHitPoints = 15;
		soldier->neededGold = 7;
		soldier->createGold = 4;
		soldier->createTime = 5;

		SoldierFramName = DOGG;
		break;
	}
	case DogZ:
	{
		soldier->twoParties = KindZhuS;
		soldier->initialHitPoints = 15;
		soldier->neededGold = 7;
		soldier->createGold = 4;
		soldier->createTime = 5;

		SoldierFramName = DOGZ;
		break;
	}
	case EngineerG:
	{
		soldier->twoParties = EvilGengS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 10;
		soldier->createGold = 4;
		soldier->createTime = 10;

		SoldierFramName = ENGINEERG;
		break;
	}
	case EngineerZ:
	{
		soldier->twoParties = KindZhuS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 10;
		soldier->createGold = 4;
		soldier->createTime = 10;

		SoldierFramName = ENGINEERZ;
		break;
	}
	case TankG:
	{
		soldier->twoParties = EvilGengS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 20;
		soldier->createGold = 10;
		soldier->createTime = 10;

		SoldierFramName = TANKG;
		break;

	}
	case TankZ:
	{
		soldier->twoParties = KindZhuS;
		soldier->initialHitPoints = 10;
		soldier->neededGold = 20;
		soldier->createGold = 10;
		soldier->createTime = 10;

		SoldierFramName = TANKZ;
		break;
	}
	default:
		break;
	}
	soldier->initWithFile(SoldierFramName);
	return soldier;
	CC_SAFE_DELETE(soldier);
}
//
//void Soldier::createSoldier(char name[])
//{
//	char temp[100];
//	SpriteFrameCache * cacheFrame = SpriteFrameCache::sharedSpriteFrameCache();
//	sprintf(temp, "%s_soldier.plist", name);    //将name转换成%s格式,然后一起放入temp中
//	cacheFrame->addSpriteFramesWithFile(temp);     //从帧文件中添加精灵
//
//	this->dic1 = __Dictionary::create();
//	this->dic1->retain();
//	//this->dic2 = __Dictionary::create();
//	//this->dic2->retain();
//
//	for (int i = 0; i < 10; ++i)
//	{
//		this->dic1->setObject(cacheFrame, i);
//	}
//}

//Soldier::Soldier(Building* type, Point position)
//{
//}
//
//Soldier* Soldier::createBuildingSoldier(Building* type, Point position)
//{
//	Soldier* soldier = new Soldier(type, position);
//	switch (type->buildingTypes)
//	{
//	case FactoryPG:
//	{
//		soldier->
//	}
//	}
//
//}
//void Soldier::MenuCallBack(Ref* pSender)
//{
//	MenuItem* soldier = (MenuItem*)pSender;
//	int tag = soldier->getTag();
//
//	Building* theBuilding;
//
//	DictElement* pElement;
//
//	CCDICT_FOREACH(dic1, pElement)
//	{
//		int key = pElement->getIntKey();
//		Sprite* sprite = (Sprite*)pElement->getObject();
//
//		switch (theBuilding->buildingTypes)
//		{
//		case FactoryPG:
//		{
//			int x = CCRANDOM_0_1() * (theBuilding->getPosition.width + 10);
//			int y = CCRANDOM_0_1() * (theBuilding->getPosition.height + 10);
//			sprite->setPosition(Vec2(x, y));
//			this->addChild(sprite);
//		}
//		default:
//			break;
//		}
//	}
//}
//
//Soldier::~Soldier()
//{
//	this->dic1->removeAllObjects();
//	CC_SAFE_RELEASE_NULL(this->dic1);
//}
Soldier::~Soldier()
{

}