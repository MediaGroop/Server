#pragma once
#include <string>
#include "ServerState.h"
#include "ServerClient.h"

using namespace std;

class ServerInfo
{
public:
	//Server host
	std::string host;
	//Name of server
	std::string name;
	//port!
	int port;
	//Server connection
	ConnectedClient* associatedClient;
	//Server status
	ServerState state;

	ServerInfo(std::string h, int p, ConnectedClient *c, ServerState s, std::string n)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
		this->name = n;
	};

	ServerInfo(const char * h, int p, ConnectedClient *c, ServerState s, std::string n)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
		this->name = n;
	};

};