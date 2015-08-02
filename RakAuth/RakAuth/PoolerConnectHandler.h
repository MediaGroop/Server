#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "ServerClient.h"

void handleconn(RakNet::Packet *packet){
	LOG(INFO) << "Incoming connection for pooler!";
	if (!poolerServer->hasClient(packet->guid)) // Won't it always be true?
	{
		ServerClient cl(packet->systemAddress);
		poolerServer->addClient(packet->guid, cl);
	}
};
