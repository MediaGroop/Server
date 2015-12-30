#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "ClientsTracker.h"

void charReqHandler(RakNet::Packet* packet)
{
	ConnectedClient* cc = authServer->getClient(packet->guid);
	if (cc != nullptr){
		AuthClient* ac = getAuthClient(cc);
		if (ac != nullptr)
		{
			if (ac->authorized())
			{
				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				RakNet::RakString server;
				bsIn.Read(server);

				RakNet::RakString nick;
				bsIn.Read(nick);

				LOG(DEBUG) << "Nick: " << nick.C_String();
				LOG(DEBUG) << "Server name: " << server.C_String();

				int serverId = -1;
				for (std::map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
				{
					if (RakNet::RakString((*ii).second.getName().c_str()) == server) {
						serverId = (*ii).second.getId();
						break;
					}
				}
				if (serverId != -1)
				{
					//TODO: gather and send info
				}
				else
				{
					//NO info! Wrong server request! Cheater! Or just slow poke :)
				}
			}
		}
	}
	//TODO: send info about server and character
};