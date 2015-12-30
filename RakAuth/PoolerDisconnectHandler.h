#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "easylogging++.h"
#include "ServersTracker.h"

void handleDisconnectFromPooler(RakNet::Packet * p)
{
	ConnectedClient* ptr = poolerServer->getClient(p->guid);
	if (ptr != nullptr)
	{
		removeServer(ptr);
	}
	poolerServer->removeClient(p->guid);
	LOG(INFO) << "Server client removed!";
}