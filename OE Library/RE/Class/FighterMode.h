#pragma once

class Fighter;

class FighterMode
{
public:
	void* modeVfPtr; //0x0000
	char pad_0008[8]; //0x0008
	char* modeName; //0x0010
	char pad_0018[8]; //0x0018
	Fighter* fighter; //0x0020
	char pad_0028[300]; //0x0028
}; //Size: 0x0154

class FighterModeManager;

typedef void* (__fastcall* FIGHTERMODEMANAGER_SetCommandSet)(FighterModeManager* fModeMan, int unk1, const char* commandsetName);
typedef void (__fastcall* FIGHTERMODEMANAGER_ToBattleStart)(FighterModeManager* fModeMan);

class FighterModeManager
{
public:
	void* vfptr; //0x0000
	class FighterMode* currentMode; //0x0008
	class FighterMode* nextMode; //0x0010
	unsigned int changeMode; //0x0018
	char pad_001C[28]; //0x001C
	class Fighter* fighter; //0x0038
	char pad_0040[2976]; //0x0040

	static FIGHTERMODEMANAGER_SetCommandSet ASM_SetCommandset;
	static FIGHTERMODEMANAGER_ToBattleStart ASM_ToBattleStart;

	void SetCommandset(int unk1, const char* commandsetName)
	{
		ASM_SetCommandset(this, unk1, commandsetName);
	}

	void ToBattleStart() 
	{
		ASM_ToBattleStart(this);
	}
}; //Size: 0x0108