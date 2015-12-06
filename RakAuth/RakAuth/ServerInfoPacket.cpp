#include "ServerInfoPacket.h"
#include "PacketTypes.h"

ServerInfoPacket::ServerInfoPacket(RakNet::RakString add, int p) : addr(add), port(p){

};

ServerInfoPacket::~ServerInfoPacket(){};

void ServerInfoPacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to){
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)SERVER_INFO);

	bsOut.Write(addr);
	bsOut.Write(port);

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
};
