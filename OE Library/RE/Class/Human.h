#pragma once
#include "RenderableEntity.h"

class HumanMotion;

#pragma pack(push, 1)
class Human : public RenderableEntity
{
public:
	char pad_00E0[32]; //0x00E0
	vec4f N00000674; //0x0100
	int32_t N00000676; //0x0110
	int32_t N000013BF; //0x0114
	char pad_0118[8]; //0x0118
	vec4f humanPos; //0x0120
	float N0000067A; //0x0130
	float N000006D4; //0x0134
	float N0000067B; //0x0138
	float N000006D6; //0x013C
	float N0000067C; //0x0140
	float N000006D8; //0x0144
	char pad_0148[168]; //0x0148
	class HumanMotion* motionPtr; //0x01F0
	char pad_01F8[72]; //0x01F8
	vec4f humanPos2; //0x0240
	char pad_0250[4]; //0x0250
}; //Size: 0x0254
#pragma pack(pop)