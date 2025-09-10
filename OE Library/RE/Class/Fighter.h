#pragma once
#include "Human.h"
#include "Struct/DisposeInfo.h"

class InputInfo
{
public:
	char pad_0000[4]; //0x0000
	float N00001420; //0x0004
	uint32_t buttonMask; //0x0008
	char pad_000C[4]; //0x000C
}; //Size: 0x0010

#pragma pack(push, 1)
class Fighter : public Human
{
public:
	int32_t N00001B51; //0x0254
	char pad_0258[128]; //0x0258
	float N00005165; //0x02D8
	float N00001B65; //0x02DC
	float N00005168; //0x02E0
	float N00001B66; //0x02E4
	int32_t N0000516A; //0x02E8
	int32_t N00001B67; //0x02EC
	char pad_02F0[96]; //0x02F0
	class DisposeInfo disposeInfo; //0x0350
	char pad_0410[20]; //0x0410
	int32_t fighterIndex; //0x0424
	char pad_0428[184]; //0x0428
	int32_t processDamage; //0x04E0
	char pad_04E4[3808]; //0x04E4
	class InputInfo inputInfo; //0x13C4
	char pad_13D4[7676]; //0x13D4
	int16_t N0000C0AC; //0x31D0
	int16_t N0000C0AE; //0x31D2
	int32_t N00005852; //0x31D4
	char pad_31D8[88]; //0x31D8
	class FighterBattleStatus* BattleStatus; //0x3230
	char pad_3238[16]; //0x3238
	class FighterController* fighterController; //0x3248
	char pad_3250[40]; //0x3250
	void* unknownPointer; //0x3278
	class FighterModeManager* fighterModeManager; //0x3280
	char pad_3288[32]; //0x3288
}; //Size: 0x32A8
#pragma pack(pop)