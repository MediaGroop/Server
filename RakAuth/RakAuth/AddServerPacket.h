#pragma once
#include "stdafx.h"
#include "Packet.h"

class AddServerPacket :
	public Packet
{
private:
	RakNet::RakString addr;
	int id;
public:
	AddServerPacket(RakNet::RakString, int);
	~AddServerPacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;

};

