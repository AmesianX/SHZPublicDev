#include "stdafx.h"
#include "DBTestGlobal.h"
#include "DBTestSwapItem.h"
#include "GConfig.h"

SUITE(DBTestItemSwapSlot)
{
	class SI_ITEM
	{
	public :
		SI_ITEM(int SLOT_TYPE, int SLOT_ID, int BEF_STACK_AMT, int NEXT_STACK_AMT, int CHAR_PTM)
			: m_SLOT_TYPE(SLOT_TYPE), m_SLOT_ID(SLOT_ID), m_BEF_STACK_AMT(BEF_STACK_AMT), m_NEXT_STACK_AMT(NEXT_STACK_AMT), m_CHAR_PTM(CHAR_PTM), m_IUID(0)
		{

		}

		void Insert(int64 GSN, int64 CSN)
		{
			static int64 NEW_IUID = 1;
			m_IUID = NEW_IUID++;
			DBTestHelper::InsertEmptyItemSlot(GSN, CSN, GConfig::m_nMyWorldID, m_SLOT_TYPE, m_SLOT_ID, m_IUID);
			UTestDB.Execute(L"UPDATE dbo.RZ_INVEN SET ITEM_ID = %d, STACK_AMT = %d, CHAR_PTM = %d, PERIOD = 0, USAGE_PERIOD = 0, EFF_END_DATE = NULL \
							 WHERE IUID = %I64d", 1, m_BEF_STACK_AMT, m_CHAR_PTM, m_IUID);
		}

		void InsertEmptySlot(int64 GSN, int64 CSN)
		{
			DBTestHelper::InsertEmptyItemSlot(GSN, CSN, GConfig::m_nMyWorldID, m_SLOT_TYPE, m_SLOT_ID);			
		}

		void Check(int64 GSN, int64 CSN, int SLOT_TYPE, int SLOT_ID, int CHAR_PTM)
		{
			TDBRecordSet rs;
			UTestDB.Execute(rs, L"SELECT STACK_AMT, CHAR_PTM, IUID FROM dbo.RZ_INVEN WHERE ACCN_ID = %I64d AND OWNER_ID = %I64d AND SLOT_TYPE = %d AND SLOT_ID = %d"
				, GSN, CSN, SLOT_TYPE, SLOT_ID);
			CHECK_EQUAL(1, rs.GetFetchedRowCount());
			CHECK_EQUAL(m_NEXT_STACK_AMT, rs.Field(L"STACK_AMT").AsInt());
			CHECK_EQUAL(m_IUID, rs.Field(L"IUID").AsInt64());
			CHECK_EQUAL(CHAR_PTM, rs.Field(L"CHAR_PTM").AsInt());
			rs.Close();
		}

		int		m_SLOT_TYPE;
		int		m_SLOT_ID;
		int		m_BEF_STACK_AMT;
		int		m_NEXT_STACK_AMT;
		int		m_CHAR_PTM;
		int64	m_IUID;
	};

	const int64 GSN				= 1;
	const int64 CSN				= 2;
	const int	NEW_CHAR_PTM	= 123;

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_NOT_EXISTS_SLOT)
	{
		SI_ITEM ITEM_FROM(1, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(1, 2, 0, 0, 0);

		ITEM_FROM.Insert(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, (int64)0, 0, 0, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_FROM.m_CHAR_PTM);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_TO.m_CHAR_PTM);
	}

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_EMPTY_SLOT)
	{
		SI_ITEM ITEM_FROM(1, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(1, 2, 0, 0, 0);

		ITEM_FROM.Insert(GSN, CSN);
		ITEM_TO.InsertEmptySlot(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, (int64)0, 0, 0, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_FROM.m_CHAR_PTM);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_TO.m_CHAR_PTM);
	}

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_EACH_ITEM)
	{
		SI_ITEM ITEM_FROM(1, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(1, 2, 3, 1, 20);

		ITEM_FROM.Insert(GSN, CSN);
		ITEM_TO.Insert(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_TO.m_IUID, ITEM_TO.m_BEF_STACK_AMT, ITEM_TO.m_NEXT_STACK_AMT
			, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_FROM.m_CHAR_PTM);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_TO.m_CHAR_PTM);
	}

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_EACH_ITEM_INVEN_TO_STORAGE)
	{
		SI_ITEM ITEM_FROM(1, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(4, 1, 3, 1, 20);

		ITEM_FROM.Insert(GSN, CSN);
		ITEM_TO.Insert(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_TO.m_IUID, ITEM_TO.m_BEF_STACK_AMT, ITEM_TO.m_NEXT_STACK_AMT
			, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, 0);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, NEW_CHAR_PTM);
	}

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_EACH_ITEM_STORAGE_TO_INVEN)
	{
		SI_ITEM ITEM_FROM(4, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(1, 1, 3, 1, 20);

		ITEM_FROM.Insert(GSN, CSN);
		ITEM_TO.Insert(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_TO.m_IUID, ITEM_TO.m_BEF_STACK_AMT, ITEM_TO.m_NEXT_STACK_AMT
			, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, NEW_CHAR_PTM);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, 0);
	}

	GAMEDB_TEST(USP_RZ_ITEM_SWAP_SLOT_EACH_ITEM_STORAGE_TO_STORAGE)
	{
		SI_ITEM ITEM_FROM(4, 1, 4, 6, 10);
		SI_ITEM ITEM_TO(4, 2, 3, 1, 20);

		ITEM_FROM.Insert(GSN, CSN);
		ITEM_TO.Insert(GSN, CSN);

		UTestDB.Execute(L"{CALL dbo.USP_RZ_ITEM_SWAP_SLOT (%d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %I64d, %I64d, %d, %d, %I64d, %d, %d, %d)}"
			, GConfig::m_nMyWorldID
			, GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, ITEM_FROM.m_IUID, ITEM_FROM.m_BEF_STACK_AMT, ITEM_FROM.m_NEXT_STACK_AMT
			, GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, ITEM_TO.m_IUID, ITEM_TO.m_BEF_STACK_AMT, ITEM_TO.m_NEXT_STACK_AMT
			, NEW_CHAR_PTM);

		ITEM_FROM.Check(GSN, CSN, ITEM_TO.m_SLOT_TYPE, ITEM_TO.m_SLOT_ID, 0);
		ITEM_TO.Check(GSN, CSN, ITEM_FROM.m_SLOT_TYPE, ITEM_FROM.m_SLOT_ID, 0);
	}
}