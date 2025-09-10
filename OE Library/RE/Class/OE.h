#pragma once
#include <Windows.h>
#include <vector>
#include "Hook/MinHook.h"

#pragma comment(lib, "Hook/libMinHook.x64.lib")

typedef void(__cdecl* _OENET_RegisterJob)();
typedef void(__cdecl* _OE_CJob_Phase_Execute)(int job);

#include "PatternScan.h"


class OE
{
	struct JobInfo
	{
		_OENET_RegisterJob funcAddress;
		unsigned int phase;
	};

	typedef void(__cdecl* _RegisterJob)(unsigned int phase, void* function, void* object, unsigned int prio);
	static _RegisterJob ASM_RegisterJob;

	static bool m_hookInit;

	static std::vector<JobInfo> m_registeredJobsPre;
	static std::vector<JobInfo> m_registeredJobsAfter;
	static _OE_CJob_Phase_Execute phase_execute_trampoline;

public:
	static void InitHook()
	{
		if (m_hookInit)
			return;

		MH_Initialize();

		void* updateFunc = PatternScan("40 53 55 57 41 56 41 57 48 83 EC ? 8B 15 ? ? ? ? 4C 63 F9 48 8D 0D ? ? ? ? E8 ? ? ? ? 4B 8D 04 7F 44 89 3D ? ? ? ?");

		MH_STATUS phaseHookStatus = MH_CreateHook(reinterpret_cast<void**>(updateFunc), &Hook_JobPhaseExecute, reinterpret_cast<void**>(&phase_execute_trampoline));
		MH_EnableHook(reinterpret_cast<void**>(updateFunc));

		m_hookInit = true;
	}

	static void Init()
	{
		InitHook();
	}


	static void RegisterJob(unsigned int phase, _OENET_RegisterJob function, void* object, unsigned int prio)
	{
		//didnt work. so sad
		//ASM_RegisterJob(phase, function, object, prio);

		JobInfo newJob = JobInfo();
		newJob.funcAddress = function;
		newJob.phase = phase;
		//newJob.after = after;

	//	if (!after)
		//m_registeredJobsPre.push_back(newJob);
		//else
			m_registeredJobsAfter.push_back(newJob);
	}

	static void Hook_JobPhaseExecute(unsigned int phase)
	{
		//make this code more efficie

		for (auto& jobReg : m_registeredJobsPre) // access by reference to avoid copying
		{
			if (jobReg.phase == phase)
				jobReg.funcAddress(); //call the function, we are at the phase
		}

		phase_execute_trampoline(phase);

		for (auto& jobReg : m_registeredJobsAfter) // access by reference to avoid copying
		{
			if (jobReg.phase == phase)
				jobReg.funcAddress(); //call the function, we are at the phase
		}

	}
};