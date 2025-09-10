#pragma once
#include "Class/CActionReactorManager.h"
#include "OEStatics.h"


OE_LIBRARY_EXPORT inline Entity* OE_LIB_ACTIONREACTORMANAGER_CREATEREACTOR(unsigned int asset, vec4f pos, vec4f rot)
{
	CActionReactorManager* reactorMan = *OEStatics::ActionReactorManager;

	if (reactorMan == nullptr)
		return nullptr;

	vec4f* pos2 = new vec4f(1, 1, 1, 1);
	*pos2 = pos;

	vec4f* rot2 = new vec4f(1, 1, 1, 1);
	*rot2 = pos;

	vec4f* scale = new vec4f(1, 1, 1, 1);
	vec4f* idk2 = new vec4f();
	vec4f* idk3 = new vec4f(1, 1, 1, 1);


	Entity* reactor =  reactorMan->CreateReactor(asset, pos2, rot2, scale, idk2, idk3);
	return reactor;
}