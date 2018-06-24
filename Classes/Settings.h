#ifndef __SETTINGS_H__
#define __SETTINGS_H__


#include <cstdint>
#include <set>


namespace Settings
{
    namespace Font//���� 														//
    {
        namespace Size//�ֺ� 
        {
            constexpr int name = 9;
            constexpr int chat = 12;
            constexpr int title  = 30;
            constexpr int label  = 20;
            constexpr int normal = 25;
            constexpr int light  = 5;
            constexpr int result = 24;
        }
        namespace Type//���� 
        {
            constexpr char title[] = "fonts/Quicksand-Bold.ttf";
            constexpr char base[] = "fonts/OpenSans-Regular.ttf";
        };
    }
    namespace Map//��ͼ 														//
    {
        constexpr char path[] = "GameItem/Map/";
        static std::set<const char *> list{
            "town_10"
        };
        namespace TileSize//��Ƭ��С 
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
    namespace Player//��� 
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
		    "Base",//���� 
		    "powerPlant",//�糧 
		    "mineField",//��  
		    "Rax",//��Ӫ 
		    "warFactory"//ս������ 
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
    namespace Server//������											// 
    {
        constexpr char addr[] = "10.22.20.4";
    }
}
#endif
