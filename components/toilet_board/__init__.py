import esphome.config_validation as cv
import esphome.codegen as cg
from esphome import pins
from esphome.components import text
from esphome.components.text import new_text
from esphome.const import (
    CONF_DATA_PIN,
)

DEPENDENCIES = ["wifi"]

board_ns = cg.esphome_ns.namespace("Board")
ToiletBoard = board_ns.class_("ToiletBoard", cg.PollingComponent, text.Text)

CONF_CITY = 'city'

CONFIG_SCHEMA = cv.Schema({
  cv.GenerateID(): cv.declare_id(ToiletBoard),
  cv.Required(CONF_DATA_PIN): pins.gpio_output_pin_schema,
  cv.Optional(CONF_CITY): cv.string_strict,
}
).extend(cv.polling_component_schema("1s")).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = await new_text(config)
    await cg.register_component(var, config)

    data_pin = await cg.gpio_pin_expression(config[CONF_DATA_PIN])
    cg.add(var.set_data_pin(data_pin))
    if CONF_CITY in config:
        cg.add(var.set_city(config[CONF_CITY]))
