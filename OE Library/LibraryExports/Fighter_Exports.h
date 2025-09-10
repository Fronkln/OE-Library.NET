#pragma once
#include "defines.h"
#include "Class/Fighter.h"
#include "Struct/FighterBattleStatus.h"

class FighterController;
class FighterModeManager;
class FighterBattleStatus;

extern "C"
{
	OE_LIBRARY_EXPORT inline int OE_LIB_FIGHTERBATTLESTATUS_GETTER_CURRENT_HEALTH(FighterBattleStatus* fighterStatus)
	{
		if (fighterStatus == nullptr)
			return 0;
		else
			return fighterStatus->CurrentHealth;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERBATTLESTATUS_SETTER_CURRENT_HEALTH(FighterBattleStatus* fighterStatus, int value)
	{
		if (fighterStatus == nullptr)
			return;
			
		fighterStatus->CurrentHealth = value;
	}

	OE_LIBRARY_EXPORT inline int OE_LIB_FIGHTERBATTLESTATUS_GETTER_MAX_HEALTH(FighterBattleStatus* fighterStatus)
	{
		if (fighterStatus == nullptr)
			return 0;
		else
			return fighterStatus->MaxHealth;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERBATTLESTATUS_SETTER_MAX_HEALTH(FighterBattleStatus* fighterStatus, int value)
	{
		if (fighterStatus == nullptr)
			return;

		fighterStatus->MaxHealth = value;
	}

	OE_LIBRARY_EXPORT inline float OE_LIB_FIGHTERBATTLESTATUS_GETTER_HEAT(FighterBattleStatus* fighterStatus)
	{
		if (fighterStatus == nullptr)
			return 0;
		else
			return fighterStatus->CurrentHeat;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERBATTLESTATUS_SETTER_HEAT(FighterBattleStatus* fighterStatus, float heat)
	{
		if (fighterStatus == nullptr)
			return;

		fighterStatus->CurrentHeat = heat;
	}

	OE_LIBRARY_EXPORT inline int OE_LIB_FIGHTERBATTLESTATUS_GETTER_STYLE(FighterBattleStatus* fighterStatus)
	{
		if (fighterStatus == nullptr)
			return 0;
		else
			return fighterStatus->StyleID;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_FIGHTERBATTLESTATUS_SETTER_STYLE(FighterBattleStatus* fighterStatus, int style)
	{
		if (fighterStatus == nullptr)
			return;
		else
			fighterStatus->StyleID = style;
	}


	OE_LIBRARY_EXPORT inline DisposeInfo* OE_LIB_FIGHTER_GETTER_DISPOSE_INFO(Fighter* fighter)
	{
		if (fighter == nullptr)
			return nullptr;
		else
			return &fighter->disposeInfo;
	}

	OE_LIBRARY_EXPORT inline FighterBattleStatus* OE_LIB_FIGHTER_GETTER_BATTLE_STATUS(Fighter* fighter)
	{
		if (fighter == nullptr)
			return nullptr;
		else
			return fighter->BattleStatus;
	}

	OE_LIBRARY_EXPORT inline FighterModeManager* OE_LIB_FIGHTER_GETTER_FIGHTERMODEMANAGER(Fighter* fighter)
	{
		if (fighter == nullptr)
			return 0;

		return fighter->fighterModeManager;
	}


	OE_LIBRARY_EXPORT inline FighterController* OE_LIB_FIGHTER_GET_INPUT_LISTENER(Fighter* fighter)
	{
		if (fighter == nullptr)
			return 0;

		return fighter->fighterController;
	}


	OE_LIBRARY_EXPORT  inline int OE_LIB_FIGHTER_GETTER_INDEX(Fighter* fighter)
	{
		if (fighter == nullptr)
			return 0;
		else
			return fighter->fighterIndex;
	}

	OE_LIBRARY_EXPORT  inline int OE_LIB_FIGHTER_GETTER_INPUT_FLAGS(Fighter* fighter)
	{
		if (fighter == nullptr)
			return 0;
		else
			return fighter->inputInfo.buttonMask;
	}

	OE_LIBRARY_EXPORT  inline void OE_LIB_FIGHTER_SETTER_INPUT_FLAGS(Fighter* fighter, int val)
	{
		if (fighter == nullptr)
			return;

		fighter->inputInfo.buttonMask = val;
	}
}