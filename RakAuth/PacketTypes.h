#pragma once
#include "MessageIdentifiers.h"

enum GameMessages
{
	ID_GAME_MESSAGE_1 = 135,

	//Server auth
	AUTH_TO_POOLER = 136,

	//Client auth and response to it
	ACCOUNT_AUTH = 137,
	AUTH_RESPONCE = ACCOUNT_AUTH + 1,

	//Verification IDs
	VERIFY_ACCOUNT = AUTH_RESPONCE + 1,
	VERIFY_RESPONSE = VERIFY_ACCOUNT + 1,

	//Character management
	CREATE_CHARACTER = VERIFY_RESPONSE + 1,
	REQUEST_CHARACTER_INFO = CREATE_CHARACTER + 1,
	DELETE_CHARACTER = REQUEST_CHARACTER_INFO + 1,
	SELECT_CHARACTER = DELETE_CHARACTER + 1,

	//Servers sync
	ADD_SERVER = SELECT_CHARACTER + 1,

	//Character creation
	CHECK_NICKNAME = ADD_SERVER + 1,

	//Part of servers sync
	SERVER_INFO = CHECK_NICKNAME + 1
};