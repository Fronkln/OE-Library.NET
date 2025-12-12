#pragma once
#include "defines.h"
#include "Class/Input.h"

OE_LIBRARY_EXPORT inline void* OE_LIB_INPUT_GETTER_RAW_INPUTS_ADDRESS()
{
#if Y0
    return *Input::DatasStart;
#endif

#if Y0DC
    long long addr = (long long)(*Input::DatasStart);
    addr += 0x250;


    return *(long long**)addr;
#endif

#if YK1
    long long addr = (long long)(*Input::DatasStart);
    addr += 0x168;


    return *(long long**)addr;
#endif
}