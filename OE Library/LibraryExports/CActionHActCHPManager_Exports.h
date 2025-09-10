#pragma once
#pragma once
#include "defines.h"
#include "OEStatics.h"
#include "Class/CActionHActCHPManager.h"

extern "C"
{
	OE_LIBRARY_EXPORT inline const char* OE_LIB_HACTCHPMANAGER_GET_CURRENT()
	{
		CActionHActCHPManager* chpMan = *OEStatics::ActionHActCHPManager;

		if (chpMan == nullptr)
			return nullptr;

		return (const char*)&chpMan->currentHAct.string;
	}
}