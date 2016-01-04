#include "AuthResponsePacket.h"
#include "BitStream.h"
#include "PacketTypes.h"

AuthResponsePacket::AuthResponsePacket(unsigned char i) : id(i){};

AuthResponsePacket::AuthResponsePacket(unsigned char i, unsigned char s[20], bool p, bool b, RakNet::RakString m) : id(i), premium(p), beta(b), mail(m){
	for (int i = 0; i < 20; ++i)
	{
		session[i] = s[i];
	}
};

AuthResponsePacket::~AuthResponsePacket(){};

void AuthResponsePacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to)
{
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)AUTH_RESPONCE);
	bsOut.Write(id);

	if (id == 3)
	{
		for (int i = 0; i < 20; ++i)
			bsOut.Write(session[i]);

		bsOut.Write(mail);
		bsOut.Write(premium);
		bsOut.Write(beta);
	}

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
};