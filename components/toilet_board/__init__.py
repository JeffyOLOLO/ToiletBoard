import esphome.config_validation as cv
import esphome.codegen as cg
from esphome import pins
from esphome.components import text
from esphome.const import (
    CONF_NAME,
    CONF_DATA_PIN,
)

DEPENDENCIES = ["wifi"]

board_ns = cg.esphome_ns.namespace("Board")
ToiletBoard = board_ns.class_("ToiletBoard", cg.PollingComponent, text.Text)

CONF_CITY = 'city'

CONFIG_SCHEMA = cv.COMPONENT_SCHEMA.extend(text.TEXT_SCHEMA.extend({
  cv.GenerateID(): cv.declare_id(ToiletBoard),
  cv.Required(CONF_DATA_PIN): pins.gpio_output_pin_schema,
  cv.Optional(CONF_CITY): cv.string_strict,
  # Required by text
  cv.Optional(CONF_NAME, default="Message"): cv.string_strict,
  cv.Optional(text.CONF_MODE, default="TEXT"): cv.enum(text.TEXT_MODES, upper=True),
}
).extend(cv.polling_component_schema("1s")))

async def to_code(config):
    var = await text.new_text(config)
    await cg.register_component(var, config)

    data_pin = await cg.gpio_pin_expression(config[CONF_DATA_PIN])
    cg.add(var.set_data_pin(data_pin))
    if CONF_CITY in config:
        cg.add(var.set_city(config[CONF_CITY]))

    cg.add_library("makuna/NeoPixelBus", "2.8.3")
