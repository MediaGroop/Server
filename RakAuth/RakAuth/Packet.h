#pragma once
#include <string.h>
#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "BitStream.h"
#include "RakNetTypes.h"  // MessageID

namespace Packets{
	class Packet{
	public:
		Packet();
		~Packet();
		virtual void send(RakNet::RakPeerInterface * by);
	};
}