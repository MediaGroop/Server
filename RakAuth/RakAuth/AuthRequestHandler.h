#pragma once
#include "stdafx.h"
#include "AuthClient.h"
#include "easylogging++.h"
#include "ServVars.h"
#include "odb\database.hxx";
#include "AccountInfo-odb.hxx"
#include "openssl\sha.h"
#include "AuthResponsePacket.h"
#include "Utils.h"

bool logged(RakNet::RakString login)
{
	LOG(INFO) << "Iterating through clients...";
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = authServer->get_connections()->begin(); ii != authServer->get_connections()->end(); ++ii)
	{
		ConnectedClient* p = &(*ii).second;
		AuthClient* ac = getAuthClient(p);
		if (ac->getAccount() != nullptr)
		{
			if (RakNet::RakString(ac->getAccount()->login().c_str()) == login)
			{
				return ac->authorized();
			}
		}
	}
	return false;
}

unsigned char* calcSession(RakNet::RakNetGUID* guid)
{
	char toHash[32];

	guid->ToString(toHash);

	unsigned char hash[20];
	SHA1(reinterpret_cast<unsigned char*>(toHash), strlen(toHash), hash);

	return hash;
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

		if (!logged(acc)){
			//LOG(INFO) << "Not logged!";
			for (int i = 0; i < 20; ++i)
				bsIn.Read(hash[i]);

			int serverId;
			bsIn.Read(serverId);

			LOG(INFO) << "Credentials:";
			LOG(INFO) << "Account: ";
			LOG(INFO) << acc.C_String();
		//	LOG(INFO) << "HASH: ";
	//		for (int i = 0; i < 20; ++i)
//				LOG(INFO) << hash[i];

			LOG(INFO) << "ServerId:";
			LOG(INFO) << serverId;

			AuthClient* ac = getAuthClient(cl);
			try
			{
				bool exists = false;

				try{
					odb::transaction t(dataBase->begin());
					dataBase->load(std::string(acc.C_String()), *(ac->getAccount()));
					exists = true;
					t.commit();

				}
				catch (odb::exception& e)
				{
					LOG(INFO) << e.what();
				}

				if (exists)
				{
				//	LOG(INFO) << "data loaded! HASH: ";
			//		for (int i = 0; i < 20; ++i)
		//				LOG(INFO) << ac->getAccount()->password()[i];

					if (compareHashes(ac->getAccount()->password(), hash))
					{
						ac->setAuthorized(true);
						LOG(INFO) << "Pass is valid!";
					}
					else{
						ac->setAuthorized(false);
						LOG(INFO) << "Pass is invalid!";
					}


					if (ac->authorized())
					{
						if (ac->getAccount()->beta())
						{
							//beta access
							//Let player in - calculate session and send
							ac->setSession(calcSession(&packet->guid));
							ServerInfo* info = getServer(serverId);
							if (info != nullptr){
								//weird convertation                                           \/
								AuthResponsePacket pack(3, ac->getSession(), RakNet::RakString(info->getHost().c_str()), info->getPort());
								pack.send(authServer->getPeer(), packet->systemAddress);
								ac->setAuthorized(true);

							}
							else
							{

								AuthResponsePacket pack(4);
								pack.send(authServer->getPeer(), packet->systemAddress);
								ac->setAuthorized(false);
							}
						}
						else
						{
							if (ac->getAccount()->premium())
							{
								//has premium(Beta has more importance - after beta test, remove "beta" flag)
								//Let player in - calculate session and send
								ac->setSession(calcSession(&packet->guid));
								ServerInfo* info = getServer(serverId);
								if (info != nullptr){
									//weird convertation                                           \/
									AuthResponsePacket pack(3, ac->getSession(), RakNet::RakString(info->getHost().c_str()), info->getPort());
									pack.send(authServer->getPeer(), packet->systemAddress);
									ac->setAuthorized(true);

								}
								else
								{
									ac->setAuthorized(false);
									AuthResponsePacket pack(4);
									pack.send(authServer->getPeer(), packet->systemAddress);
								}
							}
							else
							{
								//Warn for account not premium
								AuthResponsePacket pack(2);
								pack.send(authServer->getPeer(), packet->systemAddress);
								ac->setAuthorized(false);
							}
						}
					}
					else
					{
						AuthResponsePacket pack(1);
						pack.send(authServer->getPeer(), packet->systemAddress);
						ac->setAuthorized(false);
						//Warn for wrong credentials
					}
				}
				else
				{
					AuthResponsePacket pack(0);
					pack.send(authServer->getPeer(), packet->systemAddress);
					ac->setAuthorized(false);
					//Warn for no username
				}
			}
			catch (const odb::exception& e)
			{
				LOG(INFO) << e.what();
			}
		}
		else
		{
			LOG(INFO) << "Already logged in!";
			AuthResponsePacket pack(5);
			pack.send(authServer->getPeer(), packet->systemAddress);
		}
	}
};
