#include "Player.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

#if Y0
Player::_GetID Player::ASM_GetID = (Player::_GetID)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 89 87 C0 7F 00 00")));
#else
Player::_GetID Player::ASM_GetID = (Player::_GetID)(0x0);
#endif

Player::_UpdateStyleEffect Player::ASM_UpdateStyleEffect = (Player::_UpdateStyleEffect)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 8B CB E8 ? ? ? ? F3 0F 10 3D ? ? ? ? F3 44 0F 10 0D ? ? ? ?")));