#pragma once
#include "stdafx.h"
#include "Server.h"
//#region vars

//Security keys
static char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
static char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

static Server* authServer;
static Server* poolerServer;
//#endregion