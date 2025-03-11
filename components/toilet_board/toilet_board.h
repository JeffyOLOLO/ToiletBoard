#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text/text.h"
#include "esphome/components/text/text_traits.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace Board {

class ToiletBoard: public PollingComponent, public text::Text
{
public:
    void set_data_pin(InternalGPIOPin *data_pin) { data_pin_ = data_pin; }
    void set_city(const char* city) { city_ = city; }
    void set_text(text::Text* text) { text_ = text; }

    void set_name(const char *) {}
    void set_object_id(const char *) {}
    void set_disabled_by_default(bool) {}

    void setup() override {}
    void dump_config() override;
    void loop() override {}
    void update() override {}

    text::TextTraits traits;

protected:
    void control(const std::string &value) override {}

    InternalGPIOPin *data_pin_;
    const char* city_;
    text::Text* text_;
};

}
}
