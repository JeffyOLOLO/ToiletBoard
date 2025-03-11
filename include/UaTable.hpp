#include <cstdint>
#include <limits>
#include <array>

template <unsigned char _width, unsigned char _height>
class UaTable
{
public:
    static const uint8_t* UaTable::GetChar(uint16_t ch)
    {
        return table[ch];
    }

    static const auto width = _width;
    static const auto height = _height;
private:
    static const uint8_t table[std::numeric_limits<uint16_t>::max()][_height];
};
