#pragma once
#include "stdafx.h"
#include "Server.h"
//#region vars

//char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES] = {0,   1,   34,  5,   35,   65,  8,   75,  35,  67, 
//														 8,   6,   143, 2,   167,  8,   5,   5,   98,  21,
//														 3,   228, 26,  245, 237,  2,   56,  54,  25,  64,
//														 2,   46,  4,   123, 34,   23,  43,  23,  49,  1,
//														 2,   5,   56,  34,  0 ,   12,  23,  76,  165, 123,
//														 128, 185, 232, 123, 45,   43,  45,  153, 143, 197,
//														 0,   0,   13,  43};
//Security keys
static char public_key[cat::EasyHandshake::PUBLIC_KEY_BYTES];
static char private_key[cat::EasyHandshake::PRIVATE_KEY_BYTES];

static Server* authServer;
static Server* poolerServer;
//#endregion