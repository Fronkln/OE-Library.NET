#pragma once
#include "defines.h"
#include "Class/Input.h"

OE_LIBRARY_EXPORT inline void* OE_LIB_INPUT_GETTER_RAW_INPUTS_ADDRESS()
{
#if Y0
    return *Input::DatasStart;
#else
    long long addr = (long long)(*Input::DatasStart);
    addr += 0x168;


    return *(long long**)addr;
#endif
}