

#ifndef FLATBUFFERS_GENERATED_API_API_H_
#define FLATBUFFERS_GENERATED_API_API_H_

#include "flatbuffers/flatbuffers.h"
#include<string>

namespace API
{

    struct UserData;//用户数据

    struct Welcome;//Welcome按钮

    struct GotIt;//GotIt按钮

    struct JoinRoom;//加入房间

    struct RoomInfoUpdate;//房间信息更新

    struct UserChangeRole;//玩家更换国家

    struct UserChangeStats;//玩家状转变

    struct PlayerData;//玩家数据

    struct GameInit;//游戏初始化

    struct PlayerPosChange;//玩家地点改变

    struct SelectBuilding;//选择建筑
    
    struct BuildingPosChange;//建筑位置改变
    
    struct BuildingPosSet;//安放建筑

    struct BuildingStatusChange;//建筑状态改变
    
    struct SelectSoldier;//选择士兵
    
    struct SoldierPosChange;//士兵位置变化
    
    struct SoldierAttrChange;//士兵攻击变化

    struct SoldierStatusChange;//士兵状态变化
    
    struct BuildSoldier;//士兵出生
    
    struct BuildTank;//坦克出生
    
    struct SelectTank;//选择坦克
    
    struct TankPosChange;//坦克位置变化
    
    struct TankAttrChange;//坦克攻击变化

    struct TankStatusChange;//坦克状态变化

    struct PlayerStatusChange;//玩家状态变化

    struct GameStatusChange;//游戏状态变化

    struct Chat;//聊天

    struct Msg;

    enum MsgType
    {
        MsgType_NONE = 0,
        MsgType_Welcome = 1,
        MsgType_GotIt = 2,
        MsgType_JoinRoom = 3,
        MsgType_RoomInfoUpdate = 4,
        MsgType_UserChangeRole = 5,
        MsgType_UserChangeStats = 6,
        MsgType_Chat = 7,
        MsgType_GameInit = 8,
        MsgType_PlayerPosChange = 9,
		MsgType_SelectBuilding=10,    
    	MsgType_BuildingPosChange=11,    
    	MsgType_BuildingPosSet=12,
     	MsgType_BuildingStatusChange=13,   
    	MsgType_SelectSoldier=14,    
    	MsgType_SoldierPosChange=15,   
   		MsgType_SoldierAttrChange=16,
    	MsgType_SoldierStatusChange=17,    
    	MsgType_BuildSoldier=18,    
    	MsgType_BuildTank=19,    
    	MsgType_SelectTank=20,    
    	MsgType_TankPosChange=21,   
    	MsgType_TankAttrChange=22,
    	MsgType_TankStatusChange=23,
//    	MsgType_PlayerAttrChange=24,
    	MsgType_PlayerStatusChange=24,
    	MsgType_GameStatusChange=25,
        MsgType_MIN = MsgType_NONE,
        MsgType_MAX = MsgType_GameStatusChange
    };

    inline const char **EnumNamesMsgType()
    {
        static const char *names[] = { "NONE", "Welcome", "GotIt", "JoinRoom", "RoomInfoUpdate", "UserChangeRole",
            "UserChangeStats", "Chat", "GameInit", "PlayerPosChange","SelectBuilding","BuildingPosChange","BuildingPosSet",
			"BuildingStatusChange","SelectSoldier","SoldierPosChange","SoldierAttrChange","SoldierStatusChange",
			"BuildSoldier","BuildTank","SelectTank","TankPosChange","TankAttrChange","TankStatusChange",
            "PlayerStatusChange", "GameStatusChange", nullptr };                                        //枚举消息类型名称 
        return names;
    }

    inline const char *EnumNameMsgType(MsgType e) { return EnumNamesMsgType()[static_cast<int>(e)]; }

    template<typename T>
    struct MsgTypeTraits //traits，提取“被传进的对象”对应的返回类型，让同一个接口实现对应的功能
    {
        static const MsgType enum_value = MsgType_NONE;
    };

    template<>
    struct MsgTypeTraits<Welcome>
    {
        static const MsgType enum_value = MsgType_Welcome;
    };

    template<>
    struct MsgTypeTraits<GotIt>
    {
        static const MsgType enum_value = MsgType_GotIt;
    };

    template<>
    struct MsgTypeTraits<JoinRoom>
    {
        static const MsgType enum_value = MsgType_JoinRoom;
    };

    template<>
    struct MsgTypeTraits<RoomInfoUpdate>
    {
        static const MsgType enum_value = MsgType_RoomInfoUpdate;
    };

    template<>
    struct MsgTypeTraits<UserChangeRole>
    {
        static const MsgType enum_value = MsgType_UserChangeRole;
    };

    template<>
    struct MsgTypeTraits<UserChangeStats>
    {
        static const MsgType enum_value = MsgType_UserChangeStats;
    };

    template<>
    struct MsgTypeTraits<Chat>
    {
        static const MsgType enum_value = MsgType_Chat;
    };

    template<>
    struct MsgTypeTraits<GameInit>
    {
        static const MsgType enum_value = MsgType_GameInit;
    };

    template<>
    struct MsgTypeTraits<PlayerPosChange>
    {
        static const MsgType enum_value = MsgType_PlayerPosChange;
    };

    template<>
    struct MsgTypeTraits<SelectBuilding>
    {
        static const MsgType enum_value = MsgType_SelectBuilding;
    };
	
	template<>
    struct MsgTypeTraits<BuildingPosChange>
    {
        static const MsgType enum_value = MsgType_BuildingPosChange;
    };
	
	template<>
    struct MsgTypeTraits<BuildingPosSet>
    {
        static const MsgType enum_value = MsgType_BuildingPosSet;
    };
	
	template<>
    struct MsgTypeTraits<BuildingStatusChange>
    {
        static const MsgType enum_value = MsgType_BuildingStatusChange;
    };
	
	template<>
    struct MsgTypeTraits<SelectSoldier>
    {
        static const MsgType enum_value = MsgType_SelectSoldier;
    };
	
	template<>
    struct MsgTypeTraits<SoldierPosChange>
    {
        static const MsgType enum_value = MsgType_SoldierPosChange;
    };
	
	template<>
    struct MsgTypeTraits<SoldierAttrChange>
    {
        static const MsgType enum_value = MsgType_SoldierAttrChange;
    };
	
	template<>
    struct MsgTypeTraits<SoldierStatusChange>
    {
        static const MsgType enum_value = MsgType_SoldierStatusChange;
    };
	
	template<>
    struct MsgTypeTraits<BuildSoldier>
    {
        static const MsgType enum_value = MsgType_BuildSoldier;
    };
	
	template<>
    struct MsgTypeTraits<BuildTank>
    {
        static const MsgType enum_value = MsgType_BuildTank;
    };
	
	template<>
    struct MsgTypeTraits<SelectTank>
    {
        static const MsgType enum_value = MsgType_SelectTank;
    };
	
	template<>
    struct MsgTypeTraits<TankPosChange>
    {
        static const MsgType enum_value = MsgType_TankPosChange;
    };
	
	template<>
    struct MsgTypeTraits<TankAttrChange>
    {
        static const MsgType enum_value = MsgType_TankAttrChange;
    };
	
	template<>
    struct MsgTypeTraits<TankStatusChange>
    {
        static const MsgType enum_value = MsgType_TankStatusChange;
    };
	
    template<>
    struct MsgTypeTraits<PlayerStatusChange>
    {
        static const MsgType enum_value = MsgType_PlayerStatusChange;
    };

    template<>
    struct MsgTypeTraits<GameStatusChange>
    {
        static const MsgType enum_value = MsgType_GameStatusChange;
    };

    inline bool VerifyMsgType(flatbuffers::Verifier &verifier, const void *union_obj, MsgType type);

    enum Direction
    {
        Direction_LEFT = 0,
        Direction_RIGHT = 1,
        Direction_UP = 2,																			// 
        Direction_DOWN = 3,
        Direction_NONE = 4,
        Direction_MIN = Direction_LEFT,
        Direction_MAX = Direction_NONE
    };

    inline const char **EnumNamesDirection()														// 
    {
        static const char *names[] = { "LEFT", "RIGHT", "UP", "DOWN", "NONE", nullptr };
        return names;
    }

    inline const char *EnumNameDirection(Direction e) { return EnumNamesDirection()[static_cast<int>(e)]; }// 

	enum SoldierType
	{
		SoldierType_NONE = 0,
		SoldierType_Dog = 100,
		SoldierType_Man = 101,
		SoldierType_MIN = SoldierType_NONE,
		SoldierType_MAX = SoldierType_Man
	};
	
	enum BuildingType
	{
		BuildingType_NONE = 0,
		BuildingType_Base = 100,//基地 
		BuildingType_powerPlant = 101,//电厂 
		BuildingType_mineField = 102,//矿场  
		BuildingType_Rax = 103,//兵营 
		BuildingType_warFactory = 104,
		BuildingType_MIN = BuildingType_NONE,
		BuildingType_MAX = BuildingType_warFactory//战车工厂 
	};
	
	enum TankType
	{
		TankType_NONE = 0,
		TankType_Tank = 100,//基地 
		TankType_MIN = TankType_NONE,
		TankType_MAX = TankType_Tank//
	};

    enum BuildingStatus
    {
        BuildingStatus_FREE = 0,
        BuildingStatus_ESTABLISH = 1,
        BuildingStatus_SELECTED=2,
        BuildingStatus_POS=3,
        BuildingStatus_BLOOD=4,
        BuildingStatus_WORK=5,
        BuildingStatus_DESTROY=6,
        BuildingStatus_MIN = BuildingStatus_FREE,
        BuildingStatus_MAX = BuildingStatus_DESTROY
    };

    inline const char **EnumNamesBuildingStatus()
    {
        static const char *names[] = { "FREE", "ESTABLISH", "SELECTED","POS","BLOOD","WORK","DESTROY", nullptr };
        return names;
    }

    inline const char *EnumNameBuildingStatus(BuildingStatus e) { return EnumNamesBuildingStatus()[static_cast<int>(e)]; }
    
    enum SoldierStatus
    {
        SoldierStatus_FREE = 0,
        SoldierStatus_BORN = 1,
        SoldierStatus_FIGHT = 2,
        SoldierStatus_SELECTED=3,
        SoldierStatus_MOVE=4,
        SoldierStatus_BLOOD=5,
        SoldierStatus_DIE = 6,
        SoldierStatus_MIN = SoldierStatus_FREE,
        SoldierStatus_MAX = SoldierStatus_DIE
    };

    inline const char **EnumNamesSoldierStatus()
    {
        static const char *names[] = { "FREE", "BORN", "FIGHT","SELECTED","MOVE","BLOOD","DIE", nullptr };
        return names;
    }

    inline const char *EnumNameSoldierStatus(SoldierStatus e) { return EnumNamesSoldierStatus()[static_cast<int>(e)]; }
    
    enum TankStatus
    {
        TankStatus_FREE = 0,
        TankStatus_BORN = 1,
        TankStatus_FIGHT = 2,
        TankStatus_SELECTED=3,
        TankStatus_MOVE=4,
        TankStatus_BLOOD=5,
        TankStatus_DIE = 6,
        TankStatus_MIN = TankStatus_FREE,
        TankStatus_MAX = TankStatus_DIE
    };

    inline const char **EnumNamesTankStatus()
    {
        static const char *names[] = { "FREE", "BORN", "FIGHT","SELECTED","MOVE","BLOOD","DIE", nullptr };
        return names;
    }

    inline const char *EnumNameTankStatus(TankStatus e) { return EnumNamesTankStatus()[static_cast<int>(e)]; }
    
    enum PlayerStatus
    {
        PlayerStatus_FREE = 0,
        PlayerStatus_READY = 1,
        PlayerStatus_START = 2,
		PlayerStatus_MONEY=3,
        PlayerStatus_VICTORY = 4,
        PlayerStatus_DEFEAT = 5,
        PlayerStatus_MIN = PlayerStatus_FREE,
        PlayerStatus_MAX = PlayerStatus_DEFEAT
    };

    inline const char **EnumNamesPlayerStatus()
    {
        static const char *names[] = { "FREE", "READYE", "START","VICTORY","DEFEAT", nullptr };
        return names;
    }

    inline const char *EnumNamePlayerStatus(PlayerStatus e) { return EnumNamesPlayerStatus()[static_cast<int>(e)]; }

    enum GameStatus
    {
        GameStatus_WAITING = 0,
        GameStatus_PENDING = 1,
        GameStatus_START = 2,
        GameStatus_OVER = 3,
        GameStatus_MIN = GameStatus_WAITING,
        GameStatus_MAX = GameStatus_OVER
    };

    inline const char **EnumNamesGameStatus()
    {
        static const char *names[] = { "WAITING", "PENDING", "START", "OVER", nullptr };
        return names;
    }

    inline const char *EnumNameGameStatus(GameStatus e) { return EnumNamesGameStatus()[static_cast<int>(e)]; }
//UserData_________________________________________________________________________________________________________

    struct UserData /*FLATBUFFERS_FINAL_CLASS */: private flatbuffers::Table
    {
        enum
        {
            VT_UID = 4,//用户身份证明 
            VT_NAME = 6,
            VT_ROLE = 8,
            VT_ISREADY = 10
        };

        const flatbuffers::String *uid() const { return GetPointer<const flatbuffers::String *>(VT_UID); }

        const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }

        int32_t role() const { return GetField<int32_t>(VT_ROLE, 0); }

        bool isReady() const { return GetField<uint8_t>(VT_ISREADY, 0) != 0; }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_UID) &&
                verifier.Verify(uid()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                VerifyField<int32_t>(verifier, VT_ROLE) &&
                VerifyField<uint8_t>(verifier, VT_ISREADY) &&
                verifier.EndTable();
        }
    };

    struct UserDataBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_uid(flatbuffers::Offset<flatbuffers::String> uid) { fbb_.AddOffset(UserData::VT_UID, uid); }

        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(UserData::VT_NAME, name); }

        void add_role(int32_t role) { fbb_.AddElement<int32_t>(UserData::VT_ROLE, role, 0); }

        void add_isReady(bool isReady)
        {
            fbb_.AddElement<uint8_t>(UserData::VT_ISREADY, static_cast<uint8_t>(isReady), 0);
        }

        UserDataBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        UserDataBuilder &operator=(const UserDataBuilder &);

        flatbuffers::Offset<UserData> Finish()
        {
            auto o = flatbuffers::Offset<UserData>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<UserData> CreateUserData(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> uid = 0,
        flatbuffers::Offset<flatbuffers::String> name = 0,
        int32_t role = 0,
        bool isReady = false)
    {
        UserDataBuilder builder_(_fbb);
        builder_.add_role(role);
        builder_.add_name(name);
        builder_.add_uid(uid);
        builder_.add_isReady(isReady);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<UserData> CreateUserDataDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *uid = nullptr,
        const char *name = nullptr,
        int32_t role = 0,
        bool isReady = false)
    {
        return CreateUserData(_fbb, uid ? _fbb.CreateString(uid) : 0, name ? _fbb.CreateString(name) : 0, role,
            isReady);
    }
//Welcome
    struct Welcome /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_UID = 4
        };

        const flatbuffers::String *uid() const { return GetPointer<const flatbuffers::String *>(VT_UID); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_UID) &&
                verifier.Verify(uid()) &&
                verifier.EndTable();
        }
    };

    struct WelcomeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_uid(flatbuffers::Offset<flatbuffers::String> uid) { fbb_.AddOffset(Welcome::VT_UID, uid); }

        WelcomeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        WelcomeBuilder &operator=(const WelcomeBuilder &);

        flatbuffers::Offset<Welcome> Finish()
        {
            auto o = flatbuffers::Offset<Welcome>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<Welcome> CreateWelcome(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> uid = 0)
    {
        WelcomeBuilder builder_(_fbb);
        builder_.add_uid(uid);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Welcome> CreateWelcomeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *uid = nullptr)
    {
        return CreateWelcome(_fbb, uid ? _fbb.CreateString(uid) : 0);
    }
//GotIt
    struct GotIt /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_NAME = 4
        };

        const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
                verifier.Verify(name()) &&
                verifier.EndTable();
        }
    };

    struct GotItBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(GotIt::VT_NAME, name); }

        GotItBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        GotItBuilder &operator=(const GotItBuilder &);

        flatbuffers::Offset<GotIt> Finish()
        {
            auto o = flatbuffers::Offset<GotIt>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<GotIt> CreateGotIt(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> name = 0)
    {
        GotItBuilder builder_(_fbb);
        builder_.add_name(name);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<GotIt> CreateGotItDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *name = nullptr)
    {
        return CreateGotIt(_fbb, name ? _fbb.CreateString(name) : 0);
    }
//JoinRoom
    struct JoinRoom /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                verifier.EndTable();
        }
    };

    struct JoinRoomBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        JoinRoomBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        JoinRoomBuilder &operator=(const JoinRoomBuilder &);

        flatbuffers::Offset<JoinRoom> Finish()
        {
            auto o = flatbuffers::Offset<JoinRoom>(fbb_.EndTable(start_, 0));
            return o;
        }
    };

    inline flatbuffers::Offset<JoinRoom> CreateJoinRoom(flatbuffers::FlatBufferBuilder &_fbb)
    {
        JoinRoomBuilder builder_(_fbb);
        return builder_.Finish();
    }
//RoomInfoUpdate
    struct RoomInfoUpdate /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_USERS = 4
        };

        const flatbuffers::Vector<flatbuffers::Offset<UserData>> *
            users() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<UserData>> *>(VT_USERS); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_USERS) &&
                verifier.Verify(users()) &&
                verifier.VerifyVectorOfTables(users()) &&
                verifier.EndTable();
        }
    };

    struct RoomInfoUpdateBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_users(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UserData>>> users)
        {
            fbb_.AddOffset(RoomInfoUpdate::VT_USERS, users);
        }

        RoomInfoUpdateBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        RoomInfoUpdateBuilder &operator=(const RoomInfoUpdateBuilder &);

        flatbuffers::Offset<RoomInfoUpdate> Finish()
        {
            auto o = flatbuffers::Offset<RoomInfoUpdate>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<RoomInfoUpdate> CreateRoomInfoUpdate(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<UserData>>> users = 0)
    {
        RoomInfoUpdateBuilder builder_(_fbb);
        builder_.add_users(users);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<RoomInfoUpdate> CreateRoomInfoUpdateDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const std::vector<flatbuffers::Offset<UserData>> *users = nullptr)
    {
        return CreateRoomInfoUpdate(_fbb, users ? _fbb.CreateVector<flatbuffers::Offset<UserData>>(*users) : 0);
    }
//UserChangeRole
    struct UserChangeRole /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ROLE = 4
        };

        int32_t role() const { return GetField<int32_t>(VT_ROLE, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<int32_t>(verifier, VT_ROLE) &&
                verifier.EndTable();
        }
    };

    struct UserChangeRoleBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_role(int32_t role) { fbb_.AddElement<int32_t>(UserChangeRole::VT_ROLE, role, 0); }

        UserChangeRoleBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        UserChangeRoleBuilder &operator=(const UserChangeRoleBuilder &);

        flatbuffers::Offset<UserChangeRole> Finish()
        {
            auto o = flatbuffers::Offset<UserChangeRole>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<UserChangeRole> CreateUserChangeRole(flatbuffers::FlatBufferBuilder &_fbb,
        int32_t role = 0)
    {
        UserChangeRoleBuilder builder_(_fbb);
        builder_.add_role(role);
        return builder_.Finish();
    }
//UserChangeStats
    struct UserChangeStats /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_STAT = 4
        };

        int32_t stat() const { return GetField<int32_t>(VT_STAT, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<int32_t>(verifier, VT_STAT) &&
                verifier.EndTable();
        }
    };

    struct UserChangeStatsBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_stat(int32_t stat) { fbb_.AddElement<int32_t>(UserChangeStats::VT_STAT, stat, 0); }

        UserChangeStatsBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        UserChangeStatsBuilder &operator=(const UserChangeStatsBuilder &);

        flatbuffers::Offset<UserChangeStats> Finish()
        {
            auto o = flatbuffers::Offset<UserChangeStats>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<UserChangeStats> CreateUserChangeStats(flatbuffers::FlatBufferBuilder &_fbb,
        int32_t stat = 0)
    {
        UserChangeStatsBuilder builder_(_fbb);
        builder_.add_stat(stat);
        return builder_.Finish();
    }
//PlayerData
    struct PlayerData /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_X = 6,
            VT_Y = 8,
            VT_ROLE = 10
//            VT_SPEED = 12,
//            VT_DAMAGE = 14,
//            VT_BUBBLE = 16
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }

        int32_t x() const { return GetField<int32_t>(VT_X, 0); }

        int32_t y() const { return GetField<int32_t>(VT_Y, 0); }

        int32_t role() const { return GetField<int32_t>(VT_ROLE, 0); }

//        uint8_t speed() const { return GetField<uint8_t>(VT_SPEED, 0); }
//
//        uint8_t damage() const { return GetField<uint8_t>(VT_DAMAGE, 0); }
//
//        uint8_t bubble() const { return GetField<uint8_t>(VT_BUBBLE, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int32_t>(verifier, VT_X) &&
                VerifyField<int32_t>(verifier, VT_Y) &&
                VerifyField<int32_t>(verifier, VT_ROLE) &&
//                VerifyField<uint8_t>(verifier, VT_SPEED) &&
//                VerifyField<uint8_t>(verifier, VT_DAMAGE) &&
//                VerifyField<uint8_t>(verifier, VT_BUBBLE) &&
                verifier.EndTable();
        }
    };

    struct PlayerDataBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(PlayerData::VT_ID, id); }

        void add_x(int32_t x) { fbb_.AddElement<int32_t>(PlayerData::VT_X, x, 0); }

        void add_y(int32_t y) { fbb_.AddElement<int32_t>(PlayerData::VT_Y, y, 0); }

        void add_role(int32_t role) { fbb_.AddElement<int32_t>(PlayerData::VT_ROLE, role, 0); }

//        void add_speed(uint8_t speed) { fbb_.AddElement<uint8_t>(PlayerData::VT_SPEED, speed, 0); }
//
//        void add_damage(uint8_t damage) { fbb_.AddElement<uint8_t>(PlayerData::VT_DAMAGE, damage, 0); }
//
//        void add_bubble(uint8_t bubble) { fbb_.AddElement<uint8_t>(PlayerData::VT_BUBBLE, bubble, 0); }

        PlayerDataBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        PlayerDataBuilder &operator=(const PlayerDataBuilder &);

        flatbuffers::Offset<PlayerData> Finish()
        {
            auto o = flatbuffers::Offset<PlayerData>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<PlayerData> CreatePlayerData(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        int32_t x = 0,
        int32_t y = 0,
        int32_t role = 0
//        uint8_t speed = 0,
//        uint8_t damage = 0,
//        uint8_t bubble = 0
		)
    {
        PlayerDataBuilder builder_(_fbb);
        builder_.add_role(role);
        builder_.add_y(y);
        builder_.add_x(x);
        builder_.add_id(id);
//        builder_.add_bubble(bubble);
//        builder_.add_damage(damage);
//        builder_.add_speed(speed);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<PlayerData> CreatePlayerDataDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        int32_t x = 0,
        int32_t y = 0,
        int32_t role = 0
//        uint8_t speed = 0,
//        uint8_t damage = 0,
//        uint8_t bubble = 0
		)
    {
        return CreatePlayerData(_fbb, id ? _fbb.CreateString(id) : 0, x, y, role/*, speed, damage, bubble*/);
    }
//GameInit
    struct GameInit /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_PLAYERS = 4
        };

        const flatbuffers::Vector<flatbuffers::Offset<PlayerData>> *
            players() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<PlayerData>> *>(VT_PLAYERS); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYERS) &&
                verifier.Verify(players()) &&
                verifier.VerifyVectorOfTables(players()) &&
                verifier.EndTable();
        }
    };

    struct GameInitBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_players(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PlayerData>>> players)
        {
            fbb_.AddOffset(GameInit::VT_PLAYERS, players);
        }

        GameInitBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        GameInitBuilder &operator=(const GameInitBuilder &);

        flatbuffers::Offset<GameInit> Finish()
        {
            auto o = flatbuffers::Offset<GameInit>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<GameInit> CreateGameInit(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<PlayerData>>> players = 0)
    {
        GameInitBuilder builder_(_fbb);
        builder_.add_players(players);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<GameInit> CreateGameInitDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const std::vector<flatbuffers::Offset<PlayerData>> *players = nullptr)
    {
        return CreateGameInit(_fbb, players ? _fbb.CreateVector<flatbuffers::Offset<PlayerData>>(*players) : 0);
    }
//PlayerPosChange
    struct PlayerPosChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_DIRECTION = 6,
            VT_X = 8,
            VT_Y = 10
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }

        Direction direction() const { return static_cast<Direction>(GetField<int8_t>(VT_DIRECTION, 0)); }

        int32_t x() const { return GetField<int32_t>(VT_X, 0); }

        int32_t y() const { return GetField<int32_t>(VT_Y, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_DIRECTION) &&
                VerifyField<int32_t>(verifier, VT_X) &&
                VerifyField<int32_t>(verifier, VT_Y) &&
                verifier.EndTable();
        }
    };

    struct PlayerPosChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(PlayerPosChange::VT_ID, id); }

        void add_direction(Direction direction)
        {
            fbb_.AddElement<int8_t>(PlayerPosChange::VT_DIRECTION, static_cast<int8_t>(direction), 0);
        }

        void add_x(int32_t x) { fbb_.AddElement<int32_t>(PlayerPosChange::VT_X, x, 0); }

        void add_y(int32_t y) { fbb_.AddElement<int32_t>(PlayerPosChange::VT_Y, y, 0); }

        PlayerPosChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        PlayerPosChangeBuilder &operator=(const PlayerPosChangeBuilder &);

        flatbuffers::Offset<PlayerPosChange> Finish()
        {
            auto o = flatbuffers::Offset<PlayerPosChange>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<PlayerPosChange> CreatePlayerPosChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        Direction direction = Direction_LEFT,
        int32_t x = 0,
        int32_t y = 0)
    {
        PlayerPosChangeBuilder builder_(_fbb);
        builder_.add_y(y);
        builder_.add_x(x);
        builder_.add_id(id);
        builder_.add_direction(direction);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<PlayerPosChange> CreatePlayerPosChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        Direction direction = Direction_LEFT,
        int32_t x = 0,
        int32_t y = 0)
    {
        return CreatePlayerPosChange(_fbb, id ? _fbb.CreateString(id) : 0, direction, x, y);
    }

//    struct PlayerSetBubble FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct PlayerSetBubbleBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        PlayerSetBubbleBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        PlayerSetBubbleBuilder &operator=(const PlayerSetBubbleBuilder &);
//
//        flatbuffers::Offset<PlayerSetBubble> Finish()
//        {
//            auto o = flatbuffers::Offset<PlayerSetBubble>(fbb_.EndTable(start_, 0));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<PlayerSetBubble> CreatePlayerSetBubble(flatbuffers::FlatBufferBuilder &_fbb)
//    {
//        PlayerSetBubbleBuilder builder_(_fbb);
//        return builder_.Finish();
//    }
//
//    struct BubbleSet FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        enum
//        {
//            VT_ID = 4,
//            VT_PLAYER_ID = 6,
//            VT_X = 8,
//            VT_Y = 10,
//            VT_DAMAGE = 12
//        };
//
//        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
//
//        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }
//
//        int32_t x() const { return GetField<int32_t>(VT_X, 0); }
//
//        int32_t y() const { return GetField<int32_t>(VT_Y, 0); }
//
//        uint8_t damage() const { return GetField<uint8_t>(VT_DAMAGE, 0); }
//
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
//                verifier.Verify(id()) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
//                verifier.Verify(player_id()) &&
//                VerifyField<int32_t>(verifier, VT_X) &&
//                VerifyField<int32_t>(verifier, VT_Y) &&
//                VerifyField<uint8_t>(verifier, VT_DAMAGE) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct BubbleSetBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BubbleSet::VT_ID, id); }
//
//        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id)
//        {
//            fbb_.AddOffset(BubbleSet::VT_PLAYER_ID, player_id);
//        }
//
//        void add_x(int32_t x) { fbb_.AddElement<int32_t>(BubbleSet::VT_X, x, 0); }
//
//        void add_y(int32_t y) { fbb_.AddElement<int32_t>(BubbleSet::VT_Y, y, 0); }
//
//        void add_damage(uint8_t damage) { fbb_.AddElement<uint8_t>(BubbleSet::VT_DAMAGE, damage, 0); }
//
//        BubbleSetBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        BubbleSetBuilder &operator=(const BubbleSetBuilder &);
//
//        flatbuffers::Offset<BubbleSet> Finish()
//        {
//            auto o = flatbuffers::Offset<BubbleSet>(fbb_.EndTable(start_, 5));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<BubbleSet> CreateBubbleSet(flatbuffers::FlatBufferBuilder &_fbb,
//        flatbuffers::Offset<flatbuffers::String> id = 0,
//        flatbuffers::Offset<flatbuffers::String> player_id = 0,
//        int32_t x = 0,
//        int32_t y = 0,
//        uint8_t damage = 0)
//    {
//        BubbleSetBuilder builder_(_fbb);
//        builder_.add_y(y);
//        builder_.add_x(x);
//        builder_.add_player_id(player_id);
//        builder_.add_id(id);
//        builder_.add_damage(damage);
//        return builder_.Finish();
//    }
//
//    inline flatbuffers::Offset<BubbleSet> CreateBubbleSetDirect(flatbuffers::FlatBufferBuilder &_fbb,
//        const char *id = nullptr,
//        const char *player_id = nullptr,
//        int32_t x = 0,
//        int32_t y = 0,
//        uint8_t damage = 0)
//    {
//        return CreateBubbleSet(_fbb, id ? _fbb.CreateString(id) : 0, player_id ? _fbb.CreateString(player_id) : 0, x, y,
//            damage);
//    }
//
//    struct BubbleBoom FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        enum
//        {
//            VT_ID = 4
//        };
//
//        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
//
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
//                verifier.Verify(id()) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct BubbleBoomBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BubbleBoom::VT_ID, id); }
//
//        BubbleBoomBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        BubbleBoomBuilder &operator=(const BubbleBoomBuilder &);
//
//        flatbuffers::Offset<BubbleBoom> Finish()
//        {
//            auto o = flatbuffers::Offset<BubbleBoom>(fbb_.EndTable(start_, 1));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<BubbleBoom> CreateBubbleBoom(flatbuffers::FlatBufferBuilder &_fbb,
//        flatbuffers::Offset<flatbuffers::String> id = 0)
//    {
//        BubbleBoomBuilder builder_(_fbb);
//        builder_.add_id(id);
//        return builder_.Finish();
//    }
//
//    inline flatbuffers::Offset<BubbleBoom> CreateBubbleBoomDirect(flatbuffers::FlatBufferBuilder &_fbb,
//        const char *id = nullptr)
//    {
//        return CreateBubbleBoom(_fbb, id ? _fbb.CreateString(id) : 0);
//    }
//
//    struct PropSet FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        enum
//        {
//            VT_ID = 4,
//            VT_X = 6,
//            VT_Y = 8,
//            VT_TYPE = 10
//        };
//
//        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
//
//        int32_t x() const { return GetField<int32_t>(VT_X, 0); }
//
//        int32_t y() const { return GetField<int32_t>(VT_Y, 0); }
//
//        PropType type() const { return static_cast<PropType>(GetField<int8_t>(VT_TYPE, 0)); }
//
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
//                verifier.Verify(id()) &&
//                VerifyField<int32_t>(verifier, VT_X) &&
//                VerifyField<int32_t>(verifier, VT_Y) &&
//                VerifyField<int8_t>(verifier, VT_TYPE) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct PropSetBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(PropSet::VT_ID, id); }
//
//        void add_x(int32_t x) { fbb_.AddElement<int32_t>(PropSet::VT_X, x, 0); }
//
//        void add_y(int32_t y) { fbb_.AddElement<int32_t>(PropSet::VT_Y, y, 0); }
//
//        void add_type(PropType type) { fbb_.AddElement<int8_t>(PropSet::VT_TYPE, static_cast<int8_t>(type), 0); }
//
//        PropSetBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        PropSetBuilder &operator=(const PropSetBuilder &);
//
//        flatbuffers::Offset<PropSet> Finish()
//        {
//            auto o = flatbuffers::Offset<PropSet>(fbb_.EndTable(start_, 4));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<PropSet> CreatePropSet(flatbuffers::FlatBufferBuilder &_fbb,
//        flatbuffers::Offset<flatbuffers::String> id = 0,
//        int32_t x = 0,
//        int32_t y = 0,
//        PropType type = PropType_NONE)
//    {
//        PropSetBuilder builder_(_fbb);
//        builder_.add_y(y);
//        builder_.add_x(x);
//        builder_.add_id(id);
//        builder_.add_type(type);
//        return builder_.Finish();
//    }
//
//    inline flatbuffers::Offset<PropSet> CreatePropSetDirect(flatbuffers::FlatBufferBuilder &_fbb,
//        const char *id = nullptr,
//        int32_t x = 0,
//        int32_t y = 0,
//        PropType type = PropType_NONE)
//    {
//        return CreatePropSet(_fbb, id ? _fbb.CreateString(id) : 0, x, y, type);
//    }
//
//    struct PlayerEatProp FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        enum
//        {
//            VT_PLAYER_ID = 4,
//            VT_BUBBLE_ID = 6
//        };
//
//        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }
//
//        const flatbuffers::String *bubble_id() const { return GetPointer<const flatbuffers::String *>(VT_BUBBLE_ID); }
//
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
//                verifier.Verify(player_id()) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_BUBBLE_ID) &&
//                verifier.Verify(bubble_id()) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct PlayerEatPropBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id)
//        {
//            fbb_.AddOffset(PlayerEatProp::VT_PLAYER_ID, player_id);
//        }
//
//        void add_bubble_id(flatbuffers::Offset<flatbuffers::String> bubble_id)
//        {
//            fbb_.AddOffset(PlayerEatProp::VT_BUBBLE_ID, bubble_id);
//        }
//
//        PlayerEatPropBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        PlayerEatPropBuilder &operator=(const PlayerEatPropBuilder &);
//
//        flatbuffers::Offset<PlayerEatProp> Finish()
//        {
//            auto o = flatbuffers::Offset<PlayerEatProp>(fbb_.EndTable(start_, 2));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<PlayerEatProp> CreatePlayerEatProp(flatbuffers::FlatBufferBuilder &_fbb,
//        flatbuffers::Offset<flatbuffers::String> player_id = 0,
//        flatbuffers::Offset<flatbuffers::String> bubble_id = 0)
//    {
//        PlayerEatPropBuilder builder_(_fbb);
//        builder_.add_bubble_id(bubble_id);
//        builder_.add_player_id(player_id);
//        return builder_.Finish();
//    }
//
//    inline flatbuffers::Offset<PlayerEatProp> CreatePlayerEatPropDirect(flatbuffers::FlatBufferBuilder &_fbb,
//        const char *player_id = nullptr,
//        const char *bubble_id = nullptr)
//    {
//        return CreatePlayerEatProp(_fbb, player_id ? _fbb.CreateString(player_id) : 0,
//            bubble_id ? _fbb.CreateString(bubble_id) : 0);
//    }

//
//"SelectBuilding",
	struct SelectBuilding /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
        	VT_ID=4,
            VT_TYPE = 6
        };

		const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
		
		BuildingType type() const { return static_cast<BuildingType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct SelectBuildingBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;
        
        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SelectBuilding::VT_ID, id); }
        
        void add_type(BuildingType type) { fbb_.AddElement<int8_t>(SelectBuilding::VT_TYPE, static_cast<int8_t>(type), 0); }

        SelectBuildingBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SelectBuildingBuilder &operator=(const SelectBuildingBuilder &);

        flatbuffers::Offset<SelectBuilding> Finish()
        {
            auto o = flatbuffers::Offset<SelectBuilding>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<SelectBuilding> CreateSelectBuilding(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        BuildingType type = BuildingType_NONE)
    {
        SelectBuildingBuilder builder_(_fbb);
        builder_.add_type(type);
        builder_.add_id(id);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SelectBuilding> CreateSelectBuildingDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        BuildingType type = BuildingType_NONE)
    {
        return CreateSelectBuilding(_fbb, id ? _fbb.CreateString(id) : 0, type);
    }
//"BuildingPosChange",
	struct BuildingPosChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID=6,
            VT_FORMERX = 8,
            VT_FORMERY = 10,
            VT_NEWX = 12,
            VT_NEWY = 14,
            VT_TYPE = 16
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        int32_t formerx() const { return GetField<int32_t>(VT_FORMERX, 0); }

        int32_t formery() const { return GetField<int32_t>(VT_FORMERY, 0); }
        
        int32_t newx() const { return GetField<int32_t>(VT_NEWX, 0); }

        int32_t newy() const { return GetField<int32_t>(VT_NEWY, 0); }
        
        BuildingType type() const { return static_cast<BuildingType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int32_t>(verifier, VT_FORMERX) &&
                VerifyField<int32_t>(verifier, VT_FORMERY) &&
                VerifyField<int32_t>(verifier, VT_NEWX) &&
                VerifyField<int32_t>(verifier, VT_NEWY) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct BuildingPosChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BuildingPosChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(BuildingPosChange::VT_PLAYER_ID, player_id); }

        void add_formerx(int32_t formerx) { fbb_.AddElement<int32_t>(BuildingPosChange::VT_FORMERX, formerx, 0); }

        void add_formery(int32_t formery) { fbb_.AddElement<int32_t>(BuildingPosChange::VT_FORMERY, formery, 0); }
        
        void add_newx(int32_t newx) { fbb_.AddElement<int32_t>(BuildingPosChange::VT_NEWX, newx, 0); }

        void add_newy(int32_t newy) { fbb_.AddElement<int32_t>(BuildingPosChange::VT_NEWY, newy, 0); }

        void add_type(BuildingType type) { fbb_.AddElement<int8_t>(BuildingPosChange::VT_TYPE, static_cast<int8_t>(type), 0); }

        BuildingPosChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        BuildingPosChangeBuilder &operator=(const BuildingPosChangeBuilder &);

        flatbuffers::Offset<BuildingPosChange> Finish()
        {
            auto o = flatbuffers::Offset<BuildingPosChange>(fbb_.EndTable(start_, 7));
            return o;
        }
    };

    inline flatbuffers::Offset<BuildingPosChange> CreateBuildingPosChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        BuildingType type = BuildingType_NONE)
    {
        BuildingPosChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_formerx(formerx);
        builder_.add_formery(formery);
        builder_.add_newx(newx);
        builder_.add_newy(newy);
        builder_.add_type(type);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<BuildingPosChange> CreateBuildingPosChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id = nullptr,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        BuildingType type = BuildingType_NONE)
    {
        return CreateBuildingPosChange(_fbb, id ? _fbb.CreateString(id) : 0, player_id ? _fbb.CreateString(player_id) : 0, formerx,formery,newx,newy,type);
    }
//"BuildingPosSet",
struct BuildingPosSet /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID=6,
            VT_X = 8,
            VT_Y = 10,
            VT_TYPE = 12,
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        int32_t x() const { return GetField<int32_t>(VT_X, 0); }

        int32_t y() const { return GetField<int32_t>(VT_Y, 0); }

        BuildingType type() const { return static_cast<BuildingType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int32_t>(verifier, VT_X) &&
                VerifyField<int32_t>(verifier, VT_Y) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct BuildingPosSetBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BuildingPosSet::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(BuildingPosSet::VT_PLAYER_ID, player_id); }

        void add_x(int32_t x) { fbb_.AddElement<int32_t>(BuildingPosSet::VT_X, x, 0); }

        void add_y(int32_t y) { fbb_.AddElement<int32_t>(BuildingPosSet::VT_Y, y, 0); }

        void add_type(BuildingType type) { fbb_.AddElement<int8_t>(BuildingPosSet::VT_TYPE, static_cast<int8_t>(type), 0); }

        BuildingPosSetBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        BuildingPosSetBuilder &operator=(const BuildingPosSetBuilder &);

        flatbuffers::Offset<BuildingPosSet> Finish()
        {
            auto o = flatbuffers::Offset<BuildingPosSet>(fbb_.EndTable(start_, 5));
            return o;
        }
    };

    inline flatbuffers::Offset<BuildingPosSet> CreateBuildingPosSet(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        int32_t x = 0,
        int32_t y = 0,
        BuildingType type = BuildingType_NONE)
    {
        BuildingPosSetBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_y(y);
        builder_.add_x(x);
        builder_.add_type(type);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<BuildingPosSet> CreateBuildingPosSetDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id = nullptr,
        int32_t x = 0,
        int32_t y = 0,
        BuildingType type = BuildingType_NONE)
    {
        return CreateBuildingPosSet(_fbb, id ? _fbb.CreateString(id) : 0,/*_fbb,*/ player_id ? _fbb.CreateString(player_id) : 0, x, y, type);
    }
//"BuildingStatusChange",
struct BuildingStatusChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID = 6,
            VT_STATUS = 8
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        BuildingStatus status() const { return static_cast<BuildingStatus>(GetField<int8_t>(VT_STATUS, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int8_t>(verifier, VT_STATUS)&& 
                verifier.EndTable();
        }
    };

    struct BuildingStatusChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BuildingStatusChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(BuildingStatusChange::VT_PLAYER_ID, player_id); }

        void add_status(BuildingStatus status) { fbb_.AddElement<int8_t>(BuildingStatusChange::VT_STATUS, static_cast<int8_t>(status), 0); }

        BuildingStatusChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        BuildingStatusChangeBuilder &operator=(const BuildingStatusChangeBuilder &);

        flatbuffers::Offset<BuildingStatusChange> Finish()
        {
            auto o = flatbuffers::Offset<BuildingStatusChange>(fbb_.EndTable(start_, 3));
            return o;
        }
    };

    inline flatbuffers::Offset<BuildingStatusChange> CreateBuildingStatusChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        BuildingStatus status=BuildingStatus_FREE)
    {
        BuildingStatusChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_status(status);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<BuildingStatusChange> CreateBuildingStatusChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id=nullptr,
        BuildingStatus status=BuildingStatus_FREE)
    {
        return CreateBuildingStatusChange(_fbb, id ? _fbb.CreateString(id) : 0,/*_fbb,*/ player_id ? _fbb.CreateString(player_id) : 0, status);
    }
//"SelectSoldier",
	struct SelectSoldier /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
        	VT_ID=4,
            VT_TYPE = 6
        };

		const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
		
		SoldierType type() const { return static_cast<SoldierType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct SelectSoldierBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;
        
        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SelectSoldier::VT_ID, id); }
        
        void add_type(SoldierType type) { fbb_.AddElement<int8_t>(SelectSoldier::VT_TYPE, static_cast<int8_t>(type), 0); }

        SelectSoldierBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SelectSoldierBuilder &operator=(const SelectSoldierBuilder &);

        flatbuffers::Offset<SelectSoldier> Finish()
        {
            auto o = flatbuffers::Offset<SelectSoldier>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<SelectSoldier> CreateSelectSoldier(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        SoldierType type = SoldierType_NONE)
    {
        SelectSoldierBuilder builder_(_fbb);
        builder_.add_type(type);
        builder_.add_id(id);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SelectSoldier> CreateSelectSoldierDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        SoldierType type = SoldierType_NONE)
    {
        return CreateSelectSoldier(_fbb, id ? _fbb.CreateString(id) : 0, type);
    }

//"SoldierPosChange",
	struct SoldierPosChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID=6,
            VT_FORMERX = 8,
            VT_FORMERY = 10,
            VT_NEWX = 12,
            VT_NEWY = 14,
            VT_TYPE = 16,
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        int32_t formerx() const { return GetField<int32_t>(VT_FORMERX, 0); }

        int32_t formery() const { return GetField<int32_t>(VT_FORMERY, 0); }
        
        int32_t newx() const { return GetField<int32_t>(VT_NEWX, 0); }

        int32_t newy() const { return GetField<int32_t>(VT_NEWY, 0); }
        
        SoldierType type() const { return static_cast<SoldierType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int32_t>(verifier, VT_FORMERX) &&
                VerifyField<int32_t>(verifier, VT_FORMERY) &&
                VerifyField<int32_t>(verifier, VT_NEWX) &&
                VerifyField<int32_t>(verifier, VT_NEWY) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct SoldierPosChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SoldierPosChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(SoldierPosChange::VT_PLAYER_ID, player_id); }

        void add_formerx(int32_t formerx) { fbb_.AddElement<int32_t>(SoldierPosChange::VT_FORMERX, formerx, 0); }

        void add_formery(int32_t formery) { fbb_.AddElement<int32_t>(SoldierPosChange::VT_FORMERY, formery, 0); }
        
        void add_newx(int32_t newx) { fbb_.AddElement<int32_t>(SoldierPosChange::VT_NEWX, newx, 0); }

        void add_newy(int32_t newy) { fbb_.AddElement<int32_t>(SoldierPosChange::VT_NEWY, newy, 0); }

        void add_type(SoldierType type) { fbb_.AddElement<int8_t>(SoldierPosChange::VT_TYPE, static_cast<int8_t>(type), 0); }

        SoldierPosChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SoldierPosChangeBuilder &operator=(const SoldierPosChangeBuilder &);

        flatbuffers::Offset<SoldierPosChange> Finish()
        {
            auto o = flatbuffers::Offset<SoldierPosChange>(fbb_.EndTable(start_, 7));
            return o;
        }
    };

    inline flatbuffers::Offset<SoldierPosChange> CreateSoldierPosChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        SoldierType type = SoldierType_NONE)
    {
        SoldierPosChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_formerx(formerx);
        builder_.add_formery(formery);
        builder_.add_newx(newx);
        builder_.add_newy(newy);
        builder_.add_type(type);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SoldierPosChange> CreateSoldierPosChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id = nullptr,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        SoldierType type = SoldierType_NONE)
    {
        return CreateSoldierPosChange(_fbb, id ? _fbb.CreateString(id) : 0, player_id ? _fbb.CreateString(player_id) : 0, formerx,formery,newx,newy,type);
    }

//"SoldierAttrChange",
struct SoldierAttrChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_SPEED = 6,
            VT_DAMAGE = 8,
            VT_OBJECT = 10
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }

        uint8_t speed() const { return GetField<uint8_t>(VT_SPEED, 0); }

        uint8_t damage() const { return GetField<uint8_t>(VT_DAMAGE, 0); }

        int32_t OBJECT() const { return GetField<uint8_t>(VT_OBJECT, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<uint8_t>(verifier, VT_SPEED) &&
                VerifyField<uint8_t>(verifier, VT_DAMAGE) &&
                VerifyField<int32_t>(verifier, VT_OBJECT) &&
                verifier.EndTable();
        }
    };

    struct SoldierAttrChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SoldierAttrChange::VT_ID, id); }

        void add_damage(uint8_t damage) { fbb_.AddElement<uint8_t>(SoldierAttrChange::VT_DAMAGE, damage, 0); }

		void add_speed(uint8_t speed) { fbb_.AddElement<uint8_t>(SoldierAttrChange::VT_DAMAGE, speed, 0); }

        void add_object(int32_t object) { fbb_.AddElement<uint8_t>(SoldierAttrChange::VT_OBJECT, object, 0); }

        SoldierAttrChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SoldierAttrChangeBuilder &operator=(const SoldierAttrChangeBuilder &);

        flatbuffers::Offset<SoldierAttrChange> Finish()
        {
            auto o = flatbuffers::Offset<SoldierAttrChange>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<SoldierAttrChange> CreateSoldierAttrChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        uint8_t speed = 0,
        uint8_t damage = 0,
        int32_t object = 0)
    {
        SoldierAttrChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_object(object);
        builder_.add_damage(damage);
        builder_.add_speed(speed);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SoldierAttrChange> CreateSoldierAttrChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        uint8_t speed = 0,
        uint8_t damage = 0,
        int32_t object = 0)
    {
        return CreateSoldierAttrChange(_fbb, id ? _fbb.CreateString(id) : 0,  speed, damage, object);
    }
//"SoldierStatusChange",
struct SoldierStatusChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID = 6,
            VT_STATUS = 8
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        SoldierStatus status() const { return static_cast<SoldierStatus>(GetField<int8_t>(VT_STATUS, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int8_t>(verifier, VT_STATUS) &&
                verifier.EndTable();
        }
    };

    struct SoldierStatusChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SoldierStatusChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(SoldierStatusChange::VT_PLAYER_ID, player_id); }

        void add_status(SoldierStatus status) { fbb_.AddElement<int8_t>(SoldierStatusChange::VT_STATUS, static_cast<int8_t>(status), 0); }

        SoldierStatusChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SoldierStatusChangeBuilder &operator=(const SoldierStatusChangeBuilder &);

        flatbuffers::Offset<SoldierStatusChange> Finish()
        {
            auto o = flatbuffers::Offset<SoldierStatusChange>(fbb_.EndTable(start_, 3));
            return o;
        }
    };

    inline flatbuffers::Offset<SoldierStatusChange> CreateSoldierStatusChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        SoldierStatus status=SoldierStatus_FREE)
    {
        SoldierStatusChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_status(status);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SoldierStatusChange> CreateSoldierStatusChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id=nullptr,
        SoldierStatus status=SoldierStatus_FREE)
    {
        return CreateSoldierStatusChange(_fbb, id ? _fbb.CreateString(id) : 0,/*_fbb,*/ player_id ? _fbb.CreateString(player_id) : 0, status);
    }

//"BuildSoldier",
	struct BuildSoldier /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
        	VT_ID=4,
            VT_TYPE = 6
        };

		const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
		
		SoldierType type() const { return static_cast<SoldierType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct BuildSoldierBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;
        
        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BuildSoldier::VT_ID, id); }
        
        void add_type(SoldierType type) { fbb_.AddElement<int8_t>(BuildSoldier::VT_TYPE, static_cast<int8_t>(type), 0); }

        BuildSoldierBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        BuildSoldierBuilder &operator=(const BuildSoldierBuilder &);

        flatbuffers::Offset<BuildSoldier> Finish()
        {
            auto o = flatbuffers::Offset<BuildSoldier>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<BuildSoldier> CreateBuildSoldier(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        SoldierType type = SoldierType_NONE)
    {
        BuildSoldierBuilder builder_(_fbb);
        builder_.add_type(type);
        builder_.add_id(id);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<BuildSoldier> CreateBuildSoldierDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        SoldierType type = SoldierType_NONE)
    {
        return CreateBuildSoldier(_fbb, id ? _fbb.CreateString(id) : 0, type);
    }

//"BuildTank",
	struct BuildTank/* FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
        	VT_ID=4,
            VT_TYPE = 6
        };

		const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
		
		SoldierType type() const { return static_cast<SoldierType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct BuildTankBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;
        
        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(BuildTank::VT_ID, id); }
        
        void add_type(SoldierType type) { fbb_.AddElement<int8_t>(BuildTank::VT_TYPE, static_cast<int8_t>(type), 0); }

        BuildTankBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        BuildTankBuilder &operator=(const BuildTankBuilder &);

        flatbuffers::Offset<BuildTank> Finish()
        {
            auto o = flatbuffers::Offset<BuildTank>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<BuildTank> CreateBuildTank(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        SoldierType type = SoldierType_NONE)
    {
        BuildTankBuilder builder_(_fbb);
        builder_.add_type(type);
        builder_.add_id(id);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<BuildTank> CreateBuildTankDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        SoldierType type = SoldierType_NONE)
    {
        return CreateBuildTank(_fbb, id ? _fbb.CreateString(id) : 0, type);
    }
//"SelectTank",
	struct SelectTank /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
        	VT_ID=4,
            VT_TYPE = 6
        };

		const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
		
		SoldierType type() const { return static_cast<SoldierType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct SelectTankBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;
        
        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(SelectTank::VT_ID, id); }
        
        void add_type(SoldierType type) { fbb_.AddElement<int8_t>(SelectTank::VT_TYPE, static_cast<int8_t>(type), 0); }

        SelectTankBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        SelectTankBuilder &operator=(const SelectTankBuilder &);

        flatbuffers::Offset<SelectTank> Finish()
        {
            auto o = flatbuffers::Offset<SelectTank>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<SelectTank> CreateSelectTank(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        SoldierType type = SoldierType_NONE)
    {
        SelectTankBuilder builder_(_fbb);
        builder_.add_type(type);
        builder_.add_id(id);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<SelectTank> CreateSelectTankDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        SoldierType type = SoldierType_NONE)
    {
        return CreateSelectTank(_fbb, id ? _fbb.CreateString(id) : 0, type);
    }
//"TankPoschange",
	struct TankPosChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID=6,
            VT_FORMERX = 8,
            VT_FORMERY = 10,
            VT_NEWX = 12,
            VT_NEWY = 14,
            VT_TYPE = 16,
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        int32_t formerx() const { return GetField<int32_t>(VT_FORMERX, 0); }

        int32_t formery() const { return GetField<int32_t>(VT_FORMERY, 0); }
        
        int32_t newx() const { return GetField<int32_t>(VT_NEWX, 0); }

        int32_t newy() const { return GetField<int32_t>(VT_NEWY, 0); }
        
        TankType type() const { return static_cast<TankType>(GetField<int8_t>(VT_TYPE, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int32_t>(verifier, VT_FORMERX) &&
                VerifyField<int32_t>(verifier, VT_FORMERY) &&
                VerifyField<int32_t>(verifier, VT_NEWX) &&
                VerifyField<int32_t>(verifier, VT_NEWY) &&
                VerifyField<int8_t>(verifier, VT_TYPE) &&
                verifier.EndTable();
        }
    };

    struct TankPosChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(TankPosChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(TankPosChange::VT_PLAYER_ID, player_id); }

        void add_formerx(int32_t formerx) { fbb_.AddElement<int32_t>(TankPosChange::VT_FORMERX, formerx, 0); }

        void add_formery(int32_t formery) { fbb_.AddElement<int32_t>(TankPosChange::VT_FORMERY, formery, 0); }
        
        void add_newx(int32_t newx) { fbb_.AddElement<int32_t>(TankPosChange::VT_NEWX, newx, 0); }

        void add_newy(int32_t newy) { fbb_.AddElement<int32_t>(TankPosChange::VT_NEWY, newy, 0); }

        void add_type(TankType type) { fbb_.AddElement<int8_t>(TankPosChange::VT_TYPE, static_cast<int8_t>(type), 0); }

        TankPosChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        TankPosChangeBuilder &operator=(const TankPosChangeBuilder &);

        flatbuffers::Offset<TankPosChange> Finish()
        {
            auto o = flatbuffers::Offset<TankPosChange>(fbb_.EndTable(start_, 7));
            return o;
        }
    };

    inline flatbuffers::Offset<TankPosChange> CreateTankPosChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        TankType type = TankType_NONE)
    {
        TankPosChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_formerx(formerx);
        builder_.add_formery(formery);
        builder_.add_newx(newx);
        builder_.add_newy(newy);
        builder_.add_type(type);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<TankPosChange> CreateTankPosChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id = nullptr,
        int32_t formerx = 0,
        int32_t formery = 0,
        int32_t newx = 0,
        int32_t newy = 0,
        TankType type = TankType_NONE)
    {
        return CreateTankPosChange(_fbb, id ? _fbb.CreateString(id) : 0, player_id ? _fbb.CreateString(player_id) : 0, formerx,formery,newx,newy,type);
    }
//"TankAttrChange",
struct TankAttrChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_SPEED = 6,
            VT_DAMAGE = 8,
            VT_OBJECT = 10
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }

        uint8_t speed() const { return GetField<uint8_t>(VT_SPEED, 0); }

        uint8_t damage() const { return GetField<uint8_t>(VT_DAMAGE, 0); }

        int32_t OBJECT() const { return GetField<uint8_t>(VT_OBJECT, 0); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<uint8_t>(verifier, VT_SPEED) &&
                VerifyField<uint8_t>(verifier, VT_DAMAGE) &&
                VerifyField<int32_t>(verifier, VT_OBJECT) &&
                verifier.EndTable();
        }
    };

    struct TankAttrChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(TankAttrChange::VT_ID, id); }

        void add_damage(uint8_t damage) { fbb_.AddElement<uint8_t>(TankAttrChange::VT_DAMAGE, damage, 0); }

		void add_speed(uint8_t speed) { fbb_.AddElement<uint8_t>(TankAttrChange::VT_SPEED, speed, 0); }

        void add_object(int32_t object) { fbb_.AddElement<uint8_t>(TankAttrChange::VT_OBJECT, object, 0); }

        TankAttrChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        TankAttrChangeBuilder &operator=(const TankAttrChangeBuilder &);

        flatbuffers::Offset<TankAttrChange> Finish()
        {
            auto o = flatbuffers::Offset<TankAttrChange>(fbb_.EndTable(start_, 4));
            return o;
        }
    };

    inline flatbuffers::Offset<TankAttrChange> CreateTankAttrChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        uint8_t speed = 0,
        uint8_t damage = 0,
        int32_t object = 0)
    {
        TankAttrChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_object(object);
        builder_.add_damage(damage);
        builder_.add_speed(speed);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<TankAttrChange> CreateTankAttrChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        uint8_t speed = 0,
        uint8_t damage = 0,
        int32_t object = 0)
    {
        return CreateTankAttrChange(_fbb, id ? _fbb.CreateString(id) : 0,  speed, damage, object);
    }
//"TankStatusChange",
struct TankStatusChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_PLAYER_ID = 6,
            VT_STATUS = 8
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
        
        const flatbuffers::String *player_id() const { return GetPointer<const flatbuffers::String *>(VT_PLAYER_ID); }

        TankStatus status() const { return static_cast<TankStatus>(GetField<int8_t>(VT_STATUS, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_PLAYER_ID) &&
                verifier.Verify(player_id()) &&
                VerifyField<int8_t>(verifier, VT_STATUS) &&
                verifier.EndTable();
        }
    };

    struct TankStatusChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(TankStatusChange::VT_ID, id); }
        
        void add_player_id(flatbuffers::Offset<flatbuffers::String> player_id) { fbb_.AddOffset(TankStatusChange::VT_PLAYER_ID, player_id); }

        void add_status(TankStatus status) { fbb_.AddElement<int8_t>(TankStatusChange::VT_STATUS, static_cast<int8_t>(status), 0); }

        TankStatusChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        TankStatusChangeBuilder &operator=(const TankStatusChangeBuilder &);

        flatbuffers::Offset<TankStatusChange> Finish()
        {
            auto o = flatbuffers::Offset<TankStatusChange>(fbb_.EndTable(start_, 3));
            return o;
        }
    };

    inline flatbuffers::Offset<TankStatusChange> CreateTankStatusChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        flatbuffers::Offset<flatbuffers::String> player_id = 0,
        TankStatus status=TankStatus_FREE)
    {
        TankStatusChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_player_id(player_id);
        builder_.add_status(status);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<TankStatusChange> CreateTankStatusChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        const char *player_id=nullptr,
        TankStatus status=TankStatus_FREE)
    {
        return CreateTankStatusChange(_fbb, id ? _fbb.CreateString(id) : 0,/*_fbb,*/ player_id ? _fbb.CreateString(player_id) : 0, status);
    }

//PlayerAttrChange",
//    struct PlayerAttrChange FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table
//    {
//        enum
//        {
//            VT_ID = 4,
//            VT_SPEED = 6,
//            VT_DAMAGE = 8,
//            VT_MAXBUBBLE = 10,
//            VT_CURRENTBUBBLE = 12
//        };
//
//        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }
//
//        uint8_t speed() const { return GetField<uint8_t>(VT_SPEED, 0); }
//
//        uint8_t damage() const { return GetField<uint8_t>(VT_DAMAGE, 0); }
//
//        uint8_t maxBubble() const { return GetField<uint8_t>(VT_MAXBUBBLE, 0); }
//
//        uint8_t currentBubble() const { return GetField<uint8_t>(VT_CURRENTBUBBLE, 0); }
//
//        bool Verify(flatbuffers::Verifier &verifier) const
//        {
//            return VerifyTableStart(verifier) &&
//                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
//                verifier.Verify(id()) &&
//                VerifyField<uint8_t>(verifier, VT_SPEED) &&
//                VerifyField<uint8_t>(verifier, VT_DAMAGE) &&
//                VerifyField<uint8_t>(verifier, VT_MAXBUBBLE) &&
//                VerifyField<uint8_t>(verifier, VT_CURRENTBUBBLE) &&
//                verifier.EndTable();
//        }
//    };
//
//    struct PlayerAttrChangeBuilder
//    {
//        flatbuffers::FlatBufferBuilder &fbb_;
//        flatbuffers::uoffset_t start_;
//
//        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(PlayerAttrChange::VT_ID, id); }
//
//        void add_speed(uint8_t speed) { fbb_.AddElement<uint8_t>(PlayerAttrChange::VT_SPEED, speed, 0); }
//
//        void add_damage(uint8_t damage) { fbb_.AddElement<uint8_t>(PlayerAttrChange::VT_DAMAGE, damage, 0); }
//
//        void add_maxBubble(uint8_t maxBubble)
//        {
//            fbb_.AddElement<uint8_t>(PlayerAttrChange::VT_MAXBUBBLE, maxBubble, 0);
//        }
//
//        void add_currentBubble(uint8_t currentBubble)
//        {
//            fbb_.AddElement<uint8_t>(PlayerAttrChange::VT_CURRENTBUBBLE, currentBubble, 0);
//        }
//
//        PlayerAttrChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
//
//        PlayerAttrChangeBuilder &operator=(const PlayerAttrChangeBuilder &);
//
//        flatbuffers::Offset<PlayerAttrChange> Finish()
//        {
//            auto o = flatbuffers::Offset<PlayerAttrChange>(fbb_.EndTable(start_, 5));
//            return o;
//        }
//    };
//
//    inline flatbuffers::Offset<PlayerAttrChange> CreatePlayerAttrChange(flatbuffers::FlatBufferBuilder &_fbb,
//        flatbuffers::Offset<flatbuffers::String> id = 0,
//        uint8_t speed = 0,
//        uint8_t damage = 0,
//        uint8_t maxBubble = 0,
//        uint8_t currentBubble = 0)
//    {
//        PlayerAttrChangeBuilder builder_(_fbb);
//        builder_.add_id(id);
//        builder_.add_currentBubble(currentBubble);
//        builder_.add_maxBubble(maxBubble);
//        builder_.add_damage(damage);
//        builder_.add_speed(speed);
//        return builder_.Finish();
//    }
//
//    inline flatbuffers::Offset<PlayerAttrChange> CreatePlayerAttrChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
//        const char *id = nullptr,
//        uint8_t speed = 0,
//        uint8_t damage = 0,
//        uint8_t maxBubble = 0,
//        uint8_t currentBubble = 0)
//    {
//        return CreatePlayerAttrChange(_fbb, id ? _fbb.CreateString(id) : 0, speed, damage, maxBubble, currentBubble);
//    }
//PlayerStatusChange
    struct PlayerStatusChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_ID = 4,
            VT_STATUS = 6
        };

        const flatbuffers::String *id() const { return GetPointer<const flatbuffers::String *>(VT_ID); }

        PlayerStatus status() const { return static_cast<PlayerStatus>(GetField<int8_t>(VT_STATUS, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_ID) &&
                verifier.Verify(id()) &&
                VerifyField<int8_t>(verifier, VT_STATUS) &&
                verifier.EndTable();
        }
    };

    struct PlayerStatusChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_id(flatbuffers::Offset<flatbuffers::String> id) { fbb_.AddOffset(PlayerStatusChange::VT_ID, id); }

        void add_status(PlayerStatus status)
        {
            fbb_.AddElement<int8_t>(PlayerStatusChange::VT_STATUS, static_cast<int8_t>(status), 0);
        }

        PlayerStatusChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        PlayerStatusChangeBuilder &operator=(const PlayerStatusChangeBuilder &);

        flatbuffers::Offset<PlayerStatusChange> Finish()
        {
            auto o = flatbuffers::Offset<PlayerStatusChange>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<PlayerStatusChange> CreatePlayerStatusChange(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> id = 0,
        PlayerStatus status = PlayerStatus_FREE)
    {
        PlayerStatusChangeBuilder builder_(_fbb);
        builder_.add_id(id);
        builder_.add_status(status);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<PlayerStatusChange> CreatePlayerStatusChangeDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *id = nullptr,
        PlayerStatus status = PlayerStatus_FREE)
    {
        return CreatePlayerStatusChange(_fbb, id ? _fbb.CreateString(id) : 0, status);
    }
//GameStatusChange
    struct GameStatusChange /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_STATUS = 4
        };

        GameStatus status() const { return static_cast<GameStatus>(GetField<int8_t>(VT_STATUS, 0)); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<int8_t>(verifier, VT_STATUS) &&
                verifier.EndTable();
        }
    };

    struct GameStatusChangeBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_status(GameStatus status)
        {
            fbb_.AddElement<int8_t>(GameStatusChange::VT_STATUS, static_cast<int8_t>(status), 0);
        }

        GameStatusChangeBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        GameStatusChangeBuilder &operator=(const GameStatusChangeBuilder &);

        flatbuffers::Offset<GameStatusChange> Finish()
        {
            auto o = flatbuffers::Offset<GameStatusChange>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<GameStatusChange> CreateGameStatusChange(flatbuffers::FlatBufferBuilder &_fbb,
        GameStatus status = GameStatus_WAITING)
    {
        GameStatusChangeBuilder builder_(_fbb);
        builder_.add_status(status);
        return builder_.Finish();
    }
//Chat
    struct Chat /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_TEXT = 4
        };

        const flatbuffers::String *text() const { return GetPointer<const flatbuffers::String *>(VT_TEXT); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_TEXT) &&
                verifier.Verify(text()) &&
                verifier.EndTable();
        }
    };

    struct ChatBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_text(flatbuffers::Offset<flatbuffers::String> text) { fbb_.AddOffset(Chat::VT_TEXT, text); }

        ChatBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        ChatBuilder &operator=(const ChatBuilder &);

        flatbuffers::Offset<Chat> Finish()
        {
            auto o = flatbuffers::Offset<Chat>(fbb_.EndTable(start_, 1));
            return o;
        }
    };

    inline flatbuffers::Offset<Chat> CreateChat(flatbuffers::FlatBufferBuilder &_fbb,
        flatbuffers::Offset<flatbuffers::String> text = 0)
    {
        ChatBuilder builder_(_fbb);
        builder_.add_text(text);
        return builder_.Finish();
    }

    inline flatbuffers::Offset<Chat> CreateChatDirect(flatbuffers::FlatBufferBuilder &_fbb,
        const char *text = nullptr)
    {
        return CreateChat(_fbb, text ? _fbb.CreateString(text) : 0);
    }
///Msg_________________________________________________________________________________________________
    struct Msg /*FLATBUFFERS_FINAL_CLASS*/ : private flatbuffers::Table
    {
        enum
        {
            VT_DATA_TYPE = 4,
            VT_DATA = 6
        };

        MsgType data_type() const { return static_cast<MsgType>(GetField<uint8_t>(VT_DATA_TYPE, 0)); }

        const void *data() const { return GetPointer<const void *>(VT_DATA); }

        bool Verify(flatbuffers::Verifier &verifier) const
        {
            return VerifyTableStart(verifier) &&
                VerifyField<uint8_t>(verifier, VT_DATA_TYPE) &&
                VerifyField<flatbuffers::uoffset_t>(verifier, VT_DATA) &&
                VerifyMsgType(verifier, data(), data_type()) &&
                verifier.EndTable();
        }
    };

    struct MsgBuilder
    {
        flatbuffers::FlatBufferBuilder &fbb_;
        flatbuffers::uoffset_t start_;

        void add_data_type(MsgType data_type)
        {
            fbb_.AddElement<uint8_t>(Msg::VT_DATA_TYPE, static_cast<uint8_t>(data_type), 0);
        }

        void add_data(flatbuffers::Offset<void> data) { fbb_.AddOffset(Msg::VT_DATA, data); }

        MsgBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }

        MsgBuilder &operator=(const MsgBuilder &);

        flatbuffers::Offset<Msg> Finish()
        {
            auto o = flatbuffers::Offset<Msg>(fbb_.EndTable(start_, 2));
            return o;
        }
    };

    inline flatbuffers::Offset<Msg> CreateMsg(flatbuffers::FlatBufferBuilder &_fbb,
        MsgType data_type = MsgType_NONE,
        flatbuffers::Offset<void> data = 0)
    {
        MsgBuilder builder_(_fbb);
        builder_.add_data(data);
        builder_.add_data_type(data_type);
        return builder_.Finish();
    }

    inline bool VerifyMsgType(flatbuffers::Verifier &verifier, const void *union_obj, MsgType type)
    {
        switch (type)
        {
        case MsgType_NONE:
            return true;
        case MsgType_Welcome:
            return verifier.VerifyTable(reinterpret_cast<const Welcome *>(union_obj));
        case MsgType_GotIt:
            return verifier.VerifyTable(reinterpret_cast<const GotIt *>(union_obj));
        case MsgType_JoinRoom:
            return verifier.VerifyTable(reinterpret_cast<const JoinRoom *>(union_obj));
        case MsgType_RoomInfoUpdate:
            return verifier.VerifyTable(reinterpret_cast<const RoomInfoUpdate *>(union_obj));
        case MsgType_UserChangeRole:
            return verifier.VerifyTable(reinterpret_cast<const UserChangeRole *>(union_obj));
        case MsgType_UserChangeStats:
            return verifier.VerifyTable(reinterpret_cast<const UserChangeStats *>(union_obj));
        case MsgType_Chat:
            return verifier.VerifyTable(reinterpret_cast<const Chat *>(union_obj));
        case MsgType_GameInit:
            return verifier.VerifyTable(reinterpret_cast<const GameInit *>(union_obj));
        case MsgType_PlayerPosChange:
            return verifier.VerifyTable(reinterpret_cast<const PlayerPosChange *>(union_obj));
        case MsgType_SelectBuilding:
            return verifier.VerifyTable(reinterpret_cast<const SelectBuilding *>(union_obj));
        case MsgType_BuildingPosChange:
            return verifier.VerifyTable(reinterpret_cast<const BuildingPosChange *>(union_obj));
        case MsgType_BuildingPosSet:
            return verifier.VerifyTable(reinterpret_cast<const BuildingPosSet *>(union_obj));
        case MsgType_BuildingStatusChange:
            return verifier.VerifyTable(reinterpret_cast<const BuildingStatusChange *>(union_obj));
        case MsgType_SelectSoldier:
            return verifier.VerifyTable(reinterpret_cast<const SelectSoldier *>(union_obj));
        case MsgType_SoldierPosChange:
            return verifier.VerifyTable(reinterpret_cast<const SoldierPosChange *>(union_obj));
        case MsgType_SoldierAttrChange:
            return verifier.VerifyTable(reinterpret_cast<const SoldierAttrChange *>(union_obj));
        case MsgType_SoldierStatusChange:
            return verifier.VerifyTable(reinterpret_cast<const SoldierStatusChange *>(union_obj));
        case MsgType_BuildSoldier:
            return verifier.VerifyTable(reinterpret_cast<const BuildSoldier *>(union_obj));
        case MsgType_BuildTank:
            return verifier.VerifyTable(reinterpret_cast<const BuildTank *>(union_obj));
        case MsgType_SelectTank:
            return verifier.VerifyTable(reinterpret_cast<const SelectTank *>(union_obj));
        case MsgType_TankPosChange:
            return verifier.VerifyTable(reinterpret_cast<const TankPosChange *>(union_obj));
        case MsgType_TankAttrChange:
            return verifier.VerifyTable(reinterpret_cast<const TankAttrChange *>(union_obj));
        case MsgType_TankStatusChange:
            return verifier.VerifyTable(reinterpret_cast<const TankStatusChange *>(union_obj));
//        case MsgType_PlayerSetBubble:
//            return verifier.VerifyTable(reinterpret_cast<const PlayerSetBubble *>(union_obj));
//        case MsgType_BubbleSet:
//            return verifier.VerifyTable(reinterpret_cast<const BubbleSet *>(union_obj));
//        case MsgType_BubbleBoom:
//            return verifier.VerifyTable(reinterpret_cast<const BubbleBoom *>(union_obj));
//        case MsgType_PropSet:
//            return verifier.VerifyTable(reinterpret_cast<const PropSet *>(union_obj));
//        case MsgType_PlayerEatProp:
//            return verifier.VerifyTable(reinterpret_cast<const PlayerEatProp *>(union_obj));
//        case MsgType_PlayerAttrChange:
//            return verifier.VerifyTable(reinterpret_cast<const PlayerAttrChange *>(union_obj));
        case MsgType_PlayerStatusChange:
            return verifier.VerifyTable(reinterpret_cast<const PlayerStatusChange *>(union_obj));
        case MsgType_GameStatusChange:
            return verifier.VerifyTable(reinterpret_cast<const GameStatusChange *>(union_obj));
        default:
            return false;
        }
    }

    inline const API::Msg *GetMsg(const void *buf)
    {
        return flatbuffers::GetRoot<API::Msg>(buf);
    }

    inline bool VerifyMsgBuffer(flatbuffers::Verifier &verifier)
    {
		return verifier.VerifyBuffer<API::Msg>();
    }

    inline void FinishMsgBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<API::Msg> root)
    {
        fbb.Finish(root);
    }

}  // namespace API

#endif  // FLATBUFFERS_GENERATED_API_API_H_
