#pragma once
class CInputDeviceSlot;

class CInputDeviceListener
{
public:
	void* vftable; //0x0000
	int N00001FE7; //0x0008
	char pad_000C[4]; //0x000C
	CInputDeviceSlot* deviceSlot; //0x0010
}; //Size: 0x0018

