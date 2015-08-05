#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ConnectedClient.h"
#include "ServVars.h"
#include "ClientsTracker.h"

void handleDisconnectFromAuth(RakNet::Packet * p)
{
	ConnectedClient* c = authServer->getClient(p->guid);
	if (c != nullptr)
	{
		//TODO: add remove code
		//_clients.erase(c);
	}
	LOG(INFO) << "Removing client";
	//LOG(INFO) << "GUID:";
	//LOG(INFO) << p->guid.ToString();
	authServer->removeClient(p->guid);
	LOG(INFO) << "Client was removed!";
};