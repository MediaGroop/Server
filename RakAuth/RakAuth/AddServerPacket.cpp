#include "AddServerPacket.h"
#include "PacketTypes.h"

AddServerPacket::AddServerPacket(RakNet::RakString n,  int p) : name(n), id(p)
{
}


AddServerPacket::~AddServerPacket()
{
}

void AddServerPacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to)
{
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)ADD_SERVER);
	
	bsOut.Write(name);
	bsOut.Write(id);

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
}