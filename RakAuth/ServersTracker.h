#pragma once
#include <map>
#include "ConnectedClient.h"
#include "ServerInfo.h"
#include "easylogging++.h"

//#region servers container
static std::map<int, ServerInfo> _servers; // Server id, serverInfo


ServerInfo* getServer(ConnectedClient* id){
	for (std::map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).second.getAssocClient() == id)
			return &(*ii).second;
	}
	return NULL;
};

ServerInfo* getServer(int id){
	for (std::map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).first == id) {
			return &(*ii).second;
		}
	}
	return NULL;
};

bool hasServer(int id)
{
	if (getServer(id) == nullptr)
		return false;
	return true;
};

void addServer(int id, ServerInfo cl)
{
	_servers.insert(pair<int, ServerInfo>(id, cl));
};

void removeServer(ConnectedClient* c){
	for (std::map<int, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).second.getAssocClient() == c) {
			_servers.erase((*ii).first);
			return;
		}
	}
	LOG(INFO) << "There's no info bout this server!";
};
//#endregion