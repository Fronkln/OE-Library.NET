#pragma once
#include "Fighter.h"

class Player : public Fighter
{
	typedef int(__fastcall* _GetID)();
	typedef void(__fastcall* _UpdateStyleEffect)(Player* player);

	static _GetID ASM_GetID;
	static _UpdateStyleEffect ASM_UpdateStyleEffect;

public:
	static int GetID() {
#if YK1
		return 0;
#endif
		return ASM_GetID();
	}

	void UpdateStyleEffect() 
	{
		ASM_UpdateStyleEffect(this);
	}
};