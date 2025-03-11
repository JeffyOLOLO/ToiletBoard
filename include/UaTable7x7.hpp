#include <cstdint>
#include <limits>
#include <array>

class UaTable7x7
{
public:
    static const uint8_t* GetChar(uint16_t ch);

    static const auto width = 7;
    static const auto height = 7;
private:
    static const uint8_t table[std::numeric_limits<uint16_t>::max()][height];
};
