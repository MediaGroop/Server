#pragma once
#include "Packet.h"
#include "stdafx.h"

class AddServerPacket :
	public Packet
{
private:
	RakNet::RakString name;
	int id;
public:
	AddServerPacket(RakNet::RakString, int);
	~AddServerPacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;

};

