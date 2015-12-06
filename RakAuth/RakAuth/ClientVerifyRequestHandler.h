#pragma once
#include "stdafx.h"
#include "ServVars.h"
#include "VerifyResponsePacket.h"
#include "openssl\sha.h"
#include "Utils.h"
#include "ClientsTracker.h"

unsigned char* calculateHash(AuthClient* ac)
{
	static unsigned char hash[20];
	unsigned char* toHash = new unsigned char[41];
	for (int i = 0; i < 20; ++i){
		toHash[i] = ac->getAccount()->password()[i];
	}

	toHash[20] = '.';

	for (int i = 0; i < 20; ++i){
		toHash[i + 21] = ac->getSession()[i];
	}

	SHA1(toHash, 41, hash);//two sha1 hashes plus once symbol
	//LOG(INFO) << "Calculated hash form db:";
	//for (int i = 0; i < 20; ++i)
	//	LOG(INFO) << hash[i];



	return hash;
};

bool checkForClient(RakNet::RakString login, unsigned char* hash)
{
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = authServer->get_connections()->begin(); ii != authServer->get_connections()->end(); ++ii)
	{
		AuthClient* ac = getAuthClient(&(*ii).second);
		if (ac != nullptr){
			if (ac->getAccount() != nullptr) {
				if (ac->getAccount()->login() == std::string(login.C_String()))
				{
					if (compareHashes(calculateHash(ac), hash))
					{
						LOG(INFO) << "Hashes are equal";
						return true;
					}
					else{
						LOG(INFO) << "Hashes are not equal";
						return false;
					}
				}
			}
		}

	}
	LOG(INFO) << "No such user: " << login.C_String();
	return false;
};

void handleVerifyRequest(RakNet::Packet *packet)
{
	ConnectedClient* cc = poolerServer->getClient(packet->guid);
	LOG(DEBUG) << "Verifying account...";
	RakNet::BitStream bsIn(packet->data, packet->length, false);
	bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

	RakNet::RakString login;
	unsigned char hash[20];
	//Should I use string compressor??
	bsIn.Read(login);
	AuthClient* ac = nullptr;
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = authServer->get_connections()->begin(); ii != authServer->get_connections()->end(); ++ii)
	{
		ac = getAuthClient(&(*ii).second);
		if (ac != nullptr)
		{
			if (RakNet::RakString(ac->getAccount()->login().c_str()) == login){
				LOG(DEBUG) << "We've found da account! Name: " << login.C_String();
				break;
			}
		}
	}

	//What if we recieved corrupted packet?
	if (cc != nullptr)
	{
		if (ac != nullptr){
			if (ac->authorized()){
				for (int i = 0; i < 20; ++i){
					bsIn.Read(hash[i]);
					//	LOG(INFO) << hash[i];
				}

				if (ac->getAccount() != nullptr){
					if (checkForClient(login, hash) && (ac->getAccount()->premium() || ac->getAccount()->beta()))
					{
						VerifyResponsePacket p(0, hash, *new RakNet::RakString(ac->getAccount()->login().c_str()));
						p.send(poolerServer->getPeer(), packet->systemAddress);
						LOG(INFO) << "Verified!";
					}
					else
					{
						VerifyResponsePacket p(1, hash, *new RakNet::RakString(ac->getAccount()->login().c_str()));
						p.send(poolerServer->getPeer(), packet->systemAddress);
						LOG(INFO) << "Invalid hash!(In case if there were message \"No such user\" - no user)";
					}
				}
				else
				{
					VerifyResponsePacket p(1, hash, *new RakNet::RakString(""));
					p.send(poolerServer->getPeer(), packet->systemAddress);
				}
			}
		}
	}
};
