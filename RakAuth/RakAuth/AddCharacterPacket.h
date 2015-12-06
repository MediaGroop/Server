#pragma once
#include "Packet.h"
#include "stdafx.h"

class AddCharacterPacket :
	public Packet
{
private:
	int _server_id;
	RakNet::RakString char_name_, server_name_;

public:
	AddCharacterPacket(RakNet::RakString, RakNet::RakString, int);
	~AddCharacterPacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;

};

