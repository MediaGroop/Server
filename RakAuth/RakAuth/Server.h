#pragma once
#include "stdafx.h"
#include <thread>
#include "ServerInfo.h"
#include "ConnectedClient.h"
#include "NetworkListener.h"

using namespace std;

class Server
{
public:	
	Server(NetworkListener * lis){
		this->listener = lis;
		this->peer = RakNet::RakPeerInterface::GetInstance();

	};
	static void startNetworkTrd(Server*, int, int);

	~Server(){};
	
	//Another ghost function
	bool initSecurity(const char*, const char*);
	
	RakNet::RakPeerInterface *peer;
	NetworkListener* listener;

	std::thread *networkTrd;

	bool running = false;
	bool secure = false;

	map<RakNet::RakNetGUID, ConnectedClient> _connections;

	void addClient(RakNet::RakNetGUID, ConnectedClient);
	bool hasClient(RakNet::RakNetGUID);
	ConnectedClient* getClient(RakNet::RakNetGUID);
	void removeClient(RakNet::RakNetGUID);
};