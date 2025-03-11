#include "UaTable6x7.hpp"

#define CAST(ch) static_cast<uint16_t>(ch)

const uint8_t* UaTable6x7::GetChar(uint16_t ch)
{
    return table[ch];
}

const uint8_t UaTable6x7::table[std::numeric_limits<uint16_t>::max()][height] = {
    {   // А
        0b011110,
        0b100001,
        0b100001,
        0b111111,
        0b100001,
        0b100001,
        0b100001,
    },
    {   // Б
        0b111111,
        0b100000,
        0b100001,
        0b111111,
        0b100001,
        0b100001,
        0b111111,
    },
    {   // В
        0b111110,
        0b100001,
        0b100001,
        0b111110,
        0b100001,
        0b100001,
        0b111110,
    },
    {   // Г
        0b111111,
        0b100000,
        0b100000,
        0b100000,
        0b100000,
        0b100000,
        0b100000,
    },
    {   // Д
        0b001100,
        0b010010,
        0b010010,
        0b010010,
        0b010010,
        0b111111,
        0b100001,
    },
    {   // Е
        0b111111,
        0b100000,
        0b100000,
        0b111111,
        0b100000,
        0b100000,
        0b111111,
    },
    {   // Ж
        0b101101,
        0b101101,
        0b011110,
        0b001100,
        0b011110,
        0b101101,
        0b101101,
    },
    {   // З
        0b111111,
        0b000001,
        0b000001,
        0b111111,
        0b000001,
        0b000001,
        0b111111,
    },
    {   // И
        0b100001,
        0b100001,
        0b100011,
        0b100101,
        0b101001,
        0b110001,
        0b100001,
    },
    {   // Й
        0b101101,
        0b100001,
        0b100011,
        0b100101,
        0b101001,
        0b110001,
        0b100001,
    },
    {   // К
        0b100001,
        0b100010,
        0b100100,
        0b111000,
        0b100100,
        0b100010,
        0b100001,
    },
    {   // 
        0b000000,
        0b000000,
        0b000000,
        0b000000,
        0b000000,
        0b000000,
        0b000000,
    },
    // Е
    // Ж
    // З
    // И
    // І
    // Ї
    // Н
    // Л
};
