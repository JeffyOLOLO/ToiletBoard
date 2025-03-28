#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text/text.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace Board {

class ToiletBoard: public PollingComponent, public text::Text
{
public:
    void set_data_pin(InternalGPIOPin *data_pin) { data_pin_ = data_pin; }
    void set_city(const char *city) { city_ = city; }

    void setup() override;
    void dump_config() override;
    void loop() override {}
    void update() override {}

protected:
    void control(const std::string &value) override
    {
        std::string out;
        for (auto i = 0; i < value.length(); ++i)
        {
            char hex[3];
            sprintf(hex, "%02X", (unsigned char)value[i]);
            out += hex;
        }
        ESP_LOGD("tb", "in hex: %s.", out.c_str());
    }

    InternalGPIOPin *data_pin_;
    const char *city_;
};

}
}
