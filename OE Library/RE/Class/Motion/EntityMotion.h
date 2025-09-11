#pragma once
#include "common.h"

class Animation
{
public:
	int16_t Unknown; //0x0000
	int16_t ID; //0x0002
}; //Size: 0x0004

class EntityMotion
{
public:
	char pad_0000[32]; //0x0000
	float scaleX; //0x0020
	char pad_0024[16]; //0x0024
	float scaleY; //0x0034
	char pad_0038[16]; //0x0038
	float scaleZ; //0x0048
	char pad_004C[20]; //0x004C
	vec4f motionPos; //0x0060
	void* N000006ED; //0x0070
	uint64_t animationBlending; //0x0078
	char pad_0080[16]; //0x0080
}; //Size: 0x0090