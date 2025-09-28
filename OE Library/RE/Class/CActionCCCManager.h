#pragma once
#include "CActionBase.h"
class CActionCCCManager : public CActionBase
{
public:
	char pad_0160[136]; //0x0160
	bool isActive; //0x01E8
	int isEnding; //0x01E9
	char pad_01ED[939]; //0x01ED
}; //Size: 0x0598