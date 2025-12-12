#include "CActionFighterManager.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

#if Y0 || YK1
CActionFighterManager::_AddDisposeForSpawn CActionFighterManager::ASM_AddDisposeForSpawn = (CActionFighterManager::_AddDisposeForSpawn)(Memory::ReadCall2(PatternScan("E8 ?? ?? ?? ?? 48 8D 55 F0 48 8B CB 89 83 F0 01 00 00")));
CActionFighterManager::_ProcessDisposeQueue CActionFighterManager::ASM_ProcessDisposeQueue = (CActionFighterManager::_ProcessDisposeQueue)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? E8 ? ? ? ? 85 C0 74 ? 45 33 C9 48 8D 15 ? ? ? ? 4C 8B C7")));
CActionFighterManager::_GetFighterByUID CActionFighterManager::ASM_GetFighterByUID = (CActionFighterManager::_GetFighterByUID)(PatternScan("48 89 74 24 10 57 48 83 EC ? 8B FA 48 8B F1 85 D2 75 ?"));
#endif

#if Y0DC
CActionFighterManager::_AddDisposeForSpawn CActionFighterManager::ASM_AddDisposeForSpawn = (CActionFighterManager::_AddDisposeForSpawn)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 8B 0D ? ? ? ? 89 83 ? ? ? ? 0F B6 83")));
CActionFighterManager::_ProcessDisposeQueue CActionFighterManager::ASM_ProcessDisposeQueue = (CActionFighterManager::_ProcessDisposeQueue)(PatternScan("40 53 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B F1"));
CActionFighterManager::_GetFighterByUID CActionFighterManager::ASM_GetFighterByUID = (CActionFighterManager::_GetFighterByUID)(PatternScan("48 89 5C 24 ? 57 8B FA"));
#endif