#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "AuthClient.h"

void handleAuthconn(RakNet::Packet *packet){
	LOG(INFO) << "Incoming connection for authenticator!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	if (!authServer->hasClient(packet->guid)) // Won't it always be true?
	{
		AuthClient cl(packet->systemAddress);
		authServer->addClient(packet->guid, cl);
	}
};

