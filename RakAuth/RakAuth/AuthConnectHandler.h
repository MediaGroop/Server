#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "AuthClient.h"
#include "ClientsTracker.h"

void handleAuthconn(RakNet::Packet *packet){
	LOG(INFO) << "Incoming connection for authenticator!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	if (!authServer->hasClient(packet->guid)) // Won't it always be true?
	{
		authServer->addClient(packet->guid, *new ConnectedClient(packet->systemAddress));//holy fuck! I killed a whole day to make it D:
		addAuthClient(authServer->getClient(packet->guid), *new AuthClient); // ClientsTracker.h

	}
};

