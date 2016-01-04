#pragma once
#include "stdafx.h"
#include "Server.h"
#include "odb/database.hxx"
#include "odb/pgsql/database.hxx"

//#region vars
//Security keys
extern char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
extern char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

extern Server* authServer;
extern Server* poolerServer;

extern std::auto_ptr<odb::database> dataBase;

//#endregion