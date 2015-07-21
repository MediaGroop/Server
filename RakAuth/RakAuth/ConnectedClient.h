#pragma once
#include "RakPeerInterface.h"

class ConnectedClient
{
public:
	RakNet::AddressOrGUID addr;

	ConnectedClient(RakNet::AddressOrGUID a){
		this->addr = a;
	};

	~ConnectedClient(){};
};