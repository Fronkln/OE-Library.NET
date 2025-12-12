#include "Input.h"
#include "PatternScan.h"

#if Y0
long long** Input::DatasStart = (long long**)(resolve_relative_addr(PatternScan("48 03 1D ? ? ? ? 74 ?")));
#endif

#if Y0DC
long long** Input::DatasStart = (long long**)(resolve_relative_addr(PatternScan("48 8B 0D ? ? ? ? 8B D0 81 E2")));
#endif

#if YK1
long long** Input::DatasStart = (long long**)(resolve_relative_addr(PatternScan("48 8B 15 ? ? ? ? 8B 81 A4 12 00 00")));
#endif