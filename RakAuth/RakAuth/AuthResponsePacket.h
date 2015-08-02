#pragma once
#include "Packet.h"
#include "RakString.h"

class AuthResponsePacket : public Packet
{
private:
	// 0 - no user, 1 - wrong credentials,  2 - not premium, 3 - success, 4 - wrong server id
	unsigned char id;
	RakNet::RakString session;
	RakNet::RakString address;
	int port;
public:
	// just id(wrong credentials, no username, no premium)
	AuthResponsePacket(unsigned char);
	// id with session(success), address and port
	AuthResponsePacket(unsigned char, RakNet::RakString, RakNet::RakString address, int port);
	~AuthResponsePacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};