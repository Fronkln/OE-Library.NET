#pragma once

class CActInputDeviceManager
{
public:
	void* vfptr; //0x0000
	char pad_0008[32]; //0x0008
	unsigned int slotCount; //0x0028
	char pad_002C[4]; //0x002C
	class CInputDeviceSlot* slots[2]; //0x0030
	char pad_0078[72]; //0x0078

	static CActInputDeviceManager** instance;
}; //Size: 0x00C0