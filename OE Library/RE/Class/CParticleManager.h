#pragma once
#include "Struct/matrix.h"

class CParticleManager
{
#if Y0 || YK1
	typedef int (__fastcall* PARTICLEMANAGER_LoadParticleArchive)(const char* particleName, int unknown);
	typedef void(__fastcall* PARTICLEMANAGER_UnloadParticleArchive)(int archiveID);
	typedef void(__fastcall* _Play)(unsigned int ptcID, Matrix4x4* mtx, __int64 unk2, __int64 unk3, __int64 unk4);
#endif

#if Y0DC
	typedef int(__fastcall* PARTICLEMANAGER_LoadParticleArchive)(void* thisPtr, const char* particleName, const char* particleDir, int unknown, int unknown2);
	typedef void(__fastcall* PARTICLEMANAGER_UnloadParticleArchive)(void* thisPtr, int archiveID);
	typedef void(__fastcall* _Play)(void* thisPtr, unsigned int ptcID, Matrix4x4* mtx, __int64 unk2, __int64 unk3, __int64 unk4);
#endif

public:
	static PARTICLEMANAGER_LoadParticleArchive LoadParticleArchive;
	static PARTICLEMANAGER_UnloadParticleArchive UnloadParticleArchive;

public:
	static _Play Play;
};