#include "CActionReactorManager.h"
#include "PatternScan.h"

CActionReactorManager::REACTORMANAGER_CreateReactor CActionReactorManager::ASM_CreateReactor = (CActionReactorManager::REACTORMANAGER_CreateReactor)PatternScan("4C 8B DC 48 81 EC ? ? ? ? 44 8B D1");