#pragma once
#include "OEBase.h"

#pragma pack(push, 1)
class EntityBase : public OEBase
{
public:
	char pad_0020[32]; //0x0020
	int32_t UID; //0x0040
	char pad_0044[4]; //0x0044
	void* selfPtr; //0x0048
	int32_t UID2; //0x0050
	char pad_0054[4]; //0x0054
	int64_t N00000617; //0x0058
}; //Size: 0x0060
#pragma pack(pop)
