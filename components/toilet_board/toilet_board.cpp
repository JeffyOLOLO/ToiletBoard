#include "toilet_board.h"

#include "esphome/core/log.h"

namespace esphome {
namespace Board {

static constexpr auto TAG = "tb";

void ToiletBoard::dump_config()
{
    ESP_LOGCONFIG(TAG, "toilet_board:");
    ESP_LOGCONFIG(TAG, "  data_pin: %i", this->data_pin_->get_pin());
    ESP_LOGCONFIG(TAG, "  city: %s", this->city_ ? this->city_ : "");
}

}
}
