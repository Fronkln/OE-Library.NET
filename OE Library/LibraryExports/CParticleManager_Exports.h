#pragma once
#include "defines.h"
#include "Class/CParticleManager.h"

OE_LIBRARY_EXPORT inline int OE_LIB_PARTICLEMANAGER_LOAD_ARCHIVE(const char* archiveName, int unknown)
{
	return CParticleManager::LoadParticleArchive(archiveName, unknown);
}

OE_LIBRARY_EXPORT inline void OE_LIB_PARTICLEMANAGER_UNLOAD_ARCHIVE(int archiveID)
{
	CParticleManager::UnloadParticleArchive(archiveID);
}

OE_LIBRARY_EXPORT inline void OE_LIB_PARTICLEMANAGER_PLAY(int particleID, Matrix4x4* mtx)
{
	CParticleManager::Play(particleID, mtx, 0, 0, 0);
}