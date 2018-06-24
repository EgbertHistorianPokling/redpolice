#ifndef __ROOMSCENE_SCENE_H__
#define __ROOMSCENE_SCENE_H__

#include "cocos2d.h"
#include "RoomController.h"
#include "ui/CocosGUI.h"
#include "ui/UIButton.h"
#include "UserBox.h"

class RoomScene :public cocos2d::Layer
{
private:
    void createUI();

    RoomController * roomController;

    cocos2d::ui::Button * readyButton;
    cocos2d::ui::Button * startButton; 
    //cocos2d::Vector< RoleBox*> roleBoxes;
    bool isReady;
	//bool isStart;

    std::function<void(bool)> readyButtonCallBack;
    std::function<void(bool)> startButtonCallBack; 
    //std::function<void(int)> roleChangeCallback;

    cocos2d::Vec2 origin;
    cocos2d::Size visibleSize;

    void onEnter();

    void createReadyButton();
    void createStartButton();
    

    void createTitle();

    void initUserBox();

    //void initRoleBox();

    void initListener();

    void createBackButton();

    void createBackground();

public:
    static cocos2d::Scene * createScene();
    virtual bool init();
    CREATE_FUNC(RoomScene);
};
#endif // !__ROOMSCENE_SCENE_H__
