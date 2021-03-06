#ifndef _XPOST_GUILD_H
#define _XPOST_GUILD_H

#include "XNetClient.h"
#include "XCommandTable.h"

// 길드 생성
inline void XPostGuild_Create(const wchar_t* szName)
{
	XPOSTCMD1(MC_GUILD_CREATE_REQ, MCommandParameterWideString(szName));
}

// 길드 초대 요청
inline void XPostGuild_Invite_Req(const MUID& uidGuest)
{
	XPOSTCMD1(MC_GUILD_INVITE_REQ, MCommandParameterUID(uidGuest));
}

// 길드 초대 응답
inline void XPostGuild_Invite_Res(bool bAccept)
{
	XPOSTCMD1(MC_GUILD_INVITE_RES, MCommandParameterBool(bAccept));
}

// 길드 탈퇴
inline void XPostGuild_Leave()
{
	XPOSTCMD0(MC_GUILD_LEAVE_REQ);
}

// 길드 강퇴
inline void XPostGuild_Kick(const wchar_t* szTargetName)
{
	XPOSTCMD1(MC_GUILD_KICK_REQ, MCommandParameterWideString(szTargetName));
}

// 길드 해체
inline void XPostGuild_Destroy()
{
	XPOSTCMD0(MC_GUILD_DESTROY_REQ);
}

// 길마 변경
inline void XPostGuild_ChangeMaster(const wchar_t* szNewMasterName)
{
	XPOSTCMD1(MC_GUILD_CHANGE_MASTER_REQ, MCommandParameterWideString(szNewMasterName));
}

// 길드 보관함 입금 요청
inline void XPostGuild_DepositStorageMoney(int nMoney)
{
	XPOSTCMD1(MC_GUILD_DEPOSIT_STORAGEMONEY_REQ, MCommandParameterInt(nMoney));
}

// 길드 보관함 춫금 요청
inline void XPostGuild_WithdrawStorageMoney(int nMoney)
{
	XPOSTCMD1(MC_GUILD_WITHDRAW_STORAGEMONEY_REQ, MCommandParameterInt(nMoney));
}

#endif