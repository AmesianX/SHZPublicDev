#include "StdAfx.h"
#include "NPCListTabPage.h"

void Character_NET::NPCListTabPage::InitNPCList()
{
	char szBuf[_MAX_DIR];

	int nNPCCount = TNPCInfoMgr::GetInstance().size();
	int nCurrentNPCCount = 0;
	g_pMainApp->SetProgressBarValue();

	NPCListtreeView->Nodes->Clear();
	NPCListtreeView->Nodes->Add("none");

	for( TNPCInfoMgr::iterator itor = TNPCInfoMgr::GetInstance().begin();
		itor != TNPCInfoMgr::GetInstance().end(); ++itor)
	{
		TNPCInfo* pNPCInfo = (TNPCInfo*)(*itor).second;
		String^ strName = gcnew String(pNPCInfo->strName.c_str());

		String^ strNameWithNPCID = gcnew String(strName);
		strNameWithNPCID = strNameWithNPCID + " (" + pNPCInfo->nID + ")";

		TreeNode^ nnode = NPCListtreeView->Nodes->Add(strNameWithNPCID);
		nnode->Tag = pNPCInfo->nID;

		sprintf_s(szBuf, "%s%s%s.elu", PATH_MODEL_TOOL, pNPCInfo->strMeshPath.c_str(), pNPCInfo->strMeshName.c_str(),
			pNPCInfo->strMeshName.c_str());

		if( !ExistFile(szBuf))
		{
			nnode->BackColor = System::Drawing::Color::LightGray;
		}

		// TODO: 스킬이 존재하면 하위트리를 삽입하도록.
		TreeNode^ skillnode;

		bool bExistTalent = false;
		for (TTalentInfoMgr::iterator itorTalentInfo = g_pMainApp->m_TTalentInfoMgr.begin();
			itorTalentInfo != g_pMainApp->m_TTalentInfoMgr.end(); ++itorTalentInfo)
		{
			CSTalentInfo* pTalentInfo = static_cast<CSTalentInfo*>((*itorTalentInfo).second);
			if (pTalentInfo->m_setNPCID.find(pNPCInfo->nID) != pTalentInfo->m_setNPCID.end())
			{
				int nSkillID = pTalentInfo->m_nID;
				if (!bExistTalent)
				{
					skillnode = nnode->Nodes->Add("탈렌트");
					bExistTalent = true;
				}

				String^ strskillName = gcnew String(pTalentInfo->m_szName.c_str());
				strskillName = strskillName + "(" + nSkillID + ")";
				TreeNode^ tnode = skillnode->Nodes->Add(strskillName);
				tnode->Tag = nSkillID;

				if( !ExistFile(szBuf))
				{
					tnode->BackColor = System::Drawing::Color::LightGray;
				}
			}
		}

		++nCurrentNPCCount;
		float fRate = ((float)nCurrentNPCCount / (float)nNPCCount) * 100;
		g_pMainApp->SetProgressBarValue((int)fRate);
	}
}

void Character_NET::NPCListTabPage::FindNPCGroup( System::String^ NPCID )
{
	NPCListtreeView->Nodes->Clear();

	vector<string> vecFindList;
	map<int, TNPCInfo*> mapNPCInfo;
	TStrings::ParseFindString(NPCID, vecFindList);

	if(vecFindList.empty() == false)
	{
		for( TNPCInfoMgr::iterator itor = TNPCInfoMgr::GetInstance().begin();
			itor != TNPCInfoMgr::GetInstance().end(); ++itor)
		{
			TNPCInfo* pNPCInfo = (TNPCInfo*)(*itor).second;
			if( FindNPCList(vecFindList, pNPCInfo) )
			{
				mapNPCInfo.insert(map<int, TNPCInfo*>::value_type(pNPCInfo->nID, pNPCInfo));
			}
		}

		for(TTalentInfoMgr::iterator itor = g_pMainApp->m_TTalentInfoMgr.begin(); itor != g_pMainApp->m_TTalentInfoMgr.end(); ++itor)
		{
			TTalentInfo* pTalentInfo = (TTalentInfo*)(*itor).second;

			if(pTalentInfo->m_setNPCID.size() > 0 && 
				FindTALENTList(vecFindList, pTalentInfo))
			{
				for(set<int>::iterator itNPC = pTalentInfo->m_setNPCID.begin(); itNPC != pTalentInfo->m_setNPCID.end(); ++itNPC)
				{
					TNPCInfoMgr::iterator itFindNPC = TNPCInfoMgr::GetInstance().find(*itNPC);
					if(itFindNPC != TNPCInfoMgr::GetInstance().end())
					{
						mapNPCInfo.insert(map<int, TNPCInfo*>::value_type(*itNPC, (TNPCInfo*)(*itFindNPC).second));
					}
				}
			}
		}
	}

	// 최종 셋팅
	for(map<int, TNPCInfo*>::iterator itfinal = mapNPCInfo.begin(); itfinal != mapNPCInfo.end(); ++itfinal)
	{
		SetNPCListTreeView((TNPCInfo*)(*itfinal).second);
	}
}

bool Character_NET::NPCListTabPage::FindNPCList( vector<string>& vecNPCList, TNPCInfo* pInfo )
{
	for(vector<string>::iterator itNPC = vecNPCList.begin(); itNPC != vecNPCList.end(); itNPC++)
	{
		String^ NPCID = gcnew String((*itNPC).c_str());
		String^ tnstr = String::Format("{0} {1}", gcnew String(pInfo->strName.c_str()), pInfo->nID); // 검색용으로 스트링 만들기

		if( tnstr->StartsWith(NPCID) || tnstr->EndsWith(NPCID) || IsEqualString(tnstr, NPCID))
			return true;
	}

	return false;
}

bool Character_NET::NPCListTabPage::FindTALENTList( vector<string>& vecTalentList, TTalentInfo* pInfo )
{
	for(vector<string>::iterator itTalent = vecTalentList.begin(); itTalent != vecTalentList.end(); ++itTalent)
	{
		String^ TalentID = gcnew String((*itTalent).c_str());
		String^ tnstr = String::Format("{0} {1}", gcnew String(pInfo->GetName()), pInfo->m_nID);	// 검색용으로 스트링 만들기

		if( tnstr->StartsWith(TalentID) || tnstr->EndsWith(TalentID) || IsEqualString(tnstr, TalentID))
			return true;
	}

	return false;
}

void Character_NET::NPCListTabPage::SetNPCListTreeView( TNPCInfo* pNPCInfo )
{
	String^ strName = gcnew String(pNPCInfo->strName.c_str());

	String^ strNameWithNPCID = gcnew String(strName);
	strNameWithNPCID = strNameWithNPCID + " (" + pNPCInfo->nID + ")";

	TreeNode^ nnode = NPCListtreeView->Nodes->Add(strNameWithNPCID);
	nnode->Tag = pNPCInfo->nID;

	TreeNode^ skillnode;

	bool bExistTalent = false;
	for (TTalentInfoMgr::iterator itorTalentInfo = g_pMainApp->m_TTalentInfoMgr.begin();
		itorTalentInfo != g_pMainApp->m_TTalentInfoMgr.end(); ++itorTalentInfo)
	{
		CSTalentInfo* pTalentInfo = static_cast<CSTalentInfo*>((*itorTalentInfo).second);
		if (pTalentInfo->m_setNPCID.find(pNPCInfo->nID) != pTalentInfo->m_setNPCID.end())
		{
			int nSkillID = pTalentInfo->m_nID;
			if (!bExistTalent)
			{
				skillnode = nnode->Nodes->Add("탈렌트");
				bExistTalent = true;
			}

			String^ strskillName = gcnew String(pTalentInfo->m_szName.c_str());
			strskillName = strskillName + "(" + nSkillID + ")";
			TreeNode^ tnode = skillnode->Nodes->Add(strskillName);
			tnode->Tag = nSkillID;
		}
	}
}

void Character_NET::NPCListTabPage::ReLoadNPCList()
{
	if(NPCGroupIDtextBox->Text != "")
	{
		FindNPCGroup(NPCGroupIDtextBox->Text);
	}
	else 
	{
		InitNPCList();
	}
}