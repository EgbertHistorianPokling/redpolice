#ifndef  _LOGINSCENE_SCENE_H__
#define  _LOGINSCENE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

class LoginScene :public cocos2d::Layer
{
private:

    cocos2d::Sprite* usernameBG;//用户名字
    cocos2d::ui::TextField* usernameInput;//输入用户名

    void createBackground();//创立北京
    void createLoginButton();//创立登入按钮

    void initUserBox();

    void menuBackCallback(cocos2d::Ref* pSender);
    //void checkboxSelectedEvent(cocos2d::Ref* pSender);
    void textFieldEvent(cocos2d::Ref* sender, cocos2d::ui::TextField::EventType event);

    void onEnter();
public:

    static cocos2d::Scene * createScene();
    virtual bool init();
    CREATE_FUNC(LoginScene);

};
#endif // ! _LOGINSCENE_SCENE_H__
