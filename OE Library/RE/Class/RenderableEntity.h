#pragma once
#include "Entity.h"
#pragma pack(push, 1)
class RenderableEntity : public Entity
{
public:
	__int64 idk;
	void* N000005B8; //0x00A8
	uint32_t N000005B9; //0x00B0
	char pad_00B4[4]; //0x00B4
	void* N000005BA; //0x00B8
	void* N000005BB; //0x00C0
	int64_t N000005BC; //0x00C8
	char pad_00D0[16]; //0x00D0
}; //Size: 0x00E0
#pragma pack (pop)