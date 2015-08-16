#pragma once 
#include "ServVars.h"
#include "ServersTracker.h"
#include "AuthClient.h"
#include "ClientsTracker.h"
#include "CheckNickPacket.h"

void handleNickCheck(RakNet::Packet* p)
{
	ConnectedClient* cl = authServer->getClient(p->guid);
	if (cl != nullptr){
		AuthClient* ac = getAuthClient(cl);
		if (ac != nullptr){
			if (ac->authorized()){
				RakNet::BitStream bsIn(p->data, p->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				RakNet::RakString nick, server;
				int serverId = -1;
				bsIn.Read(server);
				bsIn.Read(nick);
				LOG(INFO) << "Server request:";
				LOG(INFO) << server.C_String();


				for (std::map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
				{
					LOG(INFO) << "Server iter:";
					LOG(INFO) << (*ii).second.getName().c_str();


					if (RakNet::RakString((*ii).second.getName().c_str()) == server) {
						serverId = (*ii).second.getId();
						break;
					}
				}
				if (serverId != -1)
				{
					typedef odb::query<CharacterLink> query;
					typedef odb::result<CharacterLink> result;

					odb::transaction t(dataBase->begin());
					std::string str = std::string(nick.C_String());
					result r(dataBase->query<CharacterLink>(query::char_name == str));
					bool uniq = true;
					for (result::iterator i(r.begin()); i != r.end(); ++i)
					{
						uniq = false;
					}
					t.commit();
					LOG(INFO) << "Nick is available: ";
					LOG(INFO) << uniq;
					CheckNickPacket pack(uniq);
					pack.send(authServer->getPeer(), *cl->getAddr());
				}
				else
				{
					LOG(INFO) << "No server with such name:";
					LOG(INFO) << server.C_String();
					//wrong server!
				}
			}
		}
	}
};