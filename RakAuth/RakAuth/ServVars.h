#pragma once
#include "stdafx.h"
#include "Server.h"
#include "odb\database.hxx"
#include "odb\pgsql\database.hxx"

//#region vars
//Security keys
static char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
static char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

static Server* authServer;
static Server* poolerServer;

std::auto_ptr<odb::database> dataBase(new odb::pgsql::database(
	"postgres",
	"root",
	"data",
	"localhost"));

//#endregion