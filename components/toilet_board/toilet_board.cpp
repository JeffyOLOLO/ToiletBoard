#include "toilet_board.h"

#include "esphome/core/log.h"
#include "NeoPixelBus.h"

namespace esphome {
namespace Board {

static constexpr auto TAG = "tb";

typedef ColumnMajorAlternatingLayout MyPanelLayout;
// typedef ColumnMajorLayout MyPanelLayout;
// typedef RowMajorAlternatingLayout MyPanelLayout;
// typedef RowMajorLayout MyPanelLayout;

// make sure to set these panel values to the sizes of yours
const uint8_t PanelWidth = 16; // 16 pixel x 16 pixel matrix of leds
const uint8_t PanelHeight = 16;
const uint8_t TileWidth = 4; // laid out in 4 panels x 1 panel mosaic
const uint8_t TileHeight = 1;

const uint16_t PixelCount = PanelWidth * PanelHeight * TileWidth * TileHeight;
const uint8_t PixelPin = 23;

NeoMosaic<MyPanelLayout> mosaic(
    PanelWidth,
    PanelHeight,
    TileWidth,
    TileHeight);

NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount, PixelPin);

void ToiletBoard::dump_config()
{
    ESP_LOGCONFIG(TAG, "toilet_board:");
    ESP_LOGCONFIG(TAG, "  data_pin: %i", this->data_pin_->get_pin());
    ESP_LOGCONFIG(TAG, "  city: %s", this->city_ ? this->city_ : "");
}

void ToiletBoard::setup()
{
    strip.Begin();
    strip.Show();
}
}
}
