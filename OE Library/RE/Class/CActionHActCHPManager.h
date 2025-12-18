#pragma once
#include "common.h"
#include "CActionBase.h"

class CHPTarget
{
public:
	uint32_t ID; //0x0000
	char pad_0004[4]; //0x0004
}; //Size: 0x0008

#if Y0 || YK1
class HActRegister
{
public:
	char pad_0000[16]; //0x0000
	vec4f position; //0x0010
	int isActive; //0x0020
	int32_t FighterUID; //0x0024
	int unkVal;
	char pad_0028[12]; //0x0028
	uint16_t rotY; //0x0038
	char pad_003A[22]; //0x003A
}; //Size: 0x0050
#else
class HActRegister
{
public:
	char pad_0000[8]; //0x0000
	vec4f position; //0x0008
	int isActive; //0x0018
	int32_t FighterUID; //0x001C
	int unkVal; //0x0020
	int32_t UID; //0x0024
	char pad_0028[40]; //0x0028
}; //Size: 0x0050
#endif

#if Y0 || YK1
class CActionHActCHPManager : public CActionBase
{
public:
	char pad_0160[8]; //0x0160
	class CHPTarget chpTargets[63]; //0x0168
	int32_t chpTargetsCount; //0x0360
	char pad_0364[12]; //0x0364
	class checksum_string uniqueHActsPlayed[32]; //0x0370
	char pad_0770[40]; //0x0770
	int32_t uniqueHActsPlayedCount; //0x0798
	char pad_079C[20]; //0x079C
	class CFileHActCHP* fileHActChp; //0x07B0
#if Y0
	char pad_07B8[44]; //0x07B8
#else
	char pad_07B8[40]; //0x07B8
#endif
	int32_t hactID; //0x07E0
#if Y0
	char pad_07E4[16]; //0x07E4
#else
	char pad_07E4[4]; //0x07E4
#endif
	class checksum_string currentHAct; //0x07E8
	char pad_0808[72]; //0x0808
	Matrix4x4 matrix; //0x0850
	char pad_0890[32]; //0x0890
	class HActRegister characterRegisters[32]; //0x08B0
	char pad_12B0[3496]; //0x12B0
}; //Size: 0x2058
#else
class CActionHActCHPManager : public CActionBase
{
public:
	char pad_0160[8]; //0x0160
	class CHPTarget chpTargets[63]; //0x0168
	int32_t chpTargetsCount; //0x0360
	char pad_0364[12]; //0x0364
	class checksum_string uniqueHActsPlayed[32]; //0x0370
	char pad_0770[40]; //0x0770
	int32_t uniqueHActsPlayedCount; //0x0798
	char pad_079C[20]; //0x079C
	class CFileHActCHP* fileHActChp; //0x07B0
	char pad_07B8[40]; //0x07B8
	int32_t hactID; //0x07E0
	char pad_07E4[4]; //0x07E4
	class checksum_string currentHAct; //0x07E8
	char pad_0808[40]; //0x0808
	Matrix4x4 matrix; //0x0830
	char pad_0870[40]; //0x0870
	class HActRegister characterRegisters[32]; //0x0898
	char pad_1298[3496]; //0x1298
}; //Size: 0x2040
#endif