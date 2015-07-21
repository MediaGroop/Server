#pragma once
#include <string>
#include "ServerState.h"
#include "ConnectedClient.h"

using namespace std;

class ServerInfo
{
public:
	std::string host;
	int port;
	ConnectedClient* associatedClient;
	ServerState state;

	ServerInfo(std::string h, int p, ConnectedClient *c, ServerState s)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
	};

	ServerInfo(const char * h, int p, ConnectedClient *c, ServerState s)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
	};

};