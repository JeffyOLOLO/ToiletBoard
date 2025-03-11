//----------------------------------------------------------------------
// NeoPixelTopologyTest
// This will display specific colors in specific locations on the led panels
//
// This is useful in confirming the layout of your panels
//
// It does require that you have the actual panels connected
//----------------------------------------------------------------------

#include <NeoPixelAnimator.h>
#include <NeoPixelBus.h>

#include "UaTable.hpp"

// uncomment one of these that matches your panel pixel layouts
// rotation is ignored for mosaic as it applies a rotation for you
// that is specific to the location of the panel within the mosaic
// to reduce connection lengths

typedef ColumnMajorAlternatingLayout MyPanelLayout;
// typedef ColumnMajorLayout MyPanelLayout;
// typedef RowMajorAlternatingLayout MyPanelLayout;
// typedef RowMajorLayout MyPanelLayout;

// make sure to set these panel values to the sizes of yours
const uint8_t PanelWidth = 16;  // 16 pixel x 16 pixel matrix of leds
const uint8_t PanelHeight = 16;
const uint8_t TileWidth = 4;  // laid out in 4 panels x 1 panel mosaic
const uint8_t TileHeight = 1;

const uint16_t PixelCount = PanelWidth * PanelHeight * TileWidth * TileHeight;
const uint8_t PixelPin = 15;  

NeoMosaic <MyPanelLayout> mosaic(
    PanelWidth,
    PanelHeight,
    TileWidth,
    TileHeight);

NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount, PixelPin);
// for esp8266 omit the pin
//NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount);

RgbColor red(128, 0, 0);
RgbColor green(0, 128, 0);
RgbColor blue(0, 0, 128);
RgbColor orange(128, 10, 0);
RgbColor white(128);
// if using NeoRgbwFeature above, use this white instead to use
// the correct white element of the LED
//RgbwColor white(128); 
RgbColor black(0);

const uint16_t left = 0;
const uint16_t right = PanelWidth * TileWidth - 1;
const uint16_t top = 0;
const uint16_t bottom = PanelHeight * TileHeight - 1;

typedef UaTable<7,7> Table;

void set_char(uint16_t ch)
{
    const auto chr = Table::GetChar(ch);
    for (auto i = 0; i < Table::height; ++i)
    {
        for (auto j = 0; j < Table::width; ++j)
        {
            bool isPixelSet = chr[i] & 1 << j;
            strip.SetPixelColor(mosaic.Map(left + i, top + j), isPixelSet ? green : black);
        }
    }
}

void setup()
{
    Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initializing...");

    strip.Begin();
    strip.Show();

    Serial.println();
    Serial.println("Running...");
}

void loop()
{
    delay(1500);

    Serial.println();
    Serial.println("If your panel is correctly defined, you should see ...");
    Serial.println("Upper left is white.");
    Serial.println("Upper right is Red.");
    Serial.println("Lower right is Green");
    Serial.println("Lower Left is Blue");

    // use the topo to map the 2d cordinate to the pixel
    // and use that to SetPixelColor
    static auto i = 0;
    set_char(i++);
    if (i == 11)
       i = 0;
    strip.Show();

    delay(1500);

    Serial.println();
    Serial.println("Cleared to black ...");
    strip.ClearTo(black);
    strip.Show();
}
