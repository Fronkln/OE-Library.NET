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
class CActionCCCManager;

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
    static CActionCCCManager** ActionCCCManager;

    static void DoOffsets()
    {
#if Y0
        DoOffsetsY0();
#endif

#if YK1
        DoOffsetsYK1();
#endif

#if Y0 || YK1
        ActionManager = (CActionManager**)(resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 48 89 44 24 38 48 85 C0 74 ? 48 8B C8 E8 ? ? ? ? EB ?")));
        SequenceManager = (CSequenceManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 4C 8B 0F"));
        ActionCameraManager = (CActionCameraManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? E8 ? ? ? ? 0F 57 D2 BA ? ? ? ? 48 8D 4C 24 40"));
        ActionReactorManager = (CActionReactorManager**)resolve_relative_addr(PatternScan("4C 8B 35 ? ? ? ? 4D 85 F6 74 ? 48 89 74 24 50"));
        ActionFighterManager = (CActionFighterManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? BA ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? BA ? ? ? ? 48 81 C1 ? ? ? ?"));
        ActionHActCHPManager = (CActionHActCHPManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 48 8B 0D ? ? ? ? 4D 89 73 E0"));
        ActionParticleManager = (CActionParticleManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? 48 85 C9 74 ? 8B 84 24 80 00 00 00"));
        ActionCCCManager = (CActionCCCManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? 48 85 C9 74 ? E8 ? ? ? ? 85 C0 0F 84 ? ? ? ? E8 ? ? ? ? 85 C0"));
#endif
#if Y0DC
        ActionManager = (CActionManager**)(resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 4C 8B A4 24 ? ? ? ? 48 8B B4 24")));
        SequenceManager = (CSequenceManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 48 8B 40 ? 8B 80 ? ? ? ? 48 8B 5C 24"));
        ActionCameraManager = (CActionCameraManager**)resolve_relative_addr(PatternScan("48 8B 35 ? ? ? ? 44 8B CF"));

        ActionFighterManager = (CActionFighterManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? C6 80 ? ? ? ? ? E9 ? ? ? ? 83 F9"));
        ActionHActCHPManager = (CActionHActCHPManager**)resolve_relative_addr(PatternScan("48 8B 35 ? ? ? ? 49 8B F8"));
        ActionParticleManager = (CActionParticleManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? 4C 8B FD"));
        ActionCCCManager = (CActionCCCManager**)resolve_relative_addr(PatternScan("48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 ? 48 83 B8 ? ? ? ? ? 74 ? 48 8B 89"));
#endif
    }

    static void DoOffsetsY0()
    {

    }

    static void DoOffsetsYK1()
    {
    }
};