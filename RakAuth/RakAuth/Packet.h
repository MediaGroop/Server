#pragma once
#include "RakPeerInterface.h"

class Packet{
public:
	Packet();
	~Packet();
	virtual void send(RakNet::RakPeerInterface * by);
};