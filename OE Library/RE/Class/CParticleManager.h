#pragma once
class CParticleManager
{
	typedef int (__fastcall* PARTICLEMANAGER_LoadParticleArchive)(const char* particleName, int unknown);
	typedef void(__fastcall* PARTICLEMANAGER_UnloadParticleArchive)(int archiveID);

public:
	static PARTICLEMANAGER_LoadParticleArchive LoadParticleArchive;
	static PARTICLEMANAGER_UnloadParticleArchive UnloadParticleArchive;
};