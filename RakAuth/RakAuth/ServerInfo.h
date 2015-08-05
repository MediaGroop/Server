#pragma once
#include <string>
#include "ServerState.h"
#include "ConnectedClient.h"

using namespace std;

class ServerInfo
{
private:
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
	//id
	int serverId;
public:

	void setId(int i)
	{
		this->serverId = i;
	}

	int getId()
	{
		return serverId;
	}

	std::string getHost(){
		return this->host;
	}

	std::string getName(){
		return this->name;
	}

	int getPort(){
		return this->port;
	}

	ConnectedClient* getAssocClient()
	{
		return this->associatedClient;
	}

	ServerState getState()
	{
		return state;
	}

	ServerInfo(std::string h, int p, ConnectedClient *c, ServerState s, std::string n, int i)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
		this->name = n;
		this->serverId = i;
	};

	ServerInfo(const char * h, int p, ConnectedClient *c, ServerState s, std::string n, int i)
	{
		this->host = h;
		this->port = p;
		this->associatedClient = c;
		this->state = s;
		this->name = n;
		this->serverId = i;
	};

};