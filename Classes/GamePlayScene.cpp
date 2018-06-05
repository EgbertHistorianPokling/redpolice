#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GamePlayScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::create();

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

	map = TMXTiledMap::create("map.tmx");                     // map
	addChild(map,0,100);

	TMXObjectGroup *group = map->getObjectGroup("objects");
	ValueMap spawnPoint = group->getObject("InitialCar");

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();

	InitialCar = Sprite::create("InitialCar.png");           //initial sprite
	InitialCar->setPosition(Vec2(x, y));
	addChild(InitialCar, 2, 200);

	collidable = map->getLayer("collidable");
	collidable->setVisible(false);                        //hide collidable

	setTouchEnabled(true);                    
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);               //set single point touch
	
	return true;
};



bool GamePlayScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	log("onTouchBegan");
	return true;
};


void GamePlayScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	log("onTouchMoved");
};


void GamePlayScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	log("onTouchEnded");

	Vec2 touchLocation = touch->getLocation();

	Vec2 spritePos = InitialCar->getPosition();
	Vec2 diff = touchLocation - spritePos;

	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			spritePos.x += map->getTileSize().width;
			InitialCar->runAction(FlipX::create(false));
		}
		else
		{
			spritePos.x -= map->getTileSize().width;
			InitialCar->runAction(FlipX::create(true));
		}
	}
	else
	{
		if (diff.y > 0)
		{
			spritePos.y += map->getTileSize().height;
		}
		else
		{
			spritePos.y -= map->getTileSize().height;
		}
	}
	InitialCar->setPosition(spritePos);
	this->setViewpointCenter(spritePos);
	//this->setSpritePosition(spritePos);
}

/*void GamePlayScene::setSpritePosition(cocos2d::Vec2 position)           //move sprite and detect collision 
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	int tileGid = collidable->getTileGIDAt(tileCoord);
	if (tileGid == 0)
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
		InitialCar->setPosition(position);
}*/

Vec2 GamePlayScene::tileCoordFromPosition(Vec2 pos)         //from pixel position to tile position
{
	int x = pos.x / map->getTileSize().width;
	int y = ((map->getMapSize().height*map->getTileSize().height) - pos.y) / map->getTileSize().height;
	return(Vec2(x, y));
}

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
