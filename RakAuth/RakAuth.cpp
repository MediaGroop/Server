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
#include "ClientVerifyRequestHandler.h"
//Auth
#include "AuthConnectHandler.h"
#include "AuthDisconnectHandler.h"
#include "AuthRequestHandler.h"
#include "CheckNicknameHandler.h"
#include "CreateCharacterHandler.h"
#include "CharRequestHandler.h"
#include "CharDeleteHandler.h"
#include "ServInfoRequestHandler.h"

using namespace FileManager;

#define ELPP_STL_LOGGING
#define ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_LOG_STD_ARRAY
#define ELPP_LOG_UNORDERED_MAP
#define ELPP_UNORDERED_SET
#define ELPP_THREAD_SAFE
#define ELPP_EXPERIMENTAL_ASYNC 

INITIALIZE_EASYLOGGINGPP

//extern vars

static char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
static char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

static Server* authServer;
static Server* poolerServer;

std::auto_ptr<odb::database> dataBase;


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
		char str[12];
		//for (int i = 0; i < sizeof(public_key) / sizeof(char); ++i)
		//{
			//itoa(i, str, 10);
			//LOG(INFO) << str;
			//LOG(INFO) << "\/";
			//itoa(public_key[i], str, 10);
			//LOG(INFO) << str;
			//LOG(INFO) << "______";
		//}
		LOG(INFO) << "Public key is loaded!";
	}
	else{
		LOG(INFO) << "Public key isn't loaded!";
		return false;
	}
	LOG(INFO) << "Security keys have loaded!";

	return true;
}

void handlefail(RakNet::Packet* p)
{
	LOG(INFO) << "Client failed to connect!";
};


void handleReq(RakNet::Packet* p)
{
	LOG(INFO) << "Client requested to connect!";
};

void handleReqAcc(RakNet::Packet* p)
{
	LOG(INFO) << "Client connect request accepted!";
};

void handlePubKey(RakNet::Packet* p)
{
	LOG(INFO) << "Client require public key!";
};

void handleWrgKey(RakNet::Packet* p)
{
	LOG(INFO) << "Client has wrong key!";
};

void handleInitSec(RakNet::Packet* p)
{
	LOG(INFO) << "We need to init security!";
};


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
	dataBase = *new std::auto_ptr<odb::database>(new odb::pgsql::database(
		ConfigLoader::getVal("Database-User"),
		ConfigLoader::getVal("Database-Pass"),
		ConfigLoader::getVal("Database-DBName"),
		ConfigLoader::getVal("Database-DBAddress")));

	//Generating and saving public and private keys
	if (!loadKeys())
	{
		cat::EasyHandshake::Initialize();
		cat::EasyHandshake handshake;
		handshake.GenerateServerKey(public_key, private_key);
		FILE *fp;
		fp = fopen("private", "wb");
		fwrite(private_key, sizeof(private_key), 1, fp);
		fclose(fp);
		fp = fopen("public", "wb");
		fwrite(public_key, sizeof(public_key), 1, fp);
		fclose(fp);
		LOG(INFO) << "Security keys have generated!";
	//	loadKeys();
	}

	//Auth server
	NetworkListener listen;
	listen.add((short)ID_NEW_INCOMING_CONNECTION, handleAuthConn);
	listen.add((short)ID_CONNECTION_LOST, handleDisconnectFromAuth);
	listen.add((short)ACCOUNT_AUTH, handleAuth);
	listen.add((short)CHECK_NICKNAME, handleNickCheck);
	listen.add((short)CREATE_CHARACTER, handleCharacterCreation);
	listen.add((short)REQUEST_CHARACTER_INFO, charReqHandler);
	listen.add((short)DELETE_CHARACTER, charDelHandle);
	listen.add((short)SERVER_INFO, serverInfoRequestHandle);

	//Debug connection
	listen.add((short)ID_CONNECTION_ATTEMPT_FAILED, handlefail);
	listen.add((short)ID_CONNECTION_REQUEST, handleReq);
	listen.add((short)ID_CONNECTION_REQUEST_ACCEPTED, handleReqAcc);
	listen.add((short)ID_REMOTE_SYSTEM_REQUIRES_PUBLIC_KEY, handlePubKey);
	listen.add((short)ID_PUBLIC_KEY_MISMATCH, handleWrgKey);
	listen.add((short)ID_OUR_SYSTEM_REQUIRES_SECURITY, handleInitSec);

	Server authSrv(&listen);

	authServer = &authSrv;
	authServer->initSecurity(public_key, private_key);//Must be called before starting network thread! (See RakPeerInterface.h for info)
	std::thread trd1(authServer->startNetworkTrd, authServer, ConfigLoader::getIntVal("Auth-Port"), ConfigLoader::getIntVal("Auth-MaxCons"));
	authServer->setThread(&trd1);
	//Auth server end
	
	LOG(INFO) << "Auth server was started!";

	//Pooler server
	NetworkListener plisten;
	plisten.add((short)ID_NEW_INCOMING_CONNECTION, handleconn);
	plisten.add((short)AUTH_TO_POOLER, handlePoolerAuth);
	plisten.add((short)ID_CONNECTION_LOST, handleDisconnectFromPooler);
	plisten.add((short)ID_DISCONNECTION_NOTIFICATION, handleDisconnectFromPooler);
	plisten.add((short)VERIFY_ACCOUNT, handleVerifyRequest);

	
	//plisten.add((short)CHANGE_SERVER_STATE, handleChangeState); will be implemented in future
	//plisten.add((short)VERIFY_REQUEST, handleVerification); will be implemented in future

	Server poolSrv(&plisten);

	poolerServer = &poolSrv;
	std::thread trd2(poolerServer->startNetworkTrd, poolerServer, ConfigLoader::getIntVal("Pooler-Port"), ConfigLoader::getIntVal("Pooler-MaxCons"));
	poolerServer->setThread(&trd2);
	//Pooler server end
	
	LOG(INFO) << "Pooler server was started!";

	//TODO: start command reader loop
	cin >> str; // just for blocking
	
	LOG(INFO) << "Stopping auth server...";
	authServer->setRunning(false);
	authServer->getThread()->join();

	LOG(INFO) << "Stopping pooler server...";
	poolerServer->setRunning(false);
	poolerServer->getThread()->join();
	
	return 0;
}