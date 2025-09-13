#pragma once
#include "defines.h"
#include "OEStatics.h"
#include "Class/CSequenceManager.h"
#include "Struct/MissionData.h"

extern "C"
{
    OE_LIBRARY_EXPORT inline unsigned int OE_LIB_SEQUENCEMANAGER_GETTER_CURRENT_MISSION()
    {
        CSequenceManager* seqMan = *OEStatics::SequenceManager;

        if (seqMan == nullptr)
            return 0;

        return seqMan->missionData->missionID;
    }

    OE_LIBRARY_EXPORT inline unsigned int OE_LIB_SEQUENCEMANAGER_GETTER_CURRENT_STAGE()
    {
        CSequenceManager* seqMan = *OEStatics::SequenceManager;

        if (seqMan == nullptr)
            return 0;

        return seqMan->missionData->stageID;
    }

    OE_LIBRARY_EXPORT inline unsigned int OE_LIB_SEQUENCEMANAGER_GETTER_CURRENT_MISSION_STATE()
    {
        CSequenceManager* seqMan = *OEStatics::SequenceManager;

        if (seqMan == nullptr)
            return 0;

        return seqMan->missionPhase;
    }
}