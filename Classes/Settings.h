#ifndef __SETTINGS_H__
#define __SETTINGS_H__


#include <cstdint>
#include <set>


namespace Settings
{
    namespace Font//字体 														//
    {
        namespace Size//字号 
        {
            constexpr int name = 9;
            constexpr int chat = 12;
            constexpr int title  = 30;
            constexpr int label  = 20;
            constexpr int normal = 25;
            constexpr int light  = 5;
            constexpr int result = 24;
        }
        namespace Type//字型 
        {
            constexpr char title[] = "fonts/Quicksand-Bold.ttf";
            constexpr char base[] = "fonts/OpenSans-Regular.ttf";
        };
    }
    namespace Map//地图 														//
    {
        constexpr char path[] = "GameItem/Map/";
        static std::set<const char *> list{
            "town_10"
        };
        namespace TileSize//瓦片大小 
        {
            constexpr int height = 40;
            constexpr int width = 40;
        }
    }
    namespace Soldier
    {
    	constexpr char path[]="GameItem/Player";
    	constexpr char* soldierName[]={
		      "Dog",
		      "Man"
		};
	}
    namespace Player//玩家 
    {
        constexpr char path[] = "GameItem/Player/";
        constexpr char* roleName[] = {
            "Player1",
            "Player2",
            "Player3",
            "Player4"
        };
    }
    namespace Building
    {
    	constexpr char path[]="GameItem/Building/";
    	constexpr char* buildingType[]={
		    "Base",//基地 
		    "powerPlant",//电厂 
		    "mineField",//矿场  
		    "Rax",//兵营 
		    "warFactory"//战车工厂 
		};
	}
	namespace Tank
	{
		constexpr char path[]="GameItem/Tank/";
		constexpr char* TankType[]={
				"Tank"
		};
	}
//    namespace Bubble
//    {
//        constexpr char path[] = "GameItem/Bubble/default.png";
//    }
//    namespace Prop
//    {
//        constexpr char path[] = "GameItem/Prop/";
//        constexpr char * name[] = {
//            "speed.png",
//            "bubble.png",
//            "damage.png"
//        };
//    }
    namespace Server//服务器											// 
    {
        constexpr char addr[] = "10.22.20.4";
    }
}
#endif
