#include "AuthClient.h"


AuthClient::AuthClient(RakNet::AddressOrGUID a) : ConnectedClient(a)
{
	account.authorized = false;
	account.beta = false;
	account.premium = false;

	account.login = "";
	account.password = "";
	account.mail = "";
}


AuthClient::~AuthClient()
{
}
