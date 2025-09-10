#include "OE.h"
#include "PatternScan.h"

std::vector<OE::JobInfo> OE::m_registeredJobsPre;
std::vector<OE::JobInfo> OE::m_registeredJobsAfter;
_OE_CJob_Phase_Execute OE::phase_execute_trampoline;

bool OE::m_hookInit = false;

OE::_RegisterJob OE::ASM_RegisterJob = (OE::_RegisterJob)(PatternScan("48 63 C1 4C 8D 1D ? ? ? ?"));