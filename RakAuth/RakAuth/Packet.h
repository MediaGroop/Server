#pragma once
#include "RakPeerInterface.h"

class Packet{
public:
	Packet(){};
	virtual ~Packet(){};
	virtual void send(RakNet::RakPeerInterface * by, RakNet::AddressOrGUID to){};
};