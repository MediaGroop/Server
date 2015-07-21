#pragma once

#include <stdio.h>
#include <string.h>
#include "stdafx.h"
#include "RakPeerInterface.h"
#include "BitStream.h"
#include "easylogging++.h"
#include <ctime>
#include "FileManager.h"
#include "ConfigLoader.h"
#include <thread>
#include <map>
#include "ServerInfo.h"
#include "ConnectedClient.h"
#include "Server.h"
#include "NetworkListener.h"
#include "PacketTypes.h"
#include "AuthClient.h"
#include "StringCompressor.h"

using namespace FileManager;

#define ELPP_STL_LOGGING
#define ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_LOG_STD_ARRAY
#define ELPP_LOG_UNORDERED_MAP
#define ELPP_UNORDERED_SET
#define ELPP_THREAD_SAFE

static Server* authServer;
static Server* poolerServer;

INITIALIZE_EASYLOGGINGPP

void setupLog(){
	time_t t;
	t = time(0);
	char str[64];

	getcwd(str, 64);
	if (!FileManager::DirExists(strcat(str, "\\logs\\"))){
		mkdir(str);
	}

	std::string log_name = "logs\\";
	log_name.append(asctime(localtime(&t)));
	log_name[log_name.length() - 1] = ' ';
	log_name.append(".txt");

	for (int i = 0; i < log_name.length(); ++i)
	{
		if (log_name[i] == ':' || log_name[i] == ' ' || log_name[i] == '\r')
		{
			log_name[i] = '_';
		}
	}

	el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Filename, log_name);
}

map<std::string, ServerInfo> _servers;


ServerInfo* getServer(ConnectedClient* c)
{
	for (map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).second.associatedClient->addr == c->addr){
			return &(*ii).second;
		}
	}
	return NULL;
}

ServerInfo* getServer(std::string name){
	for (map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if ((*ii).first == name) {
			return &(*ii).second;
		}
	}
	return NULL;
}

bool hasServer(std::string name)
{
	if (getServer(name) == nullptr)
		return false;
	return true;
}
void addServer(std::string name, ServerInfo cl)
{
	_servers.insert(pair<std::string, ServerInfo>(name, cl));
}

void removeServer(ServerInfo* ptr){
	for (map<std::string, ServerInfo>::iterator ii = _servers.begin(); ii != _servers.end(); ++ii)
	{
		if (&((*ii).second) == ptr) {
			_servers.erase((*ii).first);
			return;
		}
	}
	LOG(INFO) << "There's no info bout this server!";
}

void handleDisconnectFromPooler(RakNet::Packet * p)
{
	ServerInfo* ptr = getServer(poolerServer->getClient(p->guid));
	if (ptr != nullptr)
	{
		removeServer(ptr);
	}
	poolerServer->removeClient(p->guid);
	LOG(INFO) << "Server was removed!";
}

void handleDisconnectFromAuth(RakNet::Packet * p)
{
	ConnectedClient* c = authServer->getClient(p->guid);
	if (c != nullptr)
	{
		
	}
	LOG(INFO) << "Removing client";
	//LOG(INFO) << "GUID:";
	//LOG(INFO) << p->guid.ToString();
	authServer->removeClient(p->guid);
	LOG(INFO) << "Client was removed!";
}

void handleconn(RakNet::Packet *packet){
	LOG(INFO) << "Incoming connection for pooler!";
	if (!poolerServer->hasClient(packet->guid)) // Won't it always be true?
	{
		ConnectedClient cl(packet->systemAddress);
		poolerServer->addClient(packet->guid, cl);
	}
}


void handleAuthconn(RakNet::Packet *packet){
	LOG(INFO) << "Incoming connection for authenticator!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	if (!authServer->hasClient(packet->guid)) // Won't it always be true?
	{
		AuthClient cl(packet->systemAddress);
		authServer->addClient(packet->guid, cl);
	}
}

void loadAccInfo(AuthClient* ac){
	//PGresult* res = dbWorker->executeQuery();

}


void onFinishLoadAcc(AuthClient* ac)
{

}

void handleAuth(RakNet::Packet *packet){
	LOG(INFO) << "Auth request!";
	LOG(INFO) << "GUID:";
	LOG(INFO) << packet->guid.ToString();
	ConnectedClient* cl = authServer->getClient(packet->guid);

	if (cl != nullptr) // Won't it always be true?
	{
		RakNet::BitStream bsIn(packet->data, packet->length, false);
		bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
		RakNet::RakString acc, pas;
		RakNet::StringCompressor::Instance()->DecodeString(&acc, 256, &bsIn);
		RakNet::StringCompressor::Instance()->DecodeString(&pas, 256, &bsIn);
		
		int serverId;
		bsIn.Read(serverId);
		
		LOG(INFO) << "Credentials:";
		LOG(INFO) << "Account: ";
		LOG(INFO) << acc.C_String();
		LOG(INFO) << "Password: ";
		LOG(INFO) << pas.C_String();
		LOG(INFO) << "ServerId:";
		LOG(INFO) << serverId;

		AuthClient* ac = (AuthClient*)cl;
		loadAccInfo(ac);
		onFinishLoadAcc(ac);
	}
}


void handleWrongKey(RakNet::RakNetGUID guid){
	LOG(INFO) << "Wrong key!";
}

void handlePoolerAuth(RakNet::Packet *packet)
{
	RakNet::RakString key, shardName;
	int port, length;
	RakNet::BitStream bsIn(packet->data, packet->length, false);
	bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
	
	bsIn.Read(key);
	LOG(INFO) << "Our key is: " + ConfigLoader::getVal("Pooler-Key");
	LOG(INFO) << "Their key is: ";
	LOG(INFO) << key.C_String();
	if (key == ConfigLoader::getVal("Pooler-Key").c_str()){
		bsIn.Read(shardName);
		bsIn.Read(port);
		if (!hasServer(std::string(shardName))){
			ServerInfo info(packet->systemAddress.ToString(false), port, poolerServer->getClient(packet->guid), ServerState::ONLINE);
			addServer(shardName.C_String(), info);
			LOG(INFO) << "Registering " + shardName + " at IP " + packet->systemAddress.ToString(false) + ":" << port;
		}
	}
	else
	{
		handleWrongKey(packet->guid);
	}
}

/*boolean loadKeys()
{
	FILE *fp;
	char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
	char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

	fp = fopen("private", "rb");
	if (fp)
	{
		fread(private_key, sizeof(private_key), 1, fp);
		fclose(fp);
		LOG(INFO) << "Private key is loaded!";
	}
	else{
		LOG(INFO) << "Private key isn't loaded!";
		return false;
	}

	fp = fopen("public", "rb");
	if (fp)
	{
		fread(public_key, sizeof(public_key), 1, fp);
		fclose(fp);
		LOG(INFO) << "Public key is loaded!";
	}
	else{
		LOG(INFO) << "Public key isn't loaded!";
		return false;
	}
	return true;
}*/


//Entry point for server
//Init log
//Init configuration
//Init SSH tunnel
//Init auth server(for players)
//Init pooler server(for registering servers)
int _tmain(int argc, _TCHAR* argv[])
{
	char str[23];
	setupLog();
	LOG(INFO) << "Log was initialized...";
	ConfigLoader::init();
	LOG(INFO) << "Configuration loaded...";
	
	//dbWorker = &DatabaseWorker();
	//dbWorker->init();

	//Auth server
	NetworkListener listen;
	listen.add((short)ID_NEW_INCOMING_CONNECTION, handleAuthconn);
	listen.add((short)ID_CONNECTION_LOST, handleDisconnectFromAuth);
	listen.add((short)ACCOUNT_AUTH, handleAuth);

	Server authSrv(&listen);

	authServer = &authSrv;
	std::thread trd1(authServer->startNetworkTrd, authServer, ConfigLoader::getIntVal("Auth-Port"), ConfigLoader::getIntVal("Auth-MaxCons"));
	authServer->networkTrd = &trd1;
	/*if (!loadKeys()){
		FILE *fp;
		cat::EasyHandshake::Initialize();
		cat::EasyHandshake handshake;
		char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
		char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];
		handshake.GenerateServerKey(public_key, private_key);
		
		fp = fopen("private", "wb");
		fwrite(private_key, sizeof(private_key), 1, fp);
		fclose(fp);

		fp = fopen("public", "wb");
		fwrite(public_key, sizeof(public_key), 1, fp);
		fclose(fp);

		loadKeys();
	}*/
	//Auth server end
	
	LOG(INFO) << "Auth server was started!";

	//Pooler server
	NetworkListener plisten;
	plisten.add((short)ID_NEW_INCOMING_CONNECTION, handleconn);
	plisten.add((short)AUTH_TO_POOLER, handlePoolerAuth);
	plisten.add((short)ID_DISCONNECTION_NOTIFICATION, handleDisconnectFromPooler);
	//plisten.add((short)CHANGE_SERVER_STATE, handleChangeState); will be implemented in future
	//plisten.add((short)VERIFY_REQUEST, handleVerification); will be implemented in future

	Server poolSrv(&plisten);

	poolerServer = &poolSrv;
	std::thread trd2(poolerServer->startNetworkTrd, poolerServer, ConfigLoader::getIntVal("Pooler-Port"), ConfigLoader::getIntVal("Pooler-MaxCons"));
	poolerServer->networkTrd = &trd2;
	//Pooler server end
	
	LOG(INFO) << "Pooler server was started!";

	cin >> str;
	
	LOG(INFO) << "Stopping auth server...";
	authServer->running = false;
	authServer->networkTrd->join();

	LOG(INFO) << "Stopping pooler server...";
	poolerServer->running = false;
	poolerServer->networkTrd->join();
	
	return 0;
}