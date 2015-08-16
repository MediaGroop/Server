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
		AuthClient* ac = getAuthClient(c);
		if (ac != nullptr){
			if (!ac->authorized()){
				_clients.erase(c);
				LOG(INFO) << "Client was removed!";
			}
		}
		else{
			_clients.erase(c);
			LOG(INFO) << "Client was removed!";
		}
	}
	//LOG(INFO) << "Removing client";
	authServer->removeClient(p->guid);
	//LOG(INFO) << "Client was removed!";
};

