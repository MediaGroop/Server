#include "VerifyResponsePacket.h"
#include "PacketTypes.h"

void VerifyResponsePacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to)
{
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)VERIFY_RESPONSE);
	bsOut.Write(result);
	bsOut.Write(hash);
	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
}