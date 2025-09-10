#pragma once

class MissionData;

class CSequenceManager
{
public:
	void* vfptr; //0x0000
	char pad_0008[72]; //0x0008
	MissionData* missionData; //0x0050
	MissionData* nextMissionData; //0x0050
	char pad_0060[16]; //0x0060
	uint32_t missionPhase; //0x0070
}; //Size: 0x0080