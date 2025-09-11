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
	class Animation currentAnimation; //0x0110
	uint32_t animationTime; //0x0114
	float N00000814; //0x0118
	float N00000867; //0x011C
	char pad_0120[96]; //0x0120
	class Animation nextAnimation; //0x0180
	char pad_0184[1948]; //0x0184
	uint16_t rotY; //0x0920
	char pad_0922[30]; //0x0922
	uint16_t rotY2; //0x0940
	char pad_0942[30]; //0x0942
	int16_t N00001882; //0x0960
	char pad_0962[2070]; //0x0962

	void SetPosition(vec4f* pos) { ASM_SetPosition(this, pos); }
}; //Size: 0x0684