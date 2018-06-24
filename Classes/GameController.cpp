#include "GameController.h"
#include "newfile/api_generated.h"
#include "User.h"
#include "SimpleAudioEngine.h"
#include "GameAudio.h"
#include "flatbuffers/flatbuffers.h"


USING_NS_CC;
using namespace API;

bool GameController::init()
{
    if (!Layer::init())
    {
        return false;
    }

    origin = Director::getInstance()->getVisibleOrigin();

    //oper = Operator::create();
    //oper->addHandle(CC_CALLBACK_2(GameController::opHandle, this));

    playerManager = PlayerManager::create();
    soldierManager = SoldierManager::create();
    buildingManager = BuildingManager::create();
	tankManager = TankManager::create();

    addChild(oper, -1);
    addChild(playerManager, -1);
    addChild(soldierManager, -1);
    addChild(buildingManager, -1);
	addChild(tankManager, -1);
    
    return true;
}

void GameController::setMap(GameMap * map)
{
    if (map) this->map = map;
}

//void GameController::opHandle(Operator::OpCode opcode, Operator::OpType type)
//{
//    if (opcode == Operator::OpCode::SPACE)
//    {
//        if (type == Operator::OpType::RELEASE) onLocalPlayerSetBubble();
//    }
//    else
//    {
//        auto player = playerManager->getLocalPlayer();
//        if (!player) return;
//        auto direction = static_cast<Player::Direction>(opcode);
//        if (type == Operator::OpType::PRESS)
//        {
//            player->setDirectionByKey(direction);
//        }
//        else
//        {
//            player->removeDirectionByKey(direction);
//        }
//    }
//}


void GameController::onEnter()
{
    Layer::onEnter();
#ifdef NETWORK
    client = Client::getInstance();
    if (!client->isConnected()) client->connect();

    CLIENT_ON(MsgType_GameInit, GameController::onGameInit);
    CLIENT_ON(MsgType_GameStatusChange, GameController::onGameStatusChange);

    CLIENT_ON(MsgType_PlayerPosChange, GameController::onPlayerPositionChange);
    //CLIENT_ON(MsgType_PlayerAttrChange, GameController::onPlayerAttrChange);
    CLIENT_ON(MsgType_PlayerStatusChange, GameController::onPlayerStatusChange);
	CLIENT_ON(MsgType_SelectBuilding, GameController::onSelectBuilding);
	CLIENT_ON(MsgType_BuildingPosChange, GameController::onBuildingPosChange);
	CLIENT_ON(MsgType_BuildingPosSet, GameController::onBuildingPosSet);
	CLIENT_ON(MsgType_BuildingStatusChange, GameController::onBuildingStatusChange);
	CLIENT_ON(MsgType_SelectSoldier, GameController::onSelectSoldier);
	CLIENT_ON(MsgType_SoldierPosChange, GameController::onSoldierPosChange);
	CLIENT_ON(MsgType_SoldierAttrChange, GameController::onSoldierAttrChange);
	CLIENT_ON(MsgType_SoldierStatusChange, GameController::onSoldierStatusChange);
	CLIENT_ON(MsgType_BuildSoldier, GameController::onBuildSoldier);
	CLIENT_ON(MsgType_BuildTank, GameController::onBuildTank);
	CLIENT_ON(MsgType_SelectTank, GameController::onSelectTank);
	CLIENT_ON(MsgType_TankPosChange, GameController::onTankPosChange);
	CLIENT_ON(MsgType_TankAttrChange, GameController::onTankAttrChange);
	CLIENT_ON(MsgType_TankStatusChange, GameController::onTankStatusChange);

    //CLIENT_ON(MsgType_PropSet, GameController::onPropSet);
    //
    //{
    //    // send enter scene msg.
    //    flatbuffers::FlatBufferBuilder builder;
    //    auto orc = CreateUserChangeStats(builder, 2);
    //    auto msg = CreateMsg(builder, MsgType_UserChangeStats, orc.Union());
    //    builder.Finish(msg);
    //    client->send(builder.GetBufferPointer(), builder.GetSize());
    //}

//#else
//    auto player = playerManager->createLocalPlayer("local", 0);
//    auto pos = map->tileCoordToPosition(Vec2(0, 0));
//    player->setPosition(pos);
//    map->addPlayer(player);
//
//    auto pos1 = map->tileCoordToPosition(Vec2(0, 1));
//    auto prop = propManager->createProp("bubble", Prop::Type::BUBBLE, pos1);
//    map->addProp(prop, prop->getType());
#endif // NETWORK
}

void GameController::onExit()
{
#ifdef NETWORK
    if (gameStatus != 3) // player exit game directly
    {
        client->close();
    }
    client->clear();
    client = nullptr;
#endif // NETWORK
    Layer::onExit();
}

void GameController::syncLocalPlayerPosition(float dt)
{
    auto localPlayer = playerManager->getLocalPlayer();
    if (localPlayer != nullptr && localPlayer->getStatus() == Player::Status::FREE)
    {
        using namespace API;
        flatbuffers::FlatBufferBuilder builder;
        auto id = builder.CreateString(localPlayer->getID());
        //auto dir = static_cast<Direction>(localPlayer->getDirection());
        //auto pos = localPlayer->getPosition() - origin;
        //auto data = CreatePlayerPosChange(builder, id, dir, pos.x * 10, pos.y * 10);
        //auto msg = CreateMsg(builder, MsgType_PlayerPosChange, data.Union());
        builder.Finish(msg);

        client->send(builder.GetBufferPointer(), builder.GetSize());
    }
}

void GameController::onGameInit(const void * msg)
{
    auto data = static_cast<const GameInit*>(msg);
    auto playerVector = data->players();
    for (auto it = playerVector->begin(); it != playerVector->end(); ++it)
    {
        auto id = it->id()->str();
        auto x = it->x(), y = it->y();
        //auto role = it->role();
        Player * player;
        if (User::getInstance()->getUID() == id)
        {
            player = playerManager->createLocalPlayer(id/*, role*/);
        }
        else
        {
            player = playerManager->createPlayer(id/*, role*/);
        }
        //player->setSpeed(it->speed());
        //player->setDamage(it->damage());
        //player->setMaxBubble(it->bubble(), it->bubble());
        //player->setPosition(Vec2(x, y) + origin);
        //map->addPlayer(player);
    }
}

void GameController::onGameStatusChange(const void * msg)
{
    auto data = static_cast<const GameStatusChange*>(msg);
    auto status = data->status();
    gameStatus = static_cast<int>(status);

    if (status == GameStatus::GameStatus_START)
    {
        toStart();
    }
    else if (status == GameStatus::GameStatus_OVER)
    {
        toOver();
    }
}

void GameController::toStart()
{
    oper->start();
#ifdef NETWORK
    float dur = 1 / 30;
    //schedule(schedule_selector(GameController::syncLocalPlayerPosition), dur);
#endif // NETWORK
    //GameAudio::getInstance()->playEffect("Sound/gameStart.mp3");
}

void GameController::toOver()
{
    oper->stop();
    //unschedule(schedule_selector(GameController::syncLocalPlayerPosition));
    
    auto isWin = new bool;
    auto localPlayer = playerManager->getLocalPlayer();
    if (!localPlayer) return;
    *isWin = (localPlayer->getStatus() != Player::Status::DEFEAT);
    //if (*isWin)
    //{
    //    //GameAudio::getInstance()->playEffect("Sound/win.mp3");
    //}
    //else
    //{
    //    GameAudio::getInstance()->playEffect("Sound/defeat.mp3");
    //}
    Director::getInstance()->getRunningScene()->getEventDispatcher()->dispatchCustomEvent("game_over", isWin);

    CC_SAFE_DELETE(isWin);
}

void GameController::onPlayerPosChange(const void* msg)
{
    auto data = static_cast<const API::PlayerPosChange*>(msg);
    auto player = playerManager->getPlayer(data->id()->str());
    if (player != nullptr && !player->isLocal())
    {
        auto pos = Vec2(data->x() / 10, data->y() / 10);
        auto dir = static_cast<Player::Direction>(data->direction());
        player->setPosition(pos + origin);
        player->setDirection(dir);
        //propManager->checkEat(pos);
    }
}

void GameController::onSelectBuilding(const void* msg)
{
	auto data = static_cast<const API::SelectBuilding*>(msg);
	auto building = buildingManager->getBuilding(data->id()->str());
	if (building)
	{
         building->setType(static_cast<Building::Type>(data->type()));
	}
}

void GameController::onBuildingPosChange(const void* msg)
{
	auto data = static_cast<const API::BuildingPosChange*>(msg);
	auto Building = buildingManager->getBuilding(data->id()->str());
	if (building != nullptr
		auto pos = Vec2(data->x() / 10, data->y() / 10);
		player->setPosition(pos + origin);
	}
}

void GameController::onBuildingPosSet(const void * msg)
{
    auto localPlayer = playerManager->getLocalPlayer();
    auto id = data->id()->str();
    auto playerID = data->player_id()->str();
    auto x = data->x(), y = data->y();
    auto player = playerManager->getPlayer(playerID);
    if (player) {
    auto building = buildingManager->createBuilding(id, playerID, Vec2(x, y) + origin);
    if (building)
    {
        map->addBuilding(building);
    }
#ifdef NETWORK
        using namespace API;
        flatbuffers::FlatBufferBuilder builder;
        auto data = CreateBuildingPosSet(builder);
        auto orc = CreateMsg(builder, MsgType_BuildingPosSet, data.Union());
        builder.Finish(orc);
        client->send(builder.GetBufferPointer(), builder.GetSize());
#else
        //auto pos = map->centrePos(localPlayer->getPosition());
        //std::string id = "bubble_test" + std::to_string(time(0));
        auto building = buildingManager->createBuilding(id, localPlayer->getID(), pos);
        if (building)
        {
            map->addBuilding(building);
            scheduleOnce([=](float dt)
            {
                buildingManager->work(id);
            }, 3.0f, id);
        }
#endif // NETWORK
    }
}

void GameController::onBuildingStatusChange(const void * msg)
{
    auto data = static_cast<const API::BuildingStatusChange*>(msg);
    auto building = buildingManager->getBuilding(data->id()->str());

    if (building)
    {
        building->setStatus(static_cast<Building::Status>(data->status()));
    }
}

void GameController::onSelectSoldier(const void* msg)
{
	auto data = static_cast<const API::SelectSoldier*>(msg);
	auto soldier = soldierManager->getSoldier(data->id()->str());
	if (soldier)
	{
		soldier->setType(static_cast<Soldier::Type>(data->type()));
	}
}

void GameController::onSoldierPosChange(const void* msg)
{
	auto data = static_cast<const API::SoldierPosChange*>(msg);
	auto Soldier = soldierManager->getSoldier(data->id()->str());
	if (soldier != nullptr
		auto pos = Vec2(data->x() / 10, data->y() / 10);
	soldier->setPosition(pos + origin);
}

void GameController::onSoldierAttrChange(const void * msg)
{
    auto data = static_cast<const API::SoldierAttrChange*>(msg);
    auto soldier = soldierManager->getSoldier(data->id()->str());
    if (soldier)
    {
        soldier->setSpeed(data->speed());
        soldier->setDamage(data->damage());
        soldier->setObject(data->object());
    }
}

void GameController::onSoldierStatusChange(const void * msg)
{
	auto data = static_cast<const API::SoldierStatusChange*>(msg);
	auto soldier = soldierManager->getSoldier(data->id()->str());

	if (soldier)
	{
		soldier->setStatus(static_cast<Soldier::Status>(data->status()));
	}
}

void GameController::onBuildSoldier(const void * msg)
{
	auto localPlayer = playerManager->getLocalPlayer();
	auto id = data->id()->str();
	auto x = data->x(), y = data->y();
	auto player = playerManager->getPlayer(id);
	if (player) {
		auto soldier = soldierManager->createSoldier(id, playerID, Vec2(x, y) + origin);
		if (soldier)
		{
			map->addSoldier(soldier);
		}
#ifdef NETWORK
		using namespace API;
		flatbuffers::FlatBufferBuilder builder;
		auto data = CreateSoldierPosSet(builder);
		auto orc = CreateMsg(builder, MsgType_BuildSoldier, data.Union());
		builder.Finish(orc);
		client->send(builder.GetBufferPointer(), builder.GetSize());
#else
		//auto pos = map->centrePos(localPlayer->getPosition());
		//std::string id = "bubble_test" + std::to_string(time(0));
		auto soldier = soldierManager->createSoldier(id, localPlayer->getID(), pos);
		if (soldier)
		{
			map->addSoldier(soldier);
			scheduleOnce([=](float dt)
			{
				soldierManager->work(id);
			}, 3.0f, id);
		}
#endif // NETWORK
	}
}

void GameController::onBuildTank(const void * msg)
{
	auto localPlayer = playerManager->getLocalPlayer();
	auto id = data->id()->str();
	auto x = data->x(), y = data->y();
	auto player = playerManager->getPlayer(id);
	if (player) {
		auto tank =tankManager->createTank(id, playerID, Vec2(x, y) + origin);
		if (tank)
		{
			map->addTank(tank);
		}
#ifdef NETWORK
		using namespace API;
		flatbuffers::FlatBufferBuilder builder;
		auto data = CreateTankPosSet(builder);
		auto orc = CreateMsg(builder, MsgType_BuildTank, data.Union());
		builder.Finish(orc);
		client->send(builder.GetBufferPointer(), builder.GetSize());
#else
		//auto pos = map->centrePos(localPlayer->getPosition());
		//std::string id = "bubble_test" + std::to_string(time(0));
		auto tank = tankManager->createTank(id, localPlayer->getID(), pos);
		if (tank)
		{
			map->addTank(tank);
			scheduleOnce([=](float dt)
			{
				tankManager->work(id);
			}, 3.0f, id);
		}
#endif // NETWORK
	}
}

void GameController::onSelectTank(const void* msg)
{
	auto data = static_cast<const API::SelectTank*>(msg);
	auto tank = tankManager->getTank(data->id()->str());
	if (tank)
	{
		tank->setType(static_cast<Tank::Type>(data->type()));
	}
}

void GameController::onTankPosChange(const void* msg)
{
	auto data = static_cast<const API::TankPosChange*>(msg);
	auto Tank = tankManager->getTank(data->id()->str());
	if (tank != nullptr
		auto pos = Vec2(data->x() / 10, data->y() / 10);
	tank->setPosition(pos + origin);
}

void GameController::onTankAttrChange(const void * msg)
{
	auto data = static_cast<const API::TankAttrChange*>(msg);
	auto tank = tankManager->getTank(data->id()->str());
	if (tank)
	{
		tank->setSpeed(data->speed());
		tank->setDamage(data->damage());
		tank->setObject(data->object());
	}
}

void GameController::onTankStatusChange(const void * msg)
{
	auto data = static_cast<const API::TankStatusChange*>(msg);
	auto tank = tankManager->getTank(data->id()->str());

	if (tank)
	{
		tank->setStatus(static_cast<Tank::Status>(data->status()));
	}
}

void GameController::onPlayerStatusChange(const void * msg)
{
    auto data = static_cast<const API::PlayerStatusChange*>(msg);
    auto player = playerManager->getPlayer(data->id()->str());

    if (player)
    {
        player->setStatus(static_cast<Player::Status>(data->status()));
    }
}

