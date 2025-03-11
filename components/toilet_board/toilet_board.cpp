#include "toilet_board.h"

#include "esphome/core/log.h"

namespace esphome {
namespace Board {

static constexpr auto TAG = "tb";

void ToiletBoard::dump_config()
{
    ESP_LOGCONFIG(TAG, "ToiletBoard:");
    ESP_LOGCONFIG(TAG, "  data_pin:%i", this->update_interval_);
    ESP_LOGCONFIG(TAG, "  city: %s", this->city_);
    ESP_LOGCONFIG(TAG, "  update_interval:");
}

}
}
