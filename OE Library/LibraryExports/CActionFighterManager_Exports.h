#pragma once
#include "Class/CActionFighterManager.h"
#include "OEStatics.h"

OE_LIBRARY_EXPORT inline Fighter* OE_LIB_CACTIONFIGHTERMANAGER_GETFIGHTERBYINDEX(int index)
{
    CActionFighterManager* fman = *OEStatics::ActionFighterManager;

    if (fman == nullptr)
        return 0;

    return fman->GetFighterByIndex(index);
}

OE_LIBRARY_EXPORT inline Fighter* OE_LIB_CACTIONFIGHTERMANAGER_GETFIGHTERBYUID(int index)
{
	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return 0;

	return fman->GetFighterByUID(index);
}

OE_LIBRARY_EXPORT inline int OE_LIB_CACTIONFIGHTERMANAGER_ADD_DISPOSE_FOR_SPAWN(DisposeInfo* inf)
{
    CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return -1;

    return fman->AddDisposeForSpawn(inf);
}

OE_LIBRARY_EXPORT inline void OE_LIB_CACTIONFIGHTERMANAGER_PROCESS_DISPOSE_QUEUE()
{
	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return;

	fman->ProcessDisposeQueue();
}

OE_LIBRARY_EXPORT inline bool OE_LIB_ACTIONFIGHTERMANAGER_IS_FIGHTER_PRESENT(int index)
{
	if (index == -1)
		return false;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return false;

	return (fman->presentFighters & (static_cast<unsigned long long>(1) << 63 - index)) != 0;
}

OE_LIBRARY_EXPORT inline void OE_LIB_ACTIONFIGHTERMANAGER_SET_FIGHTER_PRESENT(unsigned int index, bool present)
{
	if (index == -1)
		return;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	unsigned long long val = (1ULL << 63 - index);

	if (present)
		fman->presentFighters |= val;
	else
		fman->presentFighters &= ~(val);
}

OE_LIBRARY_EXPORT inline bool OE_LIB_ACTIONFIGHTERMANAGER_IS_FIGHTER_ACTIVE(int index)
{
	if (index == -1)
		return false;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return false;

	return (fman->activeFighters & (1ULL << 63 - index)) != 0;
}

OE_LIBRARY_EXPORT inline void OE_LIB_ACTIONFIGHTERMANAGER_SET_FIGHTER_ACTIVE(unsigned int index, bool present)
{
	if (index == -1)
		return;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	unsigned long long val = (1ULL << 63 - index);

	if (present)
		fman->activeFighters |= val;
	else
		fman->activeFighters &= ~(val);
}


OE_LIBRARY_EXPORT inline void OE_LIB_ACTIONFIGHTERMANAGER_DESTROY_FIGHTER(int index)
{
	if (index == -1)
		return;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return;

	unsigned long long val = (static_cast<unsigned long long>(1) << 63 - index);
	fman->fightersToDestroy |= val;
}

OE_LIBRARY_EXPORT inline Fighter* OE_LIB_ACTIONFIGHTERMANAGER_GET_PLAYER()
{
	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return nullptr;

	if (fman->playerIdx < 0)
		return 0;

	return fman->GetFighterByIndex(fman->playerIdx);
}


OE_LIBRARY_EXPORT inline void OE_LIB_ACTIONFIGHTERMANAGER_SET_PLAYER(int idx)
{
	if (idx < 0)
		return;

	CActionFighterManager* fman = *OEStatics::ActionFighterManager;

	if (fman == nullptr)
		return;

	fman->playerIdx = idx;
}