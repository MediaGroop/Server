#pragma once
#include "ConnectedClient.h"

//ghost class
class ServerClient :
	public ConnectedClient
{
public:
	int id; //server id for chaining
	ServerClient(RakNet::AddressOrGUID adr) : ConnectedClient(adr){};
	~ServerClient(){};
};

