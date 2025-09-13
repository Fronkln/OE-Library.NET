#pragma once
#include "common.h"
class MissionData
{
public:
	int32_t N000034A3; //0x0000
	int32_t N000034C5; //0x0004
	char pad_0008[8]; //0x0008
	checksum_string playerModel; //0x0010
	int32_t N000034AA; //0x0030
	int32_t N000034CC; //0x0034
	char pad_0038[8]; //0x0038
	int32_t missionID; //0x0040
	int32_t N000034D0; //0x0044
	char pad_0048[184]; //0x0048
	char unk1[0x454];
	int stageID;
}; //Size: 0x0100