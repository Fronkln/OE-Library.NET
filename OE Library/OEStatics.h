#pragma once
#include <cstdint>
#include <Windows.h>
#include "common.h"
#include "PatternScan.h"

class CActionManager;
class CSequenceManager;
class CActionCameraManager;
class CActionReactorManager;
class CActionFighterManager;
class CActionHActCHPManager;
class CActionParticleManager;

class OEStatics
{
public:
    static CActionManager** ActionManager;
    static CSequenceManager** SequenceManager;
    static CActionCameraManager** ActionCameraManager;
    static CActionReactorManager** ActionReactorManager;
    static CActionFighterManager** ActionFighterManager;
    static CActionHActCHPManager** ActionHActCHPManager;
    static CActionParticleManager** ActionParticleManager;

    static void DoOffsets()
    {
#if Y0
        DoOffsetsY0();
#endif

#if YK1
        DoOffsetsYK1();
#endif

        ActionManager = (CActionManager**)(resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 48 89 44 24 38 48 85 C0 74 ? 48 8B C8 E8 ? ? ? ? EB ?")));
        SequenceManager = (CSequenceManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 4C 8B 0F"));
        ActionCameraManager = (CActionCameraManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? E8 ? ? ? ? 0F 57 D2 BA ? ? ? ? 48 8D 4C 24 40"));
        ActionReactorManager = (CActionReactorManager**)resolve_relative_addr(PatternScan("4C 8B 35 ? ? ? ? 4D 85 F6 74 ? 48 89 74 24 50"));
        ActionFighterManager = (CActionFighterManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? BA ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? BA ? ? ? ? 48 81 C1 ? ? ? ?"));
        ActionHActCHPManager = (CActionHActCHPManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 48 8B 0D ? ? ? ? 4D 89 73 E0"));
        ActionParticleManager = (CActionParticleManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? 48 85 C9 74 ? 8B 84 24 80 00 00 00"));
    }

    static void DoOffsetsY0()
    {

    }

    static void DoOffsetsYK1()
    {
    }
};