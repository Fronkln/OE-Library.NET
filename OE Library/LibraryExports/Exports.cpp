#include "OE_Exports.h"
#include "Entity_Exports.h"
#include "CCameraBase_Exports.h"
#include "Human_Exports.h"
#include "Fighter_Exports.h"
#include "Player_Exports.h"
#include "FighterMode_Exports.h"
#include "CActionManager_Exports.h"
#include "CActionCameraManager_Exports.h"
#include "CActionReactorManager_Exports.h"
#include "CActionFighterManager_Exports.h"
#include "CActionHActCHPManager_Exports.h"
#include "CInputDeviceListener_Exports.h"
#include "CActInputManager_Exports.h"
#include "CSequenceManager_Exports.h"
#include "CParticleManager_Exports.h"

#include "EntityMotion_Exports.h"
#include "HumanMotion_Exports.h"

#include "Input_Exports.h"

#include "MemoryMgr.h"
#include "PatternScan.h"

extern "C"
{
    OE_LIBRARY_EXPORT inline void LIB_UNSAFE_NOP(void* addr, unsigned int length)
    {
        DWORD oldProtect;

        VirtualProtect(addr, length, PAGE_EXECUTE_READWRITE, &oldProtect);
        memset(addr, 0x90, length);
        VirtualProtect(addr, length, oldProtect, &oldProtect);
    };


    OE_LIBRARY_EXPORT inline void LIB_UNSAFE_PATCH(void* addr, BYTE* buf, unsigned int length)
    {
        DWORD oldProtect;

        VirtualProtect(addr, length, PAGE_EXECUTE_READWRITE, &oldProtect);
        memcpy(addr, buf, length);
        VirtualProtect(addr, length, oldProtect, &oldProtect);
    };

    OE_LIBRARY_EXPORT inline void* LIB_PATTERN_SEARCH(const char* pattern)
    {
        return PatternScan(GetModuleHandle(NULL), pattern);
    };

    OE_LIBRARY_EXPORT inline void* LIB_READ_RELATIVE_ADDRESS(void* addr, int instruction_length)
    {
        return  resolve_relative_addr(addr, instruction_length);
    };

    OE_LIBRARY_EXPORT inline void* LIB_READ_CALL(void* addr)
    {
        return (void*)Memory::ReadCall2(addr);
    };

    OE_LIBRARY_EXPORT inline void LIB_WRITE_CALL(void* addr, void* func)
    {
        Memory::InjectHook(addr, func);
    };
}