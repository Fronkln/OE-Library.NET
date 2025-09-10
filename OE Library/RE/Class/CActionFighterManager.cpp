#include "CActionFighterManager.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

CActionFighterManager::_AddDisposeForSpawn CActionFighterManager::ASM_AddDisposeForSpawn = (CActionFighterManager::_AddDisposeForSpawn)(Memory::ReadCall2(PatternScan("E8 ?? ?? ?? ?? 48 8D 55 F0 48 8B CB 89 83 F0 01 00 00")));
CActionFighterManager::_GetFighterByUID CActionFighterManager::ASM_GetFighterByUID = (CActionFighterManager::_GetFighterByUID)(PatternScan("48 89 74 24 10 57 48 83 EC ? 8B FA 48 8B F1 85 D2 75 ?"));
