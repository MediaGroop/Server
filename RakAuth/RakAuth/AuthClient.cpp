#include "AuthClient.h"


AuthClient::AuthClient(){
	this->account = *new AccountInfo;
};


AuthClient::~AuthClient()
{
	LOG(INFO) << "Auth dctor";
};
