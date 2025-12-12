#include "CParticleManager.h"
#include "PatternScan.h"
#include "MemoryMgr.h"

#if Y0 || YK1
CParticleManager::PARTICLEMANAGER_LoadParticleArchive CParticleManager::LoadParticleArchive = (CParticleManager::PARTICLEMANAGER_LoadParticleArchive)Memory::ReadCall2(PatternScan("E8 ? ? ? ? C7 83 60 01 00 00 ? ? ? ? 89 83 6C 01 00 00"));
CParticleManager::PARTICLEMANAGER_UnloadParticleArchive CParticleManager::UnloadParticleArchive = (CParticleManager::PARTICLEMANAGER_UnloadParticleArchive)Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 63 83 70 01 00 00"));
CParticleManager::_Play CParticleManager::Play = (CParticleManager::_Play)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 8B C8 F3 0F 10 0D ? ? ? ?")));
#endif

#if Y0DC
CParticleManager::PARTICLEMANAGER_LoadParticleArchive CParticleManager::LoadParticleArchive = (CParticleManager::PARTICLEMANAGER_LoadParticleArchive)Memory::ReadCall2(PatternScan("E8 ? ? ? ? 8B F8 48 8B DE"));
CParticleManager::PARTICLEMANAGER_UnloadParticleArchive CParticleManager::UnloadParticleArchive = (CParticleManager::PARTICLEMANAGER_UnloadParticleArchive)Memory::ReadCall2(PatternScan(" E8 ? ? ? ? 48 8D B5 ? ? ? ? 8B 85"));
CParticleManager::_Play CParticleManager::Play = (CParticleManager::_Play)(Memory::ReadCall2(PatternScan("E8 ? ? ? ? 48 8B F0 48 85 C0 74 ? F7 80 ? ? ? ? ? ? ? ? 75 ? C5 F8 11 B8")));
#endif