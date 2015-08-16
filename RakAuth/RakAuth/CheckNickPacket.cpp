#include "CheckNickPacket.h"

CheckNickPacket::CheckNickPacket(bool p) : allowed(p){};

CheckNickPacket::~CheckNickPacket(){};

void CheckNickPacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to){
	RakNet::BitStream bsOut;
	
	bsOut.Write((RakNet::MessageID)CHECK_NICKNAME);
	bsOut.Write(allowed);

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
};