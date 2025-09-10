#pragma once
#include "defines.h"
#include "Class/CInputDeviceListener.h"


extern "C"
{
	OE_LIBRARY_EXPORT inline void* OE_LIB_CINPUTDEVICELISTENER_GETTER_SLOT(CInputDeviceListener* listener)
	{
		if (listener == nullptr)
			return nullptr;

		return listener->deviceSlot;
	}

	OE_LIBRARY_EXPORT inline void OE_LIB_CINPUTDEVICELISTENER_SETTER_SLOT(CInputDeviceListener* listener, void* slot)
	{
		if (listener == nullptr)
			return;

		listener->deviceSlot = (CInputDeviceSlot*)slot;
	}
}