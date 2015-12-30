#pragma once
#include "Packet.h"
#include "stdafx.h"

class RemoveCharacter :
	public Packet
{
private:
	RakNet::RakString char_name_;
public:
	RemoveCharacter(RakNet::RakString);
	~RemoveCharacter();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to);
};

