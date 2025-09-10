#pragma once
#include "defines.h"
#include "Class/CActInputDeviceManager.h"

class CInputDeviceSlot;

extern "C"
{
	OE_LIBRARY_EXPORT inline CInputDeviceSlot* OE_LIB_CACTIONPUTDEVICEMANAGER_GET_SLOT(int slot)
	{
		CActInputDeviceManager* man = *CActInputDeviceManager::instance;

		if (man == nullptr)
			return 0;

		return man->slots[slot];
	}
}