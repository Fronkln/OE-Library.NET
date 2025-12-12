#include "CActInputDeviceManager.h"
#include "PatternScan.h"

#if Y0 || YK1
CActInputDeviceManager** CActInputDeviceManager::instance = (CActInputDeviceManager**)resolve_relative_addr(PatternScan("48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8D 8B 98 01 00 00"));
#endif

#if Y0DC
CActInputDeviceManager** CActInputDeviceManager::instance = (CActInputDeviceManager**)resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? E8 ? ? ? ? 0F B6 83 ? ? ? ? 84 C0"));
#endif