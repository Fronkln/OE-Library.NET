#include "defines.h"
#include "Class/CActionCCCManager.h"

#include "OEStatics.h"

OE_LIBRARY_EXPORT inline bool OE_LIB_CACTIONCCCMANAGER_IS_ACTIVE()
{
    CActionCCCManager* cman = *OEStatics::ActionCCCManager;

    if (cman == nullptr)
        return 0;

    return cman->isActive;
}

OE_LIBRARY_EXPORT inline bool OE_LIB_CACTIONCCCMANAGER_IS_ENDING()
{
    CActionCCCManager* cman = *OEStatics::ActionCCCManager;

    if (cman == nullptr)
        return 0;

    return cman->isEnding;
}