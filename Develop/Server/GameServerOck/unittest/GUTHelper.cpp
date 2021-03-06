#include "stdafx.h"
#include "GUTHelper.h"
#include "GItemManager.h"
#include "GNPCInfoMgr.h"
#include "SUnitTestUtil.h"
#include "MockField.h"
#include "MockServer.h"
#include "GEntityPlayer.h"
#include "GEntityNPC.h"
#include "GModuleCombat.h"
#include "GDialogInfoMgr.h"
#include "GConditionsInfo.h"
#include "GConditionsInfoMgr.h"
#include "GItemConditionsInfoMgr.h"
#include "GQuestSystem.h"
#include "GPartySystem.h"
#include "GParty.h"
#include "GCmdHandler_Quest.h"
#include "CCommandTable.h"
#include "GLootInfo.h"
#include "GLootInfoMgr.h"
#include "GConditionInfo.h"
#include "GCraftInfo.h"
#include "GCraftInfoMgr.h"
#include "GRecipeInfo.h"
#include "GRecipeInfoMgr.h"
#include "GInnRoomInfoMgr.h"
#include "GInnRoomInfo.h"
#include "GGuild.h"
#include "GGuildMgr.h"
#include "GPlayerTalent.h"
#include "GTalentInfoMgr.h"
#include "GPlayerObjectManager.h"
#include "GQuestInfoMgr.h"
#include "MockLink.h"
#include "MockNetServer.h"
#include "GCommandCenter.h"
#include "GPlayerObjectManager.h"
#include "MockPlayerObject.h"
#include "MockEntityNPC.h"
#include "GSoulBindingInfo.h"
#include "GSoulBindingInfoMgr.h"
#include "GFieldInfoMgr.h"
#include "GFieldMgr.h"
#include "GPlayerQuests.h"
#include "GPlayerQuest.h"
#include "GDialogInfo.h"
#include "GPlayerField.h"
#include "GFieldFactory.h"
#include "GFactionInfoMgr.h"
#include "GFactionRelationInfoMgr.h"
#include "GPlayerFieldDynamic.h"
#include "GItemEquiper.h"
#include "GUTHelper_Item.h"
#include "GTestForward.h"
#include "GItemAdder.h"
#include "GItemHolder.h"
#include "CSBasicAttributeCalculator.h"

void GUTHelper::SetMeleeTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_nTiming = TC_HIT_TALENT;
	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_HITCAPSULE;
	pTalentInfo->m_EffectInfo.m_nRelation = CSEffectInfo::RELATION_ALL;
	pTalentInfo->m_nCategory = TC_MELEE;
	pTalentInfo->m_nSkillType = ST_MELEE;
	pTalentInfo->m_nDodgeDifficulty = 255;
	pTalentInfo->m_Resist.m_nDifficulty = 255;
	pTalentInfo->m_bCriticalEnable = false;
	pTalentInfo->m_fWeaponApplyRate = 1.0f;
	pTalentInfo->m_bNeedTraining = false;
}

void GUTHelper::SetPassiveTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_nSkillType = ST_PASSIVE;
	pTalentInfo->m_nTalentLine = nID;
	pTalentInfo->m_bNeedTraining = false;
}

void GUTHelper::SetArcheryTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_TARGET;
	pTalentInfo->m_EffectInfo.m_nRelation = CSEffectInfo::RELATION_ALL;
	pTalentInfo->m_nCategory = TC_RANGE;
	pTalentInfo->m_nSkillType = ST_ARCHERY;
	pTalentInfo->m_fCastingTime = 0.0f;
	pTalentInfo->m_nDodgeDifficulty = 255;
	pTalentInfo->m_Resist.m_nDifficulty = 255;
	pTalentInfo->m_bCriticalEnable = false;
	pTalentInfo->m_bNeedTraining = false;
}

void GUTHelper::SetMagicTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_nCategory = TC_MAGIC;
	pTalentInfo->m_nTalentType = TT_SKILL;
	pTalentInfo->m_nSkillType = ST_MAGIC;
	pTalentInfo->m_fCastingTime = 0.0f;
	pTalentInfo->m_fHitDelay = 0.0f;
	pTalentInfo->m_nDodgeDifficulty = 255;
	pTalentInfo->m_Resist.m_nDifficulty = 255;
	pTalentInfo->m_bCriticalEnable = false;

	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_SELF;
	pTalentInfo->m_EffectInfo.m_nRelation = CSEffectInfo::RELATION_ALL;
	pTalentInfo->m_bNeedTraining = false;
}

void GUTHelper::SetMagicMissileTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	SetMagicTalentInfo(pTalentInfo, nID);

	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_TARGET;	
}

void GUTHelper::SetMagicTargetTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	SetMagicTalentInfo(pTalentInfo, nID);

	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_TARGET;
}

void GUTHelper::SetMagicAreaTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	SetMagicTalentInfo(pTalentInfo, nID);

	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_HITCAPSULE;
}

void GUTHelper::SetBuffTalentInfo( GTalentInfo* pTalentInfo, int nID )
{
	SetMagicTalentInfo(pTalentInfo, nID);

	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_SELF;
}

void GUTHelper::SetBuffInfo( GBuffInfo* pInfo, int nID )
{
	pInfo->m_nID = nID;
}

void GUTHelper::SetExtraPassiveTalentInfo( GTalentInfo* pTalentInfo, int nID, TALENT_EXTRA_PASSIVE_TYPE nExtraPassiveType )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_nTalentType = TT_SKILL;
	pTalentInfo->m_nSkillType = ST_EXTRA_PASSIVE;
	pTalentInfo->m_nExtraPassive = nExtraPassiveType;
	pTalentInfo->m_nExtraPassiveParam = 1;
}

void GUTHelper::SetExtraActiveTalentInfo( GTalentInfo* pTalentInfo, int nID, TALENT_EXTRA_ACTIVE_TYPE nExtraActiveType )
{
	pTalentInfo->m_nID = nID;
	pTalentInfo->m_nTalentType = TT_SKILL;
	pTalentInfo->m_nSkillType = ST_EXTRA_ACTIVE;
	pTalentInfo->m_nExtraActive = nExtraActiveType;
}

void GUTHelper::AddTalentEventInfo( GTalentInfo* pTalentInfo, TALENT_EVENT nEvent, float fTime )
{
	CSTalentEventInfo eventinfo;
	eventinfo.m_nEvent = nEvent;
	eventinfo.m_fTime1 = fTime;
	pTalentInfo->m_Events.m_vecEvents.push_back(eventinfo);
}

void GUTHelper::AddTalentActEventInfo( GTalentInfo* pTalentInfo, TALENT_EVENT nEvent, float fTime )
{
	CSTalentEventInfo eventinfo;
	eventinfo.m_nEvent = nEvent;
	eventinfo.m_fTime1 = fTime;
	pTalentInfo->m_Events.m_vecActEvents.push_back(eventinfo);
}

GTalentInfo* GUTHelper::NewTalentInfo(int nID, int nTalentLine, int8 nRank)
{
	if (0 == nID) nID = SUnitTestUtil::NewID();

	GTalentInfo* pNewTalentInfo = new GTalentInfo();
	pNewTalentInfo->m_nID = nID;
	pNewTalentInfo->m_nTalentLine = nTalentLine;
	pNewTalentInfo->m_nRank = nRank;
	pNewTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_SELF;
	pNewTalentInfo->m_EffectInfo.m_nRelation = CSEffectInfo::RELATION_ALL;
	pNewTalentInfo->m_bNeedTraining = false;

	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);

	return pNewTalentInfo;
}

GTalentInfo* GUTHelper::NewMeleeTalentInfo(int nID)
{
	if (0 == nID) nID = SUnitTestUtil::NewID();

	GTalentInfo* pNewTalentInfo = new GTalentInfo();
	SetMeleeTalentInfo(pNewTalentInfo, nID);

	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);

	return pNewTalentInfo;
}

GTalentInfo* GUTHelper::NewPassiveTalentInfo( int nID )
{
	GTalentInfo* pNewTalentInfo = new GTalentInfo();
	SetPassiveTalentInfo(pNewTalentInfo, nID);

	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);

	return pNewTalentInfo;
}

GTalentInfo* GUTHelper::NewArcheryTalentInfo( int nID )
{
	GTalentInfo* pNewTalentInfo = new GTalentInfo();
	SetArcheryTalentInfo(pNewTalentInfo, nID);
	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);
	return pNewTalentInfo;
}

GBuffInfo* GUTHelper::NewBuffInfo( int nID )
{
	GBuffInfo* pNewBuffInfo = new GBuffInfo();
	SetBuffInfo(pNewBuffInfo, nID);
	gmgr.pBuffInfoMgr->Insert(pNewBuffInfo);
	return pNewBuffInfo;
}

GTalentInfo* GUTHelper::NewBuffTalentInfo( int nID )
{
	GTalentInfo* pNewTalentInfo = new GTalentInfo();
	SetBuffTalentInfo(pNewTalentInfo, nID);
	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);
	return pNewTalentInfo;
}

GTalentInfo* GUTHelper::NewMagicTalentInfo( int nID )
{
	if (0 == nID) nID = SUnitTestUtil::NewID();

	GTalentInfo* pNewTalentInfo = new GTalentInfo();

	pNewTalentInfo->m_nID = nID;
	pNewTalentInfo->m_nCategory = TC_MAGIC;
	pNewTalentInfo->m_nTalentType = TT_SKILL;
	pNewTalentInfo->m_nSkillType = ST_MAGIC;
	pNewTalentInfo->m_fCastingTime = 0.0f;
	pNewTalentInfo->m_fHitDelay = 0.0f;
	pNewTalentInfo->m_nDodgeDifficulty = 255;
	pNewTalentInfo->m_Resist.m_nDifficulty = 255;
	pNewTalentInfo->m_bCriticalEnable = false;
	gmgr.pTalentInfoMgr->Insert(pNewTalentInfo);

	return pNewTalentInfo;
}

GTalentInfo* GUTHelper::NewItemTalentInfo(int nID)
{
	GTalentInfo* pTalentInfo = NewTalentInfo(nID);
	if (NULL == pTalentInfo) return NULL;

	pTalentInfo->m_nSkillType = ST_ITEM;
	pTalentInfo->m_nRank = 1;
	pTalentInfo->m_nTalentType = TT_SKILL;
	pTalentInfo->m_nCategory = TC_COMMON;
	pTalentInfo->m_nTiming = TC_HIT_TALENT;
	pTalentInfo->m_EffectInfo.m_nPoint = CSEffectInfo::POINT_SELF;
	pTalentInfo->m_nEnabledStanceFlag = 0xFFFFFFFF;
	
	return pTalentInfo;
}

void GUTHelper::SetTalentDamage( GTalentInfo* pTalentInfo, int nDamage )
{
	pTalentInfo->m_nMinDamage = pTalentInfo->m_nMaxDamage = nDamage;
	pTalentInfo->m_fWeaponApplyRate = 0.0f;
}

void GUTHelper::AddSimpleHitInfo( GTalentInfo* pTalentInfo, float fCheckTime/*=0.0f*/ )
{
	// 캡슐은 적당히 큰 값
	MCapsule hit_cap = MCapsule(vec3(0.0f, 0.0f, -10000.0f), vec3(0.0f, 0.0f, 10000.0f), 5000.0f);
	CSHitSegment hit_seg;
	hit_seg.m_vCapsules.push_back(hit_cap);
	hit_seg.m_vDoHitCheck.push_back(true);
	hit_seg.m_fCheckTime = fCheckTime;

	int id = (int)pTalentInfo->m_HitInfo.m_vSegments.size() + 1;
	pTalentInfo->m_HitInfo.m_nID = id;
	pTalentInfo->m_HitInfo.m_vSegments.push_back(hit_seg);
	pTalentInfo->Cooking();
}

void GUTHelper::AddHitInfo( GTalentInfo* pTalentInfo, vec3 vCapsuleBottomPos, vec3 vCapsuleTopPos, float fCapsuleRadius, float fCheckTime/*=0.0f */ )
{
	// 캡슐은 적당히 큰 값
	MCapsule hit_cap = MCapsule(vCapsuleBottomPos, vCapsuleTopPos, fCapsuleRadius);
	CSHitSegment hit_seg;
	hit_seg.m_vCapsules.push_back(hit_cap);
	hit_seg.m_vDoHitCheck.push_back(true);
	hit_seg.m_fCheckTime = fCheckTime;

	int id = (int)pTalentInfo->m_HitInfo.m_vSegments.size() + 1;
	pTalentInfo->m_HitInfo.m_nID = id;
	pTalentInfo->m_HitInfo.m_vSegments.push_back(hit_seg);
	pTalentInfo->Cooking();
}

void GUTHelper::InsertTalentInfoToMgr( GTalentInfo* pTalentInfo )
{
	pTalentInfo->Cooking();
	size_t nOldQty = gmgr.pTalentInfoMgr->size();
	gmgr.pTalentInfoMgr->insert(GTalentInfoMgr::value_type(pTalentInfo->m_nID, pTalentInfo));
	VALID(nOldQty != gmgr.pTalentInfoMgr->size());
}

GEntityPlayer* GUTHelper::NewEntityPlayer( GField* pField, vec3 pos, MUID uidNew, MARKER_INFO markerExit)
{
	if (uidNew.IsInvalid()) 
	{
		uidNew = SUnitTestUtil::NewUID();
	}

	GEntityPlayer* pNewEntityPlayer = new GEntityPlayer();
	pNewEntityPlayer->Create(uidNew);

	if (markerExit.nID != 0)
	{
		pNewEntityPlayer->GetPlayerField().GetFieldDynamic().SetEnterPos(markerExit);
	}

	if (NULL != pField)
	{
		pNewEntityPlayer->EnterToField(pField, pos);
	}
	
	pNewEntityPlayer->GetChrInfo()->nMaxHP = 10000;
	pNewEntityPlayer->GetChrInfo()->nMaxEN = 10000;
	pNewEntityPlayer->GetChrInfo()->nMaxSTA = 10000;
	pNewEntityPlayer->GetChrInfo()->fSpeed = 100;
	pNewEntityPlayer->GetPlayerInfo()->nCID = SUnitTestUtil::NewCID();
	pNewEntityPlayer->SetHP(pNewEntityPlayer->GetMaxHP());
	pNewEntityPlayer->SetEN(pNewEntityPlayer->GetMaxEN());
	pNewEntityPlayer->SetSTA(pNewEntityPlayer->GetMaxSTA());
	pNewEntityPlayer->SetDir(vec3(0,1,0));

	// 능력치에 의한 보너스/패널티 0
	pNewEntityPlayer->GetPlayerInfo()->nSTR = 100;
	pNewEntityPlayer->GetPlayerInfo()->nDEX = 100;
	pNewEntityPlayer->GetPlayerInfo()->nINT = 100;
	pNewEntityPlayer->GetPlayerInfo()->nCON = 100;
	pNewEntityPlayer->GetPlayerInfo()->nCHA = 100;


	wstring strName = SUnitTestUtil::NewName();
	wcsncpy_s(pNewEntityPlayer->GetPlayerInfo()->szName, strName.c_str(), strName.length());

	pNewEntityPlayer->SetRegenActive(false);
	pNewEntityPlayer->SetTimeSynchorActive(false);

	MUID uidPlayer = pNewEntityPlayer->GetUID();
	MockPlayerObject* pMockPlayerObject = new MockPlayerObject(uidPlayer);
	gmgr.pPlayerObjectManager->AddPlayer(pMockPlayerObject);
	pMockPlayerObject->Create(pNewEntityPlayer);	
	gmgr.pPlayerObjectManager->AddCID(pMockPlayerObject);	

	pMockPlayerObject->OnStartGame();

	return pNewEntityPlayer;
}

GEntityPlayer* GUTHelper::NewEntityPlayerForGameData( GField* pField, vec3 pos, MUID uidNew, MARKER_INFO markerExit)
{
	if (uidNew.IsInvalid()) 
	{
		uidNew = SUnitTestUtil::NewUID();
	}

	GEntityPlayer* pNewEntityPlayer = new GEntityPlayer();
	pNewEntityPlayer->Create(uidNew);

	if (markerExit.nID != 0)
	{
		pNewEntityPlayer->GetPlayerField().GetFieldDynamic().SetEnterPos(markerExit);
	}

	if (NULL != pField)
	{
		pNewEntityPlayer->EnterToField(pField, pos);
	}	

	
	PLAYER_INFO* pInfo = pNewEntityPlayer->GetPlayerInfo();
	pInfo->nSTR		= PLAYER_DEFAULT_STR;
	pInfo->nDEX		= PLAYER_DEFAULT_DEX;
	pInfo->nINT		= PLAYER_DEFAULT_INT;
	pInfo->nCHA		= PLAYER_DEFAULT_CHA;
	pInfo->nCON		= PLAYER_DEFAULT_CON;
	pInfo->nMaxHP		= CSBasicAttributeCalculator::CalcMaxHP(pInfo->nLevel, pNewEntityPlayer->GetCON());
	pInfo->nMaxEN		= CSBasicAttributeCalculator::CalcMaxEN(pInfo->nLevel, pNewEntityPlayer->GetINT());
	pInfo->nMaxSTA	= CSBasicAttributeCalculator::CalcMaxSP(pInfo->nLevel, pNewEntityPlayer->GetDEX());


	pNewEntityPlayer->GetChrInfo()->fSpeed = 100;
	pNewEntityPlayer->GetPlayerInfo()->nCID = SUnitTestUtil::NewCID();
	pNewEntityPlayer->SetHP(pNewEntityPlayer->GetMaxHP());
	pNewEntityPlayer->SetEN(pNewEntityPlayer->GetMaxEN());
	pNewEntityPlayer->SetSTA(pNewEntityPlayer->GetMaxSTA());
	pNewEntityPlayer->SetDir(vec3(0,1,0));


	wstring strName = SUnitTestUtil::NewName();
	wcsncpy_s(pNewEntityPlayer->GetPlayerInfo()->szName, strName.c_str(), strName.length());

	pNewEntityPlayer->SetRegenActive(false);
	pNewEntityPlayer->SetTimeSynchorActive(false);

	MUID uidPlayer = pNewEntityPlayer->GetUID();
	MockPlayerObject* pMockPlayerObject = new MockPlayerObject(uidPlayer);
	gmgr.pPlayerObjectManager->AddPlayer(pMockPlayerObject);
	pMockPlayerObject->Create(pNewEntityPlayer);
	gmgr.pPlayerObjectManager->AddCID(pMockPlayerObject);	

	return pNewEntityPlayer;
}


MockPlayerObject* GUTHelper::NewMockPlayerObject(GField* pField, vec3 pos, MUID uidNew)
{
	if (uidNew == MUID(0,0)) uidNew = SUnitTestUtil::NewUID();

	MockPlayerObject* pNewPlayerObject = new MockPlayerObject(SUnitTestUtil::NewUID());
	pNewPlayerObject->Create();
	gmgr.pPlayerObjectManager->AddPlayer(pNewPlayerObject);
	gmgr.pPlayerObjectManager->AddCID(pNewPlayerObject);

	GEntityPlayer* pEntityPlayer = pNewPlayerObject->GetEntity();
	if (NULL == pEntityPlayer) return NULL;

	pEntityPlayer->EnterToField(pField, pos);
	pEntityPlayer->GetChrInfo()->nMaxHP = 10000;
	pEntityPlayer->GetChrInfo()->nMaxEN = 10000;
	pEntityPlayer->GetChrInfo()->nMaxSTA = 10000;
	pEntityPlayer->GetChrInfo()->fSpeed = 100;
	pEntityPlayer->GetPlayerInfo()->nCID = SUnitTestUtil::NewCID();
	pEntityPlayer->SetHP(pEntityPlayer->GetMaxHP());
	pEntityPlayer->SetEN(pEntityPlayer->GetMaxEN());
	pEntityPlayer->SetSTA(pEntityPlayer->GetMaxSTA());

	pEntityPlayer->SetRegenActive(false);
	pEntityPlayer->SetTimeSynchorActive(false);

	return pNewPlayerObject;
}

void GUTHelper::SetEntityPlayerStatus( GEntityPlayer* pEntityPlayer, int nHP, int nEN, int nSTA )
{
	PLAYER_INFO* player_info = pEntityPlayer->GetPlayerInfo();
	player_info->nMaxHP = nHP;
	player_info->nMaxEN = nEN;
	player_info->nMaxSTA = nSTA;

	pEntityPlayer->SetHP(nHP);
	pEntityPlayer->SetEN(nEN);
	pEntityPlayer->SetSTA(nSTA);
}

GNPCInfo* GUTHelper::NewNPCInfo(int nNPCId)
{
	if (0 == nNPCId)
	{
		nNPCId = SUnitTestUtil::NewID();
	}

	GNPCInfo* pNPCInfo = new GNPCInfo();
	pNPCInfo->nID = nNPCId;
	pNPCInfo->fSpeed = 100;
	pNPCInfo->fRunSpeed = 300;

	gmgr.pNPCInfoMgr->Insert(pNPCInfo);

	return pNPCInfo;
}

void GUTHelper::InsertBuffInfoToMgr( GBuffInfo* pInfo )
{
	if (gmgr.pBuffInfoMgr->find(pInfo->m_nID) != gmgr.pBuffInfoMgr->end())
	{
		gmgr.pBuffInfoMgr->erase(pInfo->m_nID);
	}

	gmgr.pBuffInfoMgr->insert(GBuffInfoMgr::value_type(pInfo->m_nID, pInfo));
}

void GUTHelper::EquipSword_ForTS2( GEntityPlayer* pEntityPlayer )
{
	const int SWORD_ITEM_ID = 1;

	GItemData* pItemData = test.item.NewWeaponItemData(SWORD_ITEM_ID, WEAPON_1H_SLASH);
	if (NULL == pItemData) return;

	EquipNewItem(pEntityPlayer, pItemData->m_nID, ITEMSLOT_RWEAPON);
}

bool GUTHelper::LearnTalent_ForTS2(GEntityPlayer* pEntityPlayer, int nTalentID)
{
	_ASSERT(pEntityPlayer);
	_ASSERT(nTalentID != INVALID_TALENT_ID);
	if (!pEntityPlayer)						return false;
	if (nTalentID == INVALID_TALENT_ID)		return false;

	GTalentInfo* pTalentInfo = gmgr.pTalentInfoMgr->Find(nTalentID);
	if (pTalentInfo == NULL)				return false;

	pTalentInfo->m_bNeedTraining = true;

	pEntityPlayer->GetTalent().Insert(pTalentInfo);

	return true;
}

void GUTHelper::NewTalentAndBuff( int nTalentID, int nBuffID, GTalentInfo*& pTalentinfo, GBuffInfo*& pBuffInfo )
{
	pBuffInfo = NewBuffInfo(nBuffID);

	pTalentinfo = NewBuffTalentInfo(nTalentID);
	pTalentinfo->m_Buff1.nID = nBuffID;
	pTalentinfo->m_Buff1.nEnchantEvent = TC_USE_TALENT;
	pTalentinfo->m_Buff1.EffectInfo.m_nPoint = CSEffectInfo::POINT_TARGET;

	InsertBuffInfoToMgr(pBuffInfo);
}

GTalentInfo* GUTHelper::NewGuardTalentInfo(int nID)
{
	GTalentInfo* pNewTalentInfo = NewTalentInfo(nID);
	pNewTalentInfo->m_nSkillType = ST_GUARD;
	pNewTalentInfo->m_nTiming = TC_GUARD_ME;
	pNewTalentInfo->m_nGuardDirection = GUARD_DIRECTION_ALL;

	return pNewTalentInfo;
}

GItemData* GUTHelper::NewItemData(int nID)
{
	return GUTHelper_Item::NewItemData(nID);
}

GItemData* GUTHelper::NewItemData(SH_ITEM_SLOT nSlot, int nID)
{	
	return GUTHelper_Item::NewItemData(nID, nSlot);
}

GItem* GUTHelper::MakeItem(int nItemID, int nAmount)
{	
	return GUTHelper_Item::NewItem(nItemID, nAmount);
}

GItem* GUTHelper::GiveNewItem(GEntityPlayer* pPlayer, int nItemID, int nItemQuantity)
{
	return GUTHelper_Item::GiveNewItem(pPlayer, nItemID, nItemQuantity);	
}

GItem* GUTHelper::EquipNewItem(GEntityPlayer* pPlayer, int nItemID, SH_ITEM_SLOT nItemSlot)
{
	return GUTHelper_Item::EquipNewItem(pPlayer, nItemID, nItemSlot);	
}

void GUTHelper::EquipItem( GEntityPlayer* pPlayer, GItem* pItem, SH_ITEM_SLOT nSlot )
{
	GUTHelper_Item::EquipItem(pPlayer, pItem, nSlot);	
}

GConditionsInfo* GUTHelper::NewConditionsInfo(int nID)
{
	GConditionsInfo* pNewConditionsInfo = new GConditionsInfo();
	pNewConditionsInfo->Create();
	if (nID != INVALID_ID)
	{
		pNewConditionsInfo->m_nID = nID;
	}
	else
	{
		pNewConditionsInfo->m_nID = SUnitTestUtil::NewID();
	}
	

	gmgr.pCondtionsInfoMgr->Insert(pNewConditionsInfo);

	return pNewConditionsInfo;
}

GConditionsInfo* GUTHelper::NewConditionsInfo_Item()
{
	GConditionsInfo* pNewConditionsInfo = new GConditionsInfo();
	pNewConditionsInfo->Create();
	pNewConditionsInfo->m_nID = SUnitTestUtil::NewID();

	gmgr.pItemConditionsInfoMgr->Insert(pNewConditionsInfo);

	return pNewConditionsInfo;
}

GConditionsInfo* GUTHelper::NewConditionsInfoForLevel(int nMinLevel, int nMaxLevel)
{
	GConditionsInfo* pNewConditionsInfo = NewConditionsInfo();
	GCondition_Leaf* pNewConditionInfo = NewConditionInfoForLevel(pNewConditionsInfo, nMinLevel, nMaxLevel);

	return pNewConditionsInfo;	
}

GCondition_Leaf* GUTHelper::NewConditionLeaf(GConditionsInfo* pConditionsInfo)
{
	if (NULL == pConditionsInfo) return NULL;

	GCondition_Leaf* pNewConditionInfo = new GCondition_Leaf();
	pConditionsInfo->m_pConditionComposite->m_vecConditionComponent.push_back(pNewConditionInfo);

	return pNewConditionInfo;
}

GCondition_Leaf* GUTHelper::NewConditionInfoForLevel(GConditionsInfo* pConditionsInfo, int nMinLevel, int nMaxLevel)
{
	if (NULL == pConditionsInfo) return NULL;

	GCondition_Leaf* pNewConditionInfo = NewConditionLeaf(pConditionsInfo);

	pNewConditionInfo->m_nCT = CT_LEVEL;
	pNewConditionInfo->m_vecParam1.push_back(nMinLevel);
	pNewConditionInfo->m_vecParam2.push_back(nMaxLevel);

	return pNewConditionInfo;
}

GCraftInfo* GUTHelper::NewCraftInfo()
{
	GCraftInfo* pNewInfo = gmgr.pCraftInfoMgr->New();
	if (NULL == pNewInfo) return NULL;

	pNewInfo->m_nID = SUnitTestUtil::NewID();
	gmgr.pCraftInfoMgr->Insert(pNewInfo);

	GDialogInfo* pNewDialogInfo = test.dialog.NewDialogInfo();
	pNewInfo->m_nDialogID = pNewDialogInfo->m_nID;

	return pNewInfo;
}

GRecipeInfo* GUTHelper::NewRecipeInfo()
{
	GRecipeInfo* pNewInfo = static_cast<GRecipeInfo*>(gmgr.pRecipeInfoMgr->New());
	if (NULL == pNewInfo) return NULL;

	pNewInfo->m_nID = SUnitTestUtil::NewID();
	gmgr.pRecipeInfoMgr->Insert(pNewInfo);

	return pNewInfo;
}

GInnRoomInfo* GUTHelper::NewInnRoomInfo()
{
	GInnRoomInfo* pNewInfo = gmgr.pInnRoomInfoMgr->NewInfo();
	if (NULL == pNewInfo) return NULL;

	pNewInfo->m_nID = SUnitTestUtil::NewID();
	gmgr.pInnRoomInfoMgr->Insert(pNewInfo);

	return pNewInfo;
}

GColtCheck* GUTHelper::GiveNewCheckInfo(GEntityNPC* pNPC, COLT_CHECK_TYPE nType, int nParam1, int nParam2, int nParam3, bool bInsertDummyAction)
{
	GColtCheck* pNewInfo = NewCheckInfo(nType, nParam1, nParam2, nParam3);
	pNPC->GetNPCInfo()->ColtInfo.vecCombatChecks[NPC_MODE_DEFAULT].push_back(pNewInfo);

	if (true == bInsertDummyAction)
	{
		GColtAction dummyActionInfo;

		pNewInfo->vecActions.push_back(dummyActionInfo);
	}

	return pNewInfo;
}

GColtCheck* GUTHelper::NewCheckInfo(COLT_CHECK_TYPE nType, int nParam1, int nParam2, int nParam3)
{
	GColtCheck* pNewInfo = new GColtCheck();
	pNewInfo->nType = nType;

	if (INT_MIN != nParam1)
	{
		pNewInfo->vecParams[0] = pair<bool, int>(true, nParam1);
	}

	if (INT_MIN != nParam2)
	{
		pNewInfo->vecParams[1] = pair<bool, int>(true, nParam2);
	}

	if (INT_MIN != nParam3)
	{
		pNewInfo->vecParams[2] = pair<bool, int>(true, nParam3);
	}	

	return pNewInfo;
}

GColtAction* GUTHelper::NewColtActionInfo(COLT_ACTION_TYPE nType, vector<wstring> qParams, int nRate, int nMaxCount)
{
	GColtAction* pNewInfo = new GColtAction();
	pNewInfo->nType = nType;
	pNewInfo->qParams = qParams;
	pNewInfo->nRate = nRate;
	pNewInfo->nMaxCount = nMaxCount;

	return pNewInfo;
}

GGuild* GUTHelper::NewGuild(GEntityPlayer* pPlayer, const wchar_t* szGuildName, int nMoney, GEntityPlayer* pGuest)
{
	int nGID = SUnitTestUtil::NewGID();	

	GGuild* pNewGuild = gmgr.pGuildMgr->Insert(nGID, szGuildName, nMoney);
	pNewGuild->InsertMember(pPlayer->GetAID(), pPlayer->GetCID(), pPlayer->GetPlayerInfo()->szName, pPlayer->GetPlayerInfo()->nLevel, GMG_MASTER);
	if (NULL != pGuest)
	{
		pNewGuild->InsertMember(pGuest->GetAID(), pGuest->GetCID(), pGuest->GetPlayerInfo()->szName, pGuest->GetPlayerInfo()->nLevel, GMG_NORMAL);
	}	

	return pNewGuild;
}

GTalentInfo* GUTHelper::LearnNewTalent(GEntityPlayer* pPlayer, int nLine, int nRank)
{
	if (NULL == pPlayer) return NULL;

	GTalentInfo* pNewInfo = NewTalentInfo(0, nLine, nRank);
	pNewInfo->m_bNeedTraining = true;

	if (false == LearnTalent_ForTS2(pPlayer, pNewInfo->m_nID)) return NULL;

	return pNewInfo;
}

bool GUTHelper::RunLuaString( const char* szFormat, ... )
{
	char szBuff[1024];

	va_list args;
	va_start(args,szFormat);
	vsprintf(szBuff,szFormat,args);
	va_end(args);

	return WRUNSTRING(WLUA, szBuff);
}

GTalentInfo* GUTHelper::MakeSimpleTalent( int nDamage, int nTalentID /*= 1*/ )
{
	GTalentInfo* pPlayerTalentInfo = NewMeleeTalentInfo(nTalentID);	
	AddSimpleHitInfo(pPlayerTalentInfo);
	pPlayerTalentInfo->Cooking();
	pPlayerTalentInfo->m_nMinDamage = nDamage;
	pPlayerTalentInfo->m_nMaxDamage = nDamage;
	return pPlayerTalentInfo;
}

MockLink* GUTHelper::NewLink( GEntityPlayer* pPlayer, bool bIgnoreAllSendCommandID )
{
	MUID uid = pPlayer->GetUID();
	MockLink* pNewMockLink = NewLink(uid, bIgnoreAllSendCommandID);

	// 만약에 PlayerObject가 없으면 편의를 위해 PlayerObject도 함께 생성해줌.
	if (gmgr.pPlayerObjectManager->GetPlayer(uid) == NULL)
	{
		MockPlayerObject* pMockPlayerObject = new MockPlayerObject(uid);
		gmgr.pPlayerObjectManager->AddPlayer(pMockPlayerObject);
		pMockPlayerObject->Create(pPlayer);
		gmgr.pPlayerObjectManager->AddCID(pMockPlayerObject);		

		pNewMockLink->AttachMockPlayerObject(pMockPlayerObject);
	}

	return pNewMockLink;
}

MockLink* GUTHelper::NewLink( MUID uidLink, bool bIgnoreAllSendCommandID )
{
	MockNetServer* pMockNetServer = dynamic_cast<MockNetServer*>(gsys.pCommandCenter->GetNetServer());
	if (!pMockNetServer) return NULL;

	MockLink* pNewMockLink = dynamic_cast<MockLink*>(pMockNetServer->AddMockLink(uidLink));
	if (!pNewMockLink) return NULL;

	if (bIgnoreAllSendCommandID)
	{
		pNewMockLink->IgnoreAll();
	}

	return pNewMockLink;
}

void GUTHelper::ClearLinks()
{
	MockNetServer* pMockNetServer = dynamic_cast<MockNetServer*>(gsys.pCommandCenter->GetNetServer());
	if (!pMockNetServer) return;

	pMockNetServer->ClearMockLinks();
}

void GUTHelper::SetSimpleActorMeshInfoHit( GActorMeshInfo* pActorMeshInfo, vec3 vCapsuleBottom, vec3 vCapsuleTop, float fRadius )
{
	CSMeshInfo meshInfo;
	CSHitGroup hitGroup;
	CSHitCapsule hitCapsule;

	hitCapsule.m_Capsule.bottom = vCapsuleBottom;
	hitCapsule.m_Capsule.top = vCapsuleTop;
	hitCapsule.m_Capsule.radius = fRadius;
	hitCapsule.m_Capsule.CalcHeight();

	hitGroup.m_nGroupID = 0;
	hitGroup.m_vecHitCapsules.push_back(hitCapsule);

	meshInfo.m_mapHitGroupInfo.insert(map<int, CSHitGroup>::value_type(hitGroup.m_nGroupID, hitGroup));

	pActorMeshInfo->Init(&meshInfo, 1.0f);
}

GEntityNPC* GUTHelper::NewEntityNPC(GField* pField, vec3 pos, int nNPCId)
{
	GNPCInfo* pNPCInfo = gmgr.pNPCInfoMgr->Find(nNPCId);
	if (!pNPCInfo)
	{
		pNPCInfo = NewNPCInfo(nNPCId);
	}

	GEntityNPC* pNewEntityNPC = new GEntityNPC();
	pNewEntityNPC->Create(SUnitTestUtil::NewUID());
	pNewEntityNPC->InitFromNPCInfo(pNPCInfo, NULL);
	pNewEntityNPC->EnterToField(pField, pos);

	return pNewEntityNPC;
}

GSoulBindingInfo* GUTHelper::NewSoulBindingInfo(MARKER_INFO* pMarkerInfo)
{
	GSoulBindingInfo* pSoulBindingInfo = new GSoulBindingInfo();
	pSoulBindingInfo->m_nID = SUnitTestUtil::NewUINT8ID();
	pSoulBindingInfo->m_pMarkerInfo = pMarkerInfo;
	_ASSERT(NULL == gmgr.pSoulBindingInfoMgr->Get(pSoulBindingInfo->m_nID));

	gmgr.pSoulBindingInfoMgr->Insert(pSoulBindingInfo);

	return pSoulBindingInfo;
}

GSoulBindingInfo* GUTHelper::NewDefaultSoulBindingInfo(MARKER_INFO* pMarkerInfo)
{
	GSoulBindingInfo* pSoulBindingInfo = gmgr.pSoulBindingInfoMgr->Get(DEFAULT_SOULBINDING_ID);
	if (NULL == pSoulBindingInfo)
	{
		GSoulBindingInfo* pSoulBindingInfo = new GSoulBindingInfo();
		pSoulBindingInfo->m_nID = DEFAULT_SOULBINDING_ID;
		SUnitTestUtil::NewUINT8ID();
		pSoulBindingInfo->m_pMarkerInfo = pMarkerInfo;
		gmgr.pSoulBindingInfoMgr->Insert(pSoulBindingInfo);
	}
	else
	{
		pSoulBindingInfo->m_pMarkerInfo = pMarkerInfo;
	}

	return pSoulBindingInfo;
}