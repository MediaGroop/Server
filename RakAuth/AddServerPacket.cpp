#include "AddServerPacket.h"
#include "PacketTypes.h"

AddServerPacket::AddServerPacket(RakNet::RakString ad, int p) : addr(ad), id(p){};


AddServerPacket::~AddServerPacket(){};

void AddServerPacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to)
{
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)SERVER_INFO);
	
	bsOut.Write(addr);
	bsOut.Write(id);

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);

};