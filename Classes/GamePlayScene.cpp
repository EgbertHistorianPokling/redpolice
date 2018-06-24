//#include "Building.h"
//#include "soldier.h"
#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

int GoldNumbers = 300;
int haveMineCreated = 0;
int haveSkyscraperCreated = 0;
int haveFactoryCreated = 0;
BuildingTypes haveBuildingTouched = Void;
cocos2d::Vector< Soldier *> GamePlayScene::movableSprites;
cocos2d::Vector< Building *> GamePlayScene::buildingArray;

Scene* GamePlayScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::createWithPhysics();

	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));        //set Gravity
//	scene->getPhysicsWorld()->setAutoStep(false);

	// 'layer' is an autorelease object

	auto layer = GamePlayScene::create();
	auto layer1 = BuildLayer::create();
	// add layer as a child to scene

	scene->addChild(layer,0,300);
	scene->addChild(layer1, 1);
	// return the scene

	return scene;
};


bool GamePlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size winSize = Director::getInstance()->getWinSize();

	map = TMXTiledMap::create("map.tmx");                     // map
	addChild(map, 0, 100);

	Size size0 = map->getContentSize();

	TMXObjectGroup *group = map->getObjectGroup("objects");
	auto spawnPoint = group->getObjects();

	for (auto it = spawnPoint.begin(); it != spawnPoint.end(); it++)
	{
		auto vm = it->asValueMap();
		float x = vm["x"].asFloat();
		float y = vm["y"].asFloat();

		auto sprite = Sprite::create("barrier.png");
		sprite->setTag(1);
		auto bd = PhysicsBody::createBox(sprite->getContentSize());
		bd->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(bd);
		PhysicsMaterial(0, 0, 0);
		bd->setDynamic(false);
		sprite->setVisible(false);
		sprite->setPosition(Vec2(x, y));
		addChild(sprite, 2);
	}
	collidable = map->getLayer("collidable");
	//collidable->setVisible(false);                        //hide collidable

	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);               //set single point touch

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	std::string images[] = { "InitialCar.png" };         //sprite array
	int images_length = 1;
	for (int i = 0; i < images_length; ++i)
	{
		std::string image = images[i];
		Sprite *sprite = Sprite::create(image);

		sprite->setTag(1);
		auto body = PhysicsBody::createBox(sprite->getContentSize());
		body->setContactTestBitmask(0xFFFFFFFF);
		sprite->setPhysicsBody(body);

		//float offsetFraction = ((float)(i + 1)) / (images_length + 1);
		//sprite->setPosition(visibleSize.width*offsetFraction, visibleSize.height / 2);
		this->addChild(sprite, 2);

		//movableSprites.pushBack(sprite);
	}

	//movableSprites.front()->setPosition(Vec2(100, 100));

	scheduleUpdate();               //Open the default timer. The refresh interval is one frame.

	return true;
};

bool BuildLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto buildMenu = Sprite::create("buildMenu.png");
	buildMenu->setAnchorPoint(Vec2(1, 1));
	auto buildMenuBody = PhysicsBody::createBox(buildMenu->getContentSize());
	buildMenuBody->setContactTestBitmask(0xFFFFFFFF);
	buildMenuBody->setDynamic(false);
	buildMenu->setPhysicsBody(buildMenuBody);
	buildMenu->setPosition(Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height));
	addChild(buildMenu, 1);


	Label *label1 = Label::createWithSystemFont("基地", "Arial", 5);
	label1->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 60));
	this->addChild(label1, 2);

	Label *label2 = Label::createWithSystemFont("电厂", "Arial", 5);
	label2->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 72));
	this->addChild(label2, 2);

	Label *label3 = Label::createWithSystemFont("矿场", "Arial", 5);
	label3->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 84));
	this->addChild(label3, 2);

	Label *label4 = Label::createWithSystemFont("兵营", "Arial", 5);
	label4->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 96));
	this->addChild(label4, 2);

	Label *label5 = Label::createWithSystemFont("车厂", "Arial", 5);
	label5->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 108));
	this->addChild(label5, 2);

	Label *label6 = Label::createWithSystemFont("警犬", "Arial", 5);
	label6->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 119));
	this->addChild(label6, 2);

	Label *label7 = Label::createWithSystemFont("大兵", "Arial", 5);
	label7->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 130));
	this->addChild(label7, 2);

	Label *label8 = Label::createWithSystemFont("坦克", "Arial", 5);
	label8->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 142));
	this->addChild(label8, 2);

	GoldNumberG = Label::create("300", "Arial", 25);
	GoldNumberG->setColor(ccc3(225, 225, 225));
	GoldNumberG->setPosition(Vec2(20,260));      //设置金币标签和位置，网络互联问题需要考虑
	this->addChild(GoldNumberG,2);

	this->schedule(schedule_selector(BuildLayer::setGoldNumber), 5.0);  //每5s增加金币
	this->schedule(schedule_selector(BuildLayer::flushGoldNumber), 0.1);

	auto building1 = MenuItemImage::create(
		"BaseG.png",
		"BaseG.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	building1->setAnchorPoint(Vec2(1, 1));
	building1->setScale(0.09);
	building1->setTag(101);
	building1->setPosition(Vec2(origin.x + visibleSize.width - 20, origin.y + visibleSize.height - 53));

	auto building2 = MenuItemImage::create(
		"FactoryEG.png",
		"FactoryEG.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	building2->setAnchorPoint(Vec2(1, 1));
	building2->setScale(0.13);
	building2->setTag(102);
	building2->setPosition(Vec2(origin.x + visibleSize.width - 15, origin.y + visibleSize.height - 63));

	auto building3 = MenuItemImage::create(
		"MineG.png",
		"MineG.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	building3->setAnchorPoint(Vec2(1, 1));
	building3->setScale(0.14);
	building3->setTag(103);
	building3->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 72));

	auto building4 = MenuItemImage::create(
		"SkyscraperG.png",
		"SkyscraperG.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	building4->setAnchorPoint(Vec2(1, 1));
	building4->setScale(0.14);
	building4->setTag(104);
	building4->setPosition(Vec2(origin.x + visibleSize.width - 13, origin.y + visibleSize.height - 85));

	auto building5= MenuItemImage::create(
		"FactoryPG.png",
		"FactoryPG.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	building5->setAnchorPoint(Vec2(1, 1));
	building5->setScale(0.13);
	building5->setTag(105);
	building5->setPosition(Vec2(origin.x + visibleSize.width - 16, origin.y + visibleSize.height - 96));

	auto arm1 = MenuItemImage::create(
		"USA character.png",
		"USA character.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	arm1->setAnchorPoint(Vec2(1, 1));
	arm1->setScale(0.11);
	arm1->setTag(106);
	arm1->setPosition(Vec2(origin.x + visibleSize.width - 18, origin.y + visibleSize.height - 111));

	auto arm2 = MenuItemImage::create(
		"USA soldier.png",
		"USA soldier.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	arm2->setAnchorPoint(Vec2(1, 1));
	arm2->setScale(0.11);
	arm2->setTag(107);
	arm2->setPosition(Vec2(origin.x + visibleSize.width - 17, origin.y + visibleSize.height - 122));

	auto tank = MenuItemImage::create(
		"USA tank.png",
		"USA tank.png",
		CC_CALLBACK_1(BuildLayer::buildingCallback, this));

	tank->setAnchorPoint(Vec2(1, 1));
	tank->setScale(0.11);
	tank->setTag(108);
	tank ->setPosition(Vec2(origin.x + visibleSize.width - 19, origin.y + visibleSize.height - 136));

	Menu *mu = Menu::create(building1, building2, building3, building4, building5, arm1, arm2, tank, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 2);
}

bool GamePlayScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	touchLocation = this->convertTouchToNodeSpace(touch);
	this->selectSpriteForTouch(touchLocation);

	if (haveBuildingTouched !=Void)
	{
		auto building = Building::createBuilding(haveBuildingTouched);
		if (GoldNumbers >= building->neededGolds)
		{
			building->setScale(0.5);
			auto bd = PhysicsBody::createBox(building->getContentSize()*0.5f);
			bd->setContactTestBitmask(0xFFFFFFFF);
			building->setPhysicsBody(bd);
			bd->setDynamic(false);
			building->setPosition(touchLocation);
			buildingArray.pushBack(building);
			addChild(building, 2);
			GoldNumbers = GoldNumbers - building->neededGolds;
			if (haveBuildingTouched == MineG)
				haveMineCreated = 1;
			if (haveBuildingTouched == SkyscraperG)
				haveSkyscraperCreated = 1;
			if (haveBuildingTouched == FactoryPG)
				haveFactoryCreated = 1;
			
			//auto bullet = Bullet::createBullet(building, touchLocation);
			//addChild(bullet);

			//this->schedule(schedule_selector(GamePlayScene::bulletAction, 1.0));

			haveBuildingTouched = Void;
		}
	}

	/*if (selSprite != nullptr)
	{
		Vec2 spritePos = selSprite->getPosition();
		Vec2 tileCoord = this->tileCoordFromPosition(touchLocation);
		int tileGid = collidable->getTileGIDAt(tileCoord);
		if (tileGid == 0)
			ActionInterval* actionTo = MoveTo::create(diff/30, touchLocation);
			selSprite->runAction(actionTo);
	}*/
	return true;
};


void GamePlayScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{

};


void GamePlayScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

};

void GamePlayScene::update(float dt)
{
	/*for (int i = 0; i < 3; ++i)
	{
		getScene()->getPhysicsWorld()->step(1 / 180.0f);
	}*/

	Size visibleSize = Director::getInstance()->getVisibleSize();
	if (selSprite != nullptr)
	{
		Vec2 spritePos = selSprite->getPosition();
		//dis = spritePos.distance(touchLocation);
		Vec2 sub = touchLocation - spritePos;
		float dis = sub.length();
		sub.normalize();
		if (dis > 1)
		{
			selSprite->setPosition(Vec2(spritePos + sub));
		}
		this->setViewpointCenter(spritePos);
	}

};


void GamePlayScene::collisionWithMap(cocos2d::Vec2 position)           //detect collision in map 
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	int tileGid = collidable->getTileGIDAt(tileCoord);
	if (tileGid = !0)
	{
		Value prop = map->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();

		std::string collision = propValueMap["Collidable"].asString();

		if (collision == "true")                    //collision detection succeed
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundBlip.wav");
			return;
		}
	}
};


Vec2 GamePlayScene::tileCoordFromPosition(Vec2 pos)         //from pixel position to tile position
{

	int x = pos.x / map->getTileSize().width;
	int y = (map->getMapSize().height*map->getTileSize().height - pos.y) / map->getTileSize().height;

	return(Vec2(x, y));
};


void GamePlayScene::setViewpointCenter(Vec2 position)       //make sprite in the map center
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);

	x = MIN(x, (map->getMapSize().width * map->getTileSize().width) - visibleSize.width / 2);
	y = MIN(y, (map->getMapSize().height* map->getTileSize().height) - visibleSize.height / 2);

	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);        //screen center
	Vec2 pointB = Vec2(x, y);

	Vec2 offset = pointA - pointB;

	this->setPosition(offset);
};

void GamePlayScene::selectSpriteForTouch(Point touchLocation)          // some actions about selected sprites 
{
	Soldier * newSprite = nullptr;
	for (auto sprite : movableSprites)
	{
		if (sprite->getBoundingBox().containsPoint(touchLocation))
		{
			newSprite = sprite;
			break;
		}
	}

	if ((newSprite != selSprite) && (newSprite != nullptr))
	{
		if (selSprite != nullptr)
		{
			selSprite->stopAllActions();
			selSprite->runAction(RotateTo::create(0.1, 0));
		}

		RotateBy * rotLeft = RotateBy::create(0.1, -14.0);
		RotateBy * rotCenter = RotateBy::create(0.1, 0.0);
		RotateBy * rotRight = RotateBy::create(0.1, 14.0);
		Sequence * rotSeq = Sequence::create(rotLeft, rotCenter, rotRight, rotCenter, NULL);
		newSprite->runAction(RepeatForever::create(rotSeq));
		selSprite = newSprite;
	}
};


void GamePlayScene::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [](PhysicsContact& contact)
	{
		auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
		auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

		return true;
	};


	listener->onContactPreSolve = [](PhysicsContact& contact,
		PhysicsContactPreSolve& solve)
	{
		return true;
	};


	listener->onContactPostSolve = [](PhysicsContact& contact,
		const PhysicsContactPostSolve& solve)
	{
		return true;
	};


	listener->onContactSeparate = [](PhysicsContact& contact)
	{
		auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
		auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

		if (spriteA && spriteA->getTag() == 1
			&& spriteB && spriteB->getTag() == 1)
		{
			spriteA->setColor(Color3B::WHITE);
			spriteB->setColor(Color3B::WHITE);
		}
	};


	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

}


void GamePlayScene::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

void BuildLayer::buildingCallback(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto tag = item->getTag();
	switch (tag)
	{
	case 101:
		haveBuildingTouched = BaseG;
		break;
	case 102:
		haveBuildingTouched = FactoryEG;
		break;
	case 103:
		haveBuildingTouched = MineG;
		break;
	case 104:
		haveBuildingTouched = SkyscraperG;
		break;
	case 105:
		haveBuildingTouched = FactoryPG;
		break;
	case 106:
	{
		auto dog = Soldier::createSoldier(DogG);
		if (GoldNumbers >= dog->neededGold&&haveSkyscraperCreated==1)
		{
			GoldNumbers = GoldNumbers - dog->neededGold;
			Vec2 bp;
			for (auto building : GamePlayScene::buildingArray)
			{
				if (building->buildingTypes == SkyscraperG)
				{
					bp = building->getPosition();
					break;
				}
			}
			dog->setScale(0.2);
			auto bd = PhysicsBody::createBox(dog->getContentSize());
			bd->setContactTestBitmask(0xFFFFFFFF);
			dog->setPhysicsBody(bd);
			//bd->setDynamic(false);
			dog->setPosition(bp + Vec2(10, 10));
			GamePlayScene::movableSprites.pushBack(dog);
			auto lay = getScene()->getChildByTag(300);
			lay->addChild(dog, 2);
		}
		break;
	}
	case 107:
	{
		auto bigSoldier = Soldier::createSoldier(SoldierG);
		if (GoldNumbers >= bigSoldier->neededGold&&haveSkyscraperCreated==1)
		{
			GoldNumbers = GoldNumbers - bigSoldier->neededGold;
			Vec2 bp;
			for (auto building : GamePlayScene::buildingArray)
			{
				if (building->buildingTypes == SkyscraperG)
				{
					bp = building->getPosition();
					break;
				}
			}
			bigSoldier->setScale(0.02);
			auto bd = PhysicsBody::createBox(bigSoldier->getContentSize());
			bd->setContactTestBitmask(0xFFFFFFFF);
			bigSoldier->setPhysicsBody(bd);
			//bd->setDynamic(false);
			bigSoldier->setPosition(bp + Vec2(10, 10));
			GamePlayScene::movableSprites.pushBack(bigSoldier);
			auto lay = getScene()->getChildByTag(300);
			lay->addChild(bigSoldier, 2);
		}
		break;
	}
	case 108:
	{
		auto tank = Soldier::createSoldier(TankG);
		if (GoldNumbers >= tank->neededGold&&haveFactoryCreated==1)
		{
			GoldNumbers = GoldNumbers - tank->neededGold;
			Vec2 bp;
			for (auto building : GamePlayScene::buildingArray)
			{
				if (building->buildingTypes == FactoryPG)
				{
					bp = building->getPosition();
					break;
				}
			}
			//	tank->setScale(0.1);
			auto bd = PhysicsBody::createBox(tank->getContentSize());
			bd->setContactTestBitmask(0xFFFFFFFF);
			tank->setPhysicsBody(bd);
			//bd->setDynamic(false);
			tank->setPosition(bp + Vec2(10, 10));
			GamePlayScene::movableSprites.pushBack(tank);
			auto lay = getScene()->getChildByTag(300);
			lay->addChild(tank, 2);
		}
		break;
	}
	}
}

	void BuildLayer::setGoldNumber(float a)
	{
		if (haveMineCreated == 1)
			GoldNumbers += 10;
	}

	void BuildLayer::flushGoldNumber(float a)
	{
		sprintf(goldNumber, "%d", GoldNumbers);
		GoldNumberG->setString(goldNumber);
	}
	void GamePlayScene::shootBullet(float dt)
	{
		Bullet *bullet=Bullet::createBullet("bullet.png");
		this->addChild(bullet, 1);
	}