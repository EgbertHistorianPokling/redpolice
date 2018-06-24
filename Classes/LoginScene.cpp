#include "LoginScene.h"
#include "Settings.h"
#include "HelloWorldScene.h"
#include "RoomScene.h"
#include "User.h"
#include "OpenSourceLibraryReference/GameAudio.h"
#include "api_generated.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* LoginScene::createScene()//创建场景
{
    auto scene = Scene::create();

    auto layer = LoginScene::create();

    scene->addChild(layer);

    return scene;
}

bool LoginScene::init()//初始化
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();//可见大小
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    createBackground();//创建背景
    createLoginButton();//登入按钮

    initUserBox();//初始化用户框

    return true;
}

void LoginScene::createBackground()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite * bg = Sprite::create("Scene/loginbg.jpg");                                                                  //change the picture
    bg->setScale(2.4f);//倍率
    //set transparent
    bg->setOpacity(255);//设置透明度
    bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));//位置

    addChild(bg);
}

void LoginScene::createLoginButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto loginButton = ui::Button::create("RoomScene/normal.png", "RoomScene/selected.png");           //change the pictures
    loginButton->setTitleText("Login");
	loginButton->setScale(0.5f);
    loginButton->setTitleFontSize(Settings::Font::Size::normal);
    loginButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.35f));
    loginButton->setOpacity(190);

    loginButton->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type)//触摸事件监听器
    {
        if (type != ui::Widget::TouchEventType::ENDED) return;
        auto username = usernameInput->getString();
        if (username.empty())//未输入名字
        {
            MessageBox("Username can't be empty", "Alert");
        }
        else
        {
            username.substr(0, 16);
            UserDefault::getInstance()->setStringForKey("username", username);
            User::getInstance()->setName(username);

            Director::getInstance()->replaceScene(TransitionFade::create(1.2f, HelloWorldScene::createScene()));//变化场景
        }
    });
    addChild(loginButton);
}

void LoginScene::initUserBox()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    usernameBG = Sprite::create("LoginScene/input_normal.png");                                                            //change the picture
    usernameBG->setScale(3.0f);
    usernameBG->setOpacity(150);

    usernameInput = ui::TextField::create("Input Username Here", Settings::Font::Type::base, Settings::Font::Size::light);
    usernameInput->setString(UserDefault::getInstance()->getStringForKey("username", ""));
    usernameInput->setColor(Color3B::BLACK);
    usernameInput->setCursorChar('|');
    usernameInput->setCursorEnabled(true);
    usernameInput->setMaxLength(15);
    usernameInput->setMaxLengthEnabled(true);
    usernameInput->setPosition(usernameBG->getContentSize()/2 );
    usernameInput->addEventListener(CC_CALLBACK_2(LoginScene::textFieldEvent, this));

    usernameBG->addChild(usernameInput);

    usernameBG->setScale(3);
    usernameBG->setPosition(Vec2(visibleSize.width / 2,
        visibleSize.height / 2 + usernameBG->getContentSize().height * 2));

    addChild(usernameBG);

}


void LoginScene::textFieldEvent(Ref* sender, ui::TextField::EventType event)
{
    switch (event) {
    case ui::TextField::EventType::ATTACH_WITH_IME:
        usernameBG->setTexture("LoginScene/input_active.png");                                               //change
        break;
    case ui::TextField::EventType::DETACH_WITH_IME:
        usernameBG->setTexture("LoginScene/input_normal.png"); 
        break;
    }
}

void LoginScene::onEnter()
{
    Layer::onEnter();
    GameAudio::getInstance()->playBgm("Sound/mainStyle.mp3");                                                //change
}

void LoginScene::menuBackCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}