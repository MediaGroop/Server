#include "RemoveCharacter.h"
#include "PacketTypes.h"

RemoveCharacter::RemoveCharacter(RakNet::RakString c) : char_name_(c)
{
}


RemoveCharacter::~RemoveCharacter()
{
}

void RemoveCharacter::send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to){
	RakNet::BitStream bsOut;

	bsOut.Write((RakNet::MessageID)DELETE_CHARACTER);
	RakNet::StringCompressor::Instance()->EncodeString(&char_name_, 256, &bsOut);

	by->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, to, false);

};