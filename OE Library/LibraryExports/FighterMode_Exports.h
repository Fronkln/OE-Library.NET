#pragma once
#include "defines.h"
#include "Class/FighterMode.h"

extern "C"
{
	OE_LIBRARY_EXPORT inline FighterMode* OE_LIB_FIGHTERMODEMANAGER_GETTER_CURRENT_MODE(FighterModeManager* fighterModeMan)
	{
		if (fighterModeMan == nullptr)
			return nullptr;
		else
			return fighterModeMan->currentMode;
	}

	OE_LIBRARY_EXPORT inline Fighter* OE_LIB_FIGHTERMODEMANAGER_GETTER_FIGHTER(FighterModeManager* fighterModeMan)
	{
		if (fighterModeMan == nullptr)
			return nullptr;
		else
			return fighterModeMan->fighter;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERMODEMANAGER_SET_COMMANDSET(FighterModeManager* fighterModeMan, const char* commandset)
	{
		if (fighterModeMan == nullptr)
			return;
		else
			fighterModeMan->SetCommandset(1, commandset);
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERMODEMANAGER_TO_BATTLE_START(FighterModeManager* fighterModeMan)
	{
		if (fighterModeMan == nullptr)
			return;
		
			
		fighterModeMan->ToBattleStart();
	}

	OE_LIBRARY_EXPORT inline char* OE_LIB_FIGHTERMODE_GETTER_NAME(FighterMode* fighterMode)
	{
		if (fighterMode == nullptr)
			return nullptr;
		else
			return fighterMode->modeName;
	}

	OE_LIBRARY_EXPORT inline Fighter* OE_LIB_FIGHTERMODE_GETTER_FIGHTER(FighterMode* fighterMode)
	{
		if (fighterMode == nullptr)
			return nullptr;
		else
			return fighterMode->fighter;
	}
}