#pragma once
#include "stdafx.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "ServersTracker.h"
#include "AddServerPacket.h"
void serverInfoRequestHandle(RakNet::Packet *packet){
	if (authServer->hasClient(packet->guid)) // Won't it always be true?
	{
		RakNet::BitStream bsIn(packet->data, packet->length, false);
		bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
		int id;

		bsIn.Read(id);
		for (map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
		{
			if ((*ii).second.getId() == id){
				LOG(DEBUG) << "We've found da server!";
				LOG(DEBUG) << "Address: " << (*ii).second.getHost().c_str();
				AddServerPacket p(RakNet::RakString((*ii).second.getHost().c_str()), (*ii).second.getPort());
				p.send(authServer->getPeer(), authServer->getPeer()->GetGuidFromSystemAddress(packet->systemAddress));
				break;
			}
		}
	}
};