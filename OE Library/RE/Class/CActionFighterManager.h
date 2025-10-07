#pragma once
#include "common.h"
#include "CActionBase.h"

class Fighter;
class DisposeInfo;

class CActionFighterManager : public CActionBase
{
    typedef int(__fastcall* _AddDisposeForSpawn)(void* thisPtr, void* inf);
    typedef void(__fastcall* _ProcessDisposeQueue)(void* thisPtr);

    typedef Fighter*(__fastcall* _GetFighterByUID)(void* thisPtr, int uid);

public:
	char pad_0160[184]; //0x0160
	class Fighter* fighters[64]; //0x0218 assigns disposeinfo first, then the fighter once created
	uint64_t presentFighters; //0x0418
	uint64_t activeFighters; //0x0420
	uint64_t fightersToCreate; //0x0428
	uint64_t fightersToDestroy; //0x0430
	char pad_0438[8]; //0x0438
	uint64_t N000003A1; //0x0440
	uint64_t N000003A2; //0x0448
	char pad_0450[56]; //0x0450
	int32_t N000003A7; //0x0488
	char pad_048C[244]; //0x048C
	int32_t playerIdx; //0x0580
	char pad_0584[68]; //0x0584

    static _AddDisposeForSpawn ASM_AddDisposeForSpawn;
    static _ProcessDisposeQueue ASM_ProcessDisposeQueue;
    static _GetFighterByUID ASM_GetFighterByUID;

public:
    Fighter* GetFighterByIndex(int index)
    {
        if (index > 0 || index <= 63)
            return fighters[index];
        else
            return 0;
    }

    Fighter* GetFighterByUID(int uid)
    {
        return ASM_GetFighterByUID(this, uid);
    }

    int AddDisposeForSpawn(DisposeInfo* inf)
    {
        return ASM_AddDisposeForSpawn(this, inf);
    }

    void ProcessDisposeQueue() 
    {
        ASM_ProcessDisposeQueue(this);
    }
};


