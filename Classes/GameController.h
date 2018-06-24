#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "cocos2d.h"
#include "Client.h"
#include "Building.h"
#include "Soldier.h"
#include "Bullets.h"
#include "LoseScene.h"
#include "WinScene.h"
//#include "GameMap.h"
//#include "Operator.h"
#define PlayerManager Player
#define SoldierManager Soldier
#define BuildingManager Building
#define TankManager   Tank

class GameController : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameController);

    void setMap(GameMap * map);

private:
    PlayerManager * playerManager;
    SoldierManager * soldierManager;
    BuildingManager * buildingManager;
	TankManager * tankManager;
    Client * client;
    GameMap * map;

    cocos2d::Vec2 origin;
    int gameStatus;

    Operator * oper;
//    void opHandle(Operator::OpCode opcode, Operator::OpType type);

    void onEnter();
    void onExit();

    void syncLocalPlayerPosition(float dt);
//    void syncLocalBuildingPosition(float dt);
//    void syncLocalTankPosition(float dt);

    void onGameInit(const void* msg);
    void onGameStatusChange(const void* msg);

    void toStart();
    void toOver();

    
    void onPlayerPosChange(const void* msg);
	void onSelectBuilding(const void* msg);
	void onBuildingPosChange(const void* msg);
	void onBuildingPosSet(const void* msg);
	void onBuildingStatusChange(const void* msg);
	void onSelectSoldier(const void* msg);
	void onSoldierPosChange(const void* msg);
	void onSoldierAttrChange(const void* msg);
	void onSoldierStatusChange(const void* msg);
	void onBuildSoldier(const void* msg);
	void onBuildTank(const void* msg);
	void onSelectTank(const void* msg);
	void onTankPoschange(const void* msg);
	void onTankAttrChange(const void* msg);
	void onTankStatusChange(const void* msg);
	void onPlayerStatusChange(const void* msg);
	void onGameStatusChange(const void* msg);


};

#endif // !__GAME_CONTROLLER_H__
