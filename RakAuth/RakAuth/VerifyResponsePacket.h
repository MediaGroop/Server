#pragma once
#include "stdafx.h"
#include "Packet.h"

class VerifyResponsePacket :
	public Packet
{
public:
	unsigned char result;// 0 - auth success, 1 - auth unsuccessfull!
	unsigned char hash[20];
	VerifyResponsePacket(unsigned char r, unsigned char h[20]) : result(r){
		for (int i = 0; i < 20; ++i)
		{
			hash[i] = h[i];
		}
	};
	~VerifyResponsePacket(){};
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};

