#pragma once
#include "EntityBase.h"

#pragma pack(push, 1)
class Entity : public EntityBase
{
public:
	char pad_0060[16]; //0x0060
	void* unkPtr; //0x0070
	char* className; //0x0078
	uint16_t rotY; //0x0080
	char pad_0082[14]; //0x0082
	vec4f entityPosition; //0x0090
}; //Size: 0x00A8
#pragma pack(pop)