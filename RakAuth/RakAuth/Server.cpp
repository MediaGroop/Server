#include "Server.h"
#include "NetworkListener.h"
#include "easylogging++.h"
#include "ConfigLoader.h"

bool Server::hasClient(RakNet::RakNetGUID guid)
{
	if (getClient(guid) == nullptr)
		return false;
	return true;
}

ConnectedClient* Server::getClient(RakNet::RakNetGUID guid){
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = this->_connections.begin(); ii != this->_connections.end(); ++ii)
	{
		if ((*ii).first == guid) {
			return &(*ii).second;
		}
	}
	return NULL;
}

void Server::addClient(RakNet::RakNetGUID guid, ConnectedClient cl)
{
	this->_connections.insert(pair<RakNet::RakNetGUID, ConnectedClient>(guid, cl));
}

void Server::startNetworkTrd(Server* instance, int port, int maxPlayers)
{
	/*instance->sslServer = RakNet::OP_NEW<RakNet::TCPInterface>(__FILE__, __LINE__);
	instance->sslServer->Start(port, maxPlayers);

	RakNet::Packet *packet;

	instance->running = true;
	while (instance->running)
	{
		Sleep(1);
		for (packet = instance->sslServer->Receive(); packet; instance->sslServer->DeallocatePacket(packet), packet = instance->sslServer->Receive())
		{
			instance->listener->handle(packet);
		}
	}

	RakNet::TCPInterface::DestroyInstance(instance->sslServer);
	*/
	instance->peer = RakNet::RakPeerInterface::GetInstance();
	RakNet::Packet *packet;

	RakNet::SocketDescriptor sd(port, 0);
	instance->peer->Startup(maxPlayers, &sd, 1);
	//LOG(INFO) << "Starting the server...";
	instance->peer->SetMaximumIncomingConnections(maxPlayers);
	LOG(INFO) << "Server has been started! Listening for conections...";
	instance->running = true;
	while (instance->running)
	{
		Sleep(1);
		for (packet = instance->peer->Receive(); packet; instance->peer->DeallocatePacket(packet), packet = instance->peer->Receive())
		{
			instance->listener->handle(packet);
		}
	}


	RakNet::RakPeerInterface::DestroyInstance(instance->peer);
}

void Server::removeClient(RakNet::RakNetGUID guid)
{
//	LOG(INFO) << _connections.size();
	for (map<RakNet::RakNetGUID, ConnectedClient>::iterator ii = this->_connections.begin(); ii != this->_connections.end(); ++ii)
	{
//		LOG(INFO) << "1 - ";
//		LOG(INFO) << (*ii).first.ToString();
//		LOG(INFO) << "2 - ";
//		LOG(INFO) << guid.ToString();
		if ((*ii).first == guid) {
			this->_connections.erase((*ii).first);
			return;
		}
	}
	LOG(INFO) << "There's no client with given guid!";
}
