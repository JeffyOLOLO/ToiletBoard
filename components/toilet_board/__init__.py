import esphome.config_validation as cv
import esphome.codegen as cg
from esphome import pins
from esphome.components import text
from esphome.components.text import new_text
from esphome.const import (
    # CONF_ID,
    CONF_NAME,
    CONF_DATA_PIN,
    CONF_DISABLED_BY_DEFAULT,
    CONF_MODE,
)

DEPENDENCIES = ["wifi"]

board_ns = cg.esphome_ns.namespace("Board")
ToiletBoard = board_ns.class_("ToiletBoard", cg.PollingComponent, text.Text)

CONF_CITY = 'city'

CONFIG_SCHEMA = cv.COMPONENT_SCHEMA.extend(text.TEXT_SCHEMA.extend({
  # cv.GenerateID(): cv.declare_id(ToiletBoard),
  cv.Required(CONF_DATA_PIN): pins.gpio_output_pin_schema,
  cv.Optional(CONF_CITY): cv.string_strict,

  cv.Optional(text.CONF_MODE, default="TEXT"): cv.enum(text.TEXT_MODES, upper=True),
}
).extend(cv.polling_component_schema("1s")))

async def to_code(config):
    print(config[CONF_NAME])
    # var = cg.new_Pvariable(config[CONF_ID])
    var = await text.new_text(config)
    await cg.register_component(var, config)

    # cg.add(var.set_text(txt))

    data_pin = await cg.gpio_pin_expression(config[CONF_DATA_PIN])
    cg.add(var.set_data_pin(data_pin))
    if CONF_CITY in config:
        cg.add(var.set_city(config[CONF_CITY]))
