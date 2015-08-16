#pragma once
#include "Packet.h"
#include "stdafx.h"

class AddCharacterPacket :
	public Packet
{
private:
	RakNet::RakString server_name_;
	RakNet::RakString char_name_;

public:
	AddCharacterPacket(RakNet::RakString, RakNet::RakString);
	~AddCharacterPacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;

};

