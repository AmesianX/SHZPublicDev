#include "stdafx.h"
#include "MDisconnector.h"
#include "MServerTcpSocket.h"
#include "MServerTcpSocketPool.h"

namespace minet {

void MDisconnector::ProcEvent( MAct* act, DWORD bytes_transferred )
{
	MTcpAct* pTcpAct = static_cast<MTcpAct*>(act);

	assert(pTcpAct->m_pTcpSocket);
	MServerTcpSocket& tcpsocket = *(pTcpAct->m_pTcpSocket);

	if (pTcpAct->m_uidLink == MUID::ZERO)
	{
		minet_logd("uid가 0 - MDisconnector::ProcEvent\n");
	}

	OnDisconnect(pTcpAct->m_uidLink);

	// 소켓 재사용
	tcpsocket.Reuse();
}

void MDisconnector::ProcError( MAct* act, DWORD bytes_transferred, DWORD error )
{
	MTcpAct* pTcpAct = static_cast<MTcpAct*>(act);

	assert(pTcpAct);
	assert(pTcpAct->m_pTcpSocket);

	MServerTcpSocket* pTcpSocket = pTcpAct->m_pTcpSocket;

	if (pTcpAct->m_uidLink == MUID::ZERO)
	{
		minet_logd("uid가 0 - MDisconnector::ProcError\n");
	}

	OnDisconnect(pTcpAct->m_uidLink);

	minet_logd("minet> Disconnector ProcError socket(%d) err(%d)\n", pTcpSocket->GetSocket(), error );

	pTcpSocket->Fini();
	m_pSocketPool->Restore(pTcpSocket);
}

void MDisconnector::Init( MProactor* proactor, MServerTcpSocketPool* pSocketPool )
{
	m_pProactor = proactor;
	m_pSocketPool = pSocketPool;
}

void MDisconnector::OnDisconnect( MUID uidLink )
{
	if (m_pListener) m_pListener->OnDisconnect(uidLink);
}

void MDisconnector::HardDisconnect(MServerTcpSocket* pTcpSocket, MUID uidLink)
{
	OnDisconnect(uidLink);

	pTcpSocket->Fini();
	m_pSocketPool->Restore(pTcpSocket);
}

} // namespace minet {