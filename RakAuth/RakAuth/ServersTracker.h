#pragma once
#include <map>
#include "ConnectedClient.h"
#include "ServerInfo.h"
#include "easylogging++.h"

//#region servers container
static std::map<std::string, ServerInfo> _servers;


ServerInfo* getServer(ConnectedClient* c)
{
	for (std::map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).second.associatedClient->addr == c->addr){
			return &(*ii).second;
		}
	}
	return NULL;
};

ServerInfo* getServer(std::string name){
	for (std::map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).first == name) {
			return &(*ii).second;
		}
	}
	return NULL;
};

bool hasServer(std::string name)
{
	if (getServer(name) == nullptr)
		return false;
	return true;
};

void addServer(std::string name, ServerInfo cl)
{
	_servers.insert(pair<std::string, ServerInfo>(name, cl));
};

void removeServer(ServerInfo* ptr){
	for (std::map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if (&((*ii).second) == ptr) {
			_servers.erase((*ii).first);
			return;
		}
	}
	LOG(INFO) << "There's no info bout this server!";
};
//#endregion