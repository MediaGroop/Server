#pragma once
#include "stdafx.h"
#include "Packet.h"

class ServerInfoPacket : public Packet
{
private:
	RakNet::RakString addr;
	int port;
public:
	ServerInfoPacket(RakNet::RakString, int);
	~ServerInfoPacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};