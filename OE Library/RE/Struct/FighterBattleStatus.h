#pragma once
class FighterBattleStatus
{
public:
	char pad_0000[20]; //0x0000
	int32_t CurrentHealth; //0x0016
	int32_t MaxHealth; //0x0018
	float CurrentHeat; //0x001C
	int16_t N0000669D; //0x0020
	uint16_t N0000666C; //0x0022
	float N000066A4; //0x0024
	char pad_0028[20]; //0x0028
	bool N0000666F; //0x003C
	bool N000066A7; //0x003D
	bool N000066AB; //0x003E
	bool N000066AE; //0x003F
	bool N000066AC; //0x0040
	char pad_0041[431]; //0x0041
	int32_t StyleID; //0x01F0
	char pad_01F4[80]; //0x01F4
}; //Size: 0x0244