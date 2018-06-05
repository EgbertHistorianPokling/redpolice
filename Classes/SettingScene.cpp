#include "SettingScene.h"
#include "HeaderSystem.h"

USING_NS_CC;
using namespace CocosDenshion;


Scene* SettingScene::createScene()
{
	// 'scene' is an autorelease object

	auto scene = Scene::create();

	// 'layer' is an autorelease object

	auto layer = SettingScene::create();

	// add layer as a child to scene

	scene->addChild(layer);

	// return the scene

	return scene;
}



bool SettingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	Sprite *bg = Sprite::create("SettingBack.jpg");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);


	//ÒôÐ§
	auto soundOnMenuItem = MenuItemImage::create(
		"on.png", "on.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"off.png", "off.png");



	float x = origin.x + 10*soundOnMenuItem->getContentSize().width;
	float y = origin.y + visibleSize.height - 2.78f*soundOnMenuItem->getContentSize().height;


	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(SettingScene::menuSoundToggleCallback, this),
		soundOffMenuItem, soundOnMenuItem, NULL);

	soundToggleMenuItem->setPosition(Vec2(x,y));

	auto soundMenuItem = MenuItemImage::create(
		"sound.jpg", "sound.jpg");
	soundMenuItem->setPosition(Vec2(origin.x+soundMenuItem->getContentSize().width,origin.y+visibleSize.height-2*soundMenuItem->getContentSize().height));



	//ÒôÀÖ
	auto musicOnMenuItem = MenuItemImage::create(
		"on.png", "on.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"off.png", "off.png");

	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(SettingScene::menuMusicToggleCallback, this),
		musicOffMenuItem, musicOnMenuItem, NULL);

	musicToggleMenuItem->setPosition(Vec2(x,y- 3*soundOnMenuItem->getContentSize().height));


	auto musicMenuItem = MenuItemImage::create(
		"music.jpg", "music.jpg");
	musicMenuItem->setPosition(Vec2(origin.x + musicMenuItem->getContentSize().width, origin.y + visibleSize.height - 4 * musicMenuItem->getContentSize().height));



	//·µ»ØÖ÷²Ëµ¥
	auto okMenuItem = MenuItemImage::create(
		"OkNormal.jpg", "Selected.png",
		CC_CALLBACK_1(SettingScene::menu0kCallback, this));

	okMenuItem->setPosition(Vec2(origin.x + okMenuItem->getContentSize().width, origin.y + 5*okMenuItem->getContentSize().height/2));

	Menu *mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem, okMenuItem,soundMenuItem,musicMenuItem, NULL);
	mn -> setPosition(Vec2::ZERO); 
	this -> addChild(mn,1);


	UserDefault *defaults = UserDefault::getInstance();

	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		musicToggleMenuItem->setSelectedIndex(1);
	}
	else
	{
		musicToggleMenuItem->setSelectedIndex(0);
	}

	if (defaults->getBoolForKey(SOUND_KEY))
	{
		soundToggleMenuItem->setSelectedIndex(1);
	}
	else
	{
		soundToggleMenuItem->setSelectedIndex(0);
	}


	return true;
}

void SettingScene::menu0kCallback(Ref *pSender)
{
	Director::getInstance()->popScene();

	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
		SimpleAudioEngine::getInstance()->playEffect("soundBlip.wav");
}


void SettingScene::menuSoundToggleCallback(Ref * pSender)
	{
		auto soundToggleMenuItem = (MenuItemToggle*)pSender;
		log("soundToggleMenuItem %d", soundToggleMenuItem -> getSelectedIndex());

		UserDefault *defaults = UserDefault::getInstance();
		if (defaults->getBoolForKey(SOUND_KEY))
		{
			defaults->setBoolForKey(SOUND_KEY, false);
		}
		else
		{
			defaults->setBoolForKey(SOUND_KEY, true);
			SimpleAudioEngine::getInstance()->playEffect("soundBlip.wav");
		}
	}


void SettingScene::menuMusicToggleCallback(Ref * pSender)
{
	auto musicToggleMenuItem = (MenuItemToggle*)pSender;
	log("musicToggleMenuItem % d", musicToggleMenuItem->getSelectedIndex());

	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		defaults->setBoolForKey(MUSIC_KEY, false);
	}
	else
	{
		defaults->setBoolForKey(MUSIC_KEY, true);
		SimpleAudioEngine::getInstance()->playEffect("bgm.mp3");
	}
}


void SettingScene::onEnter()
{
	Layer::onEnter();
	log("SettingonEnter");
}


void SettingScene::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("Setting onEnterTransitionDidFinish");

	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY))
		SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3", true);
}


void SettingScene::onExit()
{
	Layer::onExit();
	log("Setting onExit");
}


void SettingScene::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("Setting onExitTransitionDidStart");
}


void SettingScene::cleanup()
{
	Layer::cleanup();
	log("Setting cleanup");
	//Í£Ö¹

	SimpleAudioEngine::getInstance() -> stopBackgroundMusic("bgm.mp3");
}