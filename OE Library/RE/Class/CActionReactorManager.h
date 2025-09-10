#pragma once
#include "Entity.h"

class CActionReactorManager
{
	typedef Entity* (__fastcall* REACTORMANAGER_CreateReactor)(unsigned int asset, vec4f* spawnPosition, vec4f* rotation, vec4f* unk1, vec4f* unk2, vec4f* idk3);

	static REACTORMANAGER_CreateReactor ASM_CreateReactor;

public:

	Entity* CreateReactor(unsigned int asset, vec4f* spawnPosition, vec4f* rotation, vec4f* unk1, vec4f* unk2, vec4f* idk3) {

		return ASM_CreateReactor(asset, spawnPosition, rotation, unk1, unk2, idk3);
	}
};