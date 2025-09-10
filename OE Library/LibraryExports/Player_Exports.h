#include "defines.h"
#include "Class/Player.h"

OE_LIBRARY_EXPORT inline int OE_LIB_PLAYER_GET_ID()
{
	return Player::GetID();
}

OE_LIBRARY_EXPORT inline void OE_LIB_PLAYER_UPDATE_STYLE_EFFECT(Player* player)
{
	if (player == nullptr)
		return;

	player->UpdateStyleEffect();
}