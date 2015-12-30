#pragma once
#include <map>
#include "AuthClient.h"
#include "ConnectedClient.h"

static std::map<ConnectedClient*, AuthClient> _clients;

//ghost function, just for fance code
void addAuthClient(ConnectedClient* cPtr, AuthClient acPtr)
{
	_clients.insert(pair<ConnectedClient*, AuthClient>(cPtr, acPtr));
}

AuthClient* getAuthClient(ConnectedClient* c)
{
	for (std::map<ConnectedClient*, AuthClient>::iterator ii = _clients.begin(); ii != _clients.end(); ++ii)
	{
		if ((*ii).first == c){
			return &(*ii).second;
		}
	}
	return NULL;
};