#include "Human.h"
#include "PatternScan.h"

Human::_WarpToPosition Human::ASM_WarpToPosition = (Human::_WarpToPosition)PatternScan("40 53 48 83 EC ? 0F 28 02 48 8B D9 48 8B 89 F0 01 00 00");