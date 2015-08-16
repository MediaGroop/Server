#include "AddCharacterPacket.h"
#include "PacketTypes.h"

AddCharacterPacket::AddCharacterPacket(RakNet::RakString char_name, RakNet::RakString serv_name) : char_name_(char_name), server_name_(serv_name)
{
}


AddCharacterPacket::~AddCharacterPacket()
{
}

void AddCharacterPacket::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to){
	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)CREATE_CHARACTER);

	RakNet::StringCompressor::Instance()->EncodeString(char_name_, 256, &bsOut);
	RakNet::StringCompressor::Instance()->EncodeString(server_name_, 256, &bsOut);
	
	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);
}
