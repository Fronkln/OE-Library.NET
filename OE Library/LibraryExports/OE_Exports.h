#pragma once
#include "RE/Class/OE.h"
#include "OEStatics.h"
#include "CActionFighterManager_Exports.h"

class Fighter;


OE_LIBRARY_EXPORT inline bool OE_INITIALIZED()
{
    return OEStatics::ActionFighterManager != nullptr && *OEStatics::ActionFighterManager != nullptr;
}

OE_LIBRARY_EXPORT inline void OE_REFRESH_OFFSETS()
{
    OEStatics::DoOffsets();
}

OE_LIBRARY_EXPORT inline void OE_LIB_INIT()
{
    OE::Init();
}

OE_LIBRARY_EXPORT inline void OE_REGISTER_JOB(_OENET_RegisterJob funcPointer, int jobPhase, int priority)
{
    OE::RegisterJob(jobPhase, funcPointer, *OEStatics::ActionFighterManager, priority);
}

OE_LIBRARY_EXPORT inline Fighter* OE_GET_PLAYER()
{
    CActionFighterManager* fman = *OEStatics::ActionFighterManager;

    if (fman == nullptr)
        return 0;

    return fman->GetFighterByIndex(0);
}