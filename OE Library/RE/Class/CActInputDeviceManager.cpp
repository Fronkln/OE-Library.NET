#include "CActInputDeviceManager.h"
#include "PatternScan.h"

CActInputDeviceManager** CActInputDeviceManager::instance = (CActInputDeviceManager**)resolve_relative_addr(PatternScan("48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8D 8B 98 01 00 00"));