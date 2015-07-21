#pragma once
#include "ConnectedClient.h"
#include "AccountInfo.h"

class AuthClient :
	public ConnectedClient
{
public:
	AccountInfo account;
	AuthClient(RakNet::AddressOrGUID a);
	~AuthClient();
};

