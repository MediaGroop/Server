#include "AuthClient.h"


AuthClient::AuthClient(RakNet::AddressOrGUID a) : ConnectedClient(a){
	//AccountInfo acc("", 0, "", false, false);
	//account = &acc;
};


AuthClient::~AuthClient()
{
};
