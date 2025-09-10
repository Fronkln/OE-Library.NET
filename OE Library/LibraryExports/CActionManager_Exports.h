#pragma once
#include "defines.h"
#include "OEStatics.h"
#include "Class/CActionManager.h"

OE_LIBRARY_EXPORT inline float OE_LIB_ACTIONMANAGER_GETTER_DELTA_TIME()
{
    CActionManager* actMan = *OEStatics::ActionManager;

    if (actMan == nullptr)
        return 0;

    return actMan->deltaTime;
}

OE_LIBRARY_EXPORT inline float OE_LIB_ACTIONMANAGER_GETTER_FIXED_DELTA_TIME()
{
    CActionManager* actMan = *OEStatics::ActionManager;

    if (actMan == nullptr)
        return 0;

    return actMan->fixedDeltaTime;
}

OE_LIBRARY_EXPORT inline bool OE_LIB_ACTIONMANAGER_GETTER_IS_LOADED()
{
    CActionManager* actMan = *OEStatics::ActionManager;

    if (actMan == nullptr)
        return false;

    //Unimplemented
    return false;
    //return actMan->isLoaded;
}

OE_LIBRARY_EXPORT inline bool OE_LIB_ACTIONMANAGER_GETTER_IS_PAUSED()
{
    CActionManager* actMan = *OEStatics::ActionManager;

    if (actMan == nullptr)
        return false;

    return actMan->gamePaused;
}