#include "AuthResponsePacket.h"
#include "BitStream.h"
#include "PacketTypes.h"

AuthResponsePacket::AuthResponsePacket(unsigned char i) : id(i){};

AuthResponsePacket::AuthResponsePacket(unsigned char i, RakNet::RakString s, RakNet::RakString addr, int p) : id(i), session(s), address(addr), port(p){};

AuthResponsePacket::~AuthResponsePacket(){};

void AuthResponsePacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to)
{
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)AUTH_RESPONCE);
	bsOut.Write(id);
	if (id == 3)
	{
		bsOut.Write(session);
		bsOut.Write(address);
		bsOut.Write(port);

	}

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
};