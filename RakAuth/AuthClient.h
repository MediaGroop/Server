#pragma once
#include "ConnectedClient.h"
#include "AccountInfo.h"
#include "stdafx.h"

class AuthClient
{
private:
	unsigned char session[20];
	bool authorized_ = false;
	AccountInfo account;
	int serverId = -1; // > -1, if logged 
public:

	int getServerId()
	{
		return serverId;
	}

	void setServerId(int i)
	{
		this->serverId = i;
	}

	void setAuthorized(bool a)
	{
		this->authorized_ = a;
	}

	AuthClient();
	~AuthClient();
	
	AccountInfo* getAccount()
	{
		return &this->account;
	}

	bool authorized(){
		return this->authorized_;
	}

	unsigned char* getSession()
	{
		return session;
	}

	void setSession(unsigned char* s)
	{
		for (int i = 0; i < 20; ++i)
			this->session[i] = s[i];
	}

};

