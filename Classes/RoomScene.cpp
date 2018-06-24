#include "RoomScene.h"
#include "GamePlayScene.h"
#include "HelloWorldScene.h"
#include "Settings.h"
#include "GameAudio.h"
#include "ChatBox.h"

USING_NS_CC;

/*to do */
/*the back button*/
/*the case of the players*/

Scene* RoomScene::createScene()
{
    //scene is an auto release object 
    auto scene = Scene::create();

    //layer is an auto release object
    auto layer = RoomScene::create();

    //add layer as a child to scene
    scene->addChild(layer);

    //return the scene
    return scene;
}

bool RoomScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    // room controller
    roomController = RoomController::create();

    // ready button callback
    readyButtonCallBack = CC_CALLBACK_1(RoomController::onUserChangeStats, roomController);//准备响应
	//startButtonCallBack = CC_CALLBACK_1(RoomController::onUserChangeStats, roomController);
    //roleChangeCallback = CC_CALLBACK_1(RoomController::onUserChangeRole, roomController);

    createUI();

    addChild(roomController, -1);

    auto chatBox = ChatBox::create();
    chatBox->sendText = CC_CALLBACK_1(RoomController::sendChat, roomController);
    chatBox->setPosition(visibleSize.width * 0.08f, visibleSize.height * 0.15f);
    addChild(chatBox);

    return true;
}

void RoomScene::createUI()
{
    createBackground();
    createTitle();
    initUserBox();
    //initRoleBox();
    initListener();
    createBackButton();
    createReadyButton();
	createStartButton();
}

void RoomScene::onEnter()
{
    Layer::onEnter();
    readyButton->setTitleText("Ready");//设置标题提示文本
	//startButton->setTitleText("Start");
    isReady = false;//初始状态未准备
	//isStart = false;
    GameAudio::getInstance()->playBgm("Sound/roomtheme.mp3");                                                //change
}

void RoomScene::createReadyButton()
{
    auto getShowText = [](bool isReady)
    {
        return isReady ? "Cancel" : "Ready";
    };
    readyButton = ui::Button::create("RoomScene/normal.png", "RoomScene/selected.png");        //change
    readyButton->setTitleText(getShowText(isReady));
    readyButton->setTitleFontSize(Settings::Font::Size::normal);

    readyButton->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type)
    {
        if (type == ui::Widget::TouchEventType::ENDED)
        {
            auto button = static_cast<ui::Button*>(sender);
            isReady = !isReady;
            button->setTitleText(getShowText(isReady));
            if (readyButtonCallBack) readyButtonCallBack(isReady);
        }
    });

    readyButton->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height*0.27f) + origin);
	readyButton->setScale(0.5f);
    this->addChild(readyButton);
}

void RoomScene::createStartButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto startButton = ui::Button::create("RoomScene/normal.png", "RoomScene/selected.png");           //change the pictures
	startButton->setTitleText("Start");
	startButton->setScale(0.5f);
	startButton->setTitleFontSize(Settings::Font::Size::normal);
	startButton->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height*0.1f) + origin);

	startButton->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type)//触摸事件监听器
	{
		if (type != ui::Widget::TouchEventType::ENDED) return;
		Director::getInstance()->replaceScene(TransitionFade::create(1.2f, GamePlayScene::createScene()));//变化场景
	});
	addChild(startButton);
}


void RoomScene::createTitle()
{
    //the title
    auto label = Label::createWithTTF("ROOM", Settings::Font::Type::title, Settings::Font::Size::label);
    label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - label->getContentSize().height) + origin);
    label->enableGlow(Color4B::WHITE);
    this->addChild(label, 1);
}

void RoomScene::initUserBox()
{
    for (int i = 0; i < 2; i++) {
        auto _userBox = UserBox::create();
        _userBox->setPosition(Vec2(_userBox->getContentSize().width * (i + 1) * 5 - _userBox->getContentSize().width * 0.5f,
            visibleSize.height*0.68f));
		_userBox->setScale(3.0f);
		_userBox->setOpacity(200);
        addChild(_userBox);
        roomController->userBoxes.pushBack(_userBox);
    }
}

//void RoomScene::initRoleBox()
//{
//    for (int i = 0; i < 3; ++i)
//    {
//        auto roleBox = RoleBox::create(static_cast<RoleBox::roleChoice>(i));
//        //roleBox->setScale(0.9f);
//        roleBox->setPosition(cocos2d::Vec2(
//            visibleSize.width * 0.7f + (2 * i - 1) * roleBox->getContentSize().width * 0.7f,
//            visibleSize.height * 0.4f));
//        addChild(roleBox);
//        roleBoxes.pushBack(roleBox);
//    }
//    // default role
//    roleBoxes.at(0)->setChosen(true);
//}

void RoomScene::initListener()
{
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch * touch, Event * event)
    {
        return true;
    };

    touchListener->onTouchEnded = [=](Touch * touch, Event * event) {
        auto point = touch->getLocation();
        //for (auto prev : roleBoxes)
        //{
        //    auto range = prev->getBoundingBox();

        //    if (range.containsPoint(point))
        //    {
        //        roleChangeCallback(prev->getRole());

        //        for (auto val : roleBoxes)
        //            val->setChosen(false);

        //        prev->setChosen(true);
        //        break;
        //    }
        //}
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    auto keyEventListener = EventListenerKeyboard::create();
    keyEventListener->onKeyReleased = [](EventKeyboard::KeyCode code, Event* event)
    {
        if (code == EventKeyboard::KeyCode::KEY_ESCAPE)
        {
            Director::getInstance()->popScene();
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyEventListener, this);
}

void RoomScene::createBackButton()
{
    const auto buttons = Menu::create();

    const auto backButton = MenuItemLabel::create(
        Label::createWithTTF("Back", Settings::Font::Type::base, Settings::Font::Size::normal),
        [](Ref * ref) { 
        Client::getInstance()->close();
        Director::getInstance()->popScene(); 
    });

    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const auto baseY = visibleSize.height * 0.85f;

    backButton->setPosition(Vec2(backButton->getContentSize().width / 2 + 30, baseY + 30) + origin);
    //backButton->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    buttons->addChild(backButton, 1);

    buttons->setPosition(0, 0);
    this->addChild(buttons);
}

void RoomScene::createBackground()
{
    auto bg = Sprite::create("RoomScene/background.jpg");                                            //change
    bg->setScale(1.6f);
    bg->setLocalZOrder(-1);
    bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));
    this->addChild(bg);
}