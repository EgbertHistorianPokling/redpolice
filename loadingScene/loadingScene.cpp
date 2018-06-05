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
	//����ʲô����˵��
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

	loadLabel = LabelTTF::create("Loading:", "Arial", 20);//������ʾLoading: ��label  
	loadLabel->setPosition(Point(visibleSize.width / 2 - 30, visibleSize.height / 2 + 30));
	this->addChild(loadLabel, 1);

	percentLabel = LabelTTF::create("0%", "Arial", 20);//������ʾ�ٷֱȵ�label  
	percentLabel->setPosition(Point(visibleSize.width / 2 + 35, visibleSize.height / 2 + 30));
	this->addChild(percentLabel, 2);

	auto loadBg = Sprite::create("loading1.png");//�������ĵ�ͼ  
	loadBg->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));
	this->addChild(loadBg, 1);

	loadProgress = ProgressTimer::create(Sprite::create("loading2.png"));//����һ��������  
	loadProgress->setBarChangeRate(Point(1, 0));//���ý������ı仯����  
	loadProgress->setType(ProgressTimer::Type::BAR);//���ý�����������  
	loadProgress->setMidpoint(Point(0, 1));//���ý��ȵ��˶�����  
	loadProgress->setPosition(Point(visibleSize.width / 2, visibleSize.height / 3));  //���ý�������λ��
	loadProgress->setPercentage(0.0f);//���ó�ʼֵΪ0  
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
	//������������Ϸ��Ҫ��ͼƬ����ʼ�趨��10��







	return true;
}

void HelloWorldScene::loadingCallback(cocos2d::Object* pSender)
{
	++m_loadedSp;//ÿ�����������һ�Σ���m_loadedSp + 1 ,��Ϊ�Ѿ����ع�һ�� 

	char buf_str[16];
	sprintf(buf_str, "%d%%", (int)(((float)m_loadedSp / m_numSp) * 100));
	percentLabel->setString(buf_str);//����percentLabel��ֵ  

	float newPercent = 100 - ((float)m_numSp - (float)m_loadedSp) / ((float)m_numSp / 100);//�����������ǰ�İٷֱ�  
																			
	loadProgress->setPercentage(newPercent);//���½�����  

	if (m_loadedSp == m_numSp)                  //ͼƬ������ɺ�  
	{
		this->removeChild(loadProgress);//����ӵļ�������ɾ����  
		this->removeChild(percentLabel);
		this->removeChild(loadLabel);

		Scene * m_SecondScene = secondScene::createScene();
		Director::sharedDirector()->replaceScene(TransitionJumpZoom::create(1.0f, m_SecondScene));//���������и����ѿ����л���Ч
	}
}

//void HelloWorldScene::gotoNewLayer()
//{
//	auto size = Director::getInstance()->getWinSize();
//	auto sp = Sprite::create("CloseNormal.png");//��֮ǰ���ص������е�ͼƬ������һ�����顣  
//	sp->setPosition(Point(size.width / 2, size.height / 2));
//	this->addChild(sp, 1);
//}
