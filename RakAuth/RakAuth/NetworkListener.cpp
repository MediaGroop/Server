#include "NetworkListener.h"
#include "MessageIdentifiers.h"
#include "easylogging++.h"
#include "Server.h"
#include "PacketTypes.h"
#include "BitStream.h"
#include "ConfigLoader.h"

void NetworkListener::handle(RakNet::Packet *packet){

	short s = packet->data[0];
	LOG(INFO) << "A message with ID: " << s << " has been arrived!";
	for (map<short, std::function<void(RakNet::Packet*)>>::iterator ii = this->_handlers.begin(); ii != this->_handlers.end(); ++ii)
	{
		if ((*ii).first == packet->data[0])
		{
			(*ii).second(packet);
			break;
		}
	}
}

void NetworkListener::add(short id, std::function<void(RakNet::Packet*)> exec){
	this->_handlers.insert(pair<short, std::function<void(RakNet::Packet*)>>(id, exec));
}