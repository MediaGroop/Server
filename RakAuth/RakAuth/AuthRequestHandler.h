#pragma once
#include "stdafx.h"
#include "AuthClient.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "odb\database.hxx";
#include "AccountInfo-odb.hxx"
#include "openssl\sha.h"
#include "AuthResponsePacket.h"

RakNet::RakString calcSession(RakNet::RakNetGUID* guid)
{

	char toHash[32];

	guid->ToString(toHash);

	unsigned char hash[20];
	SHA1(reinterpret_cast<unsigned char*>(toHash), strlen(toHash), hash);
	
	RakNet::RakString session(hash);
	return session;
}

void handleAuth(RakNet::Packet *packet){
	LOG(INFO) << "Auth request!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	ConnectedClient* cl = authServer->getClient(packet->guid);

	if (cl != nullptr) // Won't it always be true?
	{
		RakNet::BitStream bsIn(packet->data, packet->length, false);
		bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
		RakNet::RakString acc;//, pas;
		unsigned char hash[20];
		RakNet::StringCompressor::Instance()->DecodeString(&acc, 256, &bsIn);
		bsIn.Read(hash);
		int serverId;
		bsIn.Read(serverId);

		LOG(INFO) << "Credentials:";
		LOG(INFO) << "Account: ";
		LOG(INFO) << acc.C_String();
		LOG(INFO) << "HASH: ";
		LOG(INFO) << hash;
		LOG(INFO) << "ServerId:";
		LOG(INFO) << serverId;

		AuthClient* ac = (AuthClient*)cl;
		try
		{
			typedef odb::query<AccountInfo> query;
			typedef odb::result<AccountInfo> result;

			odb::transaction t(dataBase->begin());

			result r(dataBase->query<AccountInfo>(query::login == std::string(acc.C_String())));

			bool exists = false;
			//Always must be one iteration or less(In case if there's no user)
			string hashStr(reinterpret_cast<char*>(hash));
			for (result::iterator i(r.begin()); i != r.end(); ++i)
			{
				exists = true;
				if (hashStr == i->password())
				{
					i->authorized_ = true;					
				}
			}

			t.commit();
			if (exists)
			{
				if (ac->account->authorized_)
				{
					if (ac->account->beta())
					{
						//beta access
						//Let player in - calculate session and send
						RakNet::RakString session = calcSession(&packet->guid);
						ac->session = session;
						ServerInfo* info = getServer(serverId);
						if (info != nullptr){
							//weird convertation                                           \/
							AuthResponsePacket pack(3, session, RakNet::RakString(info->host.c_str()), info->port);
							pack.send(authServer->peer, packet->systemAddress);
						}
						else
						{

							AuthResponsePacket pack(4);
							pack.send(authServer->peer, packet->systemAddress);
						}
					}
					else
					{
						if (ac->account->premium())
						{
							//has premium(Beta has more importance - after beta test, remove "beta" flag)
							//Let player in - calculate session and send
							RakNet::RakString session = calcSession(&packet->guid);
							ac->session = session; ServerInfo* info = getServer(serverId);
							if (info != nullptr){
								//weird convertation                                           \/
								AuthResponsePacket pack(3, session, RakNet::RakString(info->host.c_str()), info->port);
								pack.send(authServer->peer, packet->systemAddress);
							}
							else
							{

								AuthResponsePacket pack(4);
								pack.send(authServer->peer, packet->systemAddress);
							}
						}
						else
						{
							//Warn for account not premium
							AuthResponsePacket pack(2);
							pack.send(authServer->peer, packet->systemAddress);
						}
					}
				}
				else
				{
					AuthResponsePacket pack(1);
					pack.send(authServer->peer, packet->systemAddress);
					//Warn for wrong credentials
				}
			}
			else
			{
				AuthResponsePacket pack(0);
				pack.send(authServer->peer, packet->systemAddress);
				//Warn for no username
			}
		}
		catch (const odb::exception& e)
		{
			LOG(INFO) << e.what();
		}
	}
};
