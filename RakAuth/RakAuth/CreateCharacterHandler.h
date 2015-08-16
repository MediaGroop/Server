#pragma once 
#include "ServVars.h"

void handleCharacterCreation(RakNet::Packet* p)
{
	RakNet::BitStream bsIn(p->data, p->length, false);
	bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
	RakNet::RakString nick, server; // TODO: of course, add data
	bsIn.Read(server);
	bsIn.Read(nick);
	//Translate this packet on requested server -> handle it there -> send response -> send addchar or nothing depend on result
};