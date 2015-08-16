#pragma once
#include "stdafx.h"
#include "Packet.h"
#include "PacketTypes.h"

class CheckNickPacket : public Packet
{
private:
	bool allowed = false;
public:
	CheckNickPacket(bool);
	~CheckNickPacket() override;
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};