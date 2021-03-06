#include "StdAfx.h"
#include "ZConst.h"
#include "ZScriptManager.h"


int				ZConst::GAME_SERVER_DYNAMIC_FIELD_COUNT_LIMIT = 200;	///< 게임 서버에 생성할 수 있는 동적필드의 최대 개수
int				ZConst::GAME_SERVER_PLAYER_COUNT_LIMIT = 1000;			///< 게임 서버에 접속할 수 있는 플레이어의 최대 개수

int				ZConst::FITNESS_ADDITIONAL_VALUE_TO_ALLOC_FIELD = 10;	///< 동적 필드를 할당할 서버를 고를 때 특정 서버에게 주는 가산점
float			ZConst::TIME_UPDATE_CHANNEL_BEHOLDER_SEC = 1.0f;		///< ChannelBeholder 의 업데이트 주기 (초)
unsigned int	ZConst::TICK_EXPIRE_SILENT_CHANNEL = 300000;			///< ChannelBeholder 에서 사용하지 않는 채널을 제거하기까지 대기 시간 (ms)
int				ZConst::RATIO_CHANNEL_CROWD_FOR_NEW_CHANNEL = 90;		///< 모든 채널이 몇% 이상 포화상태이면 새로운 채널을 만들지에 대한 비율

bool			ZConst::SHOW_LUA_ERROR_LOG					= false;
bool			ZConst::ALLOC_DYNAMIC_SERVER_ANOTHER_SERVER	= false;

bool			ZConst::DEBUG_CONSOLE_SHOW_GAMETICK = false;
int				ZConst::DEBUG_CONSOLE_GAMETICK_TICK = 60;

bool			ZConst::INCLUDE_DEV_FIELD_LIST = false;
bool			ZConst::INSERT_WORLD_INFO = false;

#define GET_LUA_VAR(RETTYPE, NAME, VAR)		if (WLUA->IsExistGlobal(NAME)) VAR = WLUA->GetVar<RETTYPE>(NAME)

void ZConst::Init()
{
	GET_LUA_VAR(int,			"GAME_SERVER_DYNAMIC_FIELD_COUNT_LIMIT",	GAME_SERVER_DYNAMIC_FIELD_COUNT_LIMIT);
	GET_LUA_VAR(int,			"GAME_SERVER_PLAYER_COUNT_LIMIT",			GAME_SERVER_PLAYER_COUNT_LIMIT);

	GET_LUA_VAR(int,			"FITNESS_ADDITIONAL_VALUE_TO_ALLOC_FIELD",	FITNESS_ADDITIONAL_VALUE_TO_ALLOC_FIELD);
	GET_LUA_VAR(float,			"TIME_UPDATE_CHANNEL_BEHOLDER_SEC",			TIME_UPDATE_CHANNEL_BEHOLDER_SEC);
	GET_LUA_VAR(unsigned int,	"TICK_EXPIRE_SILENT_CHANNEL",				TICK_EXPIRE_SILENT_CHANNEL);
	GET_LUA_VAR(int,			"RATIO_CHANNEL_CROWD_FOR_NEW_CHANNEL",		RATIO_CHANNEL_CROWD_FOR_NEW_CHANNEL);

	GET_LUA_VAR(bool,			"INCLUDE_DEV_FIELD_LIST",					INCLUDE_DEV_FIELD_LIST);

	GET_LUA_VAR(bool,			"INSERT_WORLD_INFO",						INSERT_WORLD_INFO);

	/// 디버그용 ------------------------------------------------------------------

	GET_LUA_VAR(bool,			"SHOW_LUA_ERROR_LOG",						SHOW_LUA_ERROR_LOG);
	GET_LUA_VAR(bool,			"ALLOC_DYNAMIC_SERVER_ANOTHER_SERVER",		ALLOC_DYNAMIC_SERVER_ANOTHER_SERVER);

	GET_LUA_VAR(bool,			"DEBUG_CONSOLE_SHOW_GAMETICK",				DEBUG_CONSOLE_SHOW_GAMETICK);
	GET_LUA_VAR(int,			"DEBUG_CONSOLE_GAMETICK_TICK",				DEBUG_CONSOLE_GAMETICK_TICK);
}
