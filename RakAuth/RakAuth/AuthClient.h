#pragma once
#include "ConnectedClient.h"
#include "AccountInfo.h"
#include "stdafx.h"

class AuthClient :
	public ConnectedClient
{
public:
	RakNet::RakString session;
	AccountInfo* account;
	AuthClient(RakNet::AddressOrGUID a);
	~AuthClient();
};

