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

	OE_LIBRARY_EXPORT inline HActRegister* OE_LIB_HACTCHPMANAGER_GET_HACT_REPLACE(int type)
	{
		CActionHActCHPManager* chpMan = *OEStatics::ActionHActCHPManager;

		if (chpMan == nullptr)
			return nullptr;

		return &chpMan->characterRegisters[type];
	}

	OE_LIBRARY_EXPORT inline vec4f OE_LIB_HACTREPLACE_GETTER_POSITION(HActRegister* reg)
	{
		if (reg == nullptr)
			return vec4f();

		return reg->position;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_HACTREPLACE_SETTER_POSITION(HActRegister* reg, vec4f* pos)
	{
		if (reg == nullptr)
			return;

		reg->position = *pos;
	}

	OE_LIBRARY_EXPORT inline int OE_LIB_HACTREPLACE_GETTER_FIGHTER_UID(HActRegister* reg)
	{
		if (reg == nullptr)
			return -1;

		return reg->FighterUID;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_HACTREPLACE_SETTER_FIGHTER_UID(HActRegister* reg, int uid)
	{
		if (reg == nullptr)
			return;

		reg->FighterUID = uid;
	}

	OE_LIBRARY_EXPORT inline int OE_LIB_HACTREPLACE_GETTER_IS_ACTIVE(HActRegister* reg)
	{ 
		if (reg == nullptr)
			return 0;

		return reg->isActive;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_HACTREPLACE_SETTER_IS_ACTIVE(HActRegister* reg, int active)
	{
		if (reg == nullptr)
			return;

		reg->isActive = active;
	}

	OE_LIBRARY_EXPORT inline int OE_LIB_HACTREPLACE_GETTER_UNK_VAL(HActRegister* reg)
	{
		if (reg == nullptr)
			return 0;

		return reg->unkVal;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_HACTREPLACE_SETTER_UNK_VAL(HActRegister* reg, int unkVal)
	{
		if (reg == nullptr)
			return;

		reg->unkVal = unkVal;
	}
}