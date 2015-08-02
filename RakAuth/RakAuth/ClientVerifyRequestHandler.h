#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "VerifyResponsePacket.h"
#include "openssl\sha.h"

RakNet::RakString calculateHash(AuthClient* ac)
{
	static unsigned char hash[20];
	
	string toHash = ac->account->password();
	toHash += '.';
	toHash += ac->session.C_String();

	SHA1(reinterpret_cast<const unsigned char*>(toHash.c_str()), toHash.length(), hash);
	LOG(INFO) << "Calculated hash form db:";
	LOG(INFO) << hash;
	return RakNet::RakString(reinterpret_cast<char*>(hash));
};

bool checkForClient(RakNet::RakString login, RakNet::RakString hash)
{
	AuthClient* ac;
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = authServer->_connections.begin(); ii != authServer->_connections.end(); ++ii)
	{
		ac = (AuthClient*)(&(*ii).second);
		if (ac->account != nullptr) {
			if (ac->account->login() == std::string(login.C_String()))
			{
				if (calculateHash(ac) == hash)
				{
					return true;
				}
				return false;
			}
		}
	}
};

void handleVerifyRequest(RakNet::Packet *packet)
{
	ConnectedClient* cc = poolerServer->getClient(packet->guid);
	//What if we recieved corrupted packet?
	if (cc != nullptr)
	{
		RakNet::BitStream bsIn(packet->data, packet->length, false);
		bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

		RakNet::RakString login, hash;
		//Should I use string compressor??
		bsIn.Read(login);
		bsIn.Read(hash);
		if (checkForClient(login, hash))
		{
			VerifyResponsePacket p(0, hash);
			p.send(poolerServer->peer, packet->systemAddress);
		}
		else
		{
			VerifyResponsePacket p(1, hash);
			p.send(poolerServer->peer, packet->systemAddress);
		}
	}
};
