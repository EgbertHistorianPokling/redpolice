#include "HelloWorldScene.h"
#include"loadingScene.h"
#include "SimpleAudioEngine.h"
#include "HeaderSystem.h"

USING_NS_CC;

Scene* HelloWorldScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::create();

	// 'layer' is an autorelease object

	auto layer = HelloWorldScene::create();

	// add layer as a child to scene

	scene->addChild(layer);

	// return the scene

	return scene;
}


// Print useful error message instead of segfaulting when files are not there.

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorldScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.jpg",
                                           "Selected.png",
                                           CC_CALLBACK_1(HelloWorldScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width/2;
		float y = origin.y + visibleSize.height / 2 - 3 * closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	//开始精灵
	auto startSpriteNormal = Sprite::create("StartNormal.jpg");
	auto startSpriteSelected = Sprite::create("Selected.png");

	MenuItemSprite * startMenuItem = MenuItemSprite::create(startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(HelloWorldScene::menuItemStartCallback, this));

	startMenuItem->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2 + 3*startMenuItem->getContentSize().height / 2));


	//设置图片菜单
	auto settingMenuItem = MenuItemImage::create(
		"SettingNormal.jpg",
		"Selected.png",
		CC_CALLBACK_1(HelloWorldScene::menuItemSettingCallback, this));

	settingMenuItem->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));


	Menu *mu = Menu::create(startMenuItem, settingMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

 
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		Size sprite_size = getContentSize();

		this->addChild(sprite, 0);
	}		

    return true;
}


void HelloWorldScene::menuItemSettingCallback(Ref * pSender)
{
	auto sc = SettingScene::createScene();
	auto reScene = TransitionCrossFade::create(1.0f,sc); 
	Director::getInstance() -> pushScene(reScene);

	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
		SimpleAudioEngine::getInstance()->playEffect("soundBlip.wav");
}


void HelloWorldScene::menuItemStartCallback(Ref * pSender)
{
		MenuItem * item = (MenuItem*)pSender; 

		auto sc = GamePlayScene::createScene();
		auto reScene = TransitionCrossFade::create(1.0f, sc);
		Director::getInstance()->pushScene(reScene);             //enter GamePlayScene

		if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
			SimpleAudioEngine::getInstance()->playEffect("soundBlip.wav");
}


void HelloWorldScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);

}

void HelloWorldScene::onEnter()
{
	Layer::onEnter();
	log("HelloWorldonEnter");
}


void HelloWorldScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HelloWorld onEnterTransitionDidFinish");

	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY))
		SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3", true);
}


void HelloWorldScene::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
}


void HelloWorldScene::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("HelloWorld onExitTransitionDidStart");
}


void HelloWorldScene::cleanup()
{
	Layer::cleanup();
	log("HelloWorld cleanup");
	//停止

	SimpleAudioEngine::getInstance()->stopBackgroundMusic("bgm.mp3");
}
