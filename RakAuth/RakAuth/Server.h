#pragma once
#include "stdafx.h"
#include "RakPeerInterface.h"
#include <map>
#include "ServerInfo.h"
#include "ConnectedClient.h"
#include <thread>
#include "NetworkListener.h"
#include "TCPInterface.h"

using namespace std;

class Server
{
public:	
	Server(NetworkListener * lis){
		this->listener = lis;
	};
	static void startNetworkTrd(Server*, int, int);

	~Server(){};
	
	//RakNet::TCPInterface* sslServer;
	
	RakNet::RakPeerInterface *peer;
	NetworkListener* listener;

	std::thread *networkTrd;

	bool running = false;

	map<RakNet::RakNetGUID, ConnectedClient> _connections;

	void addClient(RakNet::RakNetGUID, ConnectedClient);
	bool hasClient(RakNet::RakNetGUID);
	ConnectedClient* getClient(RakNet::RakNetGUID);
	void removeClient(RakNet::RakNetGUID);
};

