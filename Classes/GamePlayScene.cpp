#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Scene* GamePlayScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::createWithPhysics();

	scene->getPhysicsWorld()->setGravity(Vec2(0,0));        //set Gravity
	//scene->getPhysicsWorld()->setAutoStep(false);

	// 'layer' is an autorelease object

	auto layer = GamePlayScene::create();

	// add layer as a child to scene

	scene->addChild(layer);

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
	Size winSize= Director::getInstance()->getWinSize();

	map = TMXTiledMap::create("map.tmx");                     // map
	addChild(map,0,100);

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
		this->addChild(sprite,2);

		movableSprites.pushBack(sprite);
	}

	movableSprites.front()->setPosition(Vec2(300, 200));


	scheduleUpdate();               //Open the default timer. The refresh interval is one frame.

	return true;
};



bool GamePlayScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	touchLocation = this->convertTouchToNodeSpace(touch);
	this->selectSpriteForTouch(touchLocation);

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
	if (selSprite != nullptr)
	{
		Vec2 spritePos = selSprite->getPosition();
		//dis = spritePos.distance(touchLocation);
		Vec2 sub = touchLocation - spritePos;
		float dis = sub.length();
		sub.normalize();
		if (dis>1)
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
	if (tileGid =! 0)
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
	int y = (map->getMapSize().height*map->getTileSize().height - pos.y ) / map->getTileSize().height;

	return(Vec2(x, y));
};


void GamePlayScene::setViewpointCenter(Vec2 position)       //make sprite in the map center
{
	Size visibleSize = Director::getInstance()-> getVisibleSize();

	int x = MAX(position.x, visibleSize.width / 2); 
	int y = MAX(position.y, visibleSize.height / 2);

	x = MIN(x, (map->getMapSize().width * map->getTileSize().width) - visibleSize.width / 2);
	y = MIN(y, (map->getMapSize().height* map->getTileSize().height) - visibleSize.height / 2);

	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);        //screen center
	Vec2 pointB = Vec2(x, y);

	Vec2 offset = pointA - pointB;

	this -> setPosition(offset);
};

void GamePlayScene::selectSpriteForTouch(Point touchLocation)          // some actions about selected sprites 
{
	Sprite * newSprite = nullptr;
	for (Sprite *sprite : movableSprites)
	{
		if (sprite->getBoundingBox().containsPoint(touchLocation))
		{
			newSprite = sprite;
			break;
		}
	}

	if ((newSprite!=selSprite) &&(newSprite!=nullptr))
	{
		if (selSprite!=nullptr)
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