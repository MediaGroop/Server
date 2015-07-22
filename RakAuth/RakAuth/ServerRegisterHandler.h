#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ConfigLoader.h"
#include "ServerInfo.h"
#include "ServersTracker.h"
#include "ServVars.h"

void handleWrongKey(RakNet::RakNetGUID guid){
	LOG(INFO) << "Wrong key!";
};


void handlePoolerAuth(RakNet::Packet *packet)
{
	RakNet::RakString key, shardName;
	int port, length;
	RakNet::BitStream bsIn(packet->data, packet->length, false);
	bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

	bsIn.Read(key);
	LOG(INFO) << "Our key is: " + ConfigLoader::getVal("Pooler-Key");
	LOG(INFO) << "Their key is: ";
	LOG(INFO) << key.C_String();
	if (key == ConfigLoader::getVal("Pooler-Key").c_str()){
		bsIn.Read(shardName);
		bsIn.Read(port);
		if (!hasServer(std::string(shardName))){
			ServerInfo info(packet->systemAddress.ToString(false), port, poolerServer->getClient(packet->guid), ServerState::ONLINE);
			addServer(shardName.C_String(), info);
			LOG(INFO) << "Registering " + shardName + " at IP " + packet->systemAddress.ToString(false) + ":" << port;
		}
	}
	else
	{
		handleWrongKey(packet->guid);
	}
};