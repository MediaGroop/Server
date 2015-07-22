#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "easylogging++.h"
#include "ServersTracker.h"

void handleDisconnectFromPooler(RakNet::Packet * p)
{
	ServerInfo* ptr = getServer(poolerServer->getClient(p->guid));
	if (ptr != nullptr)
	{
		removeServer(ptr);
	}
	poolerServer->removeClient(p->guid);
	LOG(INFO) << "Server was removed!";
}