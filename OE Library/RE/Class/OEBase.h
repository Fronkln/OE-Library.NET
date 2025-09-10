#pragma once
#include "common.h"

#pragma pack(push, 1)
class OEBase
{
public:
	void* vftable; //0x0000
	int32_t N0000052E; //0x0008
	int32_t N000004A6; //0x000C
	char pad_0010[8]; //0x0010
	int64_t N00000530; //0x0018
}; //Size: 0x0020
#pragma pack(pop)