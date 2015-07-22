#pragma once
#include "RakPeerInterface.h"
#include <map>
#include <functional>

using namespace std;

class NetworkListener
{
public:
	NetworkListener(){};
	~NetworkListener(){};
	map<short, std::function<void(RakNet::Packet*)>> _handlers;
	void handle(RakNet::Packet* packet);
	void add(short, std::function<void(RakNet::Packet*)>);
};

