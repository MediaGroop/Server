#include "MessageIdentifiers.h"

enum GameMessages
{
	ID_GAME_MESSAGE_1 = ID_USER_PACKET_ENUM + 1,
	AUTH_TO_POOLER = ID_GAME_MESSAGE_1 + 1,
	ACCOUNT_AUTH = AUTH_TO_POOLER + 1
};