#pragma once
#include "defines.h"
#include <Windows.h>
#include <cstdint>
#include "Struct/vec.h"
#include "Struct/matrix.h"
#include <array>

template <unsigned int size>
class fixed_string
{
public:
    std::array<char, size> buf;
    //  char buf[size];


    std::string toString()
    {
        return std::string(std::begin(buf), std::end(buf));
    }
};

class checksum_string
{
public:
	uint16_t checksum; //0x0000
	fixed_string<30> string; //0x0002
};