#include "Human.h"
#include "PatternScan.h"

Human::_WarpToPosition Human::ASM_WarpToPosition = (Human::_WarpToPosition)PatternScan("40 56 48 81 EC ? ? ? ? C5 F8 10 02");