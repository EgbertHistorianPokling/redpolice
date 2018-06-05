#include"HelloWorldScene.h"
#include"secondScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorldScene::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorldScene::create();
	scene->addChild(layer);
	return scene;
}

void HelloWorldScene::loadSound()
{
	//音乐什么的再说吧
}

bool HelloWorldScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	//auto bg = TMXTiledMap::create("");
	//this->addChild(bg);

	loadLabel = LabelTTF::create("Loading:", "Arial", 20);//创建显示Loading: 的label  
	loadLabel->setPosition(Point(visibleSize.width / 2 - 30, visibleSize.height / 2 + 30));
	this->addChild(loadLabel, 1);

	percentLabel = LabelTTF::create("0%", "Arial", 20);//创建显示百分比的label  
	percentLabel->setPosition(Point(visibleSize.width / 2 + 35, visibleSize.height / 2 + 30));
	this->addChild(percentLabel, 2);

	auto loadBg = Sprite::create("loading1.png");//进程条的底图  
	loadBg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));
	this->addChild(loadBg, 1);

	loadProgress = ProgressTimer::create(Sprite::create("loading2.png"));//创建一个进程条  
	loadProgress->setBarChangeRate(Point(1, 0));//设置进程条的变化速率  
	loadProgress->setType(ProgressTimer::Type::BAR);//设置进程条的类型  
	loadProgress->setMidpoint(Point(0, 1));//设置进度的运动方向  
	loadProgress->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));  //设置进度条的位置
	loadProgress->setPercentage(0.0f);//设置初始值为0  
    this->addChild(loadProgress, 2);

	Director::getInstance()->getTextureCache()->addImageAsync("HelloWorld.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("CloseSelected.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA_building.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA tank.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA building3.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA building4.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA building5.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USSR ship.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USSR ship2.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	Director::getInstance()->getTextureCache()->addImageAsync("USA soldier.png", CC_CALLBACK_1(HelloWorldScene::loadingCallback, this));
	//这里是所有游戏需要的图片，初始设定了10张







	return true;
}

void HelloWorldScene::loadingCallback(cocos2d::Object* pSender)
{
	++m_loadedSp;//每进到这个函数一次，让m_loadedSp + 1 ,即为已经加载过一次 

	char buf_str[16];
	sprintf(buf_str, "%d%%", (int)(((float)m_loadedSp / m_numSp) * 100));
	percentLabel->setString(buf_str);//更新percentLabel的值  

	float newPercent = 100 - ((float)m_numSp - (float)m_loadedSp) / ((float)m_numSp / 100);//计算进度条当前的百分比  
																			
	loadProgress->setPercentage(newPercent);//更新进度条  

	if (m_loadedSp == m_numSp)                  //图片加载完成后  
	{
		this->removeChild(loadProgress);//将添加的几个对象删除掉  
		this->removeChild(percentLabel);
		this->removeChild(loadLabel);

		Scene * m_SecondScene = secondScene::createScene();
		Director::sharedDirector()->replaceScene(TransitionJumpZoom::create(1.0f, m_SecondScene));//所以这里有个很难看的切换特效
	}
}

//void HelloWorldScene::gotoNewLayer()
//{
//	auto size = Director::getInstance()->getWinSize();
//	auto sp = Sprite::create("CloseNormal.png");//用之前加载到缓存中的图片，创建一个精灵。  
//	sp->setPosition(Point(size.width / 2, size.height / 2));
//	this->addChild(sp, 1);
//}
