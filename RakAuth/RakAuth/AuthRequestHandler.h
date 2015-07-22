#pragma once
#include "stdafx.h"
#include "AuthClient.h"
#include "easylogging++.h"
#include "ServVars.h"

void handleAuth(RakNet::Packet *packet){
	LOG(INFO) << "Auth request!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	ConnectedClient* cl = authServer->getClient(packet->guid);

	if (cl != nullptr) // Won't it always be true?
	{
		RakNet::BitStream bsIn(packet->data, packet->length, false);
		bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
		RakNet::RakString acc, pas;
		RakNet::StringCompressor::Instance()->DecodeString(&acc, 256, &bsIn);
		RakNet::StringCompressor::Instance()->DecodeString(&pas, 256, &bsIn);

		int serverId;
		bsIn.Read(serverId);

		LOG(INFO) << "Credentials:";
		LOG(INFO) << "Account: ";
		LOG(INFO) << acc.C_String();
		LOG(INFO) << "Password: ";
		LOG(INFO) << pas.C_String();
		LOG(INFO) << "ServerId:";
		LOG(INFO) << serverId;

		AuthClient* ac = (AuthClient*)cl;
		//TODO: load account data and send response
		//	loadAccInfo(ac);
		//	onFinishLoadAcc(ac);
	}
};
