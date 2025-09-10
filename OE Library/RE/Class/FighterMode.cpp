#include "FighterMode.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

FIGHTERMODEMANAGER_SetCommandSet FighterModeManager::ASM_SetCommandset = (FIGHTERMODEMANAGER_SetCommandSet)Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 8B 43 38 8B 90 28 04 00 00 48 8B 0D ? ? ? ? E8 ? ? ? ? 4C 8B C8"));
FIGHTERMODEMANAGER_ToBattleStart FighterModeManager::ASM_ToBattleStart = (FIGHTERMODEMANAGER_ToBattleStart)PatternScan("40 53 48 83 EC ? 48 8B 41 38 48 8B D9 48 8B 48 70 48 85 C9 74 ? 48 8D 15 ? ? ? ? 45 33 C0 E8 ? ? ? ? 48 85 C0");