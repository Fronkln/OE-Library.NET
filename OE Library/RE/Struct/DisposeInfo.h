#pragma once
#include "common.h"

class DisposeInfo
{
public:
	vec4f spawnPosition; //0x0000
	class checksum_string model; //0x0010
	char pad_0030[16]; //0x0030
	char name[32]; //0x0040
	char battleAnim[8]; //0x0060
	char pad_0068[26]; //0x0068
	uint16_t rotY; //0x0082
	int16_t N00001D22; //0x0084
	char pad_0086[4]; //0x0086
	uint8_t npcType; //0x008A
	char pad_008B[5]; //0x008B
	int32_t N00000610; //0x0090
	char pad_0094[12]; //0x0094
	int32_t weaponID; //0x00A0
	char pad_00A4[28]; //0x00A4
}; //Size: 0x00B4