#pragma once

#include "stdafx.h"
#include "easylogging++.h"
#include <ctime>
#include <tchar.h>
#include "PacketTypes.h"
#include "FileManager.h"
#include "ConnectedClient.h"
#include "AuthClient.h"
#include "ConfigLoader.h"
#include "ServVars.h"
#include "ServersTracker.h"

//Handlers
//Pooler
#include "PoolerConnectHandler.h"
#include "ServerRegisterHandler.h"
#include "PoolerDisconnectHandler.h"
//Auth
#include "AuthConnectHandler.h"
#include "AuthDisconnectHandler.h"
#include "AuthRequestHandler.h"

using namespace FileManager;

#define ELPP_STL_LOGGING
#define ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_LOG_STD_ARRAY
#define ELPP_LOG_UNORDERED_MAP
#define ELPP_UNORDERED_SET
#define ELPP_THREAD_SAFE

INITIALIZE_EASYLOGGINGPP


//My first function on C++, he-he...
//Configures easyLogging
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

//Reading keys from files located in same directory as server
boolean loadKeys()
{
	FILE *fp;	

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
	LOG(INFO) << "Security keys have loaded!";

	return true;
}

//Entry point for server
//Init log
//Init configuration
//Load security keys
//Init auth server(for players)
//Init pooler server(for registering servers)
int _tmain(int argc, _TCHAR* argv[])
{
	char str[23];
	setupLog();
	LOG(INFO) << "Log was initialized...";
	ConfigLoader::init("config.ini");
	LOG(INFO) << "Configuration loaded...";
	
	//Generating and saving public and private keys
	if (!loadKeys())
	{
		cat::EasyHandshake::Initialize();
		cat::EasyHandshake handshake;
		handshake.GenerateServerKey(public_key, private_key);
		FILE *fp;
		fp = fopen("private", "w");
		fwrite(private_key, sizeof(private_key), 1, fp);
		fclose(fp);
		fp = fopen("public", "w");
		fwrite(public_key, sizeof(public_key), 1, fp);
		fclose(fp);
		LOG(INFO) << "Security keys have generated!";
	//	loadKeys();
	}

	//Auth server
	NetworkListener listen;
	listen.add((short)ID_NEW_INCOMING_CONNECTION, handleAuthconn);
	listen.add((short)ID_CONNECTION_LOST, handleDisconnectFromAuth);
	listen.add((short)ACCOUNT_AUTH, handleAuth);

	Server authSrv(&listen);

	authServer = &authSrv;
	authServer->initSecurity(public_key, private_key);//Must be called before starting network thread! (See RakPeerInterface.h for info)

	std::thread trd1(authServer->startNetworkTrd, authServer, ConfigLoader::getIntVal("Auth-Port"), ConfigLoader::getIntVal("Auth-MaxCons"));
	authServer->networkTrd = &trd1;
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

	//TODO: start command reader loop
	cin >> str; // just for blocking
	
	LOG(INFO) << "Stopping auth server...";
	authServer->running = false;
	authServer->networkTrd->join();

	LOG(INFO) << "Stopping pooler server...";
	poolerServer->running = false;
	poolerServer->networkTrd->join();
	
	return 0;
}