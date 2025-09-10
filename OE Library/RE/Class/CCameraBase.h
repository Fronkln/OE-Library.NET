#pragma once
#include "Entity.h"


class CCameraBase : public Entity
{
public:
	uint32_t cameraIndex; //0x00A0
	float nearClip; //0x00A4
	float farClip; //0x00A8
	float fov; //0x00AC
	char pad_00B0[48]; //0x00B0
	vec4f currentPosition; //0x00E0
	vec4f focusPos; //0x00F0
	char pad_0100[16]; //0x0100
	Matrix4x4 matrix; //0x0110
};