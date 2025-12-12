#pragma once
#include "defines.h"
#include "Class/CParticleManager.h"

OE_LIBRARY_EXPORT inline int OE_LIB_PARTICLEMANAGER_LOAD_ARCHIVE(const char* archiveName, int unknown)
{
#if Y0 || YK1
	return CParticleManager::LoadParticleArchive(archiveName, unknown);
#endif

#if Y0DC
	return CParticleManager::LoadParticleArchive(*OEStatics::ActionParticleManager, archiveName, "data/effect/ptc_arc_w64", unknown, -1);
#endif
}

OE_LIBRARY_EXPORT inline void OE_LIB_PARTICLEMANAGER_UNLOAD_ARCHIVE(int archiveID)
{
#if Y0 || YK1
	CParticleManager::UnloadParticleArchive(archiveID);
#endif

#if Y0DC
	CParticleManager::UnloadParticleArchive(*OEStatics::ActionParticleManager, archiveID);
#endif
}

OE_LIBRARY_EXPORT inline void OE_LIB_PARTICLEMANAGER_PLAY(int particleID, Matrix4x4* mtx)
{
#if Y0 || YK1
	CParticleManager::Play(particleID, mtx, 0, 0, 0);
#endif
#if Y0DC
	CParticleManager::Play(*OEStatics::ActionParticleManager, particleID, mtx, 0, 0, 0);
#endif
}