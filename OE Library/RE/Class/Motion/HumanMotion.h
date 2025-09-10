#pragma once
#include "UnkMotionClass1.h"

class HumanMotion : public UnkMotionClass1
{
	typedef void(__fastcall* _SetPosition)(void* thisPtr, vec4f* pos);

	static _SetPosition ASM_SetPosition;

public:
	char pad_00A8[24]; //0x00A8
	Matrix4x4 matrix; //0x00C0
	char pad_0100[16]; //0x0100
	uint16_t currentAnimation; //0x0112
	uint32_t animationTime; //0x0114
	char pad_0118[104]; //0x0118
	uint16_t nextAnimation; //0x0180
	char pad_0182[1282]; //0x0182

	void SetPosition(vec4f* pos) { ASM_SetPosition(this, pos); }
}; //Size: 0x0684