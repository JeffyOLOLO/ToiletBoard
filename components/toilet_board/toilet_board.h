#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text/text.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace Board {

class ToiletBoard: public PollingComponent
{
public:
    void set_data_pin(GPIOPin *data_pin) { data_pin_ = data_pin; }
    void set_city(const char* city) { city_ = city; }
    void set_text(text::Text* text) { text_ = text; }

    void setup() override {}
    void dump_config() override;
    void loop() override {}

protected:
    GPIOPin* data_pin_;
    const char* city_;
    text::Text* text_;
};

}
}
