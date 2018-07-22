from slightstalkie.arduino_interface import ArduinoInterface
import pytest


def test_init():
    with pytest.raises(SystemExit):
        i = ArduinoInterface("dfd")


