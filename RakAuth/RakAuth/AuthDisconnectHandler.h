#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ConnectedClient.h"
#include "ServVars.h"

void handleDisconnectFromAuth(RakNet::Packet * p)
{
	ConnectedClient* c = authServer->getClient(p->guid);
	if (c != nullptr)
	{

	}
	LOG(INFO) << "Removing client";
	//LOG(INFO) << "GUID:";
	//LOG(INFO) << p->guid.ToString();
	authServer->removeClient(p->guid);
	LOG(INFO) << "Client was removed!";
};