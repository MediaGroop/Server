#pragma once
#include "RakPeerInterface.h"
#include <map>
#include <functional>

using namespace std;

class NetworkListener
{
private:
	map<short, std::function<void(RakNet::Packet*)>> _handlers;
public:
	NetworkListener(){};
	~NetworkListener(){};
	void handle(RakNet::Packet* packet);
	void add(short, std::function<void(RakNet::Packet*)>);
};

