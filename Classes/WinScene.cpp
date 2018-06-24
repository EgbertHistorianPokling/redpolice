#include"WinScene.h"

USING_NS_CC;

Scene* WinScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::create();

	// 'layer' is an autorelease object

	auto layer = WinScene::create();

	// add layer as a child to scene

	scene->addChild(layer);

	// return the scene

	return scene;
}


bool WinScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* sprite = Sprite::create("win.jpg");
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(sprite, 1);
}