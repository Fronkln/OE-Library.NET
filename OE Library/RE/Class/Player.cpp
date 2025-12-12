#include "Player.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

#if Y0
Player::_GetID Player::ASM_GetID = (Player::_GetID)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 89 87 C0 7F 00 00")));
#endif

#if YK1
Player::_GetID Player::ASM_GetID = (Player::_GetID)(0x0);
#endif

#if Y0 || YK1
Player::_UpdateStyleEffect Player::ASM_UpdateStyleEffect = (Player::_UpdateStyleEffect)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 8B CB E8 ? ? ? ? F3 0F 10 3D ? ? ? ? F3 44 0F 10 0D ? ? ? ?")));
#endif

#if Y0DC
Player::_GetID Player::ASM_GetID = (Player::_GetID)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? B9 ? ? ? ? 66 3B F9 0F 84")));
Player::_UpdateStyleEffect Player::ASM_UpdateStyleEffect = (Player::_UpdateStyleEffect)(PatternScan("40 53 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 ? 48 83 B8 ? ? ? ? ? 74 ? 48 8B 89"));
#endif
