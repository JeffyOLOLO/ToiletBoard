#pragma once

#include "esphome/core/component.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace Board {

class ToiletBoard: public PollingComponent
{
public:
    void set_data_pin(GPIOPin *data_pin) { data_pin_ = data_pin; }
    void set_city(const char* city) { city_ = city; }

    void setup() override {}
    void dump_config() override;
    void loop() override {}

protected:
    GPIOPin* data_pin_;
    const char* city_;
};

}
}
