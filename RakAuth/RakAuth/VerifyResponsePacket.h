#pragma once
#include "stdafx.h"
#include "Packet.h"

class VerifyResponsePacket :
	public Packet
{
public:
	unsigned char result;// 0 - auth success, 1 - auth unsuccessfull!
	RakNet::RakString hash;
	VerifyResponsePacket(unsigned char r, RakNet::RakString h) : result(r), hash(h){};
	~VerifyResponsePacket(){};
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};

