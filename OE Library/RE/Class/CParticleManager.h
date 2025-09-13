#pragma once
#include "Struct/matrix.h"

class CParticleManager
{
	typedef int (__fastcall* PARTICLEMANAGER_LoadParticleArchive)(const char* particleName, int unknown);
	typedef void(__fastcall* PARTICLEMANAGER_UnloadParticleArchive)(int archiveID);
	typedef void(__fastcall* _Play)(unsigned int ptcID, Matrix4x4* mtx, __int64 unk2, __int64 unk3, __int64 unk4);

public:
	static PARTICLEMANAGER_LoadParticleArchive LoadParticleArchive;
	static PARTICLEMANAGER_UnloadParticleArchive UnloadParticleArchive;

public:
	static _Play Play;
};