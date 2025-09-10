#pragma once
#include "common.h"

class CActionManager
{
public:
	void* vfptr; //0x0000
	uint32_t gamePaused; //0x0008
	uint32_t flags; //0x000C
	char pad_0010[264]; //0x0010
	float fixedDeltaTime; //0x0118
	float deltaTime; //0x011C
	char pad_0120[12]; //0x0120
	float unscaledDeltaTime; //0x012C
	char pad_0130[172]; //0x0130
	float speed[15]; //0x01DC
	char pad_0218[193304]; //0x0218
}; //Size: 0x2F530