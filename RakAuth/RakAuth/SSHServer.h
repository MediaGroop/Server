#pragma once
#include "libssh/libssh.h"
#include "libssh/server.h"
#include "libssh/callbacks.h"
#include <thread>
using namespace std;

//SSH Server class
class SSHServer{
private:
	ssh_session session;
	ssh_bind sshBind;
	ssh_channel chan = 0;
	int sshPort= 4434;
	shared_ptr<thread> trd;
	static void startListenThread(SSHServer*);
	bool running = false;
public:
	SSHServer(int);
	~SSHServer();
	int start();
};


//Some ghost function, just for handling control over it
SSHServer* startSSHServer(int port){
	SSHServer s(port);
	if (s.start() > 0)
		return &s;
	else
		return nullptr;
}