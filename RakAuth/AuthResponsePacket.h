#pragma once
#include "Packet.h"
#include "RakString.h"

class AuthResponsePacket : public Packet
{
private:
	// 0 - no user, 1 - wrong credentials,  2 - not premium, 3 - success, 4 - already logged in
	unsigned char id;
	unsigned char session[20];
	bool premium = false;
	bool beta = false;
	RakNet::RakString mail;
public:
	// just id(wrong credentials, no username, no premium, already logged)
	AuthResponsePacket(unsigned char);
	// id with session(success) and account info
	AuthResponsePacket(unsigned char, unsigned char s[20], bool, bool, RakNet::RakString);
	~AuthResponsePacket();
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to) override;
};